#include <string>
#include <fstream>
#include "timestamp.h"
#include "fetchPublicIP.h" //std::string getPublicIP()
#include "logCreateAccount.h" //std::string getCurrentDate()
#include "fileLockingTools.h" //fileFailure(...), lockFile(...), unlockFile(...)
#include "logCreateAccount.h"

/**
 * @brief This function purpose is to create a json log when the user has created an account
 *
 * This function creats a log file under log/create.dat and its purpose is to provide
 * auditing to when accounts where creates and by who or atleast its public ip address
 * The function will gather things like, timestamp, public IP. And combind it with
 * username and eventtype.
 * Example below:
 * "{"event":"account_creation","username":"colin,"source_ip":ip,"timpstamp":timestamp}"
 *
 * @param username This is the username of the account being created
 *
 * @return void
 */

void logCreateAccount(const std::string username)
{
	//varibles
	int fd = 0; //file lock id
	std::string ip = "";
	std::string timestamp = "";
	std::string event = "account_creation";
	std::string filepath = "log/create.log";
	std::string log = "";

	//get the user public ip
	ip = getPublicIP();

	//get the current timpstamp
	timestamp = getCurrentDate();

	//format JSON logfile
	log = "{\"event\":\"" + event + "\",\"username\":\"" + username + "\",\"source_ip\":\"" + ip + "\",\"timestamp\":\"" + timestamp + "\"}";

	//lock the file - sets an OS lock on the file and fd stores its ID. When someone goes to get a lock they need to wait untill it unlocks
	fd = lockFile(filepath);

	//open the file
	std::ofstream file(filepath);

	//Check for failture to open file
	if(!file.is_open())
		fileFailure(fd);

	//Add logs
	file << log << '\n';

	//unlock file
	unlockFile(fd);
}

