#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>
//Use std::sort and a lambda in the following code to sort the seasons by ascending average temperature.
struct Season
{
    std::string_view name{};
    double averageTemperature{};
};

int main()
{
    std::array<Season, 4> seasons{
      { { "Spring", 285.0 },
        { "Summer", 296.0 },
        { "Fall", 288.0 },
        { "Winter", 263.0 } }
    };

    std::sort(seasons.begin(), seasons.end(), [](const auto& a, const auto& b) {
        return a.averageTemperature < b.averageTemperature;
        });

    for (const auto& season : seasons)
    {
        std::cout << season.name << '\n';
    }

    return 0;
}