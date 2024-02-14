// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>


struct Batterfly {
	int id;
	std::string species;
	int count;
	Batterfly* next;
};

void Add(Batterfly*& first,  std::string speices) {
	Batterfly* tmp = first;
	while (tmp->next != nullptr) {
		tmp = tmp->next;
	}
	Batterfly* newbat = new Batterfly();
	newbat->count = 0;
	newbat->id = tmp->id+1;
	newbat->species = speices;
	newbat->next = nullptr;
	tmp->next = newbat;
}
void PrintCollection(Batterfly*& butter) {
	Batterfly* tmp = butter;
	while (tmp->next != nullptr) {
		tmp = tmp->next;
		std::cout << tmp->species << std::endl;
	}
}
int main()
{
	Batterfly* batter = new Batterfly();
	bool flag = false;
	int command;
	std::string tmpname;
	while (!flag)
	{
		std::cout << "Choose command" << std::endl;
		std::cin >> command;
		switch (command)
		{
		case 0:
			flag = false;
			break;
		case 1:
			std::cout << "Enter the name:" << std::endl;
			std::cin >> tmpname;
			Add(batter, tmpname);
			break;
		case 2:
			PrintCollection(batter);
		default:
			break;
		}
	}
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
