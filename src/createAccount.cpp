#include <iostream>
#include <vector>
#include <string>
#include "createAccount.h"
#include "validateInteger.h" //int checkValidInteger(int, int)
#include "UI.h" //printCreateAccount(username);
#include "opensslLib.h" //std::string hash_sha512_evp(const std::string& input)
#include "tools.h"
/**
 * @brief creates accounts
 *
 * The user is promted to enter a input ranging from 0-3 to either.
 * 0 exit backt to mainmenu, 1 enter username, 2 enter password, 3 create account.
 * create account will call two functions validateUsername and validatePassword.
 * These two functions will check if their username and password is valid, if not
 * the following error messages will be printed... And the user enters anything to repromt
 *
 * @param vector<bool>& bloomfilter: This is the prep bloomfilter from the 9.4 million commom passwords, we use it in validatePassword
 *
 * @return void
 */

void createAccount(std::vector<bool>& bloomfilter)
{
	//variables
	int choice = 0; //used for user input
	bool exitProgram = false; //LCV
	std::string username = "";
	std::string password = "";
	validateResult passwordResult; //Contain the resluts of checking if their password is valid, bool, string
	validateResult usernameResult; //Contains the results of checking if their username is valid, bool, string

	while(!exitProgram)
	{
		printCreateAccount(username);
		choice = checkValidInteger(3, 0);

		switch(choice)
		{
			case 0 :
				if(!username.empty() || !password.empty()) //Checks if the user wants to leave unsaved data
				{
					exitProgram = leaveUnsavedData();
				}
				else
				{
					exitProgram = true;
				}
				break;
			case 1 :
				getline(std::cin, username);
				break;
			case 2 :
				getline(std::cin, password);
				password = hash_sha512_evp(password + "salt");
				break;
			case 3 :
				//usernameResult = validateUsername(username);
				//validatePassword = validatePassword(bloomfilter, password);
			if(usernameResult.success == false)
				std::cout << usernameResult.message << std::endl;
			if(passwordResult.success == false)
				std::cout << passwordResult.message << std::endl;

			if(usernameResult.success && passwordResult.success)
			{
				//logCreateAccount(username)
				//storeCredentials(username, password)
				exitProgram = true;
			}
		} //swtich
	}//while
}//void createAccount
