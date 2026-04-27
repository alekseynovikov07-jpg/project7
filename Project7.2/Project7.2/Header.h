#pragma once
#include <iostream>
#include <windows.h>
#include <limits>
#include <string>

using namespace std;

struct Shedule 
{
	int number = 0;
	string type;
	string finish;
	float time;
};

Shedule* CreateArr(int n);
Shedule CreatePlain();
void PrintPlain(Shedule& ar);
void Print(Shedule* ar, int n);
void GetFlightByFinish(Shedule* ar, int n, string f);
void Sort(Shedule* ar, int n);
int CinFail();
