//Header File = Function Declaration--

#include <iostream>
#include <string>

class StringSet {

public:

	StringSet();

	StringSet(const StringSet & source);

	~StringSet();

	bool insert(std::string value);

	bool remove(std::string entry);

	int find(std::string address) const;

	int size() const;

	StringSet unions(const StringSet & source) const;

	StringSet intersection(const StringSet & source) const;

	StringSet difference(const StringSet & source) const;

private:
	
	std::string* stringArray;
	std::string* newString;
	int length;
	int top;
};