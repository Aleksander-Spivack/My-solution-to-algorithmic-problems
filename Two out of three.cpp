/*
Вам даны три списка чисел. Найдите все числа, которые встречаются хотя бы в двух из трёх списков.

Формат ввода
Во входных данных описывается три списка чисел. Первая строка каждого описания списка состоит из длины списка n (1 ≤ n ≤ 1000). Вторая строка описания содержит список натуральных чисел, записанных через пробел. Числа не превосходят 10^9.

Формат вывода
Выведите все числа, которые содержатся хотя бы в двух списках из трёх, в порядке возрастания. Обратите внимание, что каждое число необходимо выводить только один раз.
*/

#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

int main()
{
	std::set<int> common;
	std::set<int> uniqed1;
	std::set<int> uniqed2;
	std::set<int> uniqed3;

	int n = 0;
	std::cin >> n; 
	for (int i = 0; i != n; ++i)
	{
		int num = 0;
		std::cin >> num;

		uniqed1.insert(num);
	}

	std::cin >> n;
	for (int i = 0; i != n; ++i)
	{
		int num = 0;
		std::cin >> num;

		uniqed2.insert(num);
	}

	std::cin >> n;
	for (int i = 0; i != n; ++i)
	{
		int num = 0;
		std::cin >> num;

		uniqed3.insert(num);
	}

	for (auto& elem : uniqed1)
	{
		if (uniqed2.count(elem) > 0)
		{
			common.insert(elem);
		}
	}

	for (auto& elem : uniqed1)
	{
		if (uniqed3.count(elem) > 0)
		{
			common.insert(elem);
		}
	}

	for (auto& elem : uniqed2)
	{
		if (uniqed3.count(elem) > 0)
		{
			common.insert(elem);
		}
	}

	std::vector<int> result(common.begin(), common.end());
	std::sort(result.begin(), result.end());

	for (auto& elem : result)
	{
		std::cout << elem << " ";
	}
}