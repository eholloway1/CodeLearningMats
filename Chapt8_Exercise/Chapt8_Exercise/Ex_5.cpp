#include "../../std_lib_facilities.h"

int main()
try {

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