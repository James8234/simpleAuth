#ifndef BLOOMFILTER_H_
#define BLOOMFILTER_H_

struct bloomValues
{
	long m;
	int k;
};

bloomValues getBloomValues(const std::string filepath);

#endif
