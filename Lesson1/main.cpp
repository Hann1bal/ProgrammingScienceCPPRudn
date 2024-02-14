#include <iostream>
struct Rectangle
{
    int X;
    int Y;
    int H;
    int W;
};
class Rectangle2
{
    int X;
    int Y;
    int H;
    int W;
};

class Student
{
public:
    Student(int age, std::string name)
    {
        this->_age = age;
        this->_name = name;
    }
    ~Student() {}
    void virtual setAge(int age)
    {
        this->_age = age;
    }
    void getAge()
    {
        std::cout << this->_age;
    }
    void setName(std::string name)
    {
        this->_name = name;
    }
    void getName()
    {
        std::cout << this->_name;
    }

private:
    int _age;
    std::string _name;
};
class StudentNka : public Student
{
public:
    StudentNka(int age, std::string name) : Student(age, name)
    {
    }
    void setAge(int age) override
    {
    }
};

int main()
{
    std::string var1 = "dssdfdfsdf";
    std::cout << var1;
    StudentNka vasya = StudentNka(22, "Vasya");
    vasya.getAge();
    vasya.setAge(22);
    vasya.getName();
    Rectangle rec = Rectangle();
    rec.H = 5;
    Rectangle2 rec2 = Rectangle2();
    rec2.H = 5;
    return 0;
}