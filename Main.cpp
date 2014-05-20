#include <iostream>
#include <string>

#include "StringSet.h"
#define assert(x, msg) if (!(x)) throw msg;

void test_size()	{
	StringSet s;

	s.insert("dog");
	assert(s.size() == 1, "size should be 1.");
}


int main()	{
	try	{
		test_size();
	}
	catch(const char* msg) {
		std::cout << "error: " << msg << std::endl;
		return 1;
	}
	return 0;
}

