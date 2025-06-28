#include "validateResult.h" // provides struct validateResult
#include "tools.h" //bool whitespaceCheck(std::string input)
#include "checkCommonPasswords.h" //bool checkCommonPasswords(...)
#include "validatePassword.h"
#include <vector>

/**
* @brief This function validates an provided password and outputs a struct with two variables bool string
*
* The functions goal is to make sure the password is within a certain range, first to make sure the user
* has an strong password and or second that its not too large it dos the server.
* The second goal is to allow whitespace but makesure they have atleast one non-white character
* The last goal is to make strong the user has a strong password by preventing common passwords that
* are commonly used and easy to gues or brute force with rockyou.txt
*
* @param password This is the provide password to create their account
*
* @return validateResult a struct with true/false and message relating to the issue
*/

validateResult validatePassword(std::vector<bool>& bloomfilter, const std::string password)
{
	if(password.size() > 50 && password.size() < 8)
		return { false, "Error: Invalid password length. 8 min, 50 max." };

	if(whitespaceCheck(password))
		return { false, "Error: Password must have at least one character." };

	if(!(checkCommonPasswords(bloomfilter, password)))
		return { false, "Error: Password is easy to guess!" };

	return { true, " " }; //password is valid
}
