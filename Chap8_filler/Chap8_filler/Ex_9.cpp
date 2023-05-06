#include "../../std_lib_facilities.h"

/*
	
	Evan Holloway
	May 2023

	Write function that, given two vecor<double> - price & weight - computes a value - index - that is
	the sum of all price[i] * wieght[i]. Make sure weight.size() == price.size()

*/

int sum(const vector<double>&, const vector<double>&);

int main()
try {
	vector<double> p{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	vector<double> w{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	vector<double> p_wrong{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	vector<double> w_wrong{ 1, 2, 3, 4, 5, 6, 7, 8 };

	double total = sum(p, w);

	cout << "test total: " << total << '\n';

	total = sum(p_wrong, w_wrong);
	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Uknown exception\n";
	keep_window_open();
	return 2;
}

int sum(const vector<double>& price, const vector<double>& weight) {

	if(price.size() != weight.size()) error("Please enter size and weight vectors of the same size");

	double total = 0.0;
	double tmp = 0.0;

	for (int i = 0; i < price.size(); i++) {
		tmp = price[i] * weight[i];
		total += tmp;
	}

	return total;
}