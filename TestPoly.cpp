#include "Poly.h"
#include <iostream>

using namespace std;

int main() {

	Poly p1;
	p1[3] = 2;
	p1[1] = 3.6;
	p1[0] = 7;
	cout << "Polynomial p1:" << endl << p1 << endl << endl;

	Poly p2 = 5;
	p2[4] = 1;
	p2[2] = -6;
	p2[1] = 3;

	cout << "Polynomial p2: " << endl << p2 << endl << endl;


	Poly p3 = p1 + p2;
	cout << "Sum of polynomials p1 and p2: " << endl << p3 << endl << endl;

	p3 = p1 + 3;
	cout << "Sum of polynomial p1 and 3: " << endl << p3 << endl << endl;

	p3 = 3 + p1;
	cout << "Sum of 3 and polynomial p1: " << endl << p3 << endl << endl;

	p3 = p1 - p2;
	cout << "Difference of polynomials p1 and p2: " << endl << p3 << endl << endl;

	p3 = p1 - 7;
	cout << "Difference of polynomial p1 and 7: " << endl << p3 << endl << endl;

	p3 = 7 - p1;
	cout << "Difference of 7 and polynomial p1: " << endl << p3 << endl << endl;

	p3 = p1 * p2;
	cout << "Product of polynomials p1 and p2: " << endl << p3 << endl << endl;

	p3 = 2 * p1;
	cout << "Polynomial p1 multiplied by 2: " << endl << p3 << endl << endl;

	p3 = -p2;
	cout << "Negation of polynomial p2: " << endl << p3 << endl << endl;

	double val = p1(1.5);
	cout << "Value of polynomial p1 at point 1.5: " << val << endl << endl;
}
