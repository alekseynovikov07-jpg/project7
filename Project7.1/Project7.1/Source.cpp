#include "Header.h"

Product* CreateArr(int n)
{
	Product* Arr = new Product[n];

	for (int i = 0; i < n; i++)
	{
		Arr[i] = CreateProd();
	}

	return Arr;
}

Product CreateProd()
{
	Product prod;

	cout << "Введите наименование продукта: " << endl;
	getline(cin, prod.name);
	while (prod.name.empty())
	{
		cout << "Неверные данные, попробуйте ещё раз" << endl;
		getline(cin, prod.name);
	}

	cout << "Введите количество продукта: " << endl;
	prod.count = CinFail();

	cout << "Введите номер цеха продукта: " << endl;
	prod.number = CinFail();
	cin.ignore();

	return prod;
}

void PrintProd(Product& arr)
{
	cout << "Наименование продукта: " << arr.name << endl;
	cout << "Количество продукта: " << arr.count << endl;
	cout << "Номер цеха продукта: " << arr.number << endl;
}

void Print(Product* arr, int n)
{
	cout << "/------Информация о продукте------/" << endl;
	for (int i = 0; i < n; i++)
	{
		PrintProd(arr[i]);
	}
}

void GetProdByNumber(Product* arr, int n, int f)
{
	bool found = false;

	cout << "Найденные продукты по номеру цеха:" << endl;

	for (int i = 0; i < n; i++)
	{
		if (arr[i].number == f)
		{
			PrintProd(arr[i]);
			found = true;
			cout << endl;
		}
	}

	if (!found)
	{
		cout << "Продукт в указанном цехе не найден" << endl;
	}
}

int CinFail()
{
	double value = -1.1;
	while (!(cin >> value) || value <= 0 || value != int(value))
	{
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		cout << "Ошибка ввода, попробуйте ещё раз" << endl;
	}
	return value;
}