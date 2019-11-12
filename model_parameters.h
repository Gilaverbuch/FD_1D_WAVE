#pragma once
#include <vector>

class model_parameters{
public:
	int l, nsteps, dx, elements, density, velocity;
	double dt, layers; 
	std::vector<int>  x_range, density_range, velocity_range; //dynamic vectors to read velocity profile

	model_parameters();	// Custom default constructor
	void print_parameters();

private:
	double extractNumbersWords(std::string str); 
	void read_vel_profile();

};