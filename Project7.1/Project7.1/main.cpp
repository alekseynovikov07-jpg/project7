#include "Header.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	int found;

	cout << "/------Создание массива данных------/" << endl;
	cout << endl;

	cout << "Введите количество продуктов: " << endl;
	n = CinFail();
	cin.ignore();

	Product* prod = CreateArr(n);

	cout << "/------Поиск по номеру цеха------/" << endl;
	cout << endl;
	
	cout << "Введите номер цеха: " << endl;
	found = CinFail();
	cin.ignore();

	GetProdByNumber(prod, n, found);
}