#ifndef FILELOCKINGTOOLS_H_
#define FILELOCKINGTOOLS_H_

//string hash_sha1_evp(const string& password);
//int hexToDec(const std::string& hexStr);

//lock files
int lockFile(std::string filepath);
bool unlockFile(int &fd);

#endif
