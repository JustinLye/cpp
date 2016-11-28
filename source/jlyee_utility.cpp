#include "../include/jlyee_utility.h"

void lye::util::save(void* data, std::size_t size, const char* filename) {
	std::FILE* out = std::fopen(filename, "wb");
	std::fwrite(data, size, 1, out);
	std::fclose(out);
}
void lye::util::load(void* data, std::size_t size, const char* filename) {
	std::FILE* in = std::fopen(filename, "rb");
	std::fread(data, size, 1, in);
	std::fclose(in);
}