#pragma once


class model_parameters{
public:
	int l, nsteps, dx, elements, density, velocity;
	double dt; 
	model_parameters();	// Custom default constructor
	void print_parameters();

private:
	double extractNumbersWords(std::string str); 

};