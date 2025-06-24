/**
 * FUNCTION: whitespacecheck
 *
 * NEED: NIST SP 800-63B
 * STATES: Allow special characters and spaces but dont require them
 * TASK: Allow whitespace but makesure atleast one charater is not whitespace so users have a password to authenticat themself with
 * The function returns true when it has atleast one non whitespace character
 * Returns false when all charaters are whitespace.
 */
bool whitespaceCheck(std::string name)
{
	for(char c : name)
	{
		if(static_cast<int>(c) != 32)
		{
			return true;
		}
	return false;
	}
}
