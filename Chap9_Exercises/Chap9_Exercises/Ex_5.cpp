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

	string title;
	string author;
	string ISBN;
	Chrono::Date copyright;
	bool checked;

	public:
		class Invalid {};
		Book(string tit, string auth, string in_ISBN, Chrono::Date copy, bool check);
		string get_title() const;
		string get_author() const;
		string get_ISBN() const;
		Chrono::Date get_copyright() const;
		bool is_checked() const;
		void check();
};

bool valid_ISBN(string);

ostream& operator<<(ostream& os, const Book&);

int main()
try {
	Book b1{"dicks", "Jeany", "142-25-86-A", Chrono::Date{1984, Chrono::Month::mar, 20}, false};
	cout << b1;

	Book bad_Book{"bums", "Kramer", "123-4-B-!", Chrono::Date{2003, Chrono::Month::jan, 2}, true};
	cout << bad_Book;

	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (Book::Invalid& e)
{
	cerr << "Invalid book construction\n";
	keep_window_open();
	return 3;
}
catch (Chrono::Date::Invalid& e)
{
	cerr << "Invalid Date construction\n";
	keep_window_open();
	return 4;
}
catch (...) {
	cerr << "Uknown error\n";
	keep_window_open();
	return 2;
}

ostream& operator<<(ostream& os, const Book& in) {
	os << "title: " << in.get_title() << " "
				<< "Author: " << in.get_author() << " "
				<< "ISBN: " << in.get_ISBN() << " "
				<< "copyright date: " << in.get_copyright() << " "
				<< "is checked: ";
	(in.is_checked()) ? os << "yes\n" : os << "no\n";
	return os;
	
}

Book::Book(string tit, string auth, string in_ISBN, Chrono::Date copy, bool check)
	: title(tit), author(auth), ISBN(in_ISBN), copyright(copy), checked(check)
{
	if(!valid_ISBN(in_ISBN)) throw Invalid{};
}

bool valid_ISBN(string in)
{
	string hold = "";
	int j = 0;
	for (int i = 0; i < in.size();) {
		while (in[i] != '-') {
			hold += in[i];
			i++;
		}
		i++;
		if (i != in.size()) {
			for (int k = 0; k < hold.size(); k++){
				if(!isdigit(hold[k])) return false;
			}
		}
		else {
			for (int k = 0; k < hold.size(); k++) {
				if(!isdigit(hold[k]) || !isalpha(hold[k])) return false;
			}
		}
		j = 0;
		hold = "";
	}
	
	return true;
}

string Book::get_title() const{
	return title;
}

string Book::get_author() const{
	return author;
}

string Book::get_ISBN() const{
	return ISBN;
}

Chrono::Date Book::get_copyright() const{
	//cout << "Date: " << copyright << '\n';
	return copyright;
}

bool Book::is_checked() const{
	return checked;
}

void Book::check() {
	if(checked == false) checked = true;
	else {
		cout << "This book is already checked out, come again later\n";
	}
}
