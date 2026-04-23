#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <Windows.h>

using namespace std;

struct Product 
{
	string name;
	int count = 0;
	int number = 0;
};

Product* CreateArr(int n);
Product CreateProd();
void GetProdByNumber(Product* arr, int n, int f);
int CinFail();
void PrintProd(Product& arr);
void Print(Product* arr, int n);