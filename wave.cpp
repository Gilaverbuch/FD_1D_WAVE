#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream> 


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



// --------------------------------------------------------------------------------------------

void extractIntegerWords(std::string str) 
{ 
    std::stringstream ss;     
  
    /* Storing the whole string into string stream */
    ss << str; 
  
    /* Running loop till the end of the stream */
    std::string temp; 
    double found; 
    while (!ss.eof()) { 
  
        /* extracting word by word from stream */
        ss >> temp; 
  
        /* Checking the given word is integer or not */
        if (std::stringstream(temp) >> found) 
            std::cout << found << std::endl;
  
        /* To save from space at the end of string */
        temp = ""; 
    } 
} 

void read_input(){
	std::ifstream inFile;
	std::string line;

	inFile.open("input.txt");
	while(std::getline(inFile, line)) 
	  {
	  	extractIntegerWords(line);
	    // std::cout << line << std::endl;

	  }

}
// --------------------------------------------------------------------------------------------

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


	read_input();

	model_parameters model(l_, nsteps_, dx_, elements_, density_, velocity_, dt_);;
	std::cout << "model parameters" << " " << model.nsteps << std::endl;

	std::cout << "number of elements" << " " << elements_ << std::endl;
	int n=10;
	int a[n] = {};

	std::cout << a[0] << " " << a[5] << std::endl;

	return 0;
}