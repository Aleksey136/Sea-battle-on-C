#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <cmath> 
#include <complex>
#include <fstream>
#include <string>
#include <Windows.h>
#include <stdlib.h>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

const int N = 10;																								// N - Кол-во клеток карты
int io = 1;																										// io - глобальная переменная для нумерации кораблей на поле.

void Risovka(int Map[N][N], int Map2[N][N])																		// Вывод попаданий и промахов в тумане войны.
{
	cout << ' ';
	for (int i = 0; i < N; i++)
	{
		cout << i;
	}
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		cout << i;
		for (int j = 0; j < N; j++)
		{
			if (Map2[i][j] == 1)
			{
				if (Map[i][j] == 0)
					cout << 'x';
				else
					cout << '#';
			}
			else
				cout << '~';
		}
		cout << endl;
	}
}

void randomKor(int Map[N][N], int Ruz, int Kolvo)
{
	int x, y, x2, y2;
	int a = 0;																									// a - направление
	int P = 0;																									// P - высставленное кол-во кораблей
	while (P < Kolvo)
	{
		for (int i = 0; i < 5; i++)
			x = rand() % N;
		for (int i = 0; i < 5; i++)
			y = rand() % N;
		x2 = x; y2 = y;
		a = rand() % 4;
		int f = 1;																								// f - проверка на возможность поставки корабля
		for (int i = 0; i < Ruz; i++)
		{
			if ((x < 0) or (y < 0) or (x >= N) or (y >= N))
			{
				f = 0;
				break;
			}
			if (Map[x][y] >= 1)
			{
				f = 0;
				break;
			}
			if (y < N - 1)
				if (Map[x][y + 1] >= 1)
				{
					f = 0;
					break;
				}
			if (y > 0)
				if (Map[x][y - 1] >= 1)
				{
					f = 0;
					break;
				}
			if (x < N - 1)
				if (Map[x + 1][y] >= 1)
				{
					f = 0;
					break;
				}
			if (x > 0)
				if (Map[x - 1][y] >= 1)
				{
					f = 0;
					break;
				}
			if ((y < N - 1) and (x < N - 1))
				if (Map[x + 1][y + 1] >= 1)
				{
					f = 0;
					break;
				}
			if ((y < N - 1) and (x > 0))
				if (Map[x - 1][y + 1] >= 1)
				{
					f = 0;
					break;
				}
			if ((y > 0) and (x < N - 1))
				if (Map[x + 1][y - 1] >= 1)
				{
					f = 0;
					break;
				}
			if ((y > 0) and (x > 0))
				if (Map[x - 1][y - 1] >= 1)
				{
					f = 0;
					break;
				}
			if (a == 0)
				y++;
			else if (a == 1)
				x++;
			else if (a == 2)
				y--;
			else if (a == 3)
				x--;
		}
		if (f == 1)
		{
			x = x2;
			y = y2;
			for (int i = 0; i < Ruz; i++)
			{
				Map[x][y] = io;
				if (a == 0)
					y++;
				else if (a == 1)
					x++;
				else if (a == 2)
					y--;
				else if (a == 3)
					x--;
			}
			P++;
			io++;
		}
	}
}

void vruchKor(int Map[N][N], int x, int y, int a, int Ruz)
{
	int x2, y2, a2;
	x2 = x; y2 = y;
	a2 = a - 1;
	int f = 1;
	for (int i = 0; i < Ruz; i++)
	{
		if ((x2 < 0) or (y2 < 0) or (x2 >= N) or (y2 >= N))
		{
			f = 0;
			cout << "Быть такого не может.\n";
			break;
		}
		if (Map[x2][y2] >= 1)
		{
			f = 0;
			cout << "Быть такого не может.\n";
			break;
		}
		if (y2 < N - 1)
			if (Map[x2][y2 + 1] >= 1)
			{
				f = 0;
				cout << "Быть такого не может.\n";
				break;
			}
		if (y2 > 0)
			if (Map[x2][y2 - 1] >= 1)
			{
				f = 0;
				cout << "Быть такого не может.\n";
				break;
			}
		if (x2 < N - 1)
			if (Map[x2 + 1][y2] >= 1)
			{
				f = 0;
				cout << "Быть такого не может.\n";
				break;
			}
		if (x2 > 0)
			if (Map[x2 - 1][y2] >= 1)
			{
				f = 0;
				cout << "Быть такого не может.\n";
				break;
			}
		if ((y2 < N - 1) and (x2 < N - 1))
			if (Map[x2 + 1][y2 + 1] >= 1)
			{
				f = 0;
				cout << "Быть такого не может.\n";
				break;
			}
		if ((y2 < N - 1) and (x2 > 0))
			if (Map[x2 - 1][y2 + 1] >= 1)
			{
				f = 0;
				cout << "Быть такого не может.\n";
				break;
			}
		if ((y2 > 0) and (x2 < N - 1))
			if (Map[x2 + 1][y2 - 1] >= 1)
			{
				f = 0;
				cout << "Быть такого не может.\n";
				break;
			}
		if ((y2 > 0) and (x2 > 0))
			if (Map[x2 - 1][y2 - 1] >= 1)
			{
				f = 0;
				cout << "Быть такого не может.\n";
				break;
			}
		if (a2 == 0)
			y2++;
		else if (a2 == 1)
			x2++;
		else if (a2 == 2)
			y2--;
		else if (a2 == 3)
			x2--;
	}
	if (f == 1)
	{
		x2 = x;
		y2 = y;
		for (int i = 0; i < Ruz; i++)
		{
			Map[x2][y2] = io;
			if (a2 == 0)
				y2++;
			else if (a2 == 1)
				x2++;
			else if (a2 == 2)
				y2--;
			else if (a2 == 3)
				x2--;
		}
		io++;
	}
}

void Vivod(int Map[N][N])
{
	cout << ' ';
	for (int i = 0; i < N; i++)
	{
		cout << i;
	}
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		cout << i;
		for (int j = 0; j < N; j++)
		{
			if (Map[i][j] >= 1)
				cout << '#';
			else
				cout << '~';
		}
		cout << endl;
	}
}

void Vivod2(int Map[N][N], int Map2[N][N])
{
	cout << ' ';
	for (int i = 0; i < N; i++)
	{
		cout << i;
	}
	cout << endl;
	for (int i = 0; i < N; i++)
	{
		cout << i;
		for (int j = 0; j < N; j++)
		{
			if (Map2[i][j] >= 1)
			{
				if (Map[i][j] == 0)
					cout << 'x';
				else
					cout << '+';
			}
			else
				if (Map[i][j] == 0)
					cout << '~';
				else
					cout << '#';
		}
		cout << endl;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));
	int map1[N][N] = { 0 };
	int map2[N][N] = { 0 };
	int map3[N][N] = { 0 };
	int map4[N][N] = { 0 };
	int x, y, d, K;
	int u, r;
	cout << "С кем вы хотите играть? 0 - ИИ, 1 - человек с человеком.\n";
	cin >> r;
	if (r == 1)																																			// Игра 1 на 1.
	{
		cout << "Как вы хотите вводить координаты своих кораблей (Игрок 1)? (1 - вручную, 0 - случайно):\n";
		cin >> u;
		system("cls");
		if (u == 0)
		{
			randomKor(map1, 4, 1);
			randomKor(map1, 3, 2);
			randomKor(map1, 2, 3);
			randomKor(map1, 1, 4);
			cout << "Ваша карта следующая:\n" << endl;
			Vivod(map1);
			Sleep(5000);
			system("cls");
		}
		else
		{
			K = 0;
			while (K < 4)
			{
				K = 0;
				Vivod(map1);
				cout << "Введите координаты для корабля размером 4 и его направление (1 - вправо, 2 - вниз, 3 - влево, 4 - вверх):\n";
				cin >> x;
				cin >> y;
				cin >> d;
				vruchKor(map1, x, y, d, 4);
				for (int i = 0; i < N; i++)
					for (int j = 0; j < N; j++)
						if (map1[i][j] >= 1)
							K++;
				Sleep(1000);
				system("cls");
			}
			while (K < 10)
			{
				K = 0;
				Vivod(map1);
				cout << "Введите координаты для корабля размером 3 и его направление (1 - вправо, 2 - вниз, 3 - влево, 4 - вверх):\n";
				cin >> x;
				cin >> y;
				cin >> d;
				vruchKor(map1, x, y, d, 3);
				for (int i = 0; i < N; i++)
					for (int j = 0; j < N; j++)
						if (map1[i][j] >= 1)
							K++;
				Sleep(1000);
				system("cls");
			}
			while (K < 22)
			{
				K = 0;
				Vivod(map1);
				cout << "Введите координаты для корабля размером 2 и его направление (1 - вправо, 2 - вниз, 3 - влево, 4 - вверх):\n";
				cin >> x;
				cin >> y;
				cin >> d;
				vruchKor(map1, x, y, d, 2);
				for (int i = 0; i < N; i++)
					for (int j = 0; j < N; j++)
						if (map1[i][j] >= 1)
							K++;
				Sleep(1000);
				system("cls");
			}
			while (K < 24)
			{
				K = 0;
				Vivod(map1);
				cout << "Введите координаты для корабля размером 1:\n";
				cin >> x;
				cin >> y;
				d = 1;
				vruchKor(map1, x, y, d, 1);
				for (int i = 0; i < N; i++)
					for (int j = 0; j < N; j++)
						if (map1[i][j] >= 1)
							K++;
				Sleep(1000);
				system("cls");
			}
		}
		cout << "Как вы хотите вводить координаты своих кораблей (Игрок 2)? (1 - вручную, 0 - случайно):\n";
		cin >> u;
		system("cls");
		if (u == 0)
		{
			randomKor(map3, 4, 1);
			randomKor(map3, 3, 2);
			randomKor(map3, 2, 3);
			randomKor(map3, 1, 4);
			cout << "Ваша карта следующая:\n" << endl;
			Vivod(map3);
			Sleep(5000);
			system("cls");
		}
		else
		{
			K = 0;
			while (K < 4)
			{
				K = 0;
				Vivod(map3);
				cout << "Введите координаты для корабля размером 4 и его направление (1 - вправо, 2 - вниз, 3 - влево, 4 - вверх):\n";
				cin >> x;
				cin >> y;
				cin >> d;
				vruchKor(map3, x, y, d, 4);
				for (int i = 0; i < N; i++)
					for (int j = 0; j < N; j++)
						if (map3[i][j] >= 1)
							K++;
				Sleep(1000);
				system("cls");
			}
			while (K < 10)
			{
				K = 0;
				Vivod(map3);
				cout << "Введите координаты для корабля размером 3 и его направление (1 - вправо, 2 - вниз, 3 - влево, 4 - вверх):\n";
				cin >> x;
				cin >> y;
				cin >> d;
				vruchKor(map3, x, y, d, 3);
				for (int i = 0; i < N; i++)
					for (int j = 0; j < N; j++)
						if (map3[i][j] >= 1)
							K++;
				Sleep(1000);
				system("cls");
			}
			while (K < 22)
			{
				K = 0;
				Vivod(map3);
				cout << "Введите координаты для корабля размером 2 и его направление (1 - вправо, 2 - вниз, 3 - влево, 4 - вверх):\n";
				cin >> x;
				cin >> y;
				cin >> d;
				vruchKor(map3, x, y, d, 2);
				for (int i = 0; i < N; i++)
					for (int j = 0; j < N; j++)
						if (map3[i][j] >= 1)
							K++;
				Sleep(1000);
				system("cls");
			}
			while (K < 24)
			{
				K = 0;
				Vivod(map3);
				cout << "Введите координаты для корабля размером 1:\n";
				cin >> x;
				cin >> y;
				d = 1;
				vruchKor(map3, x, y, d, 1);
				for (int i = 0; i < N; i++)
					for (int j = 0; j < N; j++)
						if (map3[i][j] >= 1)
							K++;
				Sleep(1000);
				system("cls");
			}
		}
		system("cls");
		cout << "НАЧИНАЕМ!" << endl;
		Sleep(3000);
		int Kor[2 * N + 1] = { 0 };
		for (int i = 1; i <= N; i++)
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
				{
					if (map1[j][k] == i)
						Kor[i]++;
					if (map3[j][k] == i + N)
						Kor[i + N]++;
				}
		system("cls");
		d = 0;
		while (true)
		{
			K = 0;
			for (int i = 1; i <= N; i++)
				K = K + Kor[i];
			if (K == 0)
			{
				cout << "Победил 2 игрок!" << endl;
				break;
			}
			K = 0;
			for (int i = N + 1; i < 2 * N + 2; i++)
				K = K + Kor[i];
			if (K == 0)
			{
				cout << "Победил 1 игрок!" << endl;
				break;
			}
			d++;
			if (d % 2 == 1)
			{
				while (true)
				{
					cout << "Игрок номер 1:\n";
					cout << "Ваша карта:\n";
					Vivod2(map1, map2);
					cout << "Карта противника:\n";
					Risovka(map3, map4);
					cout << "Введите координаты выстрела:\n";
					cin >> x;
					cin >> y;
					while (map4[x][y] == 1)
					{
						cout << "Вы ввели координаты, введённые ранее. Введите новые координаты выстрела:\n";
						cin >> x;
						cin >> y;
					}
					while ((x < 0) or (y < 0) or (x >= N) or (y >= N))
					{
						cout << "Вы ввели несуществующие координаты. Введите новые координаты выстрела:\n";
						cin >> x;
						cin >> y;
					}
					if (map3[x][y] >= 1)
					{
						cout << "Вы попали! ";
						Kor[map3[x][y]]--;
						if (Kor[map3[x][y]] == 0)
							cout << "И уничтожили корабль!" << endl;
						Sleep(1500);
					}
					else
					{
						cout << "Вы промахнулись!\n";
						Sleep(1500);
						map4[x][y] = 1;
						break;
					}
					map4[x][y] = 1;
					system("cls");
				}
			}
			else
			{
				while (true)
				{
					cout << "Игрок номер 2:\n";
					cout << "Ваша карта:\n";
					Vivod2(map3, map4);
					cout << "Карта противника:\n";
					Risovka(map1, map2);
					cout << "Введите координаты выстрела:\n";
					cin >> x;
					cin >> y;
					while (map2[x][y] == 1)
					{
						cout << "Вы ввели координаты, введённые ранее. Введите новые координаты выстрела:\n";
						cin >> x;
						cin >> y;
					}
					while ((x < 0) or (y < 0) or (x >= N) or (y >= N))
					{
						cout << "Вы ввели несуществующие координаты. Введите новые координаты выстрела:\n";
						cin >> x;
						cin >> y;
					}
					if (map1[x][y] >= 1)
					{
						cout << "Вы попали! ";
						Kor[map1[x][y]]--;
						if (Kor[map1[x][y]] == 0)
							cout << "И уничтожили корабль!" << endl;
						Sleep(1500);
					}
					else
					{
						cout << "Вы промахнулись!\n";
						Sleep(1500);
						map2[x][y] = 1;
						break;
					}
					map2[x][y] = 1;
					system("cls");
				}
			}
			system("cls");
		}
	}
	if (r == 0)																														// Игра с ИИ.
	{
		vector <int> na;
		na.push_back(3);
		na.push_back(2);
		na.push_back(1);
		na.push_back(0);
		cout << "Как вы хотите вводить координаты своих кораблей? (1 - вручную, 0 - случайно):\n";
		cin >> u;
		system("cls");
		if (u == 0)
		{
			randomKor(map1, 4, 1);
			randomKor(map1, 3, 2);
			randomKor(map1, 2, 3);
			randomKor(map1, 1, 4);
			cout << "Ваша карта следующая:\n" << endl;
			Vivod(map1);
			Sleep(5000);
			system("cls");
		}
		else
		{
			K = 0;
			while (K < 4)
			{
				K = 0;
				Vivod(map1);
				cout << "Введите координаты для корабля размером 4 и его направление (1 - вправо, 2 - вниз, 3 - влево, 4 - вверх):\n";
				cin >> x;
				cin >> y;
				cin >> d;
				vruchKor(map1, x, y, d, 4);
				for (int i = 0; i < N; i++)
					for (int j = 0; j < N; j++)
						if (map1[i][j] >= 1)
							K++;
				Sleep(1000);
				system("cls");
			}
			while (K < 10)
			{
				K = 0;
				Vivod(map1);
				cout << "Введите координаты для корабля размером 3 и его направление (1 - вправо, 2 - вниз, 3 - влево, 4 - вверх):\n";
				cin >> x;
				cin >> y;
				cin >> d;
				vruchKor(map1, x, y, d, 3);
				for (int i = 0; i < N; i++)
					for (int j = 0; j < N; j++)
						if (map1[i][j] >= 1)
							K++;
				Sleep(1000);
				system("cls");
			}
			while (K < 22)
			{
				K = 0;
				Vivod(map1);
				cout << "Введите координаты для корабля размером 2 и его направление (1 - вправо, 2 - вниз, 3 - влево, 4 - вверх):\n";
				cin >> x;
				cin >> y;
				cin >> d;
				vruchKor(map1, x, y, d, 2);
				for (int i = 0; i < N; i++)
					for (int j = 0; j < N; j++)
						if (map1[i][j] >= 1)
							K++;
				Sleep(1000);
				system("cls");
			}
			while (K < 24)
			{
				K = 0;
				Vivod(map1);
				cout << "Введите координаты для корабля размером 1:\n";
				cin >> x;
				cin >> y;
				d = 1;
				vruchKor(map1, x, y, d, 1);
				for (int i = 0; i < N; i++)
					for (int j = 0; j < N; j++)
						if (map1[i][j] >= 1)
							K++;
				Sleep(1000);
				system("cls");
			}
		}
		randomKor(map3, 4, 1);
		randomKor(map3, 3, 2);
		randomKor(map3, 2, 3);
		randomKor(map3, 1, 4);
		cout << "НАЧИНАЕМ!" << endl;
		Sleep(3000);
		int Kor[2 * N + 1] = { 0 };
		for (int i = 1; i <= N; i++)
			for (int j = 0; j < N; j++)
				for (int k = 0; k < N; k++)
				{
					if (map1[j][k] == i)
						Kor[i]++;
					if (map3[j][k] == i + N)
						Kor[i + N]++;
				}
		system("cls");
		d = 0;
		int nap, q1, q2, q3, k1, k2, l1, l2;
		l1 = -1;
		l2 = -1;
		nap = -1;
		q1 = -1;
		q2 = -1;
		q3 = -1;
		k1 = -1;
		k2 = -1;
		while (true)
		{
			K = 0;
			for (int i = 1; i <= N; i++)
				K = K + Kor[i];
			if (K == 0)
			{
				cout << "Победил Искусственный Интелект Боб!" << endl;
				Sleep(10000);
				break;
			}
			K = 0;
			for (int i = N + 1; i < 2 * N + 2; i++)
				K = K + Kor[i];
			if (K == 0)
			{
				cout << "Победил игрок!" << endl;
				Sleep(10000);
				break;
			}
			if (d % 2 == 0)
			{
				cout << "Игрок номер 1:\n";
				cout << "Ваша карта:\n";
				Vivod2(map1, map2);
				cout << "Карта противника:\n";
				Risovka(map3, map4);
				cout << "Введите координаты выстрела:\n";
				cin >> x;
				cin >> y;
				while (map4[x][y] == 1)
				{
					cout << "Вы ввели координаты, введённые ранее. Введите новые координаты выстрела:\n";
					cin >> x;
					cin >> y;
				}
				while ((x < 0) or (y < 0) or (x >= N) or (y >= N))
				{
					cout << "Вы ввели несуществующие координаты. Введите новые координаты выстрела:\n";
					cin >> x;
					cin >> y;
				}
				if (map3[x][y] >= 1)
				{
					cout << "Вы попали! ";
					Kor[map3[x][y]]--;
					if (Kor[map3[x][y]] == 0)
						cout << "И уничтожили корабль!" << endl;
					Sleep(1500);
				}
				else
				{
					cout << "Вы промахнулись!\n";
					Sleep(1500);
					map4[x][y] = 1;
					d++;
				}
				map4[x][y] = 1;
				system("cls");
			}
			else
			{
				cout << "Искусственный Интелект Боб:\n";
				cout << "Карта игрока:\n";
				Risovka(map1, map2);
				if (l1 == -1)
				{
					cout << "Искусственный Интелект Боб выстрелил в координаты:\n";
					x = rand() % N;
					y = rand() % N;
					while (map2[x][y] == 1)
					{
						x = rand() % N;
						y = rand() % N;
					}
					cout << x << ' ' << y << endl;
				}
				if (l1 != -1)
				{
					if (nap == 0)
					{
						if (k1 > 0)
							k1--;
						else
						{
							nap++;
							break;
						}
					}
					else if (nap == 1)
					{
						if (k1 < N - 1)
							k1++;
						else
						{
							nap++;
							break;
						}
					}
					else if (nap == 2)
					{
						if (k2 > 0)
							k2--;
						else
						{
							nap++;
							break;
						}
					}
					else if (nap == 3)
					{
						if (k2 < N - 1)
							k2++;
					}
					cout << "Искусственный Интелект Боб выстрелил в координаты:\n";
					cout << k1 << ' ' << k2 << endl;
				}
				if (k1 != -1)
				{
					x = k1;
					y = k2;
				}
				if (map1[x][y] >= 1)
				{
					cout << "Он попал! ";
					Kor[map1[x][y]]--;
					if (l1 == -1)
					{
						l1 = x;
						l2 = y;
					}
					k1 = x; k2 = y;
					if (nap == -1)
						nap = 0;
					if (Kor[map1[x][y]] == 0)
					{
						cout << "И уничтожил корабль!" << endl;
						nap = -1;
						l1 = -1;
						l2 = -1;
						k1 = -1;
						k2 = -1;
					}
					Sleep(4500);
					map2[x][y] = 1;
					system("cls");
				}
				else
				{
					cout << "Он промахнулся!\n";
					map2[x][y] = 1;
					if (nap != -1)
						nap++;
					k1 = l1;
					k2 = l2;
					Sleep(4500);
					system("cls");
					d++;
				}
			}
			system("cls");
		}
	}
}