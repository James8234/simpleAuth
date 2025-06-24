#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

std::string getCurrentDate()
{
	auto now = std::chrono::system_clock::now(); //This line obtains the current time from the sys clock as a time point
	std::time_t rawTime = std::chrono::system_clock::to_time_t(now); //Converts the format into time_t (January 1, 1970)
	std::tm* timeInfo = std::localtime(&rawTime); //converst time_t into tm which is a struct representing local time (year, month, day, hour, minute, second)

	std::ostringstream oss; //Thi is the output string
	oss << std::put_time(timeInfo, "%Y-%m-%d %H:%M:%S"); //formats the time according to the pattern
	return oss.str(); // "2025-06-14 13:45:20"
}
