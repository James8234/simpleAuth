#include <string>
#include <iostream>
#include <vector>
#include "tools.h"

/**
 * @brief Extracts variables from a json text file
 *
 * This function requires the number of varables and the string which contains the json string.
 * The function extracts one variable at a time in the inerloop. The outer loop runs for every needed variable.
 * It works by getting the front and back " around the formatted data. And then using input.substr to get the
 * data.
 *
 * @param input contains the line of data from the json formatted text file
 * @param n contains the number of variables we need to extract from that single line.
 *
 * @return vector which contains the string variables in each elemnt of the vector
 */
#include <iostream>
std::vector<std::string> extractJsonInput(const std::string input, int n)
{
	//variables
	std::string variable = "";
	size_t firstPosition = 0;
	size_t secondPosition = 0;
	std::vector<std::string> var;

	//outer loop for each variable
	for(int i = 0; i < n; i++)
	{
		//internal loop to extract a single variable at a time
		for(int j = 0; j < n; j++)
		{
			//These two after the second loop has the second pair of "" which contains our variable
			firstPosition = input.find('\"', secondPosition + 1);
			secondPosition = input.find('\"', firstPosition + 1);
//std::cout << "your firstPosition is: " << firstPosition << std::endl;
//std::cout << "your secondPosition is: " << secondPosition << std::endl;
		}
		//check for errors
		if(firstPosition != std::string::npos)
		{
			variable = input.substr(firstPosition + 1, secondPosition - firstPosition - 1);
//std::cout << "yourfinal positions are: " << firstPosition << "]" << secondPosition << std::endl;
			var.push_back(variable);
		}
	}//outer loop
	return var;
}//end of function


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

