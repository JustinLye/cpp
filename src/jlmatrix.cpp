#if !defined(__JL_MATRIX_HEADER__)
#include "../inc/jlmatrix.h"
#endif

#if !defined(__JL_MATRIX_CPP__)
#define __JL_MATRIX_CPP__

template<typename Type>
jl::ds::Matrix<Type>::Matrix(int Size) : Array<Type>(Size), _rows(1), _cols(Size), _shape(Size) {}

template<typename Type>
jl::ds::Matrix<Type>::Matrix(int Rows, int Cols) : Array<Type>(Rows * Cols), _rows(Rows), _cols(Cols), _shape(Rows, Cols), _row_offset(Cols), _col_offset(1) {}

template<typename Type>
jl::ds::Matrix<Type>::Matrix(const Matrix& other) :
	Array<Type>(other._rows * other._cols),
	_rows(other._rows),
	_cols(other._cols),
	_shape(other._rows, other._cols),
	_row_offset(other._row_offset),
	_col_offset(other._col_offset) {
	for(int i = 0; i < other.size(); i++)
		this->_array[i] = other._array[i];
}


template<typename Type>
Type& jl::ds::Matrix<Type>::operator()(int row_index, int col_index) {
	return this->_array[row_index * _row_offset + col_index * _col_offset];
}

template<typename Type>
void jl::ds::Matrix<Type>::print(std::ostream& s) const {
	s << "[[";
	int temp_row = 0;
	int temp_col = 0;
	for (int i = 0; i < this->_size-1; i++) {
		s << this->_array[temp_row * this->_row_offset + temp_col * this->_col_offset];
		if ((i + 1) % _cols == 0) {
			s << ']' << std::endl << '[';
			temp_row++;
			temp_col = 0;
		} else {
			s << ',';
			temp_col++;
		}
	}
	s << this->_array[this->_size-1] << "]]" << std::endl;
}

template<typename Type>
void jl::ds::Matrix<Type>::transpose() {
	int buffer = this->_rows;
	this->_rows = this->_cols;
	this->_cols = buffer;
	_col_offset = _rows;
	_row_offset = 1;
	this->_shape = Shape(_rows, _cols);
}

#endif