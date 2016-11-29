#include<iostream>
#include<random>
#include<ctime>
#include"../inc/jlrandom.h"


int main(int argc, char* argv[]) {
	
	jl::random::initialize<int>();
	int *a = jl::random::temp(10);
	std::cout << '{';
	for(std::size_t i = 0; i < 9; i++)
		std::cout << a[i] << ',';
	std::cout << a[9] << '}' << std::endl;
	delete[] a;
	return 0;
}