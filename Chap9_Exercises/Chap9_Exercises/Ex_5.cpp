/*
	Evan Holloway	May 2023

	design and implement a Book class, such as you can imagine as part of software for a library. 
	Class Book should have members for the ISBN, title, author, and copyright date. Also store data 
	on whether or not the book is checked out. Create functions for returning those data values. 
	Create functions for checking a book in and out. Do simple validation of data entered into a Book; 
	for example, accept ISBNs only of the form n-n-n-x where n is an integer and x is a digit or a letter.
	Store an ISBN as a string.
*/

#include "../../std_lib_facilities.h"
#include "Chrono.h"

class Book {
	class Invalid{};

	string title;
	string author;
	string ISBN;
	Chrono::Date copyright;
	bool checked;

	Book(string tit, string auth, string in_ISBN, Chrono::Date copy, bool check);

	public:
		string get_title();
		string get_author();
		string get_ISBN();
		Chrono::Date get_copyright();
		bool is_checked();
		void check();
};

bool valid_ISBN(string);

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
	if(!valid_ISBN(in_ISBN)) throw Invalid{};
}

bool valid_ISBN(string in)
{
	if(in.size() > 4) return false;

	for (int i = 0; i < in.size(); i++) {
		if (i == in.size()) {
			if(!isalpha(in[i]) || isdigit(in[i])) return false;
		}
		if(in[i] < 0 || isalpha(in[i])) return false;
	}
	return true;
}

string Book::get_title() {
	return title;
}

string Book::get_author() {
	return author;
}

string Book::get_ISBN() {
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
	if(checked == false) checked = true;
	else {
		cout << "This book is already checked out, come again later\n";
	}
}
