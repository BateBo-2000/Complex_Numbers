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
	
	ComplexNumber operator+(const ComplexNumber& other) const;
	ComplexNumber& operator+=(const ComplexNumber& other);


	ComplexNumber operator-(const ComplexNumber& other) const;
	ComplexNumber& operator-=(const ComplexNumber& other);


	ComplexNumber operator*(const ComplexNumber& other) const;
	ComplexNumber& operator*=(const ComplexNumber& other);


	ComplexNumber operator/(const ComplexNumber& other) const;
	ComplexNumber& operator/=(const ComplexNumber& other);


	bool operator==(const ComplexNumber& other) const;
	bool operator!=(const ComplexNumber& other) const;

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

//All types types can be casted to double so im using this
ComplexNumber operator+(const double d, const ComplexNumber& z);
ComplexNumber operator-(const double d, const ComplexNumber& z);
ComplexNumber operator*(const double d, const ComplexNumber& z);
ComplexNumber operator/(const double d, const ComplexNumber& z);

#endif // !COMPLEX_NUMBER
