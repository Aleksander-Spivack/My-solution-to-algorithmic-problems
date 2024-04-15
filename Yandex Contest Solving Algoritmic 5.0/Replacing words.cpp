/*
С целью экономии чернил в картридже принтера было принято решение укоротить некоторые слова в тексте. Для этого был составлен словарь слов, до которых можно сокращать более длинные слова. Слово из текста можно сократить, если в словаре найдется слово, являющееся началом слова из текста. Например, если в списке есть слово "лом", то слова из текста "ломбард", "ломоносов" и другие слова, начинающиеся на "лом", можно сократить до "лом".

Если слово из текста можно сократить до нескольких слов из словаря, то следует сокращать его до самого короткого слова.

Формат ввода
В первой строке через пробел вводятся слова из словаря, слова состоят из маленьких латинских букв. Гарантируется, что словарь не пуст и количество слов в словаре не превышет 1000, а длина слов — 100 символов.

Во второй строке через пробел вводятся слова текста (они также состоят только из маленьких латинских букв). Количество слов в тексте не превосходит 10^5, а суммарное количество букв в них — 10^6.

Формат вывода
Выведите текст, в котором осуществлены замены.
*/

#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>

std::vector<std::string> SplitStrOnWord(const std::string& str)
{
	std::vector<std::string> words;
	std::string word;
	for (char c : str)
	{
		if (c == ' ')
		{
			if (word.empty()) continue;
			words.push_back(word);
			word.clear();
		}
		else
		{
			word += c;
		}
	}
	if (!word.empty()) words.push_back(word);

	return words;
}

int main()
{
	std::string dictionary_str;
	std::string text_str;

	std::getline(std::cin, dictionary_str);
	std::getline(std::cin, text_str);

	std::vector<std::string> words_dictionary = SplitStrOnWord(dictionary_str);
	std::vector<std::string> words_text = SplitStrOnWord(text_str);

	std::unordered_set<std::string> dictionary(words_dictionary.begin(), words_dictionary.end());
	
	for (auto& word : words_text)
	{
		std::string replace_word = word;

		for (int i = 1; i != word.size(); ++i)
		{
			std::string prefix_word = word.substr(0, i);
			if (dictionary.count(prefix_word) > 0)
			{
				replace_word = prefix_word;
				break;
			}
		}

		std::cout << replace_word << " ";
	}

}

