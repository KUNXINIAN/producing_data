#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string int_to_string(int a) {
	stringstream ss;
	ss << a;
	string b = ss.str();
	return b;
}