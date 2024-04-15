#include <sstream>
#include "iostream"
#include "string"
#include "set"
#include "vector"
#include "memory"

class EncodeFunction
{
public:
    std::vector<std::string> encodeDataFunction (const int &countCandidates)
    {
        std::vector<std::string> resultEncode;

        for (int i = 0; i != countCandidates; ++i)
        {
            int k = 0;
            char firstCharName;
            std::set<char> set;
            std::string sizeStr;

            int sum = 0;
            while (k <= 5)
            {
                char ch;
                std::cin.get(ch);

                if (ch != ',' && ch != ' ' && k < 5)
                {
                    if (!(ch >= 48 && ch <= 57) && set.find(ch) == set.end())
                    {
                        set.insert(ch);
                    }
                    else if (ch >= 48 && ch <= 57)
                    {
                        sum += static_cast<char>(ch - '0');
                    }

                    if (set.size() == 1)
                    {
                        firstCharName = ch;
                    }
                }
                else if (ch == ',')
                {
                    ++k;
                }

                if (k == 5)
                {
                    sizeStr += ch;

                    if (sizeStr.size() > 5)
                    {
                        break;
                    }
                }
            }

            int alphChar = static_cast<int>(firstCharName - 64);

            std::ostringstream ss;
            ss << std::hex << (sum * 64) + (alphChar * 256) + set.size();
            std::string result = ss.str();

            for (char& c : result) {
                c = std::toupper(c);
            }

            while (result.size() < 3)
            {
                result = '0' + result;
            }

            while (result.size() > 3)
            {
                result = result.erase(0, 1);
            }
            resultEncode.push_back(result);
        }
        return resultEncode;
    }

};


int main ()
{
    int countCandidates = 0;
    std::cin >> countCandidates;
    std::cin.ignore();

    std::shared_ptr<EncodeFunction> encodeFunction (new EncodeFunction);
    std::vector<std::string> result = encodeFunction->encodeDataFunction(countCandidates);

    for (auto &elem : result)
    {
        std::cout << elem << " ";
    }
}