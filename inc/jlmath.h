#include<iostream>
#include<cmath>
#if !defined(__JL_MATH_HEADER__)
#define __JL_MATH_HEADER__
namespace jl {
	template<typename T>
	T mod(const T& dividend, const T& divisor);
};

#if !defined(__JL_MATH_CPP__)
#include"../src/jlmath.cpp"
#endif
#endif