/*
Миша сидел на занятиях математики в Высшей школе экономики и решал следующую задачу: дано 
n целых чисел и нужно расставить между ними знаки + и × так, чтобы результат полученного арифметического выражения был нечётным (например, между числами 5, 7, 2, можно расставить арифметические знаки следующим образом: 5×7+2=37). Так как примеры становились все больше и больше, а Миша срочно убегает в гости, от вас требуется написать программу решающую данную задачу.

Формат ввода
В первой строке содержится единственное число 
n (2 ≤ n ≤ 10^5). Во второй строке содержится n целых чисел ai, разделённых пробелами (−10^9 ≤ ai ≤ 10^9). Гарантируется, что решение существует.

Формат вывода
В одной строке выведите n−1 символ + или ×, в результате применения которых получается нечётный результат. (Для вывода используйте соответственно знаки «+» (ASCII код—43) и «x» (ASCII код—120), без кавычек).
*/

#include "iostream"
#include "vector"

int main ()
{
    int n = 0;
    std::cin >> n;

    std::vector<int> nums(n);
    for (int i = 0; i != n; ++i)
        std::cin >> nums[i];

    std::vector<char> ch (n - 1);
    int firstODD = -1, countODD = nums[0] % 2;

    for (int i = 0; i != n - 1; ++i)
    {
        if ((nums[i] + nums[i + 1]) % 2 == 0)
        {
            ch[i] = 'x';
        }
        else
        {
            ch[i] = '+';
            if (nums[i + 1] % 2 != 0)
                ++countODD;
        }

        if (firstODD == -1 && nums[i] % 2 != 0)
            firstODD = i;
    }

    if (countODD % 2 != 0)
        for (int i = 0; i != n - 1; ++i) std::cout << ch[i];
    else
    {
        ch[firstODD] == '+' ? ch[firstODD] = 'x' : ch[firstODD] = '+';

        for (int i = 0; i != n - 1; ++i) std::cout << ch[i]; 
    }

    return 0;
}
