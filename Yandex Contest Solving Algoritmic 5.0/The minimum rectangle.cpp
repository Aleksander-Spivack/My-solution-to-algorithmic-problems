/*
На клетчатой плоскости закрашено K клеток. Требуется найти минимальный по площади прямоугольник, со сторонами, параллельными линиям сетки, покрывающий все закрашенные клетки.

Формат ввода
Во входном файле, на первой строке, находится число K (1 ≤ K ≤ 100). На следующих K строках находятся пары чисел Xi и Yi — координаты закрашенных клеток (|Xi|, |Yi| ≤ 109).

Формат вывода
Выведите в выходной файл координаты левого нижнего и правого верхнего углов прямоугольника.
*/

#include <iostream>
#include <climits>

int main()
{
	int k = 0;
	std::cin >> k;
	int minX = INT_MAX, minY = INT_MAX;
	int maxX = INT_MIN, maxY = INT_MIN;

	for (int i = 0; i != k; ++i)
	{
		int x, y;
		std::cin >> x >> y;
		
		if (minX > x) minX = x;
		if (maxX < x) maxX = x;

		if (minY > y) minY = y;
		if (maxY < y) maxY = y;
	}

	std::cout << minX << " " << minY << " " << maxX << " " << maxY;
}