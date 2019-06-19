#To Build

1. Go to src folder

2. g++ -std=c++11 main.cpp universe.cpp

3. ./a.out < ../testCaseInputs/testToad.txt

Inputs are to be given by redirecting the file to console. This code will first print the input state of universe, followed by the next tick value, in console.

4. To validate the output of this program, call the validation function with the path to file having expected final state of universe after tick. Note that no other character other than LIFE or DEATH characters should be present in the file (eg. whitespace between characters or at end of line)

example: universe.validateUniverseFromFile("../testCaseOutputs/testToad.txt");

