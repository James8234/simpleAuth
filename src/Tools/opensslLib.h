#ifndef OPENSSLLIB_H_
#define OPENSSLLIB_H_
#include <cstdint> // for uint64

std::string hash_sha1_evp(const std::string& input);
std::string hash_sha512_evp(const std::string& input);
uint64_t hexToDec(const std::string& hexStr);

#endif
