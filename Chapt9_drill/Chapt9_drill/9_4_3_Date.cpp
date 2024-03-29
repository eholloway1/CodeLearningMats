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
		Date(int y, int m, int d)
			:y{ y }, m{ m }, d{ d }
		{
			if(m < 1 || m > 12) error("Please enter a valid month of year");
			if(d < 1 || d > 31) error("Please enter a valid day of month");
		}

		void add_day(int);
		int month() const {return m;}
		int day() const {return d;}
		int year() const {return y;}
};

ostream& operator<<(ostream& os, const Date& d) {
	return os << '(' << d.day() << ',' << d.month() << ',' << d.year() << ')';
}

int main()
try {
	Date today{1978, 6, 25};
	Date tomorrow{1978, 6, today.day() + 1};

	cout << today << " " << tomorrow << '\n';
	
	Date Bad_day{1900, 13, 42};

	cout << Bad_day << '\n';

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

void Date::add_day(int n) {
	this->d += n;
}