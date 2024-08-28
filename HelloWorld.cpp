#include <iostream>
#include <limits>
#include <cstdlib>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int randomNumberGenerator()
{
    return 1 + rand() % 100;
}

bool playAgain()
{
    std::cout << "\nWould you like to play again (y/n)?\n";
    char input{};
    std::cin >> input;
    ignoreLine(); // Ignore any extra characters after the input
    while (input != 'y' && input != 'n')
    {
        std::cout << "Invalid input. Would you like to play again (y/n)?\n";
        std::cin >> input;
        ignoreLine(); // Ignore any extra characters after the input
    }
    return input == 'y';
}

void Answer(int user, int answer)
{
    if (user < answer) std::cout << "Your guess is too low.\n";
    else if (user > answer) std::cout << "Your guess is too high.\n";
    else std::cout << "Correct! You win!\n";
}

int userTrial(int answer)
{
    int input{};
    int i{ 1 };

    std::cout << "Let's play a game. I'm thinking of a number between 1 and 100. You have 7 tries to guess what it is.\n";
    for (; i <= 7; i++)
    {
        std::cout << "\nGuess #" << i << ": ";
        std::cin >> input;

        if (!std::cin)
        {
            std::cin.clear();
            ignoreLine();
            std::cout << "Invalid input. Please enter a number between 1 and 100.\n";
            i--; // Decrement the counter to give the user another chance
            continue;
        }

        if (input < 1 || input > 100)
        {
            std::cout << "Out of bounds. Please enter a number between 1 and 100.\n";
            ignoreLine();
            i--; // Decrement the counter to give the user another chance
            continue;
        }

        if (input == answer)
        {
            Answer(input, answer);
            return input;
        }
        Answer(input, answer);
    }
    std::cout << "\nSorry, you lose. The correct number was " << answer << ".\n";
    ignoreLine();
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
