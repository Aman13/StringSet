#include <iostream>
#include <string>

#include "StringSet.h"
#define assert(x, msg) if (!(x)) throw msg;

void test_size()	{
	StringSet s;

	s.insert("dog");
	assert(s.size() == 1, "size should be 1.");
}
void test_union()	{
	StringSet a;
	StringSet b;
	a.insert("dog");
	a.insert("cat");
	a.insert("cow");
	a.insert("chicken");
	a.insert("horse");
	b.insert("dog");
	b.insert("cat");
	StringSet c = a.unions(b);
	assert(c.size() == 5, "dog repeats and 5+2-2 = 5");
}
void test_intersection()	{
	StringSet a;
	StringSet b;
	a.insert("dog");
	a.insert("cat");
	a.insert("cow");
	a.insert("chicken");
	a.insert("horse");
	b.insert("dog");
	b.insert("cat");
	StringSet c = a.intersection(b);
	assert(c.size() == 2, "because only 2 strings match");
}


int main()	{
	try	{
		test_size();
		test_union();
		test_intersection();
	}
	catch(const char* msg) {
		std::cout << "error: " << msg << std::endl;
		return 1;
	}
	return 0;
}

