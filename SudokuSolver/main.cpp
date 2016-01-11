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
#include "PuzzleParser.hpp"
#include <vector>

using namespace std;

void welcome() {
    cout << "Sudoku Solver by Geordi Dosher (C) 2016" << endl;
}

string askForPuzzleTypeInput() {
    cout << "Enter .txt filename from the puzzles folder" << endl;
    cout << "or type \'text\'to enter a puzzle manually" << endl;
    string input;
    cin >> input;
    
    if(input == "text") {
        cout << "Still working on it :( Try again later" << endl;
        return askForPuzzleTypeInput();
    } else {
        return input;
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...

    welcome();
    string filename = askForPuzzleTypeInput();
    
    PuzzleParser parser;
    Puzzle puzzle = parser.textFileParse(filename);
    
    cout << "starting alg on this puzzle\n";
    puzzle.printPuzzle();
    
    BasicAlgorithm alg;
    bool solved = alg.solvePuzzleBasicMethod(&puzzle);
    
    if(solved) {
        cout << "Puzzle was solved!\n";
    } else {
        cout << "Puzzle was unsolvable\n";
    }
    puzzle.printPuzzle();
    
    return 0;
}


