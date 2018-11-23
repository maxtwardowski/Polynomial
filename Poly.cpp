#include <iostream>
#include <math.h>
#include "Poly.h"

Poly::Poly() {

}

Poly::Poly(double val) {
	this->coeffs[0] = val;
	this->checkIfEmptyCoeff(0);
}

double& Poly::operator[] (int index) {
	return this->coeffs[index];
}

Poly Poly::operator+ (const Poly &p) {
	Poly newp(*this);
	for (std::map<int, double>::const_iterator it = p.coeffs.begin(); it != p.coeffs.end(); ++it) {
		newp[it->first] += it->second;
		newp.checkIfEmptyCoeff(it->first);
	}
	return newp;
}

Poly Poly::operator- (const Poly &p) {
	Poly newp(*this);
	for (std::map<int, double>::const_iterator it = p.coeffs.begin(); it != p.coeffs.end(); ++it) {
		newp[it->first] -= it->second;
		newp.checkIfEmptyCoeff(it->first);
	}
	return newp;
}

Poly Poly::operator* (const Poly &p) {
	Poly newp;
	for (std::map<int, double>::const_iterator it1 = this->coeffs.begin(); it1 != this->coeffs.end(); ++it1)
		for (std::map<int, double>::const_iterator it2 = p.coeffs.begin(); it2 != p.coeffs.end(); ++it2) {
			newp[it1->first + it2->first] += it1->second * it2 -> second;
			newp.checkIfEmptyCoeff(it1->first + it2->first);
		}
	return newp;
}

double Poly::operator() (double arg) const {
	double val = 0;
	for (std::map<int, double>::const_iterator it = this->coeffs.begin(); it != this->coeffs.end(); ++it)
		val += pow(arg, it->first) * it->second;
	return val;
}

std::ostream & operator << (std::ostream & stream, const Poly & p) {
	bool firstDone = false;
	for (auto it = p.coeffs.rbegin(); it != p.coeffs.rend(); ++it) {
		if (it->second > 0 && firstDone)
			stream << " + ";
		else if (it->second < 0)
			stream << " - ";
		if (it->second && it->second != 1 && it->second != -1)
			stream << abs(it->second);
		if (it->first > 1) {
			stream << "x^";
			stream << it->first;
		} else if (it->first == 1)
			stream << "x";
		firstDone = true;
	}
	return stream;
}

Poly operator- (const Poly& p) {
	Poly newp(p);
	for (std::map<int, double>::iterator it = newp.coeffs.begin(); it != newp.coeffs.end(); ++it)
		it->second = -it->second;
	return newp;
}

void Poly::checkIfEmptyCoeff(unsigned int index) {
	if (!this->coeffs[index])
		this->coeffs.erase(index);
}
