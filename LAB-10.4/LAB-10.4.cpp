// LAB-10.4.cpp
// Сушинський Ігор
// Лабораторія №10.4
// Опрацювання рядків текстового файлу.
// Варіант 18

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

void CreateTXT(char* fname)							// створення файлу з введених рядків
{
	ofstream fout(fname);							// відкрили файл для запису
	char ch;										// відповідь користувача – чи продовжувати введення
	string s;										// введений користувачем рядок
	do
	{
		cin.get();									// очищуємо буфер клавіатури – щоб не було символу
		cin.sync();									// «кінець рядка», який залишився після вводу числа
		cout << "Ввести рядок: "; getline(cin, s);	// ввели рядок
		fout << s << endl;							// записали його у файл
		cout << "Продовжити? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
}

void PrintTXT(char* fname)	// виведення файлу на екран
{
	ifstream fin(fname);	// відкрили файл для зчитування
	string s;				// прочитаний рядок
	while (getline(fin, s)) // поки можна прочитати рядок
	{
		cout << s << endl;	// виводимо його на екран
	}
	cout << endl;
}

void ProcessTXT(char* fname, char* gname)					// підрахунок довжини найкоротшого слова
{
	ifstream f(fname);										// відкрили файл для зчитування
	ofstream g(gname);										// відкрили файл для запису
	string s;
	char tmp[256];
	char max[256];											// максимальне значення

	while (getline(f, s))									// поки можна прочитати рядок скануємо його і обчислюємо довжину
	{
		for (int i = 0; i < s.length(); i++)
		{
			istringstream ist(s);							// перетворює рядок у потік
			ist >> max;
			while (ist >> tmp)
			{
				if (strlen(tmp) > strlen(max))				// якщо довжина слова більша ніж max,
					strcpy(max, tmp);						// то присвоюєм нове значення для max
			}
		}
		g << max << endl;

		cout << "Довжина найдовшого слова = " << strlen(max) << endl;
		cout << "Найдовше слово = " << max << endl << endl;
	}
}

int main()
{
	SetConsoleCP(1251);			// встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251);	// встановлення сторінки win-cp1251 в потік виводу

	// текстові файли
	char fname[100];			// ім'я першого файлу
	cout << "Ввести ім'я першого файлу: "; cin >> fname;

	CreateTXT(fname);

	char gname[100];			// ім'я другого файлу
	cout << "Ввести ім'я другого файлу: "; cin >> gname;

	ProcessTXT(fname, gname);	// ввели рядки файлу з клавіатури

	return 0;
}