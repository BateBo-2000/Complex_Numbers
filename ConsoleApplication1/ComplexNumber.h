#pragma once
#ifndef COMPLEX_NUMBER
#define COMPLEX_NUMBER

#include <istream>
#include <ostream>

class ComplexNumber {
public: 
	ComplexNumber();
	ComplexNumber(double a);
	ComplexNumber(double a, double b);

	//no ned for big 4 

	ComplexNumber operator+() const;	//returns a copy
	ComplexNumber operator-() const;	//to not change it
	
	ComplexNumber& operator+=(const ComplexNumber& other);
	ComplexNumber& operator-=(const ComplexNumber& other);
	ComplexNumber& operator*=(const ComplexNumber& other);
	ComplexNumber& operator/=(const ComplexNumber& other);

	friend std::istream& operator>>(std::istream& input, ComplexNumber& z);
	friend std::ostream& operator<<(std::ostream& output, const ComplexNumber& z);

	//Getters
	double Re() const;
	double Im() const;
	//Setters
	void Re(double r);
	void Im(double i);

private:
	double real;
	double im;
};

ComplexNumber operator+(const ComplexNumber& left, const ComplexNumber& right);
ComplexNumber operator-(const ComplexNumber& left, const ComplexNumber& right);
ComplexNumber operator*(const ComplexNumber& left, const ComplexNumber& right);
ComplexNumber operator/(const ComplexNumber& left, const ComplexNumber& right);

bool operator==(const ComplexNumber& left, const ComplexNumber& right);
bool operator!=(const ComplexNumber& left, const ComplexNumber& right);


#endif // !COMPLEX_NUMBER
