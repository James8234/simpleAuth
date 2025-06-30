#ifndef TOOLS_H_
#define TOOLS_H_

#include <vector>

void extractInput(const std::string input, std::string& hash1, std::string& hash2);
bool leaveUnsavedData();
bool whitespaceCheck(std::string input);
std::vector<std::string> extractJsonInput(const std::string input, int n);


#endif
