//What three things are wrong with the following program ?

#include <iostream>

int main()
{
    int length{ 5 };
    const int arr[length]{ 9, 7, 5, 3, 1 };

    std::cout << arr[length];
    arr[0] = 4;

    return 0;
}
//1.cant re-assign a const array -> arr[0] = 4; right
//x.don't need to provide array length if all array elements are intialized not important
//3.defining a const object with a non const one - must be compile time constant right
//2.arrays are indexed from 0 to N-1 so length = 5 when array has 5 elements - is out of bounds