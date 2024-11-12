#include <iostream>
#include <cassert>
class IntArray
{
private:
	int m_size{0};
	int* L{ nullptr };

public:
	explicit IntArray(int size) : m_size{size}
	{
		assert(size > 0 && "Invalid input");
		L = new int[static_cast<std::size_t>(m_size)]{};
	};

	//copy constructor that does deep copying
	IntArray(const IntArray& array) : m_size{ array.m_size }
	{
		L = new int[static_cast<std::size_t>(m_size)] {};
		for (int count{ 0 }; count < array.m_size; ++count)
			L[count] = array.L[count];
	}

	~IntArray()
	{
		delete[] L;
	}

	friend std::ostream& operator<<(std::ostream& out, const IntArray& size);

	int& operator[] (const int index)
	{
		assert(index >= 0);
		assert(index < m_size);
		return L[index];
	}

	IntArray& operator= (const IntArray& array)
	{
		// self-assignment guard
		if (this == &array)
			return *this;

		// If this array already exists, delete it so we don't leak memory
		delete[] L;

		m_size = array.m_size;

		// Allocate a new array
		L = new int[static_cast<std::size_t>(m_size)] {};

		// Copy elements from original array to new array
		for (int count{ 0 }; count < array.m_size; ++count)
			L[count] = array.L[count];

		return *this;
	}
};

std::ostream& operator<<(std::ostream& out, const IntArray& f)
{
	for (int count{ 0 }; count < f.m_size; ++count)
	{
		out << f.L[count] << ' ';
	}
	return out;
}

IntArray fillArray()
{
	IntArray a(5);

	a[0] = 5;
	a[1] = 8;
	a[2] = 2;
	a[3] = 3;
	a[4] = 6;

	return a;
}

int main()
{
	IntArray a{ fillArray() };

	std::cout << a << '\n';

	auto& ref{ a }; // we're using this reference to avoid compiler self-assignment errors
	a = ref;

	IntArray b(1);
	b = a;

	a[4] = 7;

	std::cout << b << '\n';

	return 0;
}