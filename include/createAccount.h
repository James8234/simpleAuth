#ifndef CREATEACCOUNT_H_
#define CREATEACCOUNT_H_

#include <vector>
#include <string>

struct validateResult
{
	bool success;
	std::string message;
};

void createAccount(std::vector<bool>& bloomfilter);
validateResult validateUsername(std::string username);

#endif
