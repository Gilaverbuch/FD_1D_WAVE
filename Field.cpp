#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include "Field.h"
#include "model_parameters.h"
#include <filesystem>

// ------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------
//public functions
Field::Field(model_parameters & M){

	std::cout << "Cuctum default constructor. Initializing modeling parameters and velocity profile" << std::endl;

	dt = M.dt;
	dx = M.dx;
	steps = M.nsteps; 
	elements = M.elements;
	x_source = M.x_s;
	print_every = M.print_int;
	U = new double [M.elements];
	U_past = new double [M.elements];
	U_future = new double [M.elements]; 
	lambda = new double [M.elements];
	rho = new double [M.elements];	initialize(M.elements, rho, M.x_range, M.density_range);
	vel = new double [M.elements];	initialize(M.elements, vel, M.x_range, M.velocity_range);
	epsilon = new double [M.elements]; 
	RHS = new double [M.elements];
	sig = new double [M.elements];
	x = new double [M.elements];
	

	// calculating lambda
	for (int i=0; i<elements; i++){
		lambda[i] = rho[i] * pow(vel[i],2);
		x[i] = (i-1) * dx;
	}
}
// ------------------------------------------------------------------------------------------------------------------

void Field::Propagator(){
	double a=5.5e-6;
	double freq=5;
	double t_delay=5;
	double source;
	int i, j, itteration, pos;
	std::cout << "wave propagation!!!" << std::endl;
	system("rm results/*.txt");

	// initial conditions
	for (i=0; i<elements; i++){
		U[i] = exp(-a * pow((x[i] - x_source), 2));
		U_past[i] = exp(-a * pow((x[i] - (x_source - vel[i]*dt)), 2));
	}

	pos = int(x_source/dx);
	itteration = 0;
	print_to_file(elements, U, x, itteration);


	// propagator

	for (i=0; i<steps; i++){
		// source  =   0.001*((2*M_PI*freq) / sqrt(2 * M_PI)) * exp(-0.5 * (pow(freq,2)) * pow((i*dt - t_delay),2));
		source = 0;

		for (j=1; j<(elements-1); j++){

			RHS[j] = (U[j+1] - 2*U[j] + U[j-1])/(dx*dx) + source;

			U_future[j] = pow(vel[j],2) * pow(dt,2) * RHS[j] + 2*U[j] - U_past[j];
		}

		U_future[0] = 0;
		U_future[elements-1] = 0;



		if (i%print_every==0){
			itteration = i/print_every;

			print_to_file(elements, U_future, x, itteration);
		}


		for (j=0; j<elements; j++){
			U_past[j] = U[j];
			U[j] = U_future[j];
			U_future[j] = 0;
		}

	}



	system("mv wave_signal*.txt results/");	
}



// ------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------
//private functions
void Field::initialize(int size, double *A, std::vector<int>  x_range, std::vector<int> val){

	int pos, pos1, pos2;
	pos1 = 0;
	for (int i=0; i<int(x_range.size()); i++){

		pos2 = int(x_range[i]/dx);

		for (pos=pos1; pos<pos2; pos++){

			A[pos] = val[i];
		}
		pos1 = pos2;
	}
}
// ------------------------------------------------------------------------------------------------------------------

void Field::print_to_file(int size, double *A, double *pos, int itteration){

    std::ofstream ofile;

    ofile.open("wave_signal"+std::to_string(itteration)+".txt"); 


    for (int i=0; i<size; i++){
         ofile << pos[i] << " " << A[i] << std::endl;
       }
    ofile.close();
}
// ------------------------------------------------------------------------------------------------------------------























