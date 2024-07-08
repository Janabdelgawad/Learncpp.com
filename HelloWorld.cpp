#include "io.h"

//glue the above functions together
int main()
{
	int x{ readNumber() };
	int y{ readNumber() };
	int sum = x + y;
	writeAnswer(sum);
	return 0;
}