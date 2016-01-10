//
//  PuzzleParser.cpp
//  SudokuSolver
//
//  Created by George  Dosher III on 1/9/16.
//  Copyright © 2016 George  Dosher III. All rights reserved.
//

#include "PuzzleParser.hpp"
#include <iostream>
#include <string>
#include <fstream>

Puzzle PuzzleParser::textFileParse(string filename) {
    return parseString(getFileContents(filename));
}

string PuzzleParser::getFileContents(string filename) {
    ifstream file(filename);
    string output;
    output.assign((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
    return output;
}

Puzzle PuzzleParser::parseString(string data) {
    //TODO make parsing logic
    //data should contain data of file
    return Puzzle();
}