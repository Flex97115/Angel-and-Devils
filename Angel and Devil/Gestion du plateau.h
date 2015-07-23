//
//  Gestion du plateau.h
//  Angel and Devil
//
//  Created by Gery THRASIBULE on 04/03/2015.
//  Copyright (c) 2015 nowflare. All rights reserved.
//

#ifndef __Angel_and_Devil__Gestion_du_plateau__
#define __Angel_and_Devil__Gestion_du_plateau__

#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>
using namespace std;

/*--------------------------------------CASE----------------------------------------*/
class Case {
private:
    bool broken;
    bool free;
public:
    Case();
    Case(bool isBroken , bool isFree);
    bool getFree();
    bool getBroken();
    void setFree(bool isFree);
    void setBroken(bool isBroken);
    
    
};

/*--------------------------------------PLATEAU----------------------------------------*/
class Plateau {
private:
    Case **gameboard;
    int dim;
public:
    Plateau();
    Plateau(int dimension);
    ~Plateau();
    Plateau& operator++();
    int getDim();
    void setDim(int dimension);
    void affiche();
    void setCase(int x, int y , bool isFree , bool isBroken);
    bool getBrokenCase ( int x , int y);
    bool getFreeCase ( int x , int y);
};

#endif /* defined(__Angel_and_Devil__Gestion_du_plateau__) */
