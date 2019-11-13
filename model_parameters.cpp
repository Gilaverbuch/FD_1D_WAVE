#include <iostream>
#include <cmath>
#include <fstream>
#include <sstream> 
#include <vector>
#include "model_parameters.h"


// ------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------
//public functions
model_parameters::model_parameters(){

	std::cout << "Cuctum default constructor. Reading parameters from input.txt" << std::endl;

	std::ifstream inFile;
	std::string line;
	double data[4];
	int i=0;


	inFile.open("input.txt");
	while(std::getline(inFile, line)) 
	  {
	  	data[i] = extractNumbersWords(line);
	  	i++;

	  }

	nsteps = int(data[0]);  
	dx = int(data[1]); 
	dt = data[2];
	x_s = data[3];

	read_vel_profile();
	l = x_range[layers-1];
	elements = int (l/dx);
	
}
// ------------------------------------------------------------------------------------------------------------------


void model_parameters::print_parameters(){

	std::cout << "###############################" << std::endl;
	std::cout << "THESE ARE THE MODEL PARAMETERS:" << std::endl;
	std::cout << "length" << " " << l << std::endl;
	std::cout << "dx" << " " << dx << std::endl;
	std::cout << "number of elements" << " " << elements << std::endl;
	std::cout << "dt" << " " << dt << std::endl;
	std::cout << "number of stepss" << " " << nsteps << std::endl;
	std::cout << "###############################" << std::endl;

}

// ------------------------------------------------------------------------------------------------------------------
// ------------------------------------------------------------------------------------------------------------------
//private functions
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
// ------------------------------------------------------------------------------------------------------------------

void model_parameters::read_vel_profile(){

	std::ifstream inFile;

	inFile.open("vel_profile.txt");

	while(!inFile.eof())
	{
	    int  a, b, c;
	    inFile >> a >> b >> c; // extracts 3 values for layer


	    x_range.push_back(a);
		density_range.push_back(b);
		velocity_range.push_back(c);
	}
	layers = x_range.size();
}




















