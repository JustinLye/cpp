#include<iostream>
#include<cassert>
#if !defined(__JLYEE_CLIP_HEADER__)
#define __JLYEE_CLIP_HEADER__

namespace lye {
	namespace ds {
		template<typename Type>
		class clip {
		public:
			clip();
			~clip();
			void push_back(const Type&);

			inline int size() const { return _size; }
			inline int capacity() const { return _cap; }

			Type& operator[](int);
			inline friend std::ostream& operator<<(std::ostream& s, const clip<Type>& c) { c._print(s); return s; }
		protected:
			int _size;
			int _cap;
			Type* _array;
			void _resize();
			void _print(std::ostream& s) const;
		};
	};
};

#if !defined(__JLYEE_CLIP_CPP__)
#include"../source/jlyee_clip.cpp"
#endif
#endif