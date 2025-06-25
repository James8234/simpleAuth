#include <iostream>
#include <iomanip> // for setw and setfill
#include "UI.h"

/**
 * @brief provides a user interface to create an acconut or login to an existing account
 *
 * The user is provide an menu and they can ether leave the program, create an account
 * or lastly login to their existing account.
 *
 */
void printMainMenu()
{
	std::cout << "\033c"; //clears the screen
	std::cout << "Welcome to mainmenu" << std::endl;
	std::cout << "<0>: exit" << std::endl;
	std::cout << "<1>: createAccount" << std::endl;
	std::cout << "<2>: login" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Please enter <0-2>:";
}

/**
 * @brief provides the user interface to create an account
 *
 * The user can enter a username, enter a password, and lastly validate their entered credentials
 *
 * @param charCount this is the number of characters from the username so we don't need to pass the hashed pasword
 *
 * @return An interactive user interface to create an account to the console
 */
void printCreateAccount(std::string username)
{
	int charCount = username.size();
	std::cout << "\033c";
	std::cout << "Welcome to account creation menu\n" << std::endl;
	std::cout << "TIP: Never use the name password on multiple sites!\n" << std::endl;
	std::cout << "<0>: exit" << std::endl;
	std::cout << "<1>: Enter username: " << username << std::endl;
	std::cout << "<2>: Enter password: " << std::setfill('*') << std::setw(charCount) << " " << std::endl;
	std::cout << "<3>: Create Acconunt:" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Please enter <0-3>:";
}
