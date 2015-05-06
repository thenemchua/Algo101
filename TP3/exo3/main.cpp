#include <iostream>
#include <fstream>
#include <chrono>
#include <stdexcept>

typedef std::chrono::high_resolution_clock high_functioning_clock;
typedef std::chrono::time_point<high_functioning_clock> timer;
typedef std::chrono::duration<double, std::milli> duration;

int fibonacci(unsigned int index) {
	if(index == 0)
		return 0;
	else if(index <= 2)
		return 1;
	else
		return fibonacci(index-2) + fibonacci(index-1);
}

int main() {

	std::ofstream fibonacciCSV("fibonacci.csv");

	for(int i = 0 ; i <= 40 ; ++i) { // Do the computation for the first 40 elements
		timer start = high_functioning_clock::now();

		std::cout << "F_" << i << " = " << fibonacci(i) << std::endl; // Print it to command prompt

		duration result = high_functioning_clock::now() - start; 
		fibonacciCSV << i << ", "<< result.count() << std::endl; // Print the time it took to a csv, see ../Fibonnacci.R for plotting
	}
	
	return 0;
}
