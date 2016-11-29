#include<iostream>
#include<random>
#include<chrono>
#include<ctime>
#include<limits>
#if !defined(__JL_RANDOM_HEADER__)
#define __JL_RANDOM_HEADER__

namespace jl {

	class rand_base {
	protected:
		static std::random_device rd;
		static std::mt19937 gen;
		static void start_engine();
		static int rand_int(int high_value = RAND_MAX, int low_value = 0);
		static int* rand_int(std::size_t size, int high_value = RAND_MAX, int low_value = 0);
	private:
		rand_base(const rand_base&) {}
		rand_base(rand_base&&) {}
	};
		
	class random : private rand_base {
	public:
		template<typename T = int>
		static void initialize(T* Seed = nullptr);
		static int* temp(std::size_t size, int high_value = RAND_MAX, int low_value = 0);
		
	protected:
		template<typename T = int>
		static void seed(T* Seed = nullptr);
	};
#if !defined(__JL_RANDOM_CPP__)
#include "../src/jlrandom.cpp"
#else
#if !defined(__JL_RANDOM_TPP__)
#include "../src/jlrandom.cpp"
#endif
#endif
};
#else

#endif