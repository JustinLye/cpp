#include<iostream>
#include<cmath>
#include<stdexcept>
#include<string>
#if !defined(__JLYEE_UTILITY_HEADER__)
#define __JLYEE_UTILITY_HEADER__

namespace jl {
	namespace util {
#define BYTE_SIZE 8U
		void save(void* data, std::size_t size, const char* filename);
		void load(void* data, std::size_t size, const char* filename);
		const char* int_to_binary(std::size_t a);
	};
};

#endif