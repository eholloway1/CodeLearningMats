#include "../../std_lib_facilities.h"

/*

	Evan Holloway
	May 2023

	function maxv() that retruns the largest element of a vector

*/
double maxv(const vector<double>&);

int main()
try {
	vector<double> A{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<double> B{453, 234, 645, 9864, 4324, 10023};

	double output = maxv(A);

	cout << "max in A: " << output << '\n';

	output = maxv(B);

	cout << "max in B: " << output << '\n';

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

double maxv(const vector<double>& inV) {
	
	if(inV.size() == 0) error("Please enter a vector of at least one element to maxv");
	if(inV.size() == 1) return inV[0];

	double temp = inV[0];

	for (int i = 1; i < inV.size(); i++) {
		if(inV[i] > temp) 
			temp = inV[i];
	}

	return temp;
}