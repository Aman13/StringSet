//Function Definitions --

#include "StringSet.h"

/*StringSet::StringSet() {
	length = 4;
	top = 0;
	std::string* stringArray = new std::string[length];
		for(int i = 0; i < length; i++) {
		std::cout << stringArray[i] << std::endl;
	}
	
}

bool StringSet::insert(std::string value) {
	bool duplicate = false;

	for(int i = 0; i < this->top && !duplicate; ++i) {
		duplicate = stringArray[i] == value; 
	}
	if(duplicate)
		return false;
	if (top == length) {
		length = 2 * length;
		std::string* temp = stringArray;
		stringArray = new std::string[length];
		for(int i = 0; i < top; i++) {
			stringArray[i] = temp[i];
		}
		delete[] temp;
	}
}
*/
StringSet::StringSet() {
	length = 4;
	top = 0;
	this->stringArray = new std::string[this->length];
}

StringSet::StringSet(const StringSet & source) {
	std::cout << "copy constructor" << std::endl;
	this->length = source.length;
	this->top = source.top;
	this->stringArray = new std::string[this->length];

	for(int i = 0; i < top; ++i){
		this->stringArray[i] = source.stringArray[i];
	}

}

StringSet::~StringSet() {
	delete[] this->stringArray;
}

bool StringSet::insert(std::string value) {
	bool duplicate = false;

	for(int i = 0; i < this->top && !duplicate; ++i) {
		duplicate = this->stringArray[i] == value;
	}
	if(duplicate) {
		return false;
	}
	if (this->top == this->length) {
		std::string* temp = new std::string[this->length*2];
		for(int i = 0; i < this->length; ++i) {
			temp[i] = this->stringArray[i];
		}
		std:: cout << "Array filled up, doubling space" << std::endl;
		this->length *= 2;
		delete[] this->stringArray;
		this->stringArray = temp;
	}
	std::cout << "inserting string: " << value << ", into array " << std::endl;
	this->stringArray[top] = value;
	this->top++;
	std::cout << "array currently contains: " << std::endl;
	for(int i = 0; i < this->top; i++) {
		std::cout << stringArray[i] << std::endl;
	}
}

bool StringSet::remove(std::string entry) {
	bool duplicate = false;
	int check = 0;

	for(check; check < this-> top && !duplicate; ++check) {
		duplicate = this->stringArray[check] == entry;
		}

	if(duplicate) {
		std::cout <<"removable string found, removing string: " << entry << std::endl << "current array contains: " << std::endl;
		check--;
		this->top--;
		this->stringArray[check] = this->stringArray[this->top];
		for(int i = 0; i < this->top; i++) {
		std::cout << stringArray[i] << std::endl;
		}
		return true;
	}	
	
	if(!duplicate){
			std::cout <<"no matching string found containing:" << entry << std::endl;
			return false;
	}
}

int StringSet::find(std::string address) const {
	bool duplicate = false;
	int index = 0;
	for( index; index < this-> top && !duplicate; ++index) {
		duplicate = this->stringArray[index] == address;
	}
	if(duplicate) {
		index--;
		std::cout << "The Index for string: " << address << " is: " << index << std::endl;
		return index;
	}
	if(!duplicate) {
		std::cout << "The string: " << address << ", is not in the array" << std::endl;
		return -1;	
	}
}

int StringSet::size() const{
	std::cout << "there are currently: " << this->top << " strings in the array" << std::endl;
	return this->top;
}


/*
StringSet StringSet::unions(const StringSet & source) const{
	this->stringArray
*/


/*
	if (this->top == this->length) {
		std::string* temp = new std::string[this->length*2];
		for(int i = 0; i < this->length; ++i) {
			temp[i] = this->stringArray[i];
		}
		std:: cout << "Array filled up, doubling space" << std::endl;
		this->length *= 2;
		delete[] this->stringArray;
		this->stringArray = temp;
	}

		if(this->top == this->length) {
		std::string* temp = new std::string[this->length*2];
		this->stringArray = new std::string[this->length*2];
		for(int i = 0; i < this->top; ++i) {
			this->stringArray[i] = temp[i];
		}
		delete[] temp;
		this->length *=2;
	}
	*/