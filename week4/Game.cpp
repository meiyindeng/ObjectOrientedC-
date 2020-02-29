/**
 * C++ class for a game of the Tower of Hanoi puzzle.
 *
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "Game.h"
#include "Stack.h"
#include "Cube.h"
#include "HSLAPixel.h"

#include <iostream>
using std::cout;
using std::endl;

// Solves the Tower of Hanoi puzzle.
// (Feel free to call "helper functions" to help you solve the puzzle.)
void Game::solve() {
    // Prints out the state the game:
    Stack& first = stacks_[0];
    Stack& second = stacks_[1];
    Stack& third = stacks_[2];
    while(third.size()!=4){
        if(isEmptyStack(third)) {
            Cube top = first.removeTop();
            third.push_back(top);
        }
        if(isEmptyStack(second)){
            Cube top = first.removeTop();
            second.push_back(top);
        }
        Cube stack1cube = first.peekTop();
        Cube stack2cube = second.peekTop();
        Cube stack3cube = third.peekTop();
        if (stack2cube.getLength() < stack3cube.getLength()) {
            third.push_back(second.removeTop());
        }
        else{
            int stack2size = stack1cube.getLength()-1;
        }


    }

    cout << *this << endl;

    // @TODO -- Finish solving the game!
}




// Default constructor to create the initial state:
Game::Game() {
    // Create the three empty stacks:
    for (int i = 0; i < 3; i++) {
        Stack stackOfCubes;
        stacks_.push_back( stackOfCubes );
    }

    // Create the four cubes, placing each on the [0]th stack:
    Cube blue(4, uiuc::HSLAPixel::BLUE);
    stacks_[0].push_back(blue);

    Cube orange(3, uiuc::HSLAPixel::ORANGE);
    stacks_[0].push_back(orange);

    Cube purple(2, uiuc::HSLAPixel::PURPLE);
    stacks_[0].push_back(purple);

    Cube yellow(1, uiuc::HSLAPixel::YELLOW);
    stacks_[0].push_back(yellow);
}

bool Game::isEmptyStack(Stack stack) {
    return stack.size()==0;
}

bool Game::isSmallCube(Cube &a, Cube &b) {
    return a.getLength() < b.getLength();
}




std::ostream& operator<<(std::ostream & os, const Game & game) {
    for (unsigned i = 0; i < game.stacks_.size(); i++) {
        os << "Stack[" << i << "]: " << game.stacks_[i];
    }
    return os;
}
