//
//  Puzzle.hpp
//  SudokuSolver
//
//  Created by George  Dosher III on 1/1/16.
//  Copyright © 2016 George  Dosher III. All rights reserved.
//

#ifndef Puzzle_hpp
#define Puzzle_hpp

#include <stdio.h>
#include "cell.hpp"
#include <vector>

typedef std::vector<int> intvec;

class Puzzle {
private:
    Cell cells[9][9];
    intvec getRow(int);
    intvec getCol(int);
    intvec getBox(int,int);
    bool isSetOk(intvec);
public:
    Puzzle();
    bool isCellOk(int,int);
    void setFixedCell(int,int,int);
    std::vector<Cell*> getArrUnfixedCellPointers();
    void printPuzzle();
    std::string getPuzzleOutput();
};

#endif /* Puzzle_hpp */


