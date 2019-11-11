#include <iostream>
#include <cmath>
#include <fstream>
#include "Field.h"
#include "model_parameters.h"

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
}
// ------------------------------------------------------------------------------------------------------------------

void Field::Propagator(){

	std::cout << "wave propagation!!!" << std::endl; 
}

// ------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------
//private functions
void Field::initialize(int size, double *A, double value){

	for (int i=0; i<size; i++){
		A[i] = value;
	}
}


