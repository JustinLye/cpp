#include"../inc/jlshape.h"

jl::ds::Shape::Shape(std::size_t Sqr_Dims) : _rows(Sqr_Dims), _cols(Sqr_Dims) {}
jl::ds::Shape::Shape(std::size_t Rows, std::size_t Cols) : _rows(Rows), _cols(Cols) {}
jl::ds::Shape::Shape(const Shape& other) : _rows(other._rows), _cols(other._cols) {}
const std::size_t& jl::ds::Shape::operator[](int index) {
	assert(index == 0 || index == 1);
	if(index == 0)
		return _rows;
	else
		return _cols;
}
void jl::ds::Shape::operator()(std::size_t sqr_dims) {
	assert(sqr_dims > 0);
	_rows = sqr_dims;
	_cols = sqr_dims;
}
void jl::ds::Shape::operator()(std::size_t Rows, std::size_t Cols) {
	assert(Rows > 0 && Cols > 0);
	_rows = Rows;
	_cols = Cols;
}
void jl::ds::Shape::print(std::ostream& s) const {
	s << '(' << _rows << ',' << _cols << ')';
}