#include <iostream>
#include <vector>
#include <string>
#include "createAccount.h"
#include "validateUsername.h" //validateResult validateUsername(username);
#include "validateInteger.h" //int checkValidInteger(int, int)
#include "UI.h" //printCreateAccount(username);
#include "opensslLib.h" //std::string hash_sha512_evp(const std::string& input)
#include "validateResult.h" //provides struct validateResult
#include "validatePassword.h" //validateResult validatePassword(bloomfilter, password);
#include "storeCredentials.h" //void storeCredentials(std::string username, std::string password)
#include "logCreateAccount.h" //logCreateAccount(username);
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
				std::cout << "Enter username here ->:";
				getline(std::cin, username);
				break;
			case 2 :
				std::cout << "Enter password here ->:";
				getline(std::cin, password);
				break;
			case 3 :
				usernameResult = validateUsername(username);
				passwordResult = validatePassword(bloomfilter, password);

				//Provide feedback If the user entered an invalid username or password
				if(usernameResult.success == false)
					std::cout << usernameResult.message << std::endl;
				if(passwordResult.success == false)
					std::cout << passwordResult.message << std::endl;

				//Checks if the the username and password is valid if so the account will be created
				if(usernameResult.success && passwordResult.success)
				{
					password = hash_sha512_evp(password + "salt"); //hash password to protect from mem drop
					logCreateAccount(username);
					storeCredentials(username, password);
					exitProgram = true;
				}
				else
				{
					std::cout << "<----Enter anything to continue!---->" << std::endl;
					std::cin.ignore(100000 , '\n');
				}
				break;
			default :
				std::cout << "Errpr: input:" << std::endl;
		} //swtich
	}//while
}//void createAccount
