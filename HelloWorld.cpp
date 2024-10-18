#include <iostream>
#include <vector>

void printStack(const std::vector<int>& stack)
{
	std::cout << "\t(Stack:";

	for (auto element : stack) std::cout << ' ' << element;

	if (stack.empty()) std::cout << " empty";
	
	std::cout << ")\n";

}

void pushAndprint(std::vector<int>& stack, int value)
{
	stack.push_back(value);
	std::cout << "Push " << value;
	printStack(stack);
}

void popAndPrint(std::vector<int>& stack)
{
	stack.pop_back();
	std::cout << "Pop ";
	printStack(stack);
}

int main()
{
	std::vector<int> stack{};
	printStack(stack);

	pushAndprint(stack, 1);

	pushAndprint(stack, 2);

	pushAndprint(stack, 3);

	popAndPrint(stack);

	pushAndprint(stack, 4);

	popAndPrint(stack);

	popAndPrint(stack);

	popAndPrint(stack);
	return 0;
}