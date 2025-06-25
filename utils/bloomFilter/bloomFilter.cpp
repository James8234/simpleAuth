#include <iostream>
#include <cstdint> //uint64_t
#include <cmath> //log()
#include <fstream> // ifstream
#include <vector> //vector<boo>& bloomFilter
#include "bloomFilter.h"
#include "../../utils/Tools/fileLockingTools.h"
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
		return {0, 0};
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
 * @brief init the bloom filter based on a provided file
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
 * @param intHash1 holds the integer value of the hash1
 * @param intHash2 holds the integer value of the hash2
 * @param input the string from the file
 * @param index is the index of the bit vector we set to 1 from 0
 *
 * @return the bit array thats passed by refernce
 */

void initBloomFilter(std::vector<bool>& bloomfilter, std::string filepath, const long m, const int k)
{



}
