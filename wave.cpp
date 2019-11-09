#include <iostream>
#include <cmath>

class model_parameters{
public:
	int l, nsteps, dx, elements, density, velocity;
	double dt; 
	model_parameters(int l_, int nstep_, int dx_, int elements_, int density_, int velocity_, double dt_);

private:


};

model_parameters::model_parameters(int l_, int nstep_, int dx_, int elements_, int density_, int velocity_, double dt_){
	l = l_;
	nsteps = nstep_;  
	dx = dx_; 
	elements = elements_; 
	density = density_; 
	velocity = velocity_;
	dt = dt_;
}



int main()
{	
	// --------------------------------------------------------------------------------------------
	// define model parameters --> put in class with constructors 

	int l_ = 10000; //length [m]
	int nsteps_ = 2000; //number of timesteps
	int dx_ = 20; //[m]
	int elements_ = int(l_/dx_);
	int density_ = 2800; //[kg/m^3]
	int velocity_ = 3000; //[m/s]
	double dt_ = 0.005; //[sec]

	// --------------------------------------------------------------------------------------------



	model_parameters model(l_, nsteps_, dx_, elements_, density_, velocity_, dt_);;
	std::cout << "model parameters" << " " << model.nsteps << std::endl;

	std::cout << "number of elements" << " " << elements_ << std::endl;
	int n=10;
	int a[n] = {};

	std::cout << a[0] << " " << a[5] << std::endl;

	return 0;
}