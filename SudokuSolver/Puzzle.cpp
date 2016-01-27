//
//  Puzzle.cpp
//  SudokuSolver
//
//  Created by George  Dosher III on 1/1/16.
//  Copyright © 2016 George  Dosher III. All rights reserved.
//

#include "Puzzle.hpp"
#include <stdexcept>
#include <iostream>

typedef std::vector<int> intvec;

//std::vector< std::vector<int> > cells(9, std::vector<int>(9)); //first is row, second is column

Puzzle::Puzzle() {
    //Test Puzzle. Parser to be built later.
    //Set each cell to unfixed and 0;
    for(int x = 0; x < 9; x++) {
        for(int y = 0; y < 9; y++) {
            cells[x][y] = Cell(x,y,0,1);
        }
    }
    
//    //TESTING:
//    intvec row = getRow(2);
//    intvec col = getCol(2);
//    intvec box = getBox(2,2);
//    bool rowOk = isSetOk(getRow(2));
//    bool boxOk = isSetOk(getBox(2,2));
//    bool cellok = isCellOk(2,2);
//    std::vector<Cell*> arr = getArrUnfixedCellPointers();
//    printPuzzle();
}

void Puzzle::setFixedCell(int x, int y, int val) {
    cells[x][y] = Cell(x,y,val,0);
    if(!isCellOk(x, y)) {
        //This cell is not valid - throw exception
        throw std::invalid_argument("Setting this cell as fixed makes puzzle invalid");
    }
}

intvec Puzzle::getRow(int n) {
    if(n<0 || n>8) {
        throw std::invalid_argument("Row must be between 0 and 8");
    }
    intvec rowOut(9);
    for(int col = 0; col < 9; col++) {
        rowOut[col] = cells[n][col].getValue();
    }
    return rowOut;
}

intvec Puzzle::getBox(int x, int y) {
    if(x<0 || x>8 || y<0 || y>8) {
        throw std::invalid_argument("X and y values must be between 0-8");
    }
    
    intvec output(9);
    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            int lowX = i * 3;
            int hiX = (i+1)*3-1;
            int lowY = j * 3;
            int hiY = (j+1)*3-1;
            
            if(x >= lowX && x <= hiX &&
               y >= lowY && y <= hiY) {
                //correct box
                int index = 0;
                for(int m = lowX; m <= hiX; m++) {
                    for(int n = lowY; n <= hiY; n++) {
                        output[index] = cells[m][n].getValue();
                        index++;
                    }
                }
                return output;
            }
        }
    }
    
    throw("Unexpected code path in getBox. Couldn't find box");
}

intvec Puzzle::getCol(int n) {
    if(n<0 || n>8) {
        throw std::invalid_argument("Col must be between 0 and 8");
    }
    intvec arr(9);
    for(int row = 0; row < 9; row++ ) {
        arr[row] = cells[row][n].getValue();
    }
    return arr;
}

bool Puzzle::isSetOk(intvec arr) {
    for(int i = 0; i < arr.size() - 1; i++) {
        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[i] == 0 || arr[j] == 0) continue;
            if(arr[i] == arr[j])
                return false;
        }
    }
    return true;
}

bool Puzzle::isCellOk(int x, int y) {
    return isSetOk(getRow(x)) && isSetOk(getCol(y)) && isSetOk(getBox(x,y));
}

std::vector<Cell*> Puzzle::getArrUnfixedCellPointers() {
    std::vector<Cell*> output;
    
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if(cells[i][j].getLayer() != 0) {
                output.push_back(&cells[i][j]);
            }
        }
    }
    
    return output;
}

void Puzzle::printPuzzle() {
    std::cout << "Printing puzzle =====|\n";
    
    for(int x = 0; x < 9 ; x++) {
        for(int y = 0; y < 9; y++) {
            std::cout << cells[x][y].getValue();
            std::cout << " ";
        }
        std::cout << "\n";
    }
    
    std::cout<<"=====\n";
}

