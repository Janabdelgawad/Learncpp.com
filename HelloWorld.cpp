#include <iostream>
#include <array>
#include <algorithm>
#include <cassert>
class IntArray
{
private:
	int m_length{};
	int* m_data{};
public:
	//constructors
	IntArray() = default;
	IntArray(int length) : m_length{ length }, m_data{new int[static_cast<std::size_t>(length)]} {}
	IntArray(std::initializer_list<int> list) : IntArray(static_cast<int>(list.size()))
	{
		std::copy(list.begin(), list.end(), m_data);
	}
	~IntArray() { delete[] m_data; }

	//deleted constructor & overloaded assignment operator (shallow copies)
	IntArray(const IntArray&) = delete;
	IntArray& operator=(const IntArray& list) = delete;

	//overloaded operators
	int& operator[](int& index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	IntArray& operator=(std::initializer_list<int> list)
	{
		//reallocate list, if unequal list sizes
		int length{ static_cast<int>(list.size()) };
		if (length != m_length)
		{
			delete[] m_data;
			m_length = length;
			m_data = new int[list.size()] {};
		}

		//intialize array from old array
		std::copy(list.begin(), list.end(), m_data);

		return *this;
	}
	//access functions
	int getLength() const { return m_length; }
};
//overloaded assignment operator that takes an initializer list.
int main()
{
	IntArray array{ 5, 4, 3, 2, 1 }; // initializer list
	for (int count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	array = { 1, 3, 5, 7, 9, 11 };

	for (int count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	return 0;
}