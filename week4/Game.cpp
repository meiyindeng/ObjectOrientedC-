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
#include <vector>
#include <iostream>

using std::cout;
using std::endl;



// Solves the Tower of Hanoi puzzle.
// (Feel free to call "helper functions" to help you solve the puzzle.)
std::vector<std::tuple<char, char, char>> Game::instruction (int diskQuantity){
    std::vector<std::tuple<char, char, char>> listOfTuple;

    Instruction one('A', 'B', 'C');
    listOfTuple.push_back(one.originalTuple);


    while(diskQuantity != 1) {

        std::queue<std::tuple<char, char, char>> queueOfTuple;
        for (int index = 0; index < listOfTuple.size(); index++) {

            if ((index % 2) == 0) {
                Instruction two = listOfTuple[index];
                std::tuple<char, char, char> newTuple = two.RearrangeTuple();
                std::tuple<char, char, char> newTuple2 = two.RearrangeTuple2();
                std::tuple<char, char, char> newTuple3 = two.RearrangeTuple3();
                queueOfTuple.push(newTuple);
                queueOfTuple.push(newTuple2);
                queueOfTuple.push(newTuple3);
            }

            if (index % 2 != 0) {
                queueOfTuple.push(listOfTuple[index]);
            }

        }
        listOfTuple.resize(queueOfTuple.size());
        for (int i = 0; i < listOfTuple.size(); i++) {

            listOfTuple[i] = queueOfTuple.front();
            queueOfTuple.pop();
        }

        diskQuantity--;
    }

    return listOfTuple;
}


void Game::solve() {
    // Prints out the state the game:
    std::vector<std::tuple<char, char, char>> moveInstruction = instruction(4);
    for (int moveNumber = 0; moveNumber < moveInstruction.size(); moveNumber++){
        int instruction1 = DecodeInstruction(std::get<0> (moveInstruction[moveNumber]));
        int instruction2 = DecodeInstruction(std::get<1> (moveInstruction[moveNumber]));
        Stack& fromPeg = pegs_[instruction1];
        Stack& toPeg = pegs_[instruction2];
        Cube movingDisk = fromPeg.removeTop();
        toPeg.push_back(movingDisk);
        cout << *this << endl;
    }

    // @TODO -- Finish solving the game!
}




// Default constructor to create the initial state:
Game::Game() {
    // Create the three empty stacks:
    for (int i = 0; i < 3; i++) {
        Stack stackOfCubes;
        pegs_.push_back( stackOfCubes );
    }

    // Create the four cubes, placing each on the [0]th stack:
    Cube blue(4, uiuc::HSLAPixel::BLUE);
    pegs_[0].push_back(blue);

    Cube orange(3, uiuc::HSLAPixel::ORANGE);
    pegs_[0].push_back(orange);

    Cube purple(2, uiuc::HSLAPixel::PURPLE);
    pegs_[0].push_back(purple);

    Cube yellow(1, uiuc::HSLAPixel::YELLOW);
    pegs_[0].push_back(yellow);
}



std::ostream& operator<<(std::ostream & os, const Game & game) {
    for (unsigned i = 0; i < game.pegs_.size(); i++) {
        os << "Stack[" << i << "]: " << game.pegs_[i];
    }
    return os;
}

int Game::DecodeInstruction(char pegName) {
    int pegID = 0;
    switch(pegName){
        case 'A':
            pegID = 0;
            break;
        case 'B':
            pegID = 1;
            break;
        case 'C':
            pegID = 2;
            break;
    }
    return pegID;
}






