//Mickie Blair
//Final Project
//Validation Class
//Class Specification File

#ifndef VALIDATION_H
#define VALIDATION_H

#include <iostream>
#include <string>

using namespace std;

class Validation {

public:
	
	//validate input as integer
	static bool isInteger(string);

	//validate input as string (letter/space/hyphen/periods acceptable)
	static bool isValidName(string);

	//validate input as letters
	static bool isLetters(string);

	//validate input as letters or numbers onlys
	static bool isLettersOrNumbers(string);

	//validate for length
	static bool isValidLength(string, int);

//Exception Class
class InvalidInput {};
class EmptyInput {};
class LettersOnly {};
class NumbersOnly {};
class NumbersOrLetters {};
class MaxLength {};



};


#endif
