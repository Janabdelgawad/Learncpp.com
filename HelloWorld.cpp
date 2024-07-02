/*
lifetime is a run-time property
scope is a compile-time property
refactoring is splitting a function into multiple subfunctions
WHAT IS "The one definition rule (ODR)??????????"

there exists only one definiton of each of those -> function.type,variable. or else compilation error occurs
ORRRRR in other wordsss
Within a file, each function, variable, type, or template in a given scope can only have one definition

there exists only one definiton of a function or a variable in a program or else linkage error occurs
ORRRRR in other wordsss
Within a program, each function or a variable in a given scope can only have one definition (programs have multiple files)
*/
#include <iostream>

//DOES'T COMPILE
int add3(int x, int y);

int main3()
{
    std::cout << "3 + 4 + 5 = " << add3(3, 4, 5) << '\n';
    return 0;
}

int add3(int x, int y, int z) //compiler cant find a matching add() function that takes similar number of parameters (3 in this case x,y ,z)
{
    return x + y + z;
}

//COMPILES BUT DOESN'T LINK 

int add1(int x, int y);

int main1()
{
    std::cout << "3 + 4 = " << add1(3, 4) << '\n';
    return 0;
}

int add1(int x, int y, int z)
{
    return x + y + z;
}

//COMPILES AND LINKS
#include <iostream>
int add2(int x, int y, int z);

int main2()
{
    std::cout << "3 + 4 + 5 = " << add2(3, 4, 5) << '\n';
    return 0;
}

int add2(int z, int y, int x) // names don't match the declaration (compiler ignores the parameters, just needs similar identifiers in both functions)
{
    return x + y + z;
}

