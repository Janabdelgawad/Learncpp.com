#include <iostream>
#include <memory> // for std::shared_ptr

class Resource
{
public:
	//used weak_ptr instead of the shared_ptr so that the m_ptr wont keep the resource alive
	std::weak_ptr<Resource> m_ptr{}; // initially created empty

	Resource() { std::cout << "Resource acquired\n"; }
	~Resource() { std::cout << "Resource destroyed\n"; }
};


int main()
{
	auto ptr1{ std::make_shared<Resource>() };

	ptr1->m_ptr = ptr1; // m_ptr is now sharing the Resource that contains it

	return 0;
}