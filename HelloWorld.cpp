#include <iostream>
#include <array>
/*
When run, it should print :

The array(1, 4, 9, 16) has length 4
The array(h, e, l, l, o) has length 5
*/
template <typename T, std::size_t N>
void printArray(const std::array<T, N>& arr)
{
    bool first{ true };
    std::cout << "The array(";
    for (const auto& i : arr)
    {
        std::cout << (first ? "" : ", ");
        std::cout << i;
        first = false;
    }
    std::cout << ") has length " << N << '\n';
}

int main()
{
    constexpr std::array arr1{ 1, 4, 9, 16 };
    printArray(arr1);

    constexpr std::array arr2{ 'h', 'e', 'l', 'l', 'o' };
    printArray(arr2);

    return 0;
}