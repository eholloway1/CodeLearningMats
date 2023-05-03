#include "../../std_lib_facilities.h"

/*
	
	Evan Holloway
	May 2023

	Write function that, given two vecor<double> - price & weight - computes a value - index - that is
	the sum of all price[i] * wieght[i]. Make sure weight.size() == price.size()

*/

int main()
try {

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