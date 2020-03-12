/**
 * Simple main to create and solve a game of the Tower of Hanoi puzzle.
 *
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

#include "Game.h"
#include "Instruction.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <queue>




/*void PrintInstruction (std::vector<std::tuple<char, char, char>> listOfTuple){
    for (int i = 0; i < listOfTuple.size(); i++){
        std::cout << std::get<0>(listOfTuple[i]) << ", " <<  std::get<1>(listOfTuple[i]) << ", " <<
        std::get<2>(listOfTuple[i]) << std::endl;
    }
}
*/






int main() {

    Game g;

    std::cout << "Initial game state: " << std::endl;
    std::cout << g << std::endl;

    g.solve();

    std::cout << "Final game state: " << std::endl;
    std::cout << g << std::endl;




    return 0;
}