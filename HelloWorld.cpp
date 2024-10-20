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
	std::vector<bool> m_letterGuessed{ std::vector<bool>(26) };
	std::size_t toIndex(char c) const { return static_cast<std::size_t>((c % 32) - 1); }
public:
	std::string_view getWord() const { return m_word; }
	bool getLetter(char c) const { return m_letterGuessed[toIndex(c)]; }
	void setLetter(char c) { m_letterGuessed[toIndex(c)] = true; }
};

void draw(const Session& s)
{
	std::cout << '\n';
	std::cout << "The word: ";
	for (auto letter : s.getWord())
	{
		if (s.getLetter(letter)) std::cout << letter;
		else std::cout << '_';
	}
	std::cout << '\n';
}

char userInput(const Session& s)
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

		if (s.getLetter(input))
		{
			std::cout << "You already guessed that.  Try again.\n";
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
		
		int count{ 6 };
		while (--count)
		{
			draw(s);
			char c{ userInput(s) };
			s.setLetter(c);
		}
		draw(s);

	return 0;
}