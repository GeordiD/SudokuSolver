 //
//  BasicAlgorithm.cpp
//  SudokuSolver
//
//  Created by George  Dosher III on 1/9/16.
//  Copyright © 2016 George  Dosher III. All rights reserved.
//

#include <iostream>
#include "BasicAlgorithm.hpp"
#include "Cell.hpp"

bool BasicAlgorithm::solvePuzzleBasicMethod(Puzzle *puzzle) {
    //arr array of pointers pointing to each non-fixed cell in the puzzle;
    std::vector<Cell*> arr = puzzle->getArrUnfixedCellPointers();
    
    for(int i = 0; i < arr.size(); /*nothing*/) {
        Cell *curr = arr[i];
        //If cell is at 0, cell value ++ will make it one.
        //If cell value is already set, we are coming back to it and need to
        //    iterate from where we were.  Check to make sure we haven't gone
        //    past 9 though
        
        bool cellIsOk = false;
        bool goBack = false;
        while(!cellIsOk) {
            int newValue = curr->getValue() + 1;
            if(newValue > 9) {
                curr->setValue(0); //reset value
                if(i <= 0) {
                    //unsolvable
                    std::cout << "RETURNING FALSE AT CELL(" << curr->getX() << "," << curr->getY() << ")\n";
                    return false;
                } else {
                    i--; //Go back to the last cell
                    goBack = true; //signal going back
                    break;
                }
            } else {
                //Check if it fits in the puzzle.
                curr->setValue(newValue);
                cellIsOk = puzzle->isCellOk(curr->getX(), curr->getY());
            }
        }
        
        if(!goBack) {
//            std::cout << "Cell(" << curr->getX() << "," << curr->getY() << ") newValue = "
//                    << curr->getValue() << "\n";
            i++;
        } else {
//            std::cout << "Cell(" << curr->getX() << "," << curr->getY() << ") goBack\n";
        }
    }
    
    return true;
}