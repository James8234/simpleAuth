#ifndef CREATEACCOUNT_H_
#define CREATEACCOUNT_H_

#include <vector>

struct validateResult
{
	bool success;
	std::string message;
};

void createAccount(std::vector<bool>& bloomfilter);
#endif
