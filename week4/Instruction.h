//
// Created by Meiyin Deng on 2020-03-08.
//
#include <tuple>
#include <iostream>

#ifndef WEEK4_INSTRUCTION_H
#define WEEK4_INSTRUCTION_H



class Instruction {
    public:
        std::tuple<char, char, char> originalTuple;
        Instruction();
        Instruction(char fromPeg, char toPeg, char helperPeg);
        Instruction(std::tuple<char, char, char> parentTuple);
        std::tuple<char, char, char> RearrangeTuple();
        std::tuple<char, char, char> RearrangeTuple2();
        std::tuple<char, char, char> RearrangeTuple3();

};


#endif //WEEK4_INSTRUCTION_H
