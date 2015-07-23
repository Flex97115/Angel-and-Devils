//
//  Gestion du plateau.cpp
//  Angel and Devil
//
//  Created by Gery THRASIBULE on 04/03/2015.
//  Copyright (c) 2015 nowflare. All rights reserved.
//

#include "Gestion du plateau.h"

/*--------------------------------------CASE----------------------------------------*/

Case::Case(){
    broken = false;
    free = true;
}
Case::Case(bool isBroken , bool isFree){
    free = isFree;
    broken = isBroken;
}

bool Case::getFree(){
    return free;
}

bool Case::getBroken(){
    return broken;
}

void Case::setBroken(bool isBroken){
    broken = isBroken;
}

void Case::setFree(bool isFree){
    free = isFree;
}

Plateau::Plateau() {
    dim = 35;
    gameboard = new Case*[dim];
    for (int a = 1; a <= dim; a++) {
        gameboard[a] = new Case[dim];
    }
    
    for (int i = 1; i <= dim; i++) {
        for (int j = 1; j <= dim; j++) {
            if ( i == dim/2 && j == dim/2) {
                gameboard[i][j] = *new Case(false , false);
            }
            else{
                gameboard[i][j] = *new Case();
            }
        }
    }
}

/*--------------------------------------PLATEAU----------------------------------------*/

Plateau::Plateau(int dimension){
    dim = dimension;
    if (dim < 0) {
        dim = (int)fabsf(dim);
    }
    if (dim%2 == 0) {
        dim += 1;
    }
    if (dim > 0 && dim%2 != 0) {
        gameboard = new Case*[dim];
        for (int a = 1; a <= dim; a++) {
            gameboard[a] = new Case[dim];
        }
        for (int i = 1; i <= dim; i++) {
            for (int j = 1; j <= dim; j++) {
                if ( i == dim/2 && j == dim/2) {
                    gameboard[i][j] = *new Case(false , false);
                }
                else{
                    gameboard[i][j] = *new Case();
                }
            }
        }
    }
}

Plateau& Plateau::operator++(){
    dim += 2;
    *this = *new Plateau(dim);
    return *this;
}
Plateau::~Plateau(){
}

void Plateau::affiche(){
    for (int i = 1; i <= dim; i++) {
        for (int j = 1; j <= dim; j++) {
            if (gameboard[i][j].getBroken() == true) {
                cout << "x";
            }
            else if (gameboard[i][j].getFree() == false) {
                cout << "o";
            }
            else{
                cout << ".";
            }
        }
        cout << "\n";
    }
}

int Plateau::getDim(){
    return dim;
}
void Plateau::setDim(int dimension){
    dim = dimension;
}

void Plateau::setCase(int x, int y , bool isFree , bool isBroken){
    gameboard[x][y].setBroken(isBroken);
    gameboard[x][y].setFree(isFree);
}

bool Plateau::getBrokenCase(int x, int y){
    return gameboard[x][y].getBroken();
}

bool Plateau::getFreeCase(int x, int y){
    return gameboard[x][y].getFree();
}
