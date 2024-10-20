#include "Random.h"
#include <vector>
#include <iostream>
namespace Settings
{
	constexpr int wrongGuessesAllowed{ 6 };
}

namespace WordList
{
	std::vector words{ "mystery", "broccoli", "account", "almost", "spaghetti", "opinion", "beautiful", "distance", "luggage" };
	std::string_view pickRandomWord()
	{
		return  words[1];
	}
}

class Session
{
private: 
	std::string_view m_word{ WordList::pickRandomWord() };
	std::vector<bool> m_letterGuessed{ std::vector<bool>(26) };
	int m_wrongGuessesLeft{ Settings::wrongGuessesAllowed };
	std::size_t toIndex(char c) const { return static_cast<std::size_t>((c % 32) - 1); }
public:
	std::string_view getWord() const { return m_word; }
	bool getLetter(char c) const { return m_letterGuessed[toIndex(c)]; }
	void setLetter(char c) { m_letterGuessed[toIndex(c)] = true; }
	int wrongGuessesLeft() const { return m_wrongGuessesLeft; }
	void removeGuess() { --m_wrongGuessesLeft; }
	bool letterInWord(char c) const 
	{
        for (auto ch: m_word)
        {
            if (ch == c)
                return true;
        }

        return false;
    }
    bool won()
    {
        for (auto c: m_word)
        {
            if (!getLetter(c))
                return false;
        }

        return true;
    }
};

void draw(const Session& s)
{
	std::cout << '\n';

	std::cout << "The word: ";
	for (auto c : s.getWord())
	{
		if (s.getLetter(c)) std::cout << c;
		else std::cout << '_';
	}

	std::cout << "   Wrong guesses: ";
	for (int i = 0; i < s.wrongGuessesLeft(); ++i) std::cout << '+';
	for (char c = 'a'; c <= 'z'; ++c)
	{
        if (s.getLetter(c) && !s.letterInWord(c))
            std::cout << c;
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

void handleGuess(Session& s, char c)
{
	s.setLetter(c);

	if (s.letterInWord(c))
	{
		std::cout << "Yes, '" << c << "' is in the word!\n";
		return;
	}

	std::cout << "No, '" << c << "' is not in the word!\n";
	s.removeGuess();
}

int main()
{
		std::cout << "Welcome to C++man (a variant of Hangman)\n";
		std::cout << "To win : guess the word.To lose : run out of pluses.\n";

		Session s{};
		
		while (s.wrongGuessesLeft() && !s.won())
		{
			draw(s);
			char c{ userInput(s) };
			handleGuess(s, c);
		}
		draw(s);

		if (!s.wrongGuessesLeft())
		{
			std::cout << "You lost!   The word was: " << s.getWord() << '\n';
		}
		else std::cout << "You won!   \n";

	return 0;
}