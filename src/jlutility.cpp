#include "../inc/jlutility.h"

void jl::util::save(void* data, std::size_t size, const char* filename) {
	std::FILE* out = std::fopen(filename, "wb");
	std::fwrite(data, size, 1, out);
	std::fclose(out);
}
void jl::util::load(void* data, std::size_t size, const char* filename) {
	std::FILE* in = std::fopen(filename, "rb");
	std::fread(data, size, 1, in);
	std::fclose(in);
}
const char* jl::util::int_to_binary(std::size_t a) {
	std::size_t size = sizeof a * BYTE_SIZE;
	std::string s(size, '\0');
	for(std::size_t i = 0; i < s.size(); i++)
		s[i] = '0';
	if(a == 0)
		return s.c_str();
	size--;
	while (a > 1) {
		if (a % 2 != 0)
			s[size] = '1';
		size--;
		a = static_cast<unsigned int>(floor(a / 2));
	}
	s[size] = '1';
	return s.c_str();
}