//Mickie Blair
//Final Project
//Validation Class
//Class Specification File

#include "Validation.h"

//validate for integer
bool Validation::isInteger(string numStr)
{
	bool isInteger = true;
	int index = 0;

	while (isInteger && index < int(numStr.length()))
	{
		if (!isdigit(numStr[index]))
			isInteger = false;
		index++;
	}

	return isInteger;
}

//validate for string length and letters/spaces/hyphens/periods only
bool Validation::isValidName(string str)
{
	bool isValid = false;
	bool hasLetters = false;
	bool validChars = true;
	int strIndex = 0;
		
	while (!hasLetters && strIndex < (int)str.length())
	{
		if (isalpha(str[strIndex]))
		{
			hasLetters = true;
		}
		
		strIndex++;
	}

	strIndex = 0;
	
	while (validChars && strIndex < (int)str.length())
	{
		if (!isalpha(str[strIndex])&& str[strIndex] != '-' 
			&& str[strIndex] != '.' && !isspace(str[strIndex]))
		{
			validChars = false;
		}
		
		strIndex++;
	}
				
	
	if (hasLetters && validChars)
	{
		isValid = true;
	}
			
	return isValid;
}

//validate for letters only
bool Validation::isLetters(string str)
{
	bool isLetters = true;
	int index = 0;

	while (isLetters && index < int(str.length()))
	{
		if(!isalpha(str[index]))
			isLetters = false;
		index++;
	}
	
	return isLetters;
}

//validate for string letters or numbers
bool Validation::isLettersOrNumbers(string str)
{
	bool validChars = true;
	int strIndex = 0;
	   
	while (validChars && strIndex < (int)str.length())
	{
		if (!isalpha(str[strIndex]) && !isdigit(str[strIndex]))
		{
			validChars = false;
		}

		strIndex++;
	}
	
	return validChars;
}

//validate for max length
bool Validation::isValidLength(string str, int max)
{
	if ((int)str.length() > max)
	{
		return false;
	}

	else 
	{
		return true;
	}
	
}

