#include <iostream>
#include <vector> //Used for bit vector
#include "header.h"
#include "bloomFilter.h"
#include "menu.h" //mainMenu(passwordBloomFilter);
using namespace std;

int main()
{
//	stuff();
	vector<bool> passwordBloomFilter;
	cout << "\033c";
	cout << "Loading..." << endl;
	initializeProgram(passwordBloomFilter); //loads the bloomFilter
	mainMenu(passwordBloomFilter); //loads the main menu UI

	return 0;
}
