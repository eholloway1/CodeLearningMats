/*
	Evan Holloway	May 2023

	Add operators for the Book class. Have the == operator check whether the ISBN numbers are the same
	for two books. Have != also compare the ISBN numbers. Have a << print out the title, author, and ISBN
	on separate lines.
*/

#include "../../std_lib_facilities.h"
#include "Chrono.h"

class Book {
	class Invalid {};

	string title;
	string author;
	string ISBN;
	Chrono::Date copyright;
	bool checked;

	Book(string tit, string auth, string in_ISBN, Chrono::Date copy, bool check)
		: title(tit), author(auth), ISBN(in_ISBN), copyright(copy), checked(check)
	{

	}

public:
	string get_title() const;
	string get_author() const;
	string get_ISBN() const;
	Chrono::Date get_copyright();
	bool is_checked();
	void check();
};

bool valid_ISBN(string);

bool operator==(const Book& book0, const Book& book1) {
	return (book0.get_ISBN() == book1.get_ISBN()) ? true : false;
}

bool operator!=(const Book& book0, const Book& book1) {
	return (book0.get_ISBN() != book1.get_ISBN()) ? true : false;
}

ostream& operator<<(ostream& os, const Book& book0) {
	return os << "title: " << book0.get_title() << '\n'
				<< "author: " << book0.get_author() << '\n'
				<< "ISBN: " << book0.get_ISBN() << '\n';
}

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
	cerr << "Uknown error\n";
	keep_window_open();
	return 2;
}

Book::Book(string tit, string auth, string in_ISBN, Chrono::Date copy, bool check)
	: title(tit), author(auth), ISBN(in_ISBN), copyright(copy), checked(check)
{
	if (!valid_ISBN(in_ISBN)) throw Invalid{};
}

bool valid_ISBN(string in)
{
	if (in.size() > 4) return false;

	for (int i = 0; i < in.size(); i++) {
		if (i == in.size()) {
			if (!isalpha(in[i]) || isdigit(in[i])) return false;
		}
		if (in[i] < 0 || isalpha(in[i])) return false;
	}
}

string Book::get_title() const {
	return title;
}

string Book::get_author() const {
	return author;
}

string Book::get_ISBN() const {
	return ISBN;
}

Chrono::Date Book::get_copyright() {
	cout << "Date: " << copyright << '\n';
	return copyright;
}

bool Book::is_checked() {
	return checked;
}

void Book::check() {
	if (checked == false) checked = true;
	else {
		cout << "This book is already checked out, come again later\n";
	}
}
