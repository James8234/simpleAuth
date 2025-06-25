#include "header.h"
#include "bloomFilter.h"
#include <vector>

void initializeProgram(std::vector<bool>& bloomfilter)
{
	bloomValues passwordParam = getBloomValues("../hashedRockyou.txt");
	bloomfilter.resize(password.m, false);
	initBloomFilter(bloomfilter, "/home/test/Documents/files/hashedRockyou.txt", passwordParam.m, passwordPram.k);
}
