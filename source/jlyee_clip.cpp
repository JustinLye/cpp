#if !defined(__JLYEE_CLIP_HEADER__)
#include"../include/jlyee_clip.h"
#endif

#if !defined(__JLYEE_CLIP_CPP__)
#define __JLYEE_CLIP_CPP__

template<typename Type>
lye::ds::clip<Type>::clip() : _size(0), _cap(100), _array(new Type[_cap]) {}

template<typename Type>
lye::ds::clip<Type>::~clip() { delete[] _array; }

template<typename Type>
void lye::ds::clip<Type>::push_back(const Type& val) {
	if(_size == _cap)
		_resize();
	_array[_size] = val;
	_size++;
}

template<typename Type>
Type& lye::ds::clip<Type>::operator[](int index) { 
	assert(index < _size && index >= 0);
	return _array[index];
}

template<typename Type>
void lye::ds::clip<Type>::_resize() {
	Type* _buffer = _array;
	_cap *= 2;
	_array = new Type[_cap];
	for(int i = 0; i < _size; i++)
		_array[i] = _buffer[i];
	delete[] _buffer;
}

template<typename Type>
void lye::ds::clip<Type>::_print(std::ostream& s) const {
	if(_size == 0)
		return;
	for(int i = 0; i < _size - 1; i++)
		s << _array[i] << ' ';
	s << _array[_size-1];
}

#endif