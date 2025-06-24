#include <iostream>
#include <string>
#include <curl/curl.h>

// packages
// 
// -lcurl

size_t writeToString(void* contents, size_t size, size_t nmemb, std::string* output)
{
	size_t totalSize = size * nmemb;
	output->append((char*)contents, totalSize);
	return totalSize;
}
//Uses http to get the Public IP address from https://api.ipify.org
std::string getPublicIP()
{
	CURL* curl = curl_easy_init();
	std::string response;

	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, "https://api.ipify.org");
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeToString);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
		CURLcode res = curl_easy_perform(curl);

		curl_easy_cleanup(curl);

		if(res != CURLE_OK)
		{
			return "ERROR: " + std::string(curl_easy_strerror(res));
		}
		return response;
	}
	return "Error: libcurl init failed";
}
/*
int main()
{
	std::cout << "Your IP is: " << getPublicIP() << std::endl;
	return 0;
}
*/
