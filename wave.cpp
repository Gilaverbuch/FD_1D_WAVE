#include <iostream>
#include <cmath>


int main()
{	
	// --------------------------------------------------------------
	// define model parameters --> put in class with constructors 

	int l = 10000; //length [m]
	int nsteps = 2000; //number of timesteps
	int dx = 20; //[m]
	double dt = 0.005; //[sec]
	int elements = int(l/dx);
	int density = 2800; //[kg/m^3]
	int velocity = 3000; //[m/s]

	// --------------------------------------------------------------
	std::cout << "number of elements" << " " << elements << std::endl;
	int n=10;
	int a[n] = {};

	std::cout << a[0] << " " << a[5] << std::endl;

	return 0;
}