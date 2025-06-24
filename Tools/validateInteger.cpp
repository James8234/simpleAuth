int checkValidInteger(int max, int min)
{
	//variables
	int num;
	bool vaildInput = false;
	do
	{
		if(!(cin >> num)) //Checks if the input is a integer, the cin >> num is false when you input "in"
		{
			cin.clear();
			cin.ignore(10000 , '\n');
		}
		else if(min > num || num > max) //Checks if the input is within a range
		{
//			cout << "Error: input is out of range. Please enter between: " << max << "/" << min << " Enter your choice -->: ";
		}
		else
		{
			vaildInput = true;
		}
		cin.ignore(1000 , '\n');
	}while(!(vaildInput));
	return num;
}
