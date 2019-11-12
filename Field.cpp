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
	int i, itteration;
	int x0= 2000;
	std::cout << "wave propagation!!!" << std::endl;
	system("rm results/*.txt");

	// initial conditions
	for (i=0; i<elements; i++){
		x[i] = (i-1) * dx;
		U[i] = exp(-a * pow((x[i] - x0), 2));
		U_past[i] = exp(-a * pow((x[i] - (x0 - vel[i]*dt)), 2));
	}
	itteration = 0;
	print_to_file(elements, U, x, itteration);


	// propagator


	// for i in range(0,nsteps):
	// for j in range(0,elements-1):
	// 	epsilon[j]=(U[j+1]-U[j])/dx
	// 	sig[j]=lam[j]*epsilon[j]

	// for j in range(1,elements-1):	
	// 	RHS[j]=(sig[j]-sig[j-1])/dx

	// Ufuture[:]=(RHS[:]/rho[:])*dt**2+2*U[:]-Upast[:]
	// Ufuture[0]=0
	// Ufuture[elements-1]=0

	// #################################################
	// #printing figures
	// #change temp value in order to change the number of printed figures
	// temp=10
	// if i%temp==0:
	// 	p_num=i/temp
	// 	plt.figure()
	// 	plt.plot(x,Ufuture[:]); plt.title("1D wave"); plt.xlabel('Distance [m]') 
	// 	exec "plt.savefig('1D-wave%d.png')" %(p_num)
	// #################################################


	// Upast[:]=U[:]
	// U[:]=Ufuture[:]


	system("mv wave_signal*.txt results/");	
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

void Field::print_to_file(int size, double *A, double *pos, int itteration){

    std::ofstream ofile;

    ofile.open("wave_signal"+std::to_string(itteration)+".txt"); 


    for (int i=0; i<size; i++){
         ofile << pos[i] << " " << A[i] << std::endl;
       }
    ofile.close();
}
// ------------------------------------------------------------------------------------------------------------------























