#include "../../std_lib_facilities.h"

/*

	Evan Holloway
	May 2023

	write a function that takes a vector<string> arg and returns a vector<int> containing the number
	of characters in each string. Also find the longest and shortest string
	and the lexiographically first and last string.

	I used three seperate functions: logically the size testing on the length of each string can be done
	in one step, and the order testing can be done in its own step. Printing the findings is a
	seperate function.
*/

struct exercise {
	private:
		vector<int> string_char_num;
		string longest;
		string shortest;
		string first;
		string last;

	public:
		exercise(){}
		~exercise(){}

		void size_check(const vector<string>&);
		void order_check(const vector<string>&);
		void printVals();
};

int main()
try {

	vector<string> A{ "hi", "bye", "pie", "quit", "sky", "shy", "cry", "quit", "rye" };

	exercise example;

	example.size_check(A);
	example.order_check(A);
	example.printVals();

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

void exercise::size_check(const vector<string>& in) {
	if(in.size() == 0) error("Please pass a vector of elements to size_check");
	if (in.size() == 1) {
		string_char_num.push_back(in[0].length());
		this->first = in[0];
		this->last = in[0];
		this->longest = in[0];
		this->shortest = in[0];
	}

	int largest = 0;
	int shortest = INT_MAX;

	for (int i = 0; i < in.size(); i++) {
		int curr_size = in[i].length();
		string_char_num.push_back(curr_size);

		if(curr_size > largest) {
			largest = curr_size;
			this->longest = in[i];
		}
		if(curr_size < shortest) {
			shortest = curr_size;
			this->shortest = in[i];
		}
	}
}

void exercise::order_check(const vector<string>& in) {
	vector<string> temp = in;

	sort(temp.begin(), temp.end());
	this->first = temp[0];
	this->last = temp[temp.size() - 1];
}

void exercise::printVals() {

	cout << "the legnth of the strings in the vector<string> are (in their resepctive index):\n";
	for (int i = 0; i < string_char_num.size(); i++) {
		cout << string_char_num[i];
		if(i > 0 && i % 4 == 0) cout << '\n';
		else cout << " ";
	}
	cout << "The longest string is: " << this->longest << '\n';
	cout << "The shortest string is: " << this->shortest << '\n';
	cout << "The lexicographically first string is: " << this->first << '\n';
	cout << "The lexicographically last string is: " << this->last << '\n';
}