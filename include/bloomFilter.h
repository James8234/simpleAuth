#ifndef BLOOMFILTER_H_
#define BLOOMFILTER_H_

#include <vector>

/**
 * @brief This struct contains the result from getBloomValues
 *
 * The long m stores the number of bits that the bloom filter will need to get an positive error rate of 1/1000
 * The int k stores the number of hash functions required to get an similar positive error rate
 */

struct bloomValues
{
	long m;
	int k;
};

bloomValues getBloomValues(const std::string filepath);
void initializeProgram(std::vector<bool>& passwordBloomFilter);
void initBloomFilter(std::vector<bool>& bloomfilter, std::string filepath, const long m, const int k);
bool checkInList(std::vector<bool>& bloomfilter, const std::string input, const long m, const int k);

#endif
