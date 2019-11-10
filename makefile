all: main

main: wave.o model_parameters.o
		 g++ -o wave wave.o model_parameters.o

model_parameters.o: model_parameters.cpp
		g++ -c model_parameters.cpp

wave.o: wave.cpp
		g++ -c wave.cpp 

clean:	
	 rm *.o