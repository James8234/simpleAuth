#ifndef HEADER_H_
#define HEADER_H_

#include <iostream>
#include <string> //strings
#include <openssl/sha.h> //sha-1
#include <sstream> //sha-1
#include <iomanip>
//using namespace std;

std::string sha1(const std::string& input);

#endif
