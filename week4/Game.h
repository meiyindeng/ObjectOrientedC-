/**
 * C++ class for a game of the Tower of Hanoi puzzle.
 *
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#pragma once

#include "Stack.h"
#include "Instruction.h"
#include <vector>
#include <tuple>
#include <queue>

class Game {
public:
    Game();
    void solve();

    int DecodeInstruction(char);
    // An overloaded operator<<, allowing us to print the stack via `cout<<`:
    friend std::ostream& operator<<(std::ostream & os, const Game & game);
    std::vector<std::tuple<char, char, char>> instruction (int diskQuantity);




private:
    std::vector<Stack> pegs_;
};