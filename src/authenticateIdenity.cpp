#include <unordered_map>
#include <string>
#include "authenticateIdenity.h"
#include "loadMap.h" //void loadMap(auto& m, std::string filepath)
/**
 * @brief Turns true when the user has sucessful proven their idenity
 *
 * This function uses an unordered_map to check if a username and password are correct
 * Then it calls loadMap to lead the unordered map with the credentials file, using
 * the username as the key and the password as the contents.
 *
 * @param username the claimed idenitiy from the user
 * @param password the password the user provided to prove their idenitiy
 *
 * @return bool, True when they authenicated, false then they are not
 */

bool authenticateIdenity(std::string username, std::string& password)
{
	//variables
	const std::string filepath = "shawdow/account.dat";
	bool result = false;
	std::unordered_map<std::string, std::string> account;

	loadMap(account, filepath);
	//Check if the provided password matches the password assicated with the idenity
	result = (account[username] == password);
	//zero out local variables
	username = "";
	password = "";

	return result;
}
