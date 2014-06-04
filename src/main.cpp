#include <iostream>
#include <typeinfo>
#include <cmath>
#include "intauto.hpp"

int main(void)
{
    std::cerr << "Creating instance of intauto_t...\n\n";

    _INTAUTO_NAMESPACE_::intauto_t test(-7849031986324578909L);

    std::cerr << "Printing instance of intauto_t...\n";
    std::cerr << test << "\n\n";

    test = 0;

    std::cerr << "Printing instance of intauto_t...\n";
    std::cerr << test << "\n\n";

    test = 123456789;

    std::cerr << "Printing instance of intauto_t...\n";
    std::cerr << test << "\n\n";

    std::cerr << "Printing type of intmax_t...\n";
    std::cerr << typeid(intmax_t()).name() << "\n\n";

    std::cerr << "Printing size (in bits) of intmax_t...\n";
    std::cerr << std::pow(sizeof(intmax_t), 2) << "\n\n";
}
