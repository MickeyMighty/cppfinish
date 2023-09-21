#include "../class/A.hpp"
#include "../class/B.hpp"
#include "../class/C.hpp"
#include "../class/Base.hpp"
#include <time.h>
#include <cstdlib>
#include <iostream>
#include <stdint.h>
// #include <typeinfo>


// https://www.geeksforgeeks.org/dynamic-_cast-in-cpp/

Base* generate(void) {
  srand(time(NULL));
  int r = rand() % 3;
  if (r == 0) {
    return new A();
  } else if (r == 1) {
    return new B();
  } else {
    return new C();
  }
}

void identify(Base* p)
{
  if (dynamic_cast<A*>(p) != NULL) {
        std::cout << "Pointer is A!" << std::endl;
        return;
    }
    if (dynamic_cast<B*>(p) != NULL) {
        std::cout << "Pointer is B!" << std::endl;
        return;
    }
    if (dynamic_cast<C*>(p) != NULL) {
        std::cout << "Pointer is C!" << std::endl;
        return;
    }
    std::cout << "It has nothing to do with the base." << std::endl;
}

void	identify(Base& p)
{
	try {
		static_cast<void>(dynamic_cast<A&>(p));
		std::cout << "Reference A\n";
	} catch (std::exception &e) {}

	try {
		static_cast<void>(dynamic_cast<B&>(p));
		std::cout << "Reference B\n";
	} catch (std::exception &e) {}

	try {
		static_cast<void>(dynamic_cast<C&>(p));
		std::cout << "Reference C\n";
	} catch (std::exception &e) {}

}

int main()
{
    std::srand(static_cast<unsigned int>(time(NULL)));

    Base*   base = generate();

    identify(base);
    identify(*base);

    delete base;
}
