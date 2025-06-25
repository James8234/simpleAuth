#include <iostream>
#include <cstdint> //uint64_t
#include <cmath> //log()
#include <fstream> // ifstream
#include <vector> //vector<boo>& bloomFilter
#include <cstdint> // for uint64_t
#include "bloomFilter.h"
#include "fileLockingTools.h" //lockFile() unlockFile()
#include "opensslLib.h" //hexToDes(), hexPair struct
#include "tools.h" //extractInput()
/**
 * @brief Calculates optimal parameters for a bloom filter
 *
 * This function returns a struct containing the optimal number of bits (m)
 * and the number of hash functions (k) required for a bloom filter,
 * based on teh expected number of elements (n) and a desired false positive rate of 1/1000
 *
 * @param fd File descriptor for the Locked file
 * @param input the string read from the file
 * @param n The number of elemnts to insert into the bloom filter
 * @param m the claculate size in bits of the bloom filter
 * @param k the calulated number of hash functions to use
 * @return bloomParamters struct containing (m) and (k) values
*/
bloomValues getBloomValues(const std::string filepath)
{
	//variables
	int fd = 0;
	std::string input = "";
	long n = 0;
	const double p = 0.001;
	long m = 0;
	int k = 0;

	//open file
	fd = lockFile(filepath);

	//check for file failure
	//open file stream
	std::ifstream file(filepath);

	if(!file.is_open())
	{
		fileFailure(fd);
	}

	//scan number of inputs from file
	while(getline(file, input))
	{
		n++;
	}

	//calculate number of bits
	m = -(n * log(p) / (log(2) * log(2)));

	//calculate number of hash functions
	k = (m/n) * log(2);

	file.close(); //close file
	unlockFile(fd); //unlockfile

	return {m , k};
}

/**
 * @brief Initializes a bloom filter from a prahashed text file.
 *
 * This function passes the bit vector by refernce and then loads it from a prehashed textfile
 * This function allows us to use the bloom filter to check for common passwords or exist usernames
 * and the function relies on getBloomValues to provide its number of bits and number of hash functions
 * In the prehash text file where is two hash values in a single line seperated by " ". the second one is 
 * The salted verison of the first. Note hashes are stored as hexadecimal
 *
 * @param hash1 stores the first hash from the textfile
 * @param hash2 stores the second hash
 * @param fd File descirptor for Locked file
 * @param intHash1 holds the 64 bit integer value of the hash1
 * @param intHash2 holds the 64 bit integer value of the hash2
 * @param input the string from the file
 * @param index is the index of the bit vector we set to 1 from 0
 * @param hexs this is the struct that obtains the two intHash values using hexToDes
 *
 * @return the bit array thats passed by refernce
 */

void initBloomFilter(std::vector<bool>& bloomfilter, std::string filepath, const long m, const int k)
{
	//variables
	std::string hash1 = "";
	std::string hash2 = "";
	std::string input = "";
	int fd = 0;
	uint64_t intHash1 = 0;
	uint64_t intHash2 = 0;
	long index = 0;
	hexPair hexs;

	//open filestream
	fd = lockFile(filepath);
	std::ifstream file(filepath);

	//Check for failure of opening file
	if(!file.is_open())
	{
		fileFailure(fd);
	}
	//extract input
//std::cout << "before getting line" << std::endl;
//int f = 0;
	while(getline(file, input))
	{
		extractInput(input, hash1, hash2);
		hexs = hexToDec(hash1, hash2);
		intHash1 = hexs.value1;
		intHash2 = hexs.value2;
		//Sets the bloom filter assigned index from flase to true
		for(int i=0; i < k; i++)
		{
			index = ((intHash1 + i * intHash2) % m);
			bloomfilter[index] = true;
		}
	}
	// unlock resoucres
	file.close();
	unlockFile(fd);
}

/**
 * @brief Encapsulates the initiation of the bloom filter to check for common passwords
 *
 * The purpose of the function is to keep the main.cpp clean from these functions
 *
 * @param filepath stores the path to the file we are using to load the bloom filter
 *
 * @return the bloom filter
 */
void initializeProgram(std::vector<bool>& passwordBloomFilter)
{
	std::string filepath = "hashedRockyou.txt";
	bloomValues passwordParam = getBloomValues(filepath);
	passwordBloomFilter.resize(passwordParam.m, false);
	initBloomFilter(passwordBloomFilter, filepath, passwordParam.m, passwordParam.k);
}
