//simple array structure
#include<iostream>
#include<cassert>
#if !defined(__JLYEE_ARRAY_HEADER__)
#define __JLYEE_ARRAY_HEADER__

namespace jl {
	namespace ds {
		template<typename Type>
		class Array {
		public:
			Array(int Size);
			~Array();
			virtual int size() const;
			virtual void clear();
			virtual void fill(const Type& x);
			virtual void resize(const int Size);
			virtual Type& operator[](int Index);
			friend std::ostream& operator<<(std::ostream& s, const Array<Type>& a) {
				a.print(s);
				return s;
			}
		protected:
			int _size;
			Type* _array;
			virtual void print(std::ostream& s) const;

			Array() {}
			Array(const Array&) {}
			Array(Array&&) {}
		};
	};
};

#if !defined(__JLYEE_ARRAY_CPP__)
#include"../src/jlarray.cpp"
#endif

#endif