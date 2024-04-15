/*
Из шахматной доски по границам клеток выпилили связную (не распадающуюся на части) фигуру без дыр. Требуется определить ее периметр.

Формат ввода
Сначала вводится число N (1 ≤ N ≤ 64) – количество выпиленных клеток. В следующих N строках вводятся координаты выпиленных клеток, разделенные пробелом (номер строки и столбца – числа от 1 до 8). Каждая выпиленная клетка указывается один раз.

Формат вывода
Выведите одно число – периметр выпиленной фигуры (сторона клетки равна единице).
*/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int main()
{
	int n = 0;
	std::cin >> n;

	std::vector<std::pair<int, int>> ceils(n);
	for (int i = 0; i != n; ++i)
	{
		int row = 0, col = 0;
		std::cin >> row >> col;
		ceils[i] = std::make_pair(row, col);
	}

	int P = 0;
	for (int i = 0; i != ceils.size(); ++i)
	{
		int row = ceils[i].first;
		int col = ceils[i].second;

		if (std::find(ceils.begin(), ceils.end(), std::make_pair(row - 1, col)) == ceils.end()) ++P;
		if (std::find(ceils.begin(), ceils.end(), std::make_pair(row + 1, col)) == ceils.end()) ++P;
		if (std::find(ceils.begin(), ceils.end(), std::make_pair(row, col - 1)) == ceils.end()) ++P;
		if (std::find(ceils.begin(), ceils.end(), std::make_pair(row, col + 1)) == ceils.end()) ++P;
	}

	std::cout << P;
}
