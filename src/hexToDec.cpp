#include <iostream>
#include <sstream>
#include <string>
#include "opensslLib.h"
#include <cstdint> //uint64_t

/**
 * This function converts a hex to desimol
 *
 * How the function works is by starting with a bit array uint64_t num = 0; which has 4 bits total 0000. 
 * We are using the fact that uint64_t can hold 64 bits, when we use num <<= we are shifting the four previous bits
 * to the left. For example num <<= 4; goes from 0000 -> 00000000. This create space so we can add 4 bits to the four left bits.
 * for example we want to add 2 which is 0010 in bit form we add it to 00000000 -> 00000010.
 * By this fact what we are doing is looping 16 times to get 64 bits total.
 * When we get each single char we get it into a ascii value and subtract it from a second ascii value to get a integer with 4 bits,
 * And integer with four bits are the following 0-9. This means we are building a bit array 4 bits per look from each char in the hex string.
 *
 */
hexPair hexToDec(const std::string& hexStr1, const std::string& hexStr2)
{
//	std::string hexrStr = hexStr.substr(0, 16);
	uint64_t result1 = 0;
	uint64_t result2 = 0;
	for(size_t i = 0; i < hexStr1.size() && i < 16; ++i) //Loops from 0 to 16 charactes in the hexadecimal string
	{
		char c = hexStr1[i]; // c holds the single char in the string given by it's index c
		char d = hexStr2[i];
		result1 <<= 4; //result = result * 16 meaning 2^4
		result2 <<= 4;

		//convert c from hexStr1
		if(c >= '0' && c <= '9' ) result1 += c - '0';
		else if (c >= 'a' && c <= 'f') result1 += c - 'a' + 10;
		else if (c >= 'A' && c <= 'F') result1 += c - 'A' + 10;
		else break; //invalid character

		//convert d from hexStr1
		if(d >= '0' && d <= '9' ) result2 += d - '0';
		else if (d >= 'a' && d <= 'f') result2 += d - 'a' + 10;
		else if (d >= 'A' && d <= 'F') result2 += d - 'A' + 10;
		else break; //invalid character
	}
	return {result1, result2};
}

/**
 * Context:
 * result <<= 4; is a bitwise left shift operation
 * Means: we shift all bits in result left by 4 position
 *
 * uint64_t is an unsigned 64-bit integer, which means it store exactly
 * 64 binary digits (bits) with values ranging from 0 to 2^64 - 1
 * We can assign it binary using 0b flag uint64_t value = 0b1000000000000000000000000000000000000000000000000000000000000001;
 * In binary it looks like "10000000 00000000 00000000 00000000 00000000 00000000 00000000 00000001"
 * We can translate the binary value to an desimal: 2^63 + 2^0 = 9223372036854775808 + 1 = 9223372036854775809
 *
 * Heres an example of bitwise left shift uint8_t = 0 which is 0000 4 bits and then you go to 00000000 which is 8 bits
 *
 */
