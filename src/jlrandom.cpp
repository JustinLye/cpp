#if !defined(__JL_RANDOM_HEADER__)
#include"../inc/jlrandom.h"
#endif

#if !defined(__JL_RANDOM_CPP__)
#define __JL_RANDOM_CPP__

std::random_device jl::rand_base::rd;
std::mt19937 jl::rand_base::gen;
void jl::rand_base::start_engine() {
	gen = std::mt19937(rd());
}
int jl::rand_base::rand_int(int high_value, int low_value) {
	return ((rand() % (high_value - low_value)) + low_value);
}
int* jl::random::temp(std::size_t size, int high_value, int low_value) {
	int* a = new int[size];
	for (std::size_t i = 0; i < size; i++) {
		a[i] = rand_int(high_value, low_value);
	}
	return a;
}
#endif

#if !defined(__JL_RANDOM_TPP__)
#define __JL_RANDOM_TPP__
template<typename T>
void jl::random::initialize(T* Seed) {
	start_engine();
	seed<T>(Seed);
}

template<typename T>
void jl::random::seed(T* Seed) {
	if (Seed == nullptr) {
		srand(time(NULL));
	} else {
		srand(*Seed);
	}
}
#endif
