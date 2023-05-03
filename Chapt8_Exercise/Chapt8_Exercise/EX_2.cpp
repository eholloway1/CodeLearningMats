#include "../../std_lib_facilities.h"

void print(const string&, const vector<int>&);

int main()
try {
	
	vector<int> d{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	string a = "dicks";

	print(a, d);

	keep_window_open();
	return 0;
}
catch (exception& e) {

	cerr << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {

	cerr << "Uknown exception" << '\n';
	keep_window_open();
	return 2;
}

//function "print(string label, vector<int>& in) that prints a vector of ints to cout
void print(const string& label, const vector<int>& in) {
	
	cout << "name: " << label << '\n';
	cout << "contents: \n";

	if(in.size() == 0) return;
	
	for (int i = 0; i < in.size(); i++) {
		cout << in[i];
		if(i % 4 == 0) cout << '\n';
		else cout << " ";
	}
}