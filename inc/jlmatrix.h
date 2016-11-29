#include "jlarray.h"
#include "jlshape.h"
#if !defined(__JL_MATRIX_HEADER__)
#define __JL_MATRIX_HEADER__
namespace jl {
	namespace ds {
		template<typename Type>
		class Matrix : public Array<Type> {
		public:
			Matrix() : Array<Type>(1) {}
			Matrix(int Size);
			Matrix(int Rows, int Cols);
			Matrix(const Matrix& other);
			Type& operator()(int row_index, int col_index);
			friend std::ostream& operator<<(std::ostream& s, const Matrix<Type>& m) {
				m.print(s);
				return s;
			}
			inline Shape shape() const { return _shape; }
			virtual void transpose();
		protected:
			int _rows;
			int _cols;
			jl::ds::Shape _shape;
			int _row_offset;
			int _col_offset;
			
			
			Matrix(Matrix&&) {}
			void print(std::ostream& s) const;
			
		};
	};
};

#if !defined(__JL_MATRIX_CPP__)
#include "../src/jlmatrix.cpp"
#endif

#endif