#include <string>
#include <cassert>
#include <iostream>
class MyString
{
private:
	std::string m_word{};
public:
	MyString(std::string_view string = {})
		:m_word{ string }{}

	std::string_view operator()(int start, int length)
	{
		assert(start >= 0);
		assert(start + length <= static_cast<int>(m_word.length()) &&
		"MyString::operator(int, int): Substring is out of range");

		return
		{
			std::string_view{ m_word }.substr(
			static_cast<std::string::size_type>(start),
			static_cast<std::string::size_type>(length)
		) };

	}

	friend std::ostream& operator<<(std::ostream& out, const MyString& s)
	{
		out << s.m_word;
		return out;
	}
};

int main()
{
	MyString s{ "Hello, world!" };
	std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters

	return 0;
}

