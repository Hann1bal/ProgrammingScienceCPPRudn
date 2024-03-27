// NkaLaby.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <typeinfo>
#include <iostream>

enum Color {
	white,
	blue,
	red
};
struct Auto {
	int speed;
	int weight;
	std::string brand;
	Color color;
};

class Person {
public:
	Person();
	Person(int age, std::string name);
	Person(const Person& t) {
		this->name = t.name;
		this->age = t.age;
	}
	int age;
	std::string name;
	void virtual print();
	~Person() {

	};
};
Person::Person(int age, std::string name) {
	this->age = age;
	this->name = name;
};
Person::Person() {

}
void Person::print() {
	std::cout << this->age << this->name << std::endl;
}
class Employ : public Person {
public:
	Employ(std::string department, int age, std::string name) : Person(age, name) {
		this->department = department;
	};
	std::string department;
	void print() override {
		std::cout << this->department << this->age << this->name << std::endl;

	}
};
int main()
{
	Auto audi = Auto{ 22, 300, "Bike", Color::white };
	Person tom = Person(22, "tom");
	Employ tom2 = Employ("HD", 22, "tom2");
	tom.print();
	tom2.print();

}