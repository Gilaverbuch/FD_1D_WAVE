#include <iostream>
#include <cmath>
#include <fstream>
#include "Field.h"


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

	initialize(size, epsilon, 20.0);

	std::cout << "epsilon val " << epsilon[10] << std::endl; 

}

void Field::initialize(int size, double *A, double value){

	for (int i=0; i<size; i++){
		A[i] = value;
	}
}