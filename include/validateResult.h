#ifndef VALIDATERESULT_H_
#define VALIDATERESULT_H_

#include <string>

/**
 * @brief This struct holds the result of username or password validation
 *
 * The bool sucess variables holds true when the username or password is valid or false when its not
 * The string message contains feedback when the user inputs an invalid, and nothing when the input is valid
 */
struct validateResult
{
     bool success;
     std::string message;
};

#endif
