#include <string>
#include "tools.h"

/**
 * @brief Extracts two hash values from a single string
 *
 * This function purpose is to take a string which contains two hash values seperated by a space
 * example: "hash1 hash2"
 * And then split them into two seperate strings. The difference between the hash values stored in
 * the previous string is that one is hashed without a salt and the second one has a salt hashed
 *
 * @param firstPosition contains the integer position of the whitespace character
 *
 * @return retuns the two hash variables passed by refernce
 */

void extractInput(const std::string input, std::string& hash1, std::string& hash2)
{
	std::string::size_type firstPosition = 0;
	firstPosition = input.find(' ');

	if(firstPosition != std::string::npos)
	{
		hash1 = input.substr(0, firstPosition);
		hash2 = input.substr(firstPosition + 1);
	}
}
