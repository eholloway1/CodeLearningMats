/*
	Evan Holloway	May 2023

	Look at the headache-inducing last example of §8.4. Indent it properly and explain the meaning of each
	construct. Note that the example doesn’t do anything meaningful; it is pure obfuscation.
*/

struct X {
	void f(int x) { 
		struct Y { // X::f(int x)::struct Y
			int f() { return 1; } 
			int m;
		};
		int m; //X::f(int)::m
		m = x; //X::f(int x)::m = x argument
		Y m2;
		return f(m2.f()); //returns 1 to void function...dangerous
	}
	int m; //X::m
	void g(int m) {

		if (m) f(m + 2); //if(X::m) f(X::m + 2)
		else {
			g(m + 2); //g(X::m + 2)
		}
	}
	X() { } 
	void m3() {}

	void main() {
		X a; 
		a.f(2);
	}

};