#include <iostream>
#include <stdexcept>

#include "universe.h"

int main()
{
	Universe universe;
	universe.print();
    universe.tick();
    universe.print();

    return 0;
}
