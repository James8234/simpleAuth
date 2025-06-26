#include <string>
#include <vector> //vector<bool> usernameBloomFilter
#include "createAccount.h"
#include "bloomFilter.h" //bloomValue struct, getBoomValues(filepath), initBloomFilter(...), checkInList(...)

/**
 * @brief checks if the username provided by user, already exist in the system
 *
 * The purpose of function is to make sure every user has an unqiue idenity,
 * It dose this by loading existing users in a prehashed text file into a
 * bloom filter with an positive error rate of 1/1000.
 *
 * @param username is the idenity the user is creating
 *
 * return bool which is true if its not in the system and false if it is in the system
 */
bool checkExistingUsernames(const std::string username)
{
	//variables
	vecter<bool> usernameBoolFilter;
	std::string filepath = "shadow/hashedUsernames.dat";
	bool inList = false;



}
