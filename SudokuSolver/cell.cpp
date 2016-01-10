//
//  cell.cpp
//  SudokuSolver
//
//  Created by George  Dosher III on 1/1/16.
//  Copyright © 2016 George  Dosher III. All rights reserved.
//

#include "cell.hpp"
#include <stdexcept>

Cell::Cell() {
    
}

Cell::Cell(int x,int y,int value,int layer) {
    setX(x);
    setY(y);
    setValue(value);
    setLayer(layer);
}

int Cell::getX() {
    return x;
}

int Cell::getY() {
    return y;
}

int Cell::getValue(){
    return value;
}

int Cell::getLayer() {
    return layer;
}

void Cell::setX(int n){
    if(n >= 0 && n <= 8) {
        x = n;
    } else {
        throw std::invalid_argument("x must be set between 1-9");
    }
}

void Cell::setY(int n){
    if(n >= 0 && n <= 8) {
        y = n;
    } else {
        throw std::invalid_argument("y must be set between 1-9");
    }
}

void Cell::setValue(int n){
    if(n >= 0 && n <= 9) {
        value = n;
    } else {
        throw std::invalid_argument("value must be set between 0-9");
    }
}

void Cell::setLayer(int n){
    if(n >= 0) {
        layer = n;
    } else {
        throw std::invalid_argument("x must be positive");
    }
}