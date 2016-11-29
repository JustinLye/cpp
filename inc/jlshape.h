#include<iostream>
#include<cassert>
#if !defined(__JL_SHAPE_HEADER__)
#define __JL_SHAPE_HEADER__

namespace jl {
	namespace ds {
		class Shape {
		public:
			Shape(std::size_t Sqr_Dims);
			Shape(std::size_t Rows, std::size_t Cols);
			Shape(const Shape& other);

			inline std::size_t rows() const { return _rows; }
			inline std::size_t cols() const { return _cols; }
			inline std::size_t size() const { return _cols * _rows; }

			const std::size_t& operator[](int index);

			friend std::ostream& operator<<(std::ostream& s, const Shape& sh) {
				sh.print(s);
				return s;
			}
		protected:
			Shape() {}
			std::size_t _rows;
			std::size_t _cols;
			void print(std::ostream& s) const;
			virtual void operator()(std::size_t sqr_dims);
			virtual void operator()(std::size_t Rows, std::size_t Cols);

		};
	};
};

#endif