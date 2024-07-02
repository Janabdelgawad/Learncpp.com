#include <iostream>

void doSomething(); //function declared first to enable linkage, usage in another file else causes error

#define PRINT_MEOW

int main()
{
	doSomething();
	return 0;
}
/*The code above didn't print meow as expected because PRINT_MEOW is only defined in main.cpp and therefore only exists in it
Even though PRINT_MEOW was defined in main.cpp, that doesn’t have any impact on any of the code in APP.cpp (PRINT_MEOW is only #defined from the point of definition to the end of main.cpp).
*/

/*
prefix + identifier = qualified name, ex: std:: + cout
std -> standard
namspace scope -> scope region "any names declared inside of its scope wont be confused with other identically named identifiers by the compiler "
using directive statements to access identifiers should be AVOIDED, ex: using namespace std;
directive statements lets us use the content of the namespace in the global scope of the file without having to mention the prefix each time,
ex: writing cout instead of std::cout but that is avoided because what if the program user decides to add a cout function of his own? or the c++ std lib makes new changes and they conflict with the naming
that is why explicitly accessing identifiers using a prefix is ENCOURGED 
summary: namespace scope is made to distinguish between identifiers.
namespace scope example is -> std

CONDITIONAL COMPILATION
#if 0 -> disables code
#if 1 -> enables code
#ifdef -> if definied
#ifndef -> if not definied 
#endif -> ends a block of code that started with any of the above preprocessor directives

what does the preprocessor do? it makes the translation unit by processing all '#' first, then the rest of the file
the translation unit is what is sent to be compiled in by the compiler

what are macros? a rule that defines how input text is converted into replacement output text.
object-like macros with substitution text are used in legacy code 
syntax rules: directives' identifiers are written in ALL CAPS & the command DOESN'T end in a semi-colon
macros only cause substitution in non-preprocessor commands
preprocessor command ex: #ifdef.         non-preprocessor command ex: std::cout << "khara\n";
directives are resolved before compilation
put "#define" identifiers before functions(because theyre resolved either before or after a function, the preprocessor doesn't understand c++ and can't access the identifier from the inside of the function)
#define scope -> Directives are resolved before compilation, from top to bottom on a file-by-file basis.

right syntax               wrong syntax
#define KHARA "meow"           
int main()                 int main()
{                          {
	//bullshit					#define KHARA "meow"
}                          }

When preprocessor finishes, 
all defined identifiers from that file are discarded.
directives are only valid from the point of definition to the end of that file.
*/