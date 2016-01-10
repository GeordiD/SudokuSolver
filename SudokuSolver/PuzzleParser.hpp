//
//  PuzzleParser.hpp
//  SudokuSolver
//
//  Created by George  Dosher III on 1/9/16.
//  Copyright © 2016 George  Dosher III. All rights reserved.
//

#ifndef PuzzleParser_hpp
#define PuzzleParser_hpp

#include <stdio.h>
#include "Puzzle.hpp"
using namespace std;

class PuzzleParser {
private:
    Puzzle parseString(string);
    string getFileContents(string);
public:
    Puzzle textFileParse(string);
};

#endif /* PuzzleParser_hpp */
