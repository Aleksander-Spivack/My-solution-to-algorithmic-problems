#include <iostream>
#include <map>
#include <algorithm>
#include <memory>
#include <vector>

class AnalyticsDrivingTime
{
private:
    struct RocketEvent
    {
        int day, hour, minute, id;
        char stat;
    };
public:
    void TimeDrive (const int &countDataTypes)
    {
        std::vector<RocketEvent> Events(countDataTypes);
        for (int i = 0; i != countDataTypes; ++i)
        {
            std::cin >> Events[i].day >> Events[i].hour >> Events[i].minute >> Events[i].id >> Events[i].stat;
        }

        std::sort (Events.begin(), Events.end(), [](const RocketEvent &a, RocketEvent &b)
        {
            return a.day < b.day || (a.day == b.day && a.hour < b.hour) || (a.day == b.day && a.hour == b.hour && a.minute < b.minute);
        });

        std::map <int, int> rocketTimeMove;
        std::map<int, int> startMoveTime;
        for (const auto &event : Events)
        {
            if (event.stat == 'A')
            {
                startMoveTime[event.id] = event.day * 24 * 60 + event.hour * 60 + event.minute;
                continue;
            }
            else if (event.stat == 'C' || event.stat == 'S')
            {
                int startTime = startMoveTime[event.id];
                int currTime = event.day * 24 * 60 + event.hour * 60 + event.minute;
                int moveTime = currTime - startTime;

                rocketTimeMove[event.id] += moveTime;
            }
        }

        for (const auto &pair : rocketTimeMove)
        {
            std::cout << pair.second << " ";
        }
    }
};


int main() {
    int countDataTypes = 0;
    std::cin >> countDataTypes;

    std::shared_ptr<AnalyticsDrivingTime> analyticsDrivingTime (new AnalyticsDrivingTime);
    analyticsDrivingTime->TimeDrive(countDataTypes);
}