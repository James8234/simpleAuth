#include <string>
#include <fstream>
#include "storeHashUsername.h"
#include "opensslLib.h" //std::string hash_sha1_evp(const std::string& input)
#include "fileLockingTools.h" //fileFailure(...), lockFile(...), unlockFile(...)

/**
 * @brief Store prehash username in a textfile, used to prevent overlaping idenitiys
 *
 * The function uses openssl libary to hash the usernames. We later use these usernamse in a bloom filter to prevent
 * users from taking existing idenitiy. To reduce the load on the program we prehash the usernames in this function.
 *
 * @param username: This is the username of the new account
 *
 * @return void
 */
void storeHashUsername(std::string username)
{
	//variables
	int fd = 0; //file lock id
	const std::string hashedUsernameFile = "shadow/hashedUsernames.dat";
	std::string firstHash = "";
	std::string secondHash = "";
	std::string totalHash = "";

	//store username textfile
	firstHash = hash_sha1_evp(username);
	secondHash = hash_sha1_evp(username + "salt");

	//The total hash is what we are inputing to the hashUsernames.dat file
	totalHash = firstHash + " " + secondHash;

	//lock file
	fd = lockFile(hashedUsernameFile);

	//Open output stream
	std::ofstream file(hashedUsernameFile, std::ios::app);

	if(!file.is_open())
		fileFailure(fd);

	file << totalHash << '\n';

	//unlock file
	unlockFile(fd);

	file.close();
}

