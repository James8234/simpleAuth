#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
#include "fileLockingTools.h" //fileFailure(...), lockFile(...), unlockFile(...)
#include "tools.h" //std::vector<std::string> extractJsonInput(const std::string input, int n)
#include "loadMap.h"
/**
 * @brief The function purpose is to load a hashmap
 *
 * The function in our case uses the uesername as the key and the password as the contents
 *
 * @param m the hashmap
 * @param filepath the file we want to load the hashmap with
 *
 * @return void
 */
void loadMap(std::unordered_map<std::string, std::string>& m, const std::string filepath)
{
	//variables
	std::string input = "";
	std::string hash1 = "";
	std::string hash2 = "";
	int fd = 0;
	std::vector<std::string> var;

	//lockfike
	fd = lockFile(filepath);

	std::ifstream file(filepath);

	//check if file opened correctly
	if(!file.is_open())
	{
		fileFailure(fd);
	}

	while(getline(file, input))
	{
		var = extractJsonInput(input, 2);
		hash1 = var[0];
		hash2 = var[1];
		m.insert( make_pair(hash1, hash2));
	}

	//cleanup
	file.close();
	unlockFile(fd);
}//end of function
