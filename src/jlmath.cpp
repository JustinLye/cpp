#if !defined(__JL_MATH_HEADER__)
#include"../inc/jlmath.h"
#endif

#if !defined(__JL_MATH_CPP__)
#define __JL_MATH_CPP__
template<typename T>
T jl::mod(const T& dividend, const T& divisor) {
	T r = 0;
	(dividend > 0) ? r = std::fmod(dividend, divisor) : r = divisor + std::fmod(dividend, divisor);
	return r;
}

#endif