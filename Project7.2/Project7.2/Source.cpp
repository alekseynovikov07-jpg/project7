#include "Header.h"

Shedule* CreateArr(int n)
{
	Shedule* ar = new Shedule[n];

	for (int i = 0; i < n; i++)
	{
		ar[i] = CreatePlain();
	}

	return ar;
}

Shedule CreatePlain()
{
	Shedule plain;

	cout << "Введите номер рейса: " << endl;
	plain.number = CinFail();
	cin.ignore();

	cout << "Введите  тип самолёта: " << endl;
	getline(cin, plain.type);

	while (plain.type.empty())
	{
		cout << "Неправильные данные, попробуйте ещё раз" << endl;
		getline(cin, plain.type);
	}

	cout << "Введите пункт назначения: " << endl;
	getline(cin, plain.finish);

	while (plain.finish.empty())
	{
		cout << "Неправильные данные, попробуйте ещё раз" << endl;
		getline(cin, plain.finish);
	}

	cout << "Введите время вылета через '.': " << endl;
	cin >> plain.time;

	while (plain.time < 0)
	{
		cout << "Неправильные данные, попробуйте ещё раз" << endl;
		cin >> plain.time;
	}

	return plain;
}

void PrintPlain(Shedule& ar)
{
	cout << "Номер рейса: " << ar.number << endl;
	cout << "Тип самолёта: " << ar.type << endl;
	cout << "Пункт назначения: " << ar.finish << endl;
	cout << "Время вылета: " << ar.time << endl;
}

void Print(Shedule* ar, int n)
{
	cout << "=====Рейсы=====" << endl;

	for (int i = 0; i < n; i++)
	{
		PrintPlain(ar[i]);
	}
	cout << endl;
}

void GetFlightByFinish(Shedule* ar, int n, string f)
{
	bool found = false;

	for (int i = 0; i < n; i++)
	{
		if (f == ar[i].finish)
		{
			cout << "Найденные рейсы: " << endl;
			PrintPlain(ar[i]);
			found = true;
		}
	}

	if (!found)
	{
		cout << "Такие рейсы не найдены" << endl;
	}
}

void Sort(Shedule* ar, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (ar[j].time > ar[j + 1].time)
			{
				swap(ar[j], ar[j + 1]);
			}
		}
	}
}

int CinFail()
{
	double value = -1.1;
	while (!(cin>>value) || value != int(value) || value <= 0)
	{
		cin.clear();
		cin.ignore((numeric_limits<streamsize>::max)(), '\n');
		cout << "Введены неправильные данные, попробуйте ещё раз" << endl;
	}
	return value;
}