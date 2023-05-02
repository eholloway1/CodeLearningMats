#include "../../std_lib_facilities.h"

/*

	write two functions that reverse the order of elements in a
	vector<string>, e.g. 1,3,5,7,9 becomes 9,7,5,3,1. The first reverse
	function should produce a new vector, leaving the o.g. unchanged.
	The second should reverse the o.g. vector directly

*/

vector<string> reverse_return(const vector<string>&);
void reverse_ref(vector<string>&);

int main()
try {
	vector<string> a{ "hi", "bye", "sky", "pie", "fry"};
	vector<string> a2{ "hi", "bye", "sky", "pie", "fry" };

	vector<string> a3 = reverse_return(a);

	cout << "reverse return\n";

	for (int i = 0; i < a.size(); i++) {
		cout << a[i];
		if (i % 2 == 0 && i != 0) cout << '\n';
		else cout << " ";
	}
	cout << '\n';


	cout << "reverse return result\n";

	for (int i = 0; i < a3.size(); i++) {
		cout << a3[i];
		if (i % 2 == 0 && i != 0) cout << '\n';
		else cout << " ";
	}
	cout << '\n';

	reverse_ref(a2);

	cout << "reverse no alt\n";

	for (int i = 0; i < a2.size(); i++) {
		cout << a2[i];
		if (i % 2 == 0 && i != 0) cout << '\n';
		else cout << " ";
	}
	cout << '\n';

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

vector<string> reverse_return(const vector<string>& in) {

	if (in.size() == 0) error("Please enter a vector of elements");
	if (in.size() == 1) return in;

	vector<string> temp;

	for (int i = in.size() - 1, j = 0; i >= 0; i--, j++) {

		temp.push_back(in[i]);
	}

	return temp;
}

void reverse_ref(vector<string>& in) {

	if (in.size() == 0) error("Please enter a vector of elements");
	if (in.size() == 1) return;


	for (int i = in.size() - 1, j = 0; i > in.size() / 2; i--, j++) {
		string temp1 = in[j];
		string temp2 = in[i];
		in[j] = temp2;
		in[i] = temp1;
	}

}
