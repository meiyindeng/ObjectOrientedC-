//
// Created by Meiyin Deng on 2020-03-08.
//

#include "Instruction.h"

Instruction::Instruction() {
    std::get<0> (originalTuple) = 'X';
    std::get<1> (originalTuple) = 'X';
    std::get<2> (originalTuple) = 'X';
}

Instruction::Instruction(char fromPeg, char toPeg, char helperPeg) {
    std::get<0> (originalTuple) = fromPeg;
    std::get<1> (originalTuple) = toPeg;
    std::get<2> (originalTuple) = helperPeg;
}

Instruction::Instruction(std::tuple<char, char, char> parentTuple){
    std::get<0> (originalTuple) = std::get<0> (parentTuple);
    std::get<1> (originalTuple) = std::get<1> (parentTuple);
    std::get<2> (originalTuple) = std::get<2> (parentTuple);

}

std::tuple<char, char, char> Instruction::RearrangeTuple(){
    std::tuple<char, char, char> newTuple1 = std::make_tuple(std::get<0> (originalTuple), std::get<2> (originalTuple), std::get<1> (originalTuple));
    //std::cout << std::get<0>(newTuple1) << " , " << std::get<1>(newTuple1)  << " , " << std::get<2>(newTuple1) << std::endl;
    return newTuple1;
}

std::tuple<char, char, char> Instruction::RearrangeTuple2(){
    std::tuple<char, char, char> newTuple2 = std::make_tuple(std::get<0> (originalTuple), std::get<1> (originalTuple), std::get<2> (originalTuple));
    //std::cout << std::get<0>(newTuple2) << " , " << std::get<1>(newTuple2)  << " , " << std::get<2>(newTuple2) << std::endl;
    return newTuple2;
}

std::tuple<char, char, char> Instruction::RearrangeTuple3(){
    std::tuple<char, char, char> newTuple3 = std::make_tuple(std::get<2> (originalTuple), std::get<1> (originalTuple), std::get<0>(originalTuple));
    //std::cout << std::get<0>(newTuple3) << " , " << std::get<1>(newTuple3)  << " , " << std::get<2>(newTuple3) << std::endl;
    return newTuple3;
}


