#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/file.h> // For flock()
#include <thread> //This is for std::this_thread::sleep_for
#include <chrono> //This is for std::chrono::milliseconds

/**
 * FUNCTION bool lockFile(int &fd)
 *
 * 1. fd is a file descriptor
 * you get it from open("file.txt", O_RDWR);
 * It represents a currently open file
 * 2. flock(fd, LOCK_EX | LOCK_NB)
 * LOCK_EX: Request an exclusive lock (no one else can read or write while this is held)
 * LOCK_NB: Non-Blocking - don't wait if it's already lockedm just fail immediately
 * 3.return value
 * If flock() returns -1, it couldn't acquire the lock
 * If it returns 0, it succeeded, and thsi process now holds an exclusive lock on the file
 */
bool acquireLock(int &fd)
{
	if(flock(fd, LOCK_EX | LOCK_NB) == -1)
	{
		return false; // meaning the file is locked
	}
	return true; //Acquire an exclusive lock
}

bool checkIfLocked(std::string filepath)
{
//	string userID = initialUser->getID();

//	string filepath = "./data/" + userID + "_bankAccountInfo.dat";
//	std::string filepath = "data/stuff.dat";

	int fd = open(filepath.c_str(), O_RDWR);

	if(fd == -1)
	{
//		cout << "Error file could not open" << endl;
//		cin.ignore(1000 , '\n');
		return 0;
	}

	if(!acquireLock(fd)) //should return true when it locks the file
	{
		std::cout << "The file is locked by another process." << std::endl;
		close(fd);
		std::cin.ignore(10000000, '\n');
		return 0;
	}

	return 1;
}


/**
 * FUNCTION: void waitUntillUnlocked(int &fd)
 *
 * This function tries repeatedly untill the lock is acquired
 */
void waitUntillUnlocked(int &fd)
{
	//waits untill we can get a lock
	while (!acquireLock(fd))
	{
		std::cout << "test" << std::endl;
	    std::this_thread::sleep_for(std::chrono::milliseconds(500)); // Wait 0.5 seconds
	}
}


/**
 * FUNCTION: void lockfile(std::string filepath)
 *
 * In this function we are opening the file and getting our fd
 * and attemps to lock the file and wait if its already locked. and returns the locked fd
 *
 */

int lockFile(std::string filepath)
{
	int fd = open(filepath.c_str(), O_RDWR);
	if(fd == -1)
	{
		std::cerr << " file may not exist or cannot be opened" << std::endl;
		close(fd);
		return -1;
	}
	if(!acquireLock(fd))
	{
		waitUntillUnlocked(fd);
	}
	return fd; //This is our id which needs to be returned to later unlock the file
}

bool unlockFile(int &fd)
{
	return flock(fd, LOCK_UN); //Release the lock
}

/*
int main()
{
	return 0;
}
*/
