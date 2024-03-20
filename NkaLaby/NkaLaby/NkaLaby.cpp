// NkaLaby.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <typeinfo>
#include "mathcustom.h"
#include <iostream>


int main()
{
	Vect first = Vect(3, new double[3] {1, 2, 3});
	Vect second = Vect(3, new double[3] {3, 2, 1});
	Vect third = Vect(3, new double[3]);
	third = first-second;
	third.print();
}