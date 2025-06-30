#include <string>
#include <fstream>
#include "storeCredentials.h"
#include "storeHashUsername.h"//void storeHashUsername(std::string username)
#include "fileLockingTools.h" //fileFailure(...), lockFile(...), unlockFile(...)

/**
 * @brief THis function purpose is to store the user credentials into the text file database
 *
 * This function goal is to create a JSON format string that contains the username and hashed with salt password
 * Example:"{"event":"account","username":"colin,"password","hashpassword"}"
 * This function also stores the hashed version of the username in a seperate text. This text file is later used
 * for checking if the username already exist when creating an account.
 *
 * @param username: This is the username of the new account
 * @param password: This is the hashed password of the new account
 *
 * @return void
 */

void storeCredentials(std::string username, std::string password)
{
	//variables
	int fd = 0; //file lock id
	const std::string credentialsFilepath = "shadow/account.dat";
	std::string storeAccount = "";

	//create json format
	storeAccount = "{\"username\":\"" + username + "\",\"password\":\"" + password + "\"}";

	//lock file
	fd = lockFile(credentialsFilepath);

	//open output stream
	std::ofstream file(credentialsFilepath, std::ios::app);

	//check for open failure
	if(!file.is_open())
		fileFailure(fd);

	//output to file
	file << storeAccount << '\n';

	file.close();

	//release the lock
	unlockFile(fd);

	//store the username in a text file to prevent people from overlaping idenitiys
	storeHashUsername(username);
}

