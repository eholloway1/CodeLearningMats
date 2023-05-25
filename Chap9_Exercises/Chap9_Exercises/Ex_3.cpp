/*
	Evan Holloway
	May 2023

	Replace the Name_pair::print() with a (global) operator << and define == and != for Name_pairs
*/

#include "../../std_lib_facilities.h"

class Name_pairs {
public:
	void read_names();
	void read_ages();
	void print();
	void sort();
	vector<string> get_name() const {return name;}
	vector<double> get_age() const {return age;}
private:
	vector<string> name;
	vector<double> age;
};

ostream& operator<<(ostream& os, const Name_pairs& in) {
	const vector<string> in_names = in.get_name();
	const vector<double> in_age = in.get_age();
	os << "names: ";

	for (int i = 0; i < in_names.size(); i++) {
		os << in_names[i] << " ";
	}

	os << '\n';
	os << "ages: ";

	for (int i = 0; i < in_age.size(); i++) {
		os << in_age[i] << " ";
	}

	os << '\n';
	return os;
}
int main()
try {
	Name_pairs init_list;
	init_list.read_names();
	init_list.read_ages();
	cout << init_list;
	init_list.sort();
	cout << "Post sort():\n";
	cout << init_list;

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
		if (input == "|") return;
		name.push_back(input);
	}
}

void Name_pairs::read_ages() {
	cout << "Enter the list of ages associated with each name. Terminate input by entering -1\n";
	double input;

	for (;;) {
		cin >> input;
		if (input == -1) break;
		else if (input < -1) error("Please enter a valid age");
		age.push_back(input);
	}

	if (age.size() != name.size()) error("Please enter the correct number of ages");
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
			if (temp[j] == name[i]) age[i] = temp_age[j];
		}
	}
}
