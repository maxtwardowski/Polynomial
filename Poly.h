#pragma once
#include <map>

class Poly {
private:
	std::map<int, double> coeffs;
	void checkIfEmptyCoeff(unsigned int index);
public:
	Poly();
	Poly(double val);
	double& operator[] (int index);
	friend std::ostream & operator << (std::ostream& stream, const Poly& p);
	Poly operator+ (const Poly &p);
	Poly operator- (const Poly &p);
	Poly operator* (const Poly &p);
	inline friend Poly operator+ (const Poly& p1, const Poly& p2) {
		return Poly(p1) + p2;
	}
	inline friend Poly operator- (const Poly& p1, const Poly& p2) {
		return Poly(p1) - p2;
	}
	inline friend Poly operator* (const Poly& p1, const Poly& p2) {
		return Poly(p1) * p2;
	}
	friend Poly operator- (const Poly& p);
	double operator() (double arg) const;
};
