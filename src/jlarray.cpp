#if !defined(__JLYEE_ARRAY_HEADER__)
#include"../inc/jlarray.h"
#endif

#if !defined(__JLYEE_ARRAY_CPP__)
#define __JLYEE_ARRAY_CPP__

template<typename Type>
jl::ds::Array<Type>::Array(int Size) : _size(Size), _array(nullptr) {
	//allocate memory
	_array = new Type[_size];
}

template<typename Type>
jl::ds::Array<Type>::~Array() {
	if (_array != nullptr) {
		delete[] _array;
	}
}

//Array.size()
//Returns total elements in the array.
//Size is set at construction
template<typename Type>
int jl::ds::Array<Type>::size() const { return this->_size; }

//Array.clear()
//Release all current memory allocated to the array.
//All elements currently in the array are lost.
template<typename Type>
void jl::ds::Array<Type>::clear() {
	if (_array != nullptr) {
		delete[] _array;
	}
	_array = new Type[_size];
}

template<typename Type>
void jl::ds::Array<Type>::fill(const Type& x) {
	for(int i = 0; i < _size; i++)
		_array[i] = x;
}

template<typename Type>
void jl::ds::Array<Type>::resize(int Size) {
	assert(Size > 0);
	if(Size == _size)
		return;
	_size = Size;
	clear();
}

template<typename Type>
Type& jl::ds::Array<Type>::operator[](int Index) {
	return _array[Index];
}

template<typename Type>
void jl::ds::Array<Type>::print(std::ostream& s) const {
	s << "[";
	for (int i = 0; i < _size-1; i++) {
		s << _array[i] << ",";
	}
	s << _array[_size - 1] << "]";
}

#endif
