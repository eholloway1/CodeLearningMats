/*
	Evan Holloway
	May 2023

	Design and implement a Name_pairs class holding (name, age) pairs where name is a string
	and age is a double. Represent that as a vector<string> name and vector<double age members
	Provide an inpit operation read_names() that reads a series of names. Provide Read_ages()
	that prompts the user for an age for each name. Provide a print() operation that prints out
	(name[i], age[i]) pairs in the order determined by the name vector. Provide a sort() that
	sorts name in alphabetical order and reorganizes age to match. implement all "operations"
	as member functions. Test the class.
*/

#include "../../std_lib_facilities.h"

class Name_pairs {
	public:
		void read_names();
		void read_ages();
		void print();
		void sort();
	private:
		vector<string> name;
		vector<double> age;
};

int main()
try {
	Name_pairs init_list;
	init_list.read_names();
	init_list.read_ages();
	init_list.print();
	init_list.sort();
	cout << "Post sort():\n";
	init_list.print();

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

void Name_pairs::read_names() {
	cout << "Enter your list of names. Terminate input using '|':\n";
	string input;

	for (;;) {
		cin >> input;
		if(input == "|") return;
		name.push_back(input);
	}
}

void Name_pairs::read_ages() {
	cout << "Enter the list of ages associated with each name. Terminate input by entering -1\n";
	double input;

	for (;;) {
		cin >> input;
		if(input == -1) break;
		else if(input < -1) error("Please enter a valid age");
		age.push_back(input);
	}

	if(age.size() != name.size()) error("Please enter the correct number of ages");
}

void Name_pairs::print() {
	for (int i = 0; i < name.size(); i++) {
		cout << "name: " << name[i] << " age: " << age[i] << '\n';
	}
}
void Name_pairs::sort() {
	vector<string> temp = name;
	vector<double> temp_age = age;
	std::sort(name.begin(), name.end());

	for (int i = 0; i < name.size(); i++) {
		for (int j = 0; j < name.size(); j++) {
			if(temp[j] == name[i]) age[i] = temp_age[j];
		}
	}
}
