#include <iostream>
#include <string>
#include "loginAccount.h"
#include "validateInteger.h" //int checkValidInteger(max, min)
#include "opensslLib.h" //std::string hash_sha512_evp(const std::string& input)
#include "authenticateIdenity.h" //authenticateIdenity(username, password);
#include "logAuthticationAttempt.h"
#include "UI.h" //printLoginAccount
/**
 * @brief This function allows the user to login to their existing account
 *
 * The user is promted a integer which they have a certain range 0-3
 * 0 exits the program, 1 enters the username, 2 enters the password, 3 validates authentication
 * The authentication system will use an unordered_map to check if a password is in the correct.
 * How it works is that the program will use the username as an key, alough they are prehashed so
 * we need to prehash the user input username as the unordered_map hashed it again by default.
 * And If the provided key the username matches it will check if the contents the hash password is equal.
 * The program will also check if the use has unsaved data and ask them before leaving
 *
 * @return void
 */
void loginAccount()
{
	//variables
	int choice = 0;
	int passwordSize = 0;
	int usernameSize = 0;
	bool exitProgram = false;
	std::string username = "";
	std::string password = "";
	bool loginStatus = false;

	while(!exitProgram)
	{
		printLoginAccount(username, passwordSize);
		choice = checkValidInteger(3, 0);

		switch(choice)
		{
			case 0 :
				exitProgram = true;
				break;
			case 1 :
				std::cout << "Enter your username ->:";
				getline(std::cin, username);
				usernameSize = username.size();
				break;
			case 2 :
				std::cout << "Enter your password ->:";
				getline(std::cin, password);
				passwordSize = password.size();
				password = hash_sha512_evp(password + "salt");
				break;
			case 3 :
				if(usernameSize >= 4 && usernameSize <= 50 && passwordSize >= 8 && passwordSize <= 50)
				{
					loginStatus = authenticateIdenity(username, password);
					logAuthticationAttempt(username, loginStatus);
					if(loginStatus == true)
						printAccount(username);
					exitProgram = true;
				}
				else
				{
					std::cout << "Input left empty" << std::endl;
					std::cin.ignore(100000 , '\n');
				}
				break;
			default :
				std::cout << "input error" << std::endl;
		}//switch(choice)
	}//while(!exitProgram)
//	if(loginStatus == true)
//		printAccount(username);
}//end of function
