#include "../../std_lib_facilities.h"
/*
	Drill 9.1

	Evan Holloway	May 22, 2023

	Get chapt 9.4.1 date to run. test with date June 25, 1978 and one bad date.
	Date check can be simple and ingore leap years. Check for month in [1,12] range and date in [1,31]
*/

struct Date {
	int y; // year
	int m; // month in year
	int d; // day of month
};

void init_day(Date& dd, int y, int m, int d) {

	//check that (y, m ,d) is a valid date
	if(m < 1 || m > 12) error("Please enter a valid month");
	if(d < 1 || d > 31) error("Please enter a valid day");

	dd.y = y;
	dd.m = m;
	dd.d = d;
}
void add_day(Date& dd, int n) {
	//increase dd by n days
	dd.d += n;
}

ostream& operator<<(ostream& os, const Date& d) {
	return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}

int main()
try {
	Date today;
	init_day(today, 1978, 6, 25);

	Date tomorrow{today};

	add_day(tomorrow, 1);

	cout << today << " " << tomorrow << '\n';

	Date Bad_day;
	init_day(Bad_day, 2000, 20, 32);

	cout << Bad_day << '\n';

	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << e.what() << endl;
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Unkown exception!" << endl;
	keep_window_open();
	return 2;
}
