//
//  cell.hpp
//  SudokuSolver
//
//  Created by George  Dosher III on 1/1/16.
//  Copyright © 2016 George  Dosher III. All rights reserved.
//

#ifndef cell_hpp
#define cell_hpp

#include <stdio.h>

class Cell {
private:
    int x, y; //The location in the puzzle. pos 1-9
    int value; //The number in the cell. 0 if
    int layer; //The pass in which the the cell's value was added. 0 = part of puzzle.
public:
    Cell();
    Cell(int, int,int,int);
    int getX();
    int getY();
    int getValue();
    int getLayer();
    void setX(int);
    void setY(int);
    void setValue(int);
    void setLayer(int);
};

#endif /* cell_hpp */


