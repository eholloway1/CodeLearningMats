#include "../../std_lib_facilities.h"
/*
	Drill 9.3

	Evan Holloway	May 22, 2023

	Get chapt 9.4.3 date to run. test with date June 25, 1978 and one bad date.
	Date check can be simple and ingore leap years. Check for month in [1,12] range and date in [1,31]
*/
class Date {
	int y, m, d;

	public:
		Date(int y, int m, int d);
		void add_day(int);
		int month(){return m;}
		int day(){return d;}
		int year(){return y;}
};
int main()
try {
	
	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << e.what() << '\n';
	keep_window_open();
	return 0;
}
catch (...) {
	cerr << "Uknown exception\n";
	keep_window_open();
	return 1;
}