#include <iostream>
#include <fstream>
#include <chrono>
#include <stdexcept>

typedef std::chrono::high_resolution_clock high_functioning_clock;
typedef std::chrono::time_point<high_functioning_clock> timer;
typedef std::chrono::duration<double, std::milli> duration;

int fibonacci(int index) {
	if(index < 0)
		throw std::invalid_argument("The index for the Fibonacci sequence must be positive");
	else if(index == 0)
		return 0;
	else if(index <= 2)
		return 1;
	else
		return fibonacci(index-2) + fibonacci(index-1);
}

int main() {

	std::ofstream fibonacciCSV("fibonacci.csv");

	for(int i = 0 ; i <= 40 ; ++i) {
		timer start = high_functioning_clock::now();

		std::cout << "F_" << i << " = " << fibonacci(i) << std::endl;

		duration result = high_functioning_clock::now() - start;
		fibonacciCSV << i << ", "<< result.count() << std::endl;
	}
	
	return 0;
}
