#include <iostream>
#include <vector> //Used for bit vector
#include "header.h"
#include "test.h"
#include "bloomFilter.h"
#include "UI.h"
using namespace std;

int main()
{
//	stuff();
	vector<bool> passwordBloomFilter;
	initializeProgram(passwordBloomFilter); //loads the bloomFilter
	mainMenu(passwordBloomFilter); //loads the main menu UI

	return 0;
}
