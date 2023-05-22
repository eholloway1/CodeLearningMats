#include "../../std_lib_facilities.h"
/*
	Drill 9.2

	Evan Holloway	May 22, 2023

	Get chapt 9.4.2 date to run. test with date June 25, 1978 and one bad date.
	Date check can be simple and ingore leap years. Check for month in [1,12] range and date in [1,31]
*/

struct Date {
	int y, m, d;	//year, month, day
	Date(int y, int m, int d);	//check for valid date and initialize
	void add_day(int n);	//increase the Date by n days
};

ostream& operator<<(ostream& os, const Date& d) {
	return os << '(' << d.y << ',' << d.m << ',' << d.d << ')';
}

int main()
try {
	Date today{1978, 6, 26};
	Date tomorrow{1978, 6, today.d + 1};

	cout << today << " " << tomorrow << '\n';
	
	Date Bad_day {2000, 13, 0};

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

	cerr << "Uknown error!\n";
	keep_window_open();
	return 2;
}

Date::Date(int y, int m, int d) {
	//check that (y, m ,d) is a valid date
	if (m < 1 || m > 12) error("Please enter a valid month");
	if (d < 1 || d > 31) error("Please enter a valid day");

	this->y = y;
	this->m = m;
	this->d = d;
}

void Date::add_day(int n) {
	//increase dd by n days
	d += n;
}