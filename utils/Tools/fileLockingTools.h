#ifndef FILELOCKINGTOOLS_H_
#define FILELOCKINGTOOLS_H_

//lock files
int lockFile(std::string filepath);
bool unlockFile(int &fd);

//filehandling
void fileFailure(int &fd);

#endif
