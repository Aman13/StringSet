//Header File = Function Declaration--

#include <iostream>
#include <string>

class StringSet {

public:
	//Default Constructor
	StringSet();
	//Copy constructor - Creates deep copy of its parameter
	StringSet(const StringSet & source);
	//Destructor -
	~StringSet();
	//Inserts a string into the set if it does not already contain it
	bool insert(std::string value);
	//Removes a string if it exist in the set
	bool remove(std::string entry);
	//Finds the index number of a string if it exist in the set
	int find(std::string address) const;
	//Returns the current number of entries in the set
	int size() const;
	//Constructs a union of two sets and returns the result
	StringSet unions(const StringSet & source) const;
	//constructs a intersection of two sets and returns the result
	StringSet intersection(const StringSet & source) const;
	//constructs a difference of two sets and returns the result
	StringSet difference(const StringSet & source) const;

private:
	
	std::string* stringArray;
	std::string* newString;
	int length;
	int top;
};