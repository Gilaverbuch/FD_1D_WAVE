#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream> 


// --------------------------------------------------------------------------------------------
// --------------------------------------------------------------------------------------------
class model_parameters{
public:
	int l, nsteps, dx, elements, density, velocity;
	double dt; 
	model_parameters();	// Custom default constructor
	void print_parameters();

private:
	double extractNumbersWords(std::string str); 

};


// public functions
model_parameters::model_parameters(){

	std::cout << "Cuctum default constructor. Reading parameters from input.txt" << std::endl;

	std::ifstream inFile;
	std::string line;
	double data[6];
	int i=0;


	inFile.open("input.txt");
	while(std::getline(inFile, line)) 
	  {
	  	data[i] = extractNumbersWords(line);
	  	// print line
	  	// std::cout << line << std::endl;
	  	// std::cout << data[i] << std::endl;
	  	i++;

	  }

	l = int(data[0]);
	nsteps = int(data[1]);  
	dx = int(data[2]); 
	elements = int(data[0]/data[2]); 
	density = int(data[3]); 
	velocity = int(data[4]);
	dt = data[5];
}


void model_parameters::print_parameters(){

	std::cout << "###############################" << std::endl;
	std::cout << "THESE ARE THE MODEL PARAMETERS:" << std::endl;
	std::cout << "length" << " " << l << std::endl;
	std::cout << "dx" << " " << dx << std::endl;
	std::cout << "number of elements" << " " << elements << std::endl;
	std::cout << "dt" << " " << dt << std::endl;
	std::cout << "number of stepss" << " " << nsteps << std::endl;
	std::cout << "density" << " " << density << std::endl;
	std::cout << "velocity" << " " << velocity << std::endl;
	std::cout << "###############################" << std::endl;

}

// private functions
double model_parameters::extractNumbersWords(std::string str){ 
    std::stringstream ss;     
  
    /* Storing the whole string into string stream */
    ss << str; 
  
    /* Running loop till the end of the stream */
    std::string temp; 
    double found, val; 
    while (!ss.eof()) { 
  
        // extracting word by word from stream 
        ss >> temp; 
  
        /* Checking the given word is integer or not */
        if (std::stringstream(temp) >> found) 
            // std::cout << found << std::endl;
  			val=found;
        /* To save from space at the end of string */
        temp = ""; 
    } 
   	return val;
} 



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



