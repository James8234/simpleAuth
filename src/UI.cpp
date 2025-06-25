#include <iostream>
#include <vector> //vector<bool>
#include "validateInteger.h"
#include "UI.h"

/**
 * @brief provides the mainmenu UI for users to login or create an account
 *
 * The user is provide an menu and they can ether leave the program, create an account
 * or lastly login to their existing account.
 *
 * @param exitProgram stores a bool, false means contine to loop, true means leave
 * @param choice stores the integer input from the user
 *
 * @return the bit vector is passed to later be used to check for common passwords
 */

void mainMenu(std::vector<bool>& passwordBloomFilter)
{

	//variables
	bool exitProgram = false;
	int choice = 0;

	std::cout << "\033c"; //clears the screen
	std::cout << "hello welcome" << std::endl;
	while(!exitProgram)
	{
		choice = checkValidInteger(2, 0);

		switch(choice)
		{
			case 0 :
				exitProgram = true;
				break;
			case 1 :

				break;
			case 2 :

				break;
			default :
				std::cout << "Input Error" << std::endl;
		}

	}

}
