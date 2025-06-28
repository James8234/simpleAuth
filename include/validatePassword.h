#ifndef VALIDATEPASSWORD_H_
#define VALIDATEPASSWORD_H_

#include <vector>
#include "validateResult.h" //provides struct validateResult

validateResult validatePassword(std::vector<bool>& bloomfilter, const std::string password);

#endif
