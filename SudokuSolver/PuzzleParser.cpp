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
    cout << "filename = " << filename << endl;
    return parseString(getFileContents(filename));
}

string PuzzleParser::getFileContents(string filename) {
    ifstream file(filename);
    string output;
    output.assign((istreambuf_iterator<char>(file)), (istreambuf_iterator<char>()));
    return output;
}

Puzzle PuzzleParser::parseString(string data) {
    Puzzle puzzle;
    std::vector<int> buffer;
    
    data.erase(std::remove(data.begin(), data.end(), '\n'), data.end());
    
    for(char& c : data) {
        if(c == '.') {
            if(buffer.size() == 3) {
                int x,y,val;
                
                val = buffer.back() - '0';
                buffer.pop_back();
                y = buffer.back() - '0';
                buffer.pop_back();
                x = buffer.back() - '0';
                buffer.pop_back();
                buffer.clear();
                
                puzzle.setFixedCell(x, y, val);
            } else {
                throw std::invalid_argument("Found invalid character in string");
            }
        } else if (isdigit(c)) {
            if(buffer.size() < 3) {
                buffer.push_back(c);
            } else {
                throw std::invalid_argument("Found invalid character in string");
            }
        } else {
            throw std::invalid_argument("Found invalid character in string");
        }
    }
    
    return puzzle;
}