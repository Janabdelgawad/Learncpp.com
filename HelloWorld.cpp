#include "Random.h"
#include <vector>
#include <iostream>
namespace WordList
{
	std::vector words{ "mystery", "broccoli", "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage" };
	std::string_view pickRandomWord()
	{
		return  words[Random::get<std::size_t>(0, words.size() - 1)];
	}

}

class Session
{
private: 
	std::string_view m_word{ WordList::pickRandomWord() };

public:
	std::string_view getWord() const { return m_word; }
};

void draw(const Session& s)
{
	std::cout << '\n';
	std::cout << "The word: ";
	for (auto letter : s.getWord())  std::cout << '_';
	std::cout << '\n';
}

char userInput()
{
	while (true)
	{
		std::cout << "Enter your next letter: ";
		char input{};
		std::cin >> input;

		if (!std::cin)
		{
			std::cin.clear();
			std::cout << "That wasn't a valid input. Try again\n";
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		
		if (input < 'a' || input > 'z')
		{
			std::cout << "That wasn't a valid input.  Try again.\n";
			continue;
		}

		return input;
	}

}

int main()
{
		std::cout << "Welcome to C++man (a variant of Hangman)\n";
		std::cout << "To win : guess the word.To lose : run out of pluses.\n";

		Session s{};
		draw(s);
		char c{ userInput() };
		std::cout << "you entered: " << c << '\n';
	return 0;
}