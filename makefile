all: main

main: wave.o model_parameters.o Field.o
		 g++ -o wave wave.o model_parameters.o Field.o

model_parameters.o: model_parameters.cpp
		g++ -c model_parameters.cpp

Field.o: Field.cpp
		g++ -c Field.cpp

wave.o: wave.cpp
		g++ -c wave.cpp 

clean:	
	 rm *.o