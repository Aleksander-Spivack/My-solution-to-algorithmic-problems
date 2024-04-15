/*
Задано две строки, нужно проверить, является ли одна анаграммой другой. Анаграммой называется строка, полученная из другой перестановкой букв.

Формат ввода
Строки состоят из строчных латинских букв, их длина не превосходит 100000. Каждая записана в отдельной строке.

Формат вывода
Выведите "YES" если одна из строк является анаграммой другой и "NO" в противном случае.
*/

#include <iostream>
#include <string>
#include <algorithm>

int main()
{
	std::string str1, str2;
	std::cin >> str1 >> str2;

	int n = str1.size(), m = str2.size();

	std::sort(str1.begin(), str1.end());
	std::sort(str2.begin(), str2.end());

	int i = 0;
	int j = 0;
	while (j < n)
	{
		if (str1[j] != str2[i])
		{
			std::cout << "NO";
			return 0;
		}
		else
		{
			++i;
			++j;
		}
	}
	std::cout << "YES";

}

