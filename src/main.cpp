#include <iostream>
#include <stdexcept>

#include "universe.h"

int main()
{
	Universe universe;
	std::cout << "Universe input state" << std::endl;
	universe.print();
    universe.tick();
	std::cout << "Universe state after a tick" << std::endl;
    universe.print();

	// Pass the path of file which has expected outputs. (No space between character or at the end of line)
	universe.validateUniverseFromFile("../testCaseOutputs/testToad.txt");

	return 0;
}
