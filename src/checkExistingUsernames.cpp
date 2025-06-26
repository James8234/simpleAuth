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
	std::vector<bool> usernameBloomFilter;
	std::string filepath = "shadow/hashedUsernames.dat";
	bool inList = false;

	//Determines and changes bloom filter size based on provided file
	bloomValues usernameParam = getBloomValues(filepath);
	usernameBloomFilter.resize(usernameParam.m, false);
	//Fill the bloom filter
	initBloomFilter(usernameBloomFilter, filepath, usernameParam.m, usernameParam.k);
	//Check if username is in existing list
	inList = checkInList(usernameBloomFilter, username, usernameParam.m, usernameParam.k);

	return inList; //return true when not in list. return false when it might be in list 1/1000 false posistive chance
}
