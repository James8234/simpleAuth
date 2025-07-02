#include <string>
#include <fstream>
#include "timestamp.h" //std::string getCurrentDate()
#include "fetchPublicIP.h" //std::string getPublicIP()
#include "fileLockingTools.h" //fileFailure(...), lockFile(...), unlockFile(...)
#include "logAuthticationAttempt.h"

/**
 * @brief generates a log when someone attemps to login to an account
 *
 * The purpose of this function is to provde log files that we can forward
 * to a SIEM system like wazuh. Later we will lest wazuh decoders, rules
 * to be notified when someone fails to login multiple times.
 *
 * @param username the username the login attempted claimed
 * @param loginStatus holds true or false depending if they proved their idenitiy
 *
 * @return void
 */
void logAuthticationAttempt(const std::string username, bool loginStatus)
{
	//variables
	const std::string filepath = "log/auth.log";
	std::string ip = "";
	std::string event = "login_attempt";
	std::string timestamp = "";
	std::string status = "";
	std::string authLog = "";//holds the log string
	int fd = 0; //filelock id

	//set variables
	if(loginStatus)
	{
		status = "success";
	}
	else
	{
		status = "failed";
	}

	timestamp = getCurrentDate();
	ip = getPublicIP();

	authLog = "{\"event\":\"" + event + "\",\"status\":\"" + status + "\",\"username\":\"" + username + "\",\"source_ip\":\"" + ip + "\",\"timestamp\":\"" + timestamp + "\"}";

	//open file for output stream
	fd = lockFile(filepath);

	std::ofstream file(filepath, std::ios::app);

	//Quits program as it should never happen
	if(!file.is_open())
		fileFailure(fd);

	file << authLog << '\n';

	file.close();

	unlockFile(fd);
}
