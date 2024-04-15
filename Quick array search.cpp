Дан массив из N целых чисел. Все числа от −10^9 до 10^9. Нужно уметь отвечать на запросы вида “Cколько чисел имеют значения от L до R?”.

Формат ввода
Число N (1 ≤ N ≤ 10^5). Далее N целых чисел.Затем число запросов K (1 ≤ K ≤ 10^5).Далее K пар чисел L,R (−10^9 ≤ L ≤ R ≤ 10^9) — собственно запросы.

Формат вывода
Выведите K чисел — ответы на запросы.

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;
    std::cin >> N;

    std::vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        std::cin >> nums[i];
    }

    int K;
    std::cin >> K;

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < K; i++) {
        int L, R;
        std::cin >> L >> R;
        int left_index = std::lower_bound(nums.begin(), nums.end(), L) - nums.begin();
        int right_index = std::upper_bound(nums.begin(), nums.end(), R) - nums.begin();
        int count = right_index - left_index;
        std::cout << count << " ";
    }

    return 0;
}