/*
POLY.H
Author: Chandler Ford
Description: This is the header file for the poly class. This class has a size and a dynamically allocated
             array that keeps track of polynomials. The index of the array represents the exponents while
			 the contents represent their respective coefficients.
*/

#include <iostream>
#pragma once
using namespace std;
class Poly
{
	//Precondition: <iostream> is included, Poly exists and is valid
	//Postcondition:  Override << operator to print polynomial (e.g. +5x^ -5x +5)
	friend ostream& operator<<(ostream &output, const Poly &input);  

	//Precondition: <iostream> is included, Poly exists and is valid
	//Postcondition: Override << operator to input coefficients and exponents until user enters -1 -1 
	friend istream& operator>>(istream &output, Poly &input);  
public:
	//Precondition: Parameters are valid arguments
	//Postcondition: Polynomial will be created with a coefficient, exponent, and size (exponent + 1)
	Poly(int coefficient, int exponent); 

	//Precondition: Parameter is valid argument
	//Postcondition: Polynomial will be created with a coefficient at exponent 0 with a size of 1
	Poly(int coefficient);  

	//Precondition: None
	//Postcondition: Polynomial will be created with a coefficient of zero at exponent 0 with a size of 1
	Poly();  

	//Precondition: Poly exists and is valid
	//Postcondition: A deep copy will be created
	Poly(const Poly &toCopy);  

	//Precondition: Poly exists and is valid
	//Postcondition: Poly arrays will be added together into new array
	Poly operator+(const Poly &rhs) const; 

	//Precondition: Poly exists and is valid
	//Postcondition: Poly array will be subtracted from other Poly array into new array
	Poly operator-(const Poly &rhs) const;  

	//Precondition: Poly exists and is valid
	//Postcondition: Poly arrays will be multiplied with each other into new array
	Poly operator*(const Poly &rhs) const;  

	//Precondition: Poly exists and is valid
	//Postcondition: Poly and data members (myArray and size) will be assigned to other Poly
	Poly& operator=(const Poly &rhs);

	//Precondition: Poly exists and is valid
	//Postcondition: Value of other Poly will be added to existing
	Poly& operator+=(const Poly &rhs);  

	//Precondition: Poly exists and is valid
	//Postcondition: Value of other Poly will be subtracted from existing
	Poly& operator-=(const Poly &rhs);  

	//Precondition: Poly exists and is valid
	//Postcondition: Value of other Poly will be multiplied by existing
	Poly& operator*=(const Poly &rhs);  

	//Precondition: Poly exists and is valid
	//Postcondition: Will return true if both Poly arrays and sizes are equal
	bool operator==(const Poly &rhs) const;  

	//Precondition: Poly exists and is valid
	//Postcondition: Will return true if both Poly arrays and sizes are not equal
	bool operator!=(const Poly &rhs) const;  

	//Precondition: Poly exists and is valid, exponent is valid (not negative)
	//Postcondition: Will return the coefficient paired with the given exponent
	int getCoeff(int exponent);  

	//Precondition: Poly exists and is valid, exponent is valid (not negative)
	//Postcondition: Will set the Poly array at the given exponent to the given coefficient
	void setCoeff(int coefficient, int exponent); 
private:
	//Data members
	int *myArray;  //Dynamically allocated array
	int size;  //keep track of size of dynamically allocated array
};

