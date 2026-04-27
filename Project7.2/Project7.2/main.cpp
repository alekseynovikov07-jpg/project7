#include "Header.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n;
	string f;

	cout << "Введите кол-во рейсов" << endl;
	n = CinFail();
	cin.ignore();

	Shedule* Ar = CreateArr(n);

	cout << "До сортировки: " << endl;
	Print(Ar, n);
	Sort(Ar, n);
	cout << "После сортировки: " << endl;
	Print(Ar, n);

	cout << "Поиск по пункту назначения: " << endl;
	cout << "Введите пункт назначения: " << endl;

	cin.ignore();
	getline(cin, f);
	while (f.empty())
	{
		cout << "Введите название: " << endl;
		getline(cin, f);
	}
	GetFlightByFinish(Ar, n, f);

	delete[] Ar;

}