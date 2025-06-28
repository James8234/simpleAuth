#include <string>
#include <iostream>
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

/**
 * @brief Determs if the user wants to leave unsaved data
 *
 * The function ask Y or N if they want to leave with unsaved data. This function is called
 * when its determined they are saving with unsaved data.
 *
 * @return true when they do, false when they don't
 */

bool leaveUnsavedData()
{
	char leaveData;
	std::cout << "Are you sure you want to leave unsaved data <Y/N> ";
	std::cin.get(leaveData);
	leaveData = toupper(leaveData);

	if(leaveData == 'Y')
	{
		return true;
	}
	return false;
}

/**
 * @brief Checks if a string has atleast one non whitespace character
 *
 * The purpose of this function is to allow users to have passwords and username with whitespace
 * But they need to have atleast one non-white character in their inputs.
 *
 * @param input is the provided string from the user
 *
 * return bool, true means its valid and has one non-white space character, false means its all white-space
 */

bool whitespaceCheck(std::string input)
{
	for(char c : input)
	{
		if(static_cast<int>(c) != 32)
			return true;
	}
	return false;
}

