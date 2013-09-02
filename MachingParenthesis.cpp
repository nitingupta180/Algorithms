/* WAP to print all permutations of brackets */

#include <iostream>
#include <string>

using namespace std;

void brackets(int open, int close, string str) {
	if(open == 0 && close == 0) {
		cout << str << endl;
	}
	if(open > 0) {
		brackets(open - 1, close + 1, str + "<");
	}
	if(close > 0) {
		brackets(open, close - 1, str + ">");
	}
}

int main_brackets() {
	brackets(3, 0, "<");
	return 0;
}
