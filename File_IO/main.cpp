// NKA_IO.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include<vector>

struct Temperature {
	Temperature(int min, int max, int aver, int month, int year) :min{ min }, max{ max }, average{ aver }, monthNum{ month }, year{ year } {}
	int min;
	int max;
	int average;
	int monthNum;
	int year;
};
class Db {
public:
	Db(std::string connectionString) {
		this->connectionString = connectionString;
	}
	void Save() {
		std::ofstream out(connectionString);
		if (out.is_open()) {
			for (const Temperature& temperature : temps) {
				out << temperature.min << " " << temperature.max << " " << temperature.average << " " << temperature.monthNum << " " << temperature.year << " " << std::endl;
			}

		}
		out.close();
	};
	void Load() {
		std::ifstream in(connectionString);
		if (in.is_open()) {
			int min, max, average, monthNum, year;
			while (in >> min >> max >> average >> monthNum >> year) {
				this->temps.push_back(Temperature{ min,max,average,monthNum, year });
			}
		}
		in.close();
	};
	void Add(Temperature temp) {
		this->temps.push_back(temp);
	}
	void Clear() {
		this->temps.clear();
	}
	void Print() {
		for (const Temperature& temperature : temps) {
			std::cout << temperature.min << " " << temperature.max << " " << temperature.average << " " << temperature.monthNum << " " << temperature.year << " " << std::endl;
		}
		std::cout << "<============================================================>" << std::endl;
	}
private:
	std::vector<Temperature> temps;
	std::string connectionString = "";
};

int main()
{
	Db db = Db{ "Temps.txt" };
	db.Add(Temperature{ 1,14,7,5,21 });
	db.Add(Temperature{ 21,35,27,8,22 });
	db.Add(Temperature{ 5,10,7,3,25 });
	db.Print();
	db.Save();
	db.Clear();
	db.Print();
	db.Load();
	db.Print();
	std::cout << "Hello World!\n";
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
