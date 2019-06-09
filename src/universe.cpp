#include <iostream>
#include <stdexcept>
#include "universe.h"

Universe::Universe()
{
    this->initFromUserInput();
}

void Universe::tick()
{
    this->expandUniverse();

    std::vector<std::vector<char>> tempUniverseRoot;
    for( int i = 0 ; i < this->universeRoot.size() ; ++i )
    {
        tempUniverseRoot.push_back(this->universeRoot[i]);
    }

    for( int i = 0 ; i < tempUniverseRoot.size() ; ++i )
    {
        for(int j = 0 ; j < tempUniverseRoot[0].size() ; ++ j)
        {
            int totalLiveNeighbours = 0;
            char leftTop = i-1 < 0 || j-1 < 0 || i-1 >= tempUniverseRoot.size() || j-1 >= tempUniverseRoot[0].size() ? ' ' : tempUniverseRoot[i-1][j-1];
            char rightTop = i-1 < 0 || j+1 < 0 || i-1 >= tempUniverseRoot.size() || j+1 >= tempUniverseRoot[0].size() ? ' ' : tempUniverseRoot[i-1][j+1];

            char leftBottom = i+1 < 0 || j-1 < 0 || i+1 >= tempUniverseRoot.size() || j-1 >= tempUniverseRoot[0].size() ? ' ' : tempUniverseRoot[i+1][j-1];
            char rightBottom = i+1 < 0 || j+1 < 0 || i+1 >= tempUniverseRoot.size() || j+1 >= tempUniverseRoot[0].size() ? ' ' : tempUniverseRoot[i+1][j+1];

            char left = i < 0 || j-1 < 0 || i >= tempUniverseRoot.size() || j-1 >= tempUniverseRoot[0].size() ? ' ' : tempUniverseRoot[i][j-1];
            char right = i < 0 || j+1 < 0 || i >= tempUniverseRoot.size() || j+1 >= tempUniverseRoot[0].size() ? ' ' : tempUniverseRoot[i][j+1];
            char top = i-1 < 0 || j < 0 || i-1 >= tempUniverseRoot.size() || j >= tempUniverseRoot[0].size() ? ' ' : tempUniverseRoot[i-1][j];
            char bottom = i+1 < 0 || j < 0 || i+1 >= tempUniverseRoot.size() || j >= tempUniverseRoot[0].size() ? ' ' : tempUniverseRoot[i+1][j];

            if( leftTop == LIFE )
                totalLiveNeighbours ++;
            if( rightTop == LIFE )
                totalLiveNeighbours ++;
            if( leftBottom == LIFE )
                totalLiveNeighbours ++;
            if( rightBottom == LIFE )
                totalLiveNeighbours ++;
            if( left == LIFE )
                totalLiveNeighbours ++;
            if( right == LIFE )
                totalLiveNeighbours ++;
            if( top == LIFE )
                totalLiveNeighbours ++;
            if( bottom == LIFE )
                totalLiveNeighbours ++;

            if( this->universeRoot[i][j] == LIFE )
            {
                if(totalLiveNeighbours < 2 || totalLiveNeighbours > 3 )
                {
                    this->universeRoot[i][j] = DEATH;
                }
            }

            else if( this->universeRoot[i][j] == DEATH )
            {
                if( 3 == totalLiveNeighbours )
                {
                    this->universeRoot[i][j] = LIFE;
                }
            }

            else
            {
                throw std::invalid_argument("Invalid life state for Universe");
            }
        }
    }
}

void Universe::print()
{
    std::cout << std::endl;
    for(std::vector<char> line : this->universeRoot)
    {
        for (char character : line)
        {
            std::cout << character << " ";
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Universe::expandUniverse()
{
    int currentWidth  = this->universeRoot[0].size();

    for(std::vector<char> &line : this->universeRoot)
    {
        line.insert(line.begin(),DEATH);
        line.push_back(DEATH);
    }

    std::vector<char> line (currentWidth + 2 , DEATH);
    this->universeRoot.insert(this->universeRoot.begin(),line);
    this->universeRoot.push_back(line);
}

void Universe::initFromUserInput()
{
    std::string line;
    unsigned int lengthOfLine = 0;

    while (getline(std::cin, line))
    {
        if (0 == lengthOfLine)
        {
            lengthOfLine = line.length();
        }

        else
        {
            if (line.length() != lengthOfLine)
            {
                throw std::invalid_argument("All lines in input should have same number of characters.");
            }
        }

        std::vector<char> charStoreage;
        for (char inputChar : line)
        {
            charStoreage.push_back(inputChar);
        }

        this->universeRoot.push_back(charStoreage);
    }
}
