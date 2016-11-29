#include<iostream>
#include<random>
#include<ctime>
#include"../inc/jlutility.h"
#include"../inc/jlarray.h"
#include"../inc/jlmatrix.h"
#include"../inc/jlmath.h"


int main(int argc, char* argv[]) {
	unsigned int a = std::atoi(argv[1]);
	const char *b = jl::util::int_to_binary(a);
	std::cout << b << std::endl;
	std::size_t size = sizeof(unsigned int) * BYTE_SIZE;
	for (std::size_t i = 0; i < size; i++) {
		std::cout << b[i];
		if((i + 1 ) % 4 == 0)
			std::cout << ' ';
	}
	std::cout << std::endl;
	return 0;
}