/*
Вам дана последовательность измерений некоторой величины. Требуется определить, повторялась ли какое-либо число, причём расстояние между повторами не превосходило k.

Формат ввода
В первой строке задаются два числа n и k (1 ≤ n, k ≤ 10^5).

Во второй строке задаются n чисел, по модулю не превосходящих 10^9.

Формат вывода
Выведите YES, если найдется повторяющееся число и расстояние между повторами не превосходит k и NO в противном случае.
*/

#include <iostream>
#include <vector>
#include <map>

int main()
{
	int n = 0, k = 0;
	std::cin >> n >> k;

	bool IsOrden = false;
	std::map <int, int> map;

	for (int i = 0; i != n; ++i)
	{
		int num = 0;
		std::cin >> num;

		if (map.count(num) > 0 && i - map[num] <= k)
		{
			IsOrden = true;
			break;
		}
		map[num] = i;
	}

	if (IsOrden)
	{
		std::cout << "YES";
		return 0;
	}
	std::cout << "NO";
	return 0;
}

