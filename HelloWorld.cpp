#include <iostream>
#include <cstdlib>
int randomNumberGenerator()
{
	return 1 + rand() % 100;
}
//function to ask the user if they want to play again
bool playAgain()
{
	std::cout << "\nWould you like to play again (y/n)?\n";
	char input{};
	std::cin >> input;
	while (input != 'y' && input != 'n')
	{
		std::cout << "Would you like to play again (y/n)?\n";
		std::cin >> input;
	}
	return input == 'y';
}
//check the user's guess
void Answer(int user, int answer)
{
		if (user < answer) std::cout << "Your guess is too low.";
		else if (user > answer) std::cout << "Your guess is too high.";
		else std::cout << "Correct! You win!";
}
//function to handle the user's trials
int userTrial(int answer)
{
	int input{};
	int i{ 1 };

	std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";
	for (; i <= 7; i++)
	{
		std::cout << "\nGuess #" << i << ": ";
		std::cin >> input;
		if (input == answer)
		{
			Answer(input, answer);
			return input;
		}
		Answer(input, answer);
	}
	std::cout << "\nSorry, you lose. The correct number was " << answer;
	return input;
}
int main()
{
	do
	{
		int randomNumber{ randomNumberGenerator() };
		int userNumber{ userTrial(randomNumber) };
	} while (playAgain());

	std::cout << "Thank you for playing!\n";
	return 0;
}
