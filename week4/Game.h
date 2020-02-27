/**
 * C++ class for a game of the Tower of Hanoi puzzle.
 *
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#pragma once

#include "Stack.h"
#include <vector>

class Game {
public:
    Game();
    void solve();
    bool isEmptyStack(Stack stack);
    //if the cube is smaller than the top cube in the next stack, the cube can move to the next stack
    bool isSmallCube(Cube& a, Cube& b);
    void transferTopCubetoNextStack(int current, Cube& top);

    // An overloaded operator<<, allowing us to print the stack via `cout<<`:
    friend std::ostream& operator<<(std::ostream & os, const Game & game);

private:
    std::vector<Stack> stacks_;
};