#include "../../std_lib_facilities.h"
/*
	Drill 9.5

	Evan Holloway	May 22, 2023

	Get chapt 9.7.1 date to run. test with date June 25, 1978 and one bad date.
	Date check can be simple and ingore leap years. Check for month in [1,12] range and date in [1,31]
*/
enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

class Date {
	public:
		Date(int y, Month m, int d)	
			:y{ y }, m{ m }, d{ d }
		{
			if (int(m) < 1 || int(m) > 12) error("Please enter a valid month of year");
			if (d < 1 || d > 31) error("Please enter a valid day of month");
		}

		void add_day(int);
		int month() const { return int(m); }
		int day() const { return d; }
		int year() const { return y; }

	private:
		int y;
		Month m;
		int d;
};

ostream& operator<<(ostream& os, const Date& d) {
	return os << '(' << d.day() << ',' << d.month() << ',' << d.year() << ')';
}

int main()
try {
	Date today{ 1978, Month::jun, 25 };
	Date tomorrow{ 1978, Month(today.month()), today.day() + 1};

	cout << today << " " << tomorrow << '\n';

	Date Bad_day{ 1900, Month(14), 42};

	cout << Bad_day << '\n';

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

void Date::add_day(int n) {
	this->d += n;
}