/*
To start, the user should be asked for the height of the tower in meters. 

gravity = (9.8 m/s2),
velocity = 0
Have the program output the height of the ball above the ground after 0, 1, 2, 3, 4, and 5 seconds. 
The ball should not go underneath the ground (height 0).

Use a function to calculate the height of the ball after x seconds.
The function can calculate how far the ball has fallen after x seconds using the following formula:
distance fallen = gravity_constant * x_seconds2 / 2
*/
#include <iostream>

double towerHeight()
{
	std::cout << "Enter the height of the tower in meters: ";
	double input{};
	std::cin >> input;
	return input;
}

double calculateBallHeight(double height, int seconds)
{
	double gravity{ 9.8 };

	double distance{ gravity * (seconds * seconds) / 2.0 };
	double ballHeight{height - distance};

	//if ball underground, place it on the ground
	if (ballHeight < 0.0)
		return 0.0;

	return ballHeight;
}

void printBallHeight(double height, int seconds)
{
	if(height > 0.0)
		std::cout << "At " << seconds << " seconds, the ball is at height : " << height << " meters\n";
	else
		std::cout << "At " << seconds << " seconds, the ball is on the ground.\n";
}

void calculateAndPrint(double height, int seconds) {
	printBallHeight(calculateBallHeight(height, seconds), seconds);
}

int main()
{
	double height{ towerHeight() } ;
	calculateAndPrint(height, 0);
	calculateAndPrint(height, 1);
	calculateAndPrint(height, 2);
	calculateAndPrint(height, 3);
	calculateAndPrint(height, 4);
	calculateAndPrint(height, 5);
	return 0;
}