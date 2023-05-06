#include "../../std_lib_facilities.h"

/*

	Evan Holloway
	May 2023

	improve 8.5.2::print_until_s(). What makes a good set of test cases? Write a print_until_ss that 
	prints until it sees a second occurrence of its quit argument

*/

void print_until_s(const vector<string>& v, const string& quit);
void print_until_ss(const vector<string>& v, const string& quit);

int main()
try {

	vector<string> A{"hi", "bye", "pie", "quit", "sky", "shy", "cry", "quit", "rye"};
	string exit = "quit";

	print_until_s(A, exit);
	cout << '\n';
	print_until_ss(A, exit);

	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << e.what() << endl;
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Uknown exception" << endl;
	keep_window_open();
	return 2;
}

void print_until_s(const vector<string>& v, const string& quit) {

	for (string s : v) {
		if(s == quit) return;
		cout << s << '\n';
	}
}

void print_until_ss(const vector<string>& v, const string& quit) {
	bool seen = false;

	for (string s : v) {
		if(s == quit && seen == false) seen = true;
		else if(s == quit && seen == true) return;
		cout << s << '\n';
	}
}
