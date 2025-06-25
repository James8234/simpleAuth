#ifndef OPENSSLLIB_H_
#define OPENSSLLIB_H_
#include <cstdint> // for uint64

std::string hash_sha1_evp(const std::string& input);
std::string hash_sha512_evp(const std::string& input);

struct hexPair
{
	uint64_t value1;
	uint64_t value2;
};

hexPair hexToDec(const std::string& hexStr1, const std::string& hexStr2);


#endif
