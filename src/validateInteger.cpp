#include <iostream>

/**
 * @brief validates the user input
 *
 * This function makes sure the provded input is a integer by checking if the number can be extracted !(cin >>num)
 * Which returns false if it has an error, and true if its correct. The next statement makes sure the integer is 
 * within a certain range.
 *
 * @param num gets the input from the user
 * @param vaildInput is what determins if the input is correct or not
 *
 * @return the integer value of the user if its correct
 */

int checkValidInteger(int max, int min)
{
	//variables
	int num = 0;
	bool vaildInput = false;
	do
	{
		if(!(std::cin >> num)) //Checks if the input is a integer, the cin >> num is false when you input "in"
		{
			std::cout << "Error: Please enter a integer!" << std::endl;
			std::cin.clear();
//			std::cin.ignore(10000 , '\n');
		}
		else if(min > num || num > max) //Checks if the input is within a range
		{
//			cout << "Error: input is out of range. Please enter between: " << max << "/" << min << " Enter your choice -->: ";
		}
		else
		{
			vaildInput = true;
		}
		std::cin.ignore(1000 , '\n');
	}while(!(vaildInput));
	return num;
}
