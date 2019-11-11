#include <iostream>
#include <cmath>
#include <fstream>
#include "Field.h"
#include "model_parameters.h"
#include <filesystem>

// ------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------
//public functions
Field::Field(model_parameters & M){

	std::cout << "Cuctum default constructor. Initializing the field parameters" << std::endl;

	U = new double [M.elements];
	U_past = new double [M.elements];
	U_future = new double [M.elements]; 
	lambda = new double [M.elements];
	rho = new double [M.elements];	initialize(M.elements, rho, M.density);
	vel = new double [M.elements];	initialize(M.elements, vel, M.velocity);
	epsilon = new double [M.elements]; 
	RHS = new double [M.elements];
	sig = new double [M.elements];
	x = new double [M.elements];
	dt = M.dt;
	dx = M.dx;
	steps = M.nsteps; 
	elements = M.elements;
}
// ------------------------------------------------------------------------------------------------------------------

void Field::Propagator(){
	double a=5.5e-6;
	int i;
	int x0= 2000;
	std::cout << "wave propagation!!!" << std::endl;

	// initial conditions
	for (i=0; i<elements; i++){
		x[i] = (i-1) * dx;
		U[i] = exp(-a * pow((x[i] - x0), 2));
		U_past[i] = exp(-a * pow((x[i] - (x0 - vel[i]*dt)), 2));
	}

	print_to_file(elements, U, x);

	
}

// ------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------
//private functions
void Field::initialize(int size, double *A, double value){

	for (int i=0; i<size; i++){
		A[i] = value;
	}
}
// ------------------------------------------------------------------------------------------------------------------

void Field::print_to_file(int size, double *A, double *pos){

    std::ofstream ofile;

    
    system("mkdir t");
    ofile.open("wave_signal.txt"); 

    for (int i=0; i<size; i++){
         ofile << pos[i] << " " << A[i] << std::endl;
       }
    ofile.close();


}























