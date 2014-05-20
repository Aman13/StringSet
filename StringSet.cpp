//Function Definitions --

#include "StringSet.h"

//Default Constructor
StringSet::StringSet()	{
	length = 4;
	top = 0;
	this->stringArray = new std::string[this->length];
}
//Copy Constructor - Creates Deep Copy
StringSet::StringSet(const StringSet & source)	{
	this->length = source.length;
	this->top = source.top;
	this->stringArray = new std::string[this->length];
	for(int i = 0; i < top; ++i)	{
		this->stringArray[i] = source.stringArray[i];
	}

}

StringSet::~StringSet()	{
	delete[] this->stringArray;
}

//	Inserts a string into the array, if it does not already contain that string
bool StringSet::insert(std::string value)	{
	bool duplicate = false;
	//The loop checks the set with the new entry, if there is a duplicate
	//duplicate becomes true, and the loop stops
	for(int i = 0; i < this->top && !duplicate; ++i)	{
		duplicate = this->stringArray[i] == value;
	}
	if(duplicate)	{
		return false;
	}
	//Before we attempt to insert the new string, must make sure the array has space
	//if the top is equal to length, that means the array must be made larger.
	//A temporary array is made to hold the entries, and then a larger array 
	//is created and given the entries.
	if (this->top == this->length)	{
		std::string* temp = new std::string[this->length*2];
		for(int i = 0; i < this->length; ++i)	{
			temp[i] = this->stringArray[i];
		}
		this->length *= 2;
		delete[] this->stringArray;
		this->stringArray = temp;
	}
	this->stringArray[top] = value;
	this->top++;
}
// Removes a string if it is in the array
bool StringSet::remove(std::string entry)	{
	bool duplicate = false;
	int check = 0;

	for(check; check < this-> top && !duplicate; ++check)	{
		duplicate = this->stringArray[check] == entry;
	}
	//Loops through looking for a duplicate, if it finds a duplicate
	//The duplicate word is replaced by the last word in the array
	//Top is decremented to now point to the last entry and is then put
	//into the position of the removed entery
	if(duplicate)	{
		check--;
		this->top--;
		this->stringArray[check] = this->stringArray[this->top];
		return true;
	}		
	if(!duplicate)	{
			return false;
	}
}

//Looks for a specific string located in the array
int StringSet::find(std::string address)	const{
	bool duplicate = false;
	int index = 0;
	for(index; index < this-> top && !duplicate; ++index)	{
		duplicate = this->stringArray[index] == address;
	}
	//If the string is found, it returns the index of the string,
	//if it does not exist in the array it returns -1
	if(duplicate)	{
		index--;
		return index;
	}
	if(!duplicate)	{
		return -1;	
	}
}
//Returns how many entries are in an array, because arrays have an index of 0,
//the next spot variable can be returned for the current size 
int StringSet::size()	const{
	return this->top;
}
//Constructs the union of two sets and returns the result
//Using the insert function, and inserting one set after the other
//into the new set, insures no string is inserted more than once
StringSet StringSet::unions(const StringSet & source)	const{
	StringSet newString;
	for(int i = 0; i < this->top; ++i)	{
		newString.insert(this->stringArray[i]);
	}
	for(int i = 0; i < source.top; ++i)	{
		newString.insert(source.stringArray[i]);
	}
	return newString;
}
//Constructs the intersection of two sets and returns the result
StringSet StringSet::intersection(const StringSet & source)	const{
	StringSet newString;
	int b = 0;
	//Because the intersection requires both sets to contain the string
	//the nested for loop, is required to make sure no string is missed
	//Using the find function return of -1 meaning there is no match
	//to choose which string should be inserted into the new set
	for(int i = 0; i < this->top; ++i)	{
		for(int j = 0; j < source.top;++j)	{
			b = this->stringArray[i].find(source.stringArray[j]);
			if(b > -1)	{
				newString.insert(this->stringArray[i]);
			}
		}
	}
	return newString;
}
//Constructs the difference of two sets and returns the result
StringSet StringSet::difference(const StringSet & source) const{
	StringSet newString;
	for(int i = 0; i < this->top; ++i){
		newString.insert(this->stringArray[i]);
	}
	//The new sets is given all the values of the object set
	//and parameter set is then called to remove any string it contains
	for(int i = 0; i < source.top; ++i){
		newString.remove(source.stringArray[i]);
	}
	return newString;
}
