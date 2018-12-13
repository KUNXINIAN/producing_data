//test

#include <iostream>
#include <fstream>
using namespace std;
int main(){
	cout << "hello world" << endl;
	ofstream txt("hello.txt");
	txt << "hello this is txt" << endl;
return 0;
}
