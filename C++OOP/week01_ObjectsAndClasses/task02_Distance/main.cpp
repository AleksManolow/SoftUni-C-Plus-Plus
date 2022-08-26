#include<iostream>
#include<math.h>
#include <iomanip>
struct Point
{
    int x;
    int y;
};
class Distance
{
private:
    Point a;
    Point b;

public:
    Distance()
    {
        a.x = 0;
        a.y = 0;
        b.x = 0;
        b.y = 0;
    }
    void readPoints()
    {
        std::cin >> a.x;
        std::cin >> a.y;
        std::cin >> b.x;
        std::cin >> b.y;
    }
    double getDistance()
    {
        return sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
    }

};
int main()
{
    Distance pointsDistance;
    pointsDistance.readPoints();
    std::cout << std::fixed << std::setprecision(3) << pointsDistance.getDistance() << std::endl;
    return 0;
}