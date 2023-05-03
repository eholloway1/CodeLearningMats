#include "../../std_lib_facilities.h"
/*

	create vector of fibonacci numbers and print them using the function from exercise 2...
	print(string name, vector<int> in). To create vector, write a function, fibonacci(x,y,v,n)...
	where x and y are ints, v is an empty vector<int>, and n is the number of elements to put into...
	v.

*/

void print(const string&, const vector<int>&);
void fibonacci(const int, const int, vector<int>&, const int);

int main()
try {
	const int size = 10;
	vector<int> fill(size);
	const string name = "fib";

	fibonacci(1, 2, fill, size);
	print(name, fill);

	keep_window_open();
	return 0;
}
catch (exception& e) {
	
	cerr << e.what() << endl;
	keep_window_open();
	return 1;
}
catch (...) {
	
	cerr << "Uknown exception\n";
	keep_window_open();
	return 2;
}

//function "print(string label, vector<int>& in) that prints a vector of ints to cout
void print(const string& label, const vector<int>& in) {

	cout << "name: " << label << '\n';
	cout << "contents: \n";

	if (in.size() == 0) return;

	for (int i = 0; i < in.size(); i++) {
		cout << in[i];
		if (i % 3 == 0 && i != 0) cout << '\n';
		else cout << " ";
	}
	cout << '\n';
}

void fibonacci(const int v0, const int v1, vector<int>& result, const int size) {
	
	if(size == 0) return;
	
	for (int i = 0; i < size; i++)
	{
		if(result[i] != 0) error("Please pass an empty vector to fibonacci()");
	}

	if (size == 1) {
		result[0] = v0;
		return;
	}
	
	result[0] = v0;
	result[1] = v1;
	if(size == 2) return;

	for (int i = 2; i < size; i++) {

		int sum = 0;
		sum += result[i - 1];
		sum += result[i - 2];
		result[i] = sum;
	}

}
