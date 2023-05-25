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
