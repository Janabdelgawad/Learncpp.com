#include <iostream>
#include <vector>
 template <typename T>
 void printArray(const std::vector<T>& arr)
 {
     for (std::size_t index{ 0 }; index < arr.size(); ++index)
         std::cout << arr[index] << ' ';
 }
int main()
{
    std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };

    printArray(arr); // use function template to print array

    return 0;
}