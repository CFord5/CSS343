/*
POLY.CPP
Author: Chandler Ford
Description: This is the implementation file for the poly class. This class has a size and a dynamically allocated
			 array that keeps track of polynomials. The index of the array represents the exponents while the contents 
			 represent their respective coefficients.
*/

#include "poly.h"

//----------------------------- << ------------------------------------------
//Precondition: <iostream> is included, Poly exists and is valid
//Postcondition: Override << operator to print polynomial (e.g. +5x^ -5x +5)
ostream& operator<<(ostream &output, const Poly &rhs)
{
	for (int i = rhs.size - 1; i >= 0; i--)  //Loop backwards from the end of the polynomial
	{
		if (i > 1) {  //If the index is greater than zero, print the x and exponent
			if (rhs.myArray[i] > 0)  //Positive numbers get a plus
			{
				output << " +" << (rhs.myArray)[i] << "x^" << i;
			}
			else if (rhs.myArray[i] < 0)  //Negative numbers automatically get a minus sign
			{
				output << (rhs.myArray)[i] << "x^" << i;
			}
			else
			{
				//Output nothing
			}
		}
		else if (i == 1)  //If the index is zero, print the x but not the exponent
		{
			if (rhs.myArray[i] > 0)  //Positive numbers get a plus
			{
				output << " +" << (rhs.myArray)[i] << "x";
			}
			else if (rhs.myArray[i] < 0)  //Negative numbers automatically get a minus sign
			{
				output << (rhs.myArray)[i] << "x";
			}
			else
			{
				//Output nothing
			}
		}
		else  //If the index is zero don't print the x or the exponent
		{
			if (rhs.myArray[i] > 0)  //Positive numbers get a plus
			{
				output << " +" << (rhs.myArray)[i];
			}
			else if (rhs.myArray[i] < 0)  //Negative numbers automatically get a minus sign
			{
				output << (rhs.myArray)[i];
			}
			else
			{
				//Output nothing
			}
		}
	}
	return output;
}

//----------------------------- >> -------------------------------------------
//Precondition: <iostream> is included, Poly exists and is valid
//Postcondition: Override << operator to input coefficients and exponents 
//until user enters -1 -1 
istream& operator>>(istream &input, Poly &rhs)
{
	int coefficient = 0;  //Declare and initialize two temp variables
	int exponent = 0;
	while (coefficient != -1 && exponent != -1)  //While the user doesn't enter -1 -1 
	{
		input >> coefficient;  //The pair of numbers ] typed in create 
		input >> exponent;     //new Poly objects
		rhs.setCoeff(coefficient, exponent);
	}
	return input;
}

//---------------------------- CONSTRUCTOR -----------------------------------
//Precondition: Parameters are valid arguments
//Postcondition: Polynomial will be created with a coefficient, exponent,
//and size (exponent + 1)
Poly::Poly(int coefficient, int exponent)
{
	size = exponent + 1;  //The size is always 1 more than the highest exponent
	myArray = new int[size];  //Initialize the dynamically allocated array
	for (int i = 0; i < size; i++)  
	{
		myArray[i] = 0;
	}
	myArray[exponent] = coefficient;  //Set exponent (index) to coefficient
}

//---------------------------- CONSTRUCTOR -----------------------------------
//Precondition: Parameter is valid argument
//Postcondition: Polynomial will be created with a coefficient at exponent 
//0 with a size of 1
Poly::Poly(int coefficient)
{
	size = 1;
	myArray = new int[size];  //Initialize the dynamically allocated array
	myArray[0] = coefficient; //Set exponent (index 0 ) to coefficient
}

//---------------------------- CONSTRUCTOR -----------------------------------
//Precondition: None
//Postcondition: Polynomial will be created with a coefficient of zero at 
//exponent 0 with a size of 1
Poly::Poly()
{
	size = 1;
	myArray = new int[size];
	myArray[0] = 0;  //Set exponent(index 0) to  0
}

//------------------------------- COPY ---------------------------------------
//Precondition: Poly exists and is valid
//Postcondition: A deep copy will be created
Poly::Poly(const Poly &toCopy)
{
	size = toCopy.size;  //Take the size of the Poly to be copied
	myArray = new int[size];  //Use it to set up new array
	for (int i = 0; i < size; i++)  //Loop through both arrays and copy
	{
		this->myArray[i] = toCopy.myArray[i];
	}
}

//------------------------------- + ------------------------------------------
//Precondition: Poly exists and is valid
//Postcondition: Poly arrays will be added together into new array
Poly Poly::operator+(const Poly &rhs) const
{
	Poly sumPoly = *this;  //Set Poly equal to object being added to
	return sumPoly += rhs;  //Use overloaded += operator
}

//------------------------------- - ------------------------------------------
//Precondition: Poly exists and is valid
//Postcondition: Poly array will be subtracted from other Poly array 
//into new array
Poly Poly::operator-(const Poly &rhs) const
{
	Poly diffPoly = *this;  //Set Poly equal to object being subtracted from
	return diffPoly -= rhs;  //Use overloaded -= operator
}

//------------------------------- * ------------------------------------------
//Precondition: Poly exists and is valid
//Postcondition: Poly arrays will be multiplied with each other into 
//new array
Poly Poly::operator*(const Poly &rhs) const
{
	Poly productPoly = *this;  //Set Poly equal to object being multiplied 
	return productPoly *= rhs;  //Use overloaded *= operator
}

//------------------------------- = ------------------------------------------
//Precondition: Poly exists and is valid
//Postcondition: Poly and data members (myArray and size) will be
//assigned to other Poly
Poly& Poly::operator=(const Poly &rhs)
{
	if (this != &rhs)
	{
		delete[] myArray;  //Get rid of old memory allocation
		int newSize = rhs.size;
		this->size = newSize;
		this->myArray = new int[this->size];  //Current Poly uses new size
		for (int i = 0; i < this->size; i++)  //from right hand side of =
		{
			this->myArray[i] = rhs.myArray[i];  //Copy over
		}
	}
	return *this;
}

//------------------------------- += -----------------------------------------
//Precondition: Poly exists and is valid
//Postcondition: Value of other Poly will be added to existing
Poly & Poly::operator+=(const Poly &rhs)
{
	int newSize = rhs.size;  //Keep track of size to right of +=
	if (size < newSize)  //If current array is smaller
	{
		int *newMyArray = new int[newSize];  //Need to make new larger array
		for (int i = 0; i < size; i++)  //Loop through old and fill
		{
			newMyArray[i] = myArray[i];
		}
		for (int i = size; i < newSize; i++)  //Loop up to new larger size
		{
			newMyArray[i] = 0;  //Initialize to zero so it doesn't error
		}
		size = newSize;  //Set to new larger size before memory deallocated
		delete[] myArray;
		myArray = newMyArray;  //Set to new values
		newMyArray = NULL;  //Deal with pointer
	}
	for (int i = 0; i < newSize; i++)  //Loop and add the values together
	{
		myArray[i] = myArray[i] + rhs.myArray[i];
	}
	return *this;
}

//------------------------------- -= -----------------------------------------
//Precondition: Poly exists and is valid
//Postcondition: Value of other Poly will be subtracted from existing
Poly & Poly::operator-=(const Poly & rhs)
{
	int newSize = rhs.size;  //Keep track of size to right of +=
	if (size < newSize)  //If current array is smaller
	{
		int *newMyArray = new int[newSize];  //Need to make new larger array
		for (int i = 0; i < size; i++)  //Loop through old and fill
		{
			newMyArray[i] = myArray[i];
		}
		for (int i = size; i < newSize; i++)  //Loop up to new larger size
		{
			newMyArray[i] = 0;  //Initialize to zero so it doesn't error
		}
		size = newSize;  //Set to new larger size before memory deallocated
		delete[] myArray;
		myArray = newMyArray;  //Set to new values
		newMyArray = NULL;  //Deal with pointer
	}
	for (int i = 0; i < newSize; i++)  //Loop and subtract
	{
		myArray[i] = myArray[i] - rhs.myArray[i];
	}
	return *this;
}

//------------------------------- *= -----------------------------------------
//Precondition: Poly exists and is valid
//Postcondition: Value of other Poly will be multiplied by existing
Poly & Poly::operator*=(const Poly &rhs)
{
	int newSize = (size * rhs.size);  //Create a new array with a larger size
	int *newMyArray = new int[newSize];  
	for (int i = 0; i < newSize; i++)  //Loop through and initialize to zero
	{
		newMyArray[i] = 0;
	}
	//if (size > rhs.size)  //If larger you want to start with the current Poly
	//{ 
		for (int i = 0; i < size; i++)  //Loop through and multiply into new array
		{
			for (int j = 0; j < rhs.size; j++)
			{
				newMyArray[i + j] += myArray[i] * rhs.myArray[j];
			}
		}
	//}
	//else  //If size is not larger than the right hand side poly
	//{
		//for (int i = 0; i < rhs.size; i++)  //Loop through and multiply into new array
		//{
			//for (int j = 0; j < size; j++)
			//{
				//newMyArray[i + j] += myArray[j] * rhs.myArray[i];
			//}
		//}
	//}
	size = newSize;  //Reset size
	delete[] myArray;  //Deallocate memory
	myArray = newMyArray;  //Set array 
	newMyArray = NULL;  //Deal with pointer
	return *this;
}

//------------------------------- == -----------------------------------------
//Precondition: Poly exists and is valid
//Postcondition: Will return true if both Poly arrays and sizes are equal
bool Poly::operator==(const Poly &rhs) const
{
	bool isEqual = true;
	if (size != rhs.size)  //If sizes aren't equal it's false
	{
		isEqual = false;
	}
	else
	{
		for (int i = 0; i < size; i++)  //If any contents are different it's false
		{
			if (this->myArray[i] != rhs.myArray[i])
			{
				isEqual = false;
			}
		}
	}
	return isEqual;
}

//------------------------------- != -----------------------------------------
//Precondition: Poly exists and is valid
//Postcondition: Will return true if both Poly arrays and sizes are not equal
bool Poly::operator!=(const Poly & rhs) const
{
	bool notEqual = false;
	if (size != rhs.size)  //True if not the same size
	{
		notEqual = true;
	}
	else
	{
		for (int i = 0; i < size; i++)  //False if anything the same at index
		{
			if (this->myArray[i] != rhs.myArray[i])
			{
				notEqual = true;
			}
		}
	}
	return notEqual;
}

//------------------------------- getCoeff -------------------------------------
//Precondition: Poly exists and is valid, exponent is valid (not negative)
//Postcondition: Will return the coefficient paired with the given exponent
int Poly::getCoeff(int exponent)
{
	int coeff = 0;
	if (exponent >= 0) {  //Loop through until index is exponent
		for (int i = 0; i < size; i++)
		{
			if (i == exponent)
			{
				coeff = myArray[i];  //Return if found
			}
		}
		return coeff;
	}
	else
	{
		coeff = 0;  //If negative exponent return zero
		return coeff;
	}
}

//------------------------------- setCoeff -------------------------------------
//Precondition: Poly exists and is valid, exponent is valid (not negative)
//Postcondition: Will set the Poly array at the given exponent to the 
//given coefficient
void Poly::setCoeff(int coefficient, int exponent)
{
	int newSize = exponent + 1;  //Size going to be one larger than biggest exponent
	if (newSize > size)  //If new size larger than old size
	{
		int *myNewArray = new int[newSize];  //Make a bigger array 
		for (int i = 0; i < size; i++)  //Loop through original and fill
		{
			myNewArray[i] = myArray[i];
		}
		for (int i = size; i < exponent; i++)
		{
			myNewArray[i] = 0;  //Initialize space inbetween to zero
		}
		myNewArray[exponent] = coefficient;  //Set new leading exponent coefficient
		size = newSize;  //Reset size
		delete[] myArray;  //Deallocate memory
		myArray = myNewArray;  //Set array to new array
		myNewArray = NULL;  //Deal with pointer
	}
	else  //Otherwise just set the coefficient at exponent index in array
	{
		myArray[exponent] = coefficient;
	}
}