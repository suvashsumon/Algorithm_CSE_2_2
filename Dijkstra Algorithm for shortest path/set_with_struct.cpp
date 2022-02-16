// CPP implementation to use
// user-defined data type in
// structures
#include<bits/stdc++.h>
using namespace std;

// Structure definition
struct Test {
	int id;
    float result;
	
	// This function is used by set to order
	// elements of Test.
	bool operator<(const Test& t) const
	{
		return (this->result < t.result);
	}
};

// Driver method
int main()
{
	// put values in each
	// structure define below.
	Test t1 = { 110, 4.5 }, t2 = { 102, 4.23 },
		t3 = { 101, 5.00 }, t4 = { 115, 4.98 };

	// define a set having
	// structure as its elements.
	set<struct Test> s;
	
	// insert structure in set
	s.insert(t1);
	s.insert(t2);
	s.insert(t3);
	s.insert(t4);
	
	// define an iterator to iterate the whole set.
	set<struct Test>::iterator it;
	
	for (it = s.begin(); it != s.end(); it++)
	{
		// print in ascending order as required.
		cout << (*it).id << " " << (*it).result << endl;
	}
	
	return 0;
}
