//
//  Gestion d'une partie.h
//  Angel and Devil
//
//  Created by Gery THRASIBULE on 04/03/2015.
//  Copyright (c) 2015 nowflare. All rights reserved.
//

#ifndef __Angel_and_Devil__Gestion_d_une_partie__
#define __Angel_and_Devil__Gestion_d_une_partie__

#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>
#include "Gestion du plateau.h"
#include "Gestion des joueurs.h"

using namespace std;

/*--------------------------------------PARTIE----------------------------------------*/
class Partie{
private:
    Plateau plateau;
    Joueur *joueurs[2];
public:
    Partie();
    Partie( int dimen , string pseudo1 , string pseudo2 , bool isSimpleAngel , int puissance , bool canResize);
    bool tourDeJeu();
    bool partieTerminee();
    void setAngePuissant(int dimen ,  int puissance);
    void setAnge(int dimen);
    
    
};

#endif /* defined(__Angel_and_Devil__Gestion_d_une_partie__) */
