#include <iostream>
struct Vect2 {
	int n;
	int m;
};
class Vect {
private:
	int dimention;
	double* values;
public:
	static int count;
	Vect(int dim, double* rawValues);
	Vect* operator= (const Vect& other);
	Vect operator+ (Vect& other);
	Vect operator- (Vect& other);
	int getDimtion();
	void print();

};

class Matrix {
	Vect2 dim{ 3,3 };
};