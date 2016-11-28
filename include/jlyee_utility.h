#include<iostream>
#if !defined(__JLYEE_UTILITY_HEADER__)
#define __JLYEE_UTILITY_HEADER__

namespace lye {
	namespace util {
		void save(void* data, std::size_t size, const char* filename);
		void load(void* data, std::size_t size, const char* filename);
	};
};

#endif