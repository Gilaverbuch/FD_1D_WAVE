#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream> 
#include "model_parameters.h"


// --------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------
class Field{
public:
	double *U, *U_past, *U_future, *lambda, *rho, *vel, *epsilon, *RHS, *sig, *x;
	Field(int size);	// Custom default constructor
	
private:
	

};

Field::Field(int size){

	std::cout << "Cuctum default constructor. Initializing the field parameters" << std::endl;

	U = new double [size];
	U_past = new double [size];
	U_future = new double [size]; 
	lambda = new double [size];
	rho = new double [size];
	vel = new double [size];
	epsilon = new double [size];
	RHS = new double [size];
	sig = new double [size];
	x = new double [size];
}


// --------------------------------------------------------------------------------------------

int main()
{	

	model_parameters model;
	model.print_parameters();
	Field displacement(model.elements);

	// this is another way to print the model parameters
	// std::cout << "length" << " " << model.l << std::endl;
	// std::cout << "dx" << " " << model.dx << std::endl;
	// std::cout << "number of elements" << " " << model.elements << std::endl;
	// std::cout << "dt" << " " << model.dt << std::endl;
	// std::cout << "number of stepss" << " " << model.nsteps << std::endl;
	// std::cout << "density" << " " << model.density << std::endl;
	// std::cout << "velocity" << " " << model.velocity << std::endl;


	// std::cout << "number of elements" << " " << elements_ << std::endl;
	// int n=10;
	// int a[n] = {};

	// std::cout << a[0] << " " << a[5] << std::endl;

	return 0;
}



