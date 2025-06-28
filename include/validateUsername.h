#ifndef VALIDATEUSERNAME_H_
#define VALIDATEUSERNAME_H_

#include <string>



struct validateResult
{
     bool success;
     std::string message;
};

validateResult validateUsername(std::string username);

#endif
