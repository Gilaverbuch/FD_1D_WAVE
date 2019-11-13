#pragma once
#include "model_parameters.h"
#include <vector>

class Field{
public:
	double *U, *U_past, *U_future, *lambda, *rho, *vel, *epsilon, *RHS, *sig, *x;
	double dt;
	int dx, steps, elements, x_source, print_every;
	Field(model_parameters&);	// Custom default constructor
	void Propagator(); //wave propagation
	
private:
	void initialize(int size, double *A, std::vector<int>  x_range, std::vector<int> val);
	void print_to_file(int size, double *A, double *pos, int itteration);
	

};