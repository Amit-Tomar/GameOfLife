#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <vector>
#define LIFE 'x'
#define DEATH '-'

class Universe
{
	public:
		Universe();
        void tick();
		void print();

	private:
        void initFromUserInput();
        void expandUniverse();
        void contractUniverse();
        std::vector<std::vector<char>> universeRoot;
};

#endif
