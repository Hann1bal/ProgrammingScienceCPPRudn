#include "mathcustom.h"



Vect::Vect(int dim, double* rawValues)
{
	this->dimention = dim;
	this->values = rawValues;
}

Vect* Vect::operator=(const Vect& other)
{
	this->dimention = other.dimention;
	this->values = other.values;
	return this;
}

bool Check(Vect* first, Vect& second) {
	return first->getDimtion() == second.getDimtion();
}
// + = * / - == != < > >= <=
Vect Vect::operator+(Vect& other)
{
	if (Check(this, other)) {
		Vect temp = Vect(other.dimention, new double[other.dimention]);
		temp.dimention = this->dimention;
		for (int i = 0; i < this->dimention; i++)
			temp.values[i] = this->values[i] + other.values[i];
		return temp;
	}
	throw "Invalid dimention of second vector";
}

Vect Vect::operator- (Vect& other)
{
	if (this == nullptr) {
		Vect temp = Vect(other.dimention, new double[other.dimention]);
		temp.dimention = other.dimention;
		for (int i = 0; i < other.dimention; i++)
			temp.values[i] = 0 - other.values[i];
		return temp;
	}
	if (Check(this, other)) {
		Vect temp = Vect(other.dimention, new double[other.dimention]);
		temp.dimention = this->dimention;
		for (int i = 0; i < this->dimention; i++)
			temp.values[i] = this->values[i] - other.values[i];
		return temp;
	}
	throw "Invalid dimention of second vector";
}

int Vect::getDimtion()
{
	this->values = new double [3] {1, 2, 3};
	return this->dimention;
}

void Vect::print()
{
	for (int i = 0; i < this->dimention; i++) {
		std::cout << this->values[i] << std::endl;
	}
}