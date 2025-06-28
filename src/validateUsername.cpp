#include "validateUsername.h"
#include "checkExistingUsernames.h" //checkExistingUsername(username)
#include "tools.h" //whitespace check
#include <string>

/**
 * @brief This function validates an provided username and outputs a struct with two variables bool string
 *
 * The functions goal is to make sure the username is within a certain range, first to make sure the user
 * has an ideity for auiding and second that its not too large it dos the server.
 * The second goal is to allow whitespace but makesure they have atleast one non-white character
 * The last goal is to make sure they don't use an idenity that already exist
 *
 * @param username This is the provide username to create their account
 *
 * @return validateResult a struct with
 */
validateResult validateUsername(std::string username)
{
	if(username.size() > 50 && username.size() < 4)
		return { false, "Error: Invalid username length. Keep within 50-4" };

	if(!whitespaceCheck(username))
		return { false, "Error: username must have atleast one character" };

	if(checkExistingUsernames(username))
		return { false, "Error: Username already exist" };

	//This case is true then the username passess the three previous checks
	return { true, "Successful" };

}

