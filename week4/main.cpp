/**
 * Simple main to create and solve a game of the Tower of Hanoi puzzle.
 *
 * @author
 *   Wade Fagen-Ulmschneider <waf@illinois.edu>
 */

//#include "Game.h"
#include <iostream>
#include <vector>

std::vector<int> CalculateMoveSequence(int n){
    std::vector<int> moveSequence;
    if(n<=0){
        return moveSequence;
    }
    if(n==1){

        moveSequence.push_back(n);

        return moveSequence;
    }
    else{
        std::vector<int> prevSequence = CalculateMoveSequence(n-1);

        for(auto& x :prevSequence){
            moveSequence.push_back(x);
        }

        moveSequence.push_back(n);

        for(auto& x :prevSequence){
            moveSequence.push_back(x);
        }

        return moveSequence;
    }
}


int main() {
    /*Game g;

    std::cout << "Initial game state: " << std::endl;
    std::cout << g << std::endl;

    g.solve();

    std::cout << "Final game state: " << std::endl;
    std::cout << g << std::endl;*/
    std::vector<int> sequence = CalculateMoveSequence(3);
    for (int i = 0; i < sequence.size(); i++){
        std::cout << sequence[i] << ", ";
    }




    return 0;
}