#ifndef BLOOMFILTER_H_
#define BLOOMFILTER_H_

struct bloomValues
{
	long m;
	int k;
};

bloomValues getBloomValues(const std::string filepath);
void initializeProgram(std::vector<bool>& passwordBloomFilter);
void initBloomFilter(std::vector<bool>& bloomfilter, std::string filepath, const long m, const int k);

#endif
