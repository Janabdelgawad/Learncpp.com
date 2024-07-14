#include <iostream>

double TowerHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double towerHeight{};
	std::cin >> towerHeight;
	return towerHeight;
}

double CalculateBallHeight(double height, int seconds)
{
	double gravity{ 9.8 };
	double distance{ gravity * (seconds * seconds) / 2.0 };
	double ballHeight{ height - distance };
	if (ballHeight < 0.0)
		return 0.0;
	return ballHeight;
}

void PrintBallHeight(double height, int seconds)
{
	if (height > 0.0)
		std::cout << "At " << seconds << " seconds, the ball is at height : " << height << " meters\n";
	else
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

void calculateAndPrint(double height, int seconds)
{
	double ballHeight{ CalculateBallHeight(height, seconds) };
	PrintBallHeight(ballHeight, seconds);
}

int main()
{
	double towerHeight{ TowerHeight() };
	calculateAndPrint(towerHeight, 0);
	calculateAndPrint(towerHeight, 1);
	calculateAndPrint(towerHeight, 2);
	calculateAndPrint(towerHeight, 3);
	calculateAndPrint(towerHeight, 4);
	calculateAndPrint(towerHeight, 5);

	return 0;
}