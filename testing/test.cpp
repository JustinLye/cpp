#include<iostream>
#include<fstream>
#include<string>
#include<random>
#include<ctime>

#include"../include/jlyee_array.h"
#include"../include/jlyee_utility.h"

int main(int argc, char* argv[]) {
	srand(42);
	lye::ds::Array<int> a(10);
	for(int i = 0; i < 10; i++)
		a[i] = rand() % 100;
	std::cout << a << std::endl;
	lye::util::save(&a, sizeof a, "array_save.txt");
	lye::ds::Array<int> b(10);
	for (int i = 0; i < 10; i++)
		b[i] = rand() % 100;
	std::cout << b << std::endl;
	lye::ds::Array<int> c(10);
	for (int i = 0; i < 10; i++)
		c[i] = b[i];
	std::cout << c << std::endl;
	lye::util::load(&b, sizeof b, "array_save.txt");
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	return 0;
}
