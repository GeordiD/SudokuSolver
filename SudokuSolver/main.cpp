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

typedef chrono::high_resolution_clock mytime;

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
        return "puzzleTxtFiles/" + input;
    }
}

chrono::milliseconds getTime() {
    return chrono::duration_cast<chrono::milliseconds>
        (chrono::system_clock::now().time_since_epoch());
}

void programLoop() {
    string filename = askForPuzzleTypeInput();
    
    PuzzleParser parser;
    Puzzle puzzle = parser.textFileParse(filename);
    
    
    cout << "starting alg on this puzzle\n";
    puzzle.printPuzzle();
    
    auto startTime = mytime::now();
    BasicAlgorithm alg;
    bool solved = alg.solvePuzzleBasicMethod(&puzzle);
    
    if(solved) {
        cout << "Puzzle was solved!\n";
        
        auto endTime = mytime::now();
        chrono::milliseconds ms = chrono::duration_cast<chrono::milliseconds>(endTime - startTime);
        double seconds = ms.count() / 1000.0;
        
        cout << "Solved in " << seconds << " seconds" << endl;
        puzzle.printPuzzle();
    } else {
        cout << "Puzzle was unsolvable\n";
    }
}

void serverApp(string input) {
    PuzzleParser parser;
    Puzzle puzzle = parser.parseString(input);
    BasicAlgorithm alg;
    
    if(alg.solvePuzzleBasicMethod(&puzzle)) {
        cout << puzzle.getPuzzleOutput();
        return;
    } else {
        cout << "US" << endl;
    }
}

int main(int argc, const char * argv[]) {
    if(argc > 2) {
        return 2;
    }
    
    string input = "";
    if(argc == 2) {
        input = argv[1];
    }
    
    try {
        serverApp(input);
    } catch (std::exception e) {
        return 1;
    }
    
    
    return 0;
}


