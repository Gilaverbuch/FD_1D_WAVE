#pragma once
#include "model_parameters.h"

class Field{
public:
	double *U, *U_past, *U_future, *lambda, *rho, *vel, *epsilon, *RHS, *sig, *x;
	double dt;
	int dx, steps;
	Field(model_parameters&);	// Custom default constructor
	void Propagator(); //wave propagation
	
private:
	void initialize(int size, double *A, double value);
	

};