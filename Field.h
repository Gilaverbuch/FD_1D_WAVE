#pragma once


class Field{
public:
	double *U, *U_past, *U_future, *lambda, *rho, *vel, *epsilon, *RHS, *sig, *x;
	Field(int size);	// Custom default constructor
	
private:
	void initialize(int size, double *A, double value);
	

};