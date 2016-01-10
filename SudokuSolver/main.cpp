//
//  main.cpp
//  SudokuSolver
//
//  Created by George  Dosher III on 1/1/16.
//  Copyright © 2016 George  Dosher III. All rights reserved.
//

#include <iostream>
#include "cell.hpp"
#include "Puzzle.hpp"
#include "BasicAlgorithm.hpp"
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...

    Puzzle puzzle;

    
    cout << "starting alg on this puzzle";
    puzzle.printPuzzle();
    
    BasicAlgorithm alg;
    bool solved = alg.solvePuzzleBasicMethod(&puzzle);
    
    if(solved) {
        cout << "Puzzle was solved!\n";
    } else {
        cout << "Puzzle was unsolvable\n";
    }
    puzzle.printPuzzle();
    
//    std::vector<int> row = puzzle.getRow(5);
//    
//    for(int i = 0; i < row.size(); i++) {
//        cout << row[i];
//    }
//    cout << "\n";
    
    return 0;
}
