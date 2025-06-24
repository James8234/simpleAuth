#include <iostream>
#include <sstream>
#include <string>
#include "opensslLib.h"
#include <cstdint> //uint64_t

uint64_t hexToDec(const std::string& hexStr)
{
	std::string hexrStr = hexStr.substr(0, 16);
	uint64_t decimalValue = 0;
	std::stringstream ss;
	ss << std::hex << hexrStr;
	ss >> decimalValue;
	return decimalValue;
}
