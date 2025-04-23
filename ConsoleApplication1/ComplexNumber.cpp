#include "ComplexNumber.h"

#include <istream>
#include <ostream>

ComplexNumber::ComplexNumber(): real(0), im(0)
{ }

ComplexNumber::ComplexNumber(double a) : real(a), im(0)
{ }

ComplexNumber::ComplexNumber(double a, double b): real(a), im(b)
{ }

//no ned for big 4 

ComplexNumber ComplexNumber::operator+() const {
	return *this;
}

ComplexNumber ComplexNumber::operator-() const {
	ComplexNumber z(*this);
	z.Re(z.Re() * (-1));
	z.Im(z.Im() * (-1));
	return z;
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const {
	ComplexNumber z(*this);
	z += other;
	return z;
}
ComplexNumber& ComplexNumber::operator+=(const ComplexNumber& other) {
	this->real += other.real;
	this->im += other.im;
	return *this;
}


ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const {
	ComplexNumber z(*this);
	z -= other;
	return z;
}
ComplexNumber& ComplexNumber::operator-=(const ComplexNumber& other) {
	this->real -= other.real;
	this->im -= other.real;
	return *this;
}


ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const {
	ComplexNumber z(*this);
	z *= other;
	return z;
}
ComplexNumber& ComplexNumber::operator*=(const ComplexNumber& other) {
	this->real = this->real * other.real - this->im * other.im;
	this->im = this->real * other.im + this->im * other.real;
	return *this;
}


ComplexNumber ComplexNumber::operator/(const ComplexNumber& other) const {
	ComplexNumber z(*this);
	z /= other;
	return z;
}
ComplexNumber& ComplexNumber::operator/=(const ComplexNumber& other) {
	//for readability
	double a = this->real;
	double b = this->im;
	double c = other.real;
	double d = other.im;

	if (c == 0 && d == 0) throw "Cannot divide by 0!";

	this->real = (a * c + b * d) / (c * c + d * d);
	this->im = (b * c - a * d) / (c * c + d * d);
	return *this;
}


bool ComplexNumber::operator==(const ComplexNumber& other) const {
	return (this->real == other.real && this->im == other.im);
}
bool ComplexNumber::operator!=(const ComplexNumber& other) const {
	return !(*this == other);
}

std::istream& operator>>(std::istream& input, ComplexNumber& z) {
	input >> z.real;
	
	char c;
	bool positive = true;

	input >> c; // removes the +/-
	if (c == '-') positive = false; //5-i6

	input >> c;	// removes the i

	if (c == 'i') {
		input >> z.im;
		if (positive == false) z.im *= -1;
	}
	else {
		z.im = 0;
	}
	
	return input;
}
std::ostream& operator<<(std::ostream& output, const ComplexNumber& z) {
	output << z.real;

	if (z.im >= 0) {
		output << "+i" << z.im;
	}
	else {
		output << "-i" << (- z.im);
	}
	return output;
}

//Getters
double ComplexNumber::Re() const {
	return this->real;
}
double ComplexNumber::Im() const {
	return this->im;
}
//Setters
void ComplexNumber::Re(double r) {
	this->real = r;
}
void ComplexNumber::Im(double i) {
	this->im = i;
}


ComplexNumber operator+(const double d, const ComplexNumber& z) {
	return z + d;
}
ComplexNumber operator-(const double d, const ComplexNumber& z) {
	return z - d;
}
ComplexNumber operator*(const double d, const ComplexNumber& z) {
	return z * d;
}
ComplexNumber operator/(const double d, const ComplexNumber& z) {
	return z / d;
}
