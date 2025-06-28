#include "checkCommonPasswords.h"
#include "bloomFilter.h" //For bloomValues struct, checkInList(...), getBloomValues(...)
#include <vector>
#include <string>
/**
 * @brief This function checks if the user password is common
 *
 * This function works by passing the preloaded bloomfilter with common passwords from the rockyou.txt text file
 * Note the rockyou.txt is around 9.6 million passwords, and passwords shorter than 8 are removed.
 * The common passwords are prehashed with sha-1, and has a non salted hash seperated with a " " from a salted hash.
 *
 * @param bloomfilter this is the bit vector which is preloaded with the hashedrockyou.txt
 * @param password this is the hashed value from the provided password
 *
 * @return bool, true when it's not in the list, false when it is in the list.
 */

bool checkCommonPasswords(std::vector<bool>& bloomfilter, const std::string password)
{
	bool inList = false;
	std::string filepath = "hashedRockyou.txt";

	bloomValues passwordParam = getBloomValues(filepath);
	inList = checkInList(bloomfilter, password, passwordParam.m, passwordParam.k);

	return inList;
}
