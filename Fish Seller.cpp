/*
Вася решил заняться торговлей рыбой. С помощью методов машинного обучения он предсказал цены на рыбу на N дней вперёд. Он решил, что в один день он купит рыбу, а в один из следующих дней — продаст (то есть совершит или ровно одну покупку и продажу или вообще не совершит покупок и продаж, если это не принесёт ему прибыли). К сожалению, рыба — товар скоропортящийся и разница между номером дня продажи и номером дня покупки не должна превышать K.

Определите, какую максимальную прибыль получит Вася.

Формат ввода
В первой строке входных данных задаются числа N и K (1 ≤ N ≤ 10000, 1 ≤ K ≤ 100).

Во второй строке задаются цены на рыбу в каждый из N дней. Цена — целое число, которое может находится в пределах от 1 до 10^9.

Формат вывода
Выведите одно число — максимальную прибыль, которую получит Вася.
*/

#include <iostream>
#include <vector>

int main()
{
	int N, K;
	std::cin >> N >> K;

	std::vector<int> prices(N);
	for (int i = 0; i != N; ++i)
	{
		std::cin >> prices[i];
	}

	int maxProfit = 0;
	for (int i = 0; i != N; ++i)
	{
		for (int j = i + 1; j <= std::min(i + K, N - 1); ++j)
		{
			maxProfit = std::max(maxProfit, prices[j] - prices[i]);
		}
	}

	std::cout << maxProfit;
}
