#include "../../std_lib_facilities.h"
/*
	Evan Holloway
	May 2023
	May 2023

	read five names into a vector<string> name, prompt user for ages of people named and store in
	vector<double> age. print out the five pairs. sort the names, sory(name.begin(), name.end())
	and print out the name, age pairs. Before sorting name, take a copy and use it to sort age
	after sorting name

*/

void printer(vector<string>, vector<double>);
void getter(vector<string>&, vector<double>&);

int main()
try {

	vector<string> name;
	vector<double> age;

	getter(name, age);
	printer(name, age);

	vector<string> tempName = name;
	vector<double> tempAge = age;

	sort(name.begin(), name.end());

	for (int i = 0; i < name.size(); i++) {
		for (int j = 0; j != name.size(); j++) {
			if (name[i] == tempName[j]) {
				tempAge[i] = age[j];
			}
		}
	}

	printer(name, tempAge);

	keep_window_open();
	return 0;
}
catch (exception& e) {

	cerr << e.what() << endl;
	keep_window_open();
	return 1;
}
catch (...) {

	cerr << "Uknown exception\n";
	keep_window_open();
	return 2;
}

void printer(vector<string> inName, vector<double> inAge) {

	for (int i = 0; i < inName.size(); i++)
	{
		cout << "name: " << inName[i] << " age: " << inAge[i];

		if (i == inName.size() - 1) cout << '\n';
		else cout << ", ";
	}

}

void getter(vector<string>& outName, vector<double>& outAge) {
	
	string in;
	double ages;

	cout << "Please enter five names:\n";

	for (int i = 0; i < 5; i++)
	{
		cin >> in;
		outName.push_back(in);
	}

	cout << "Please enter the ages of the five people, in order:\n";

	for (int i = 0; i < 5; i++)
	{
		cin >> ages;
		outAge.push_back(ages);
	}
	
}

