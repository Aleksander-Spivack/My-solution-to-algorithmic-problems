/*
Костя успешно прошел собеседование и попал на стажировку в отдел разработки сервиса «Музыка».
Конкретно ему поручили такое задание — научиться подбирать плейлист для группы друзей, родственников или коллег. При этом нужно подобрать такой плейлист, в который входят исключительно нравящиеся всем членам группы песни.
Костя очень хотел выполнить это задание быстро и качественно, но у него не получается. Помогите ему написать программу, которая составляет плейлист для группы людей.

Формат ввода
В первой строке расположено одно натуральное число n(1 ≤ n ≤ 2*10^5), где n – количество человек в группе. В следующих 2. n строках идет описание любимых плейлистов членов группы. По 2 строки на каждого участника. В первой из этих 2-х строк расположено число ki — количество любимых треков i-го члена группы. В следующей строке расположено ki строк через пробел — названия любимых треков i-го участника группы. Каждый трек в плейлисте задан в виде строки, все строки уникальны, сумма длин строк не превосходит 2*10^6. Строки содержат большие и маленькие латинские буквы и цифры.

Формат вывода
Выведите количество, а затем сам список песен через пробел — список треков, которые нравятся каждому участнику группы. Ответ необходимо отсортировать в лексикографическом порядке!
*/

#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
	int n; 
	std::cin >> n;

	bool IsFirstPerson = true;
	std::set<std::string> commonPlaylist;
	for (int i = 0; i != n; ++i)
	{
		int k;
		std::cin >> k;

		std::set<std::string> personMusic;
		for (int j = 0; j != k; ++j)
		{
			std::string music;
			std::cin >> music;
			personMusic.insert(music);
		}

		if (IsFirstPerson)
		{
			IsFirstPerson = false;
			commonPlaylist = personMusic;
		}
		else 
		{
			std::set<std::string> temp;
			for (auto& track : commonPlaylist)
			{
				if (personMusic.count(track) > 0)
				{
					temp.insert(track);
				}
			}
			commonPlaylist = temp;
		}
	}

	std::vector<std::string> resultPlaylist(commonPlaylist.begin(), commonPlaylist.end());
	std::sort(resultPlaylist.begin(), resultPlaylist.end());

	std::cout << resultPlaylist.size() << "\n";
	for (auto& elem : resultPlaylist)
	{
		std::cout << elem << " ";
	}

	return 0;
}

