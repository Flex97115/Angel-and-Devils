//
//  Gestion d'une partie.cpp
//  Angel and Devil
//
//  Created by Gery THRASIBULE on 04/03/2015.
//  Copyright (c) 2015 nowflare. All rights reserved.
//

#include "Gestion d'une partie.h"

/*--------------------------------------Partie----------------------------------------*/
Partie::Partie(){
    
}

Partie::Partie(int dimen , string pseudo1 , string pseudo2 , bool isSimpleAngel , int puissance = 0 , bool canResize = false){
    
    plateau = Plateau(dimen);
    if (canResize) {
        plateau = ++plateau;
        dimen += 2;
    }
    joueurs[1] = new Demon();
    
    if (isSimpleAngel) {
        setAnge(dimen);
    }
    else if (isSimpleAngel == false) {
        setAngePuissant(dimen, puissance);
    }
    
    joueurs[0]->setPseudo(pseudo1);
    joueurs[1]->setPseudo(pseudo2);
}

bool Partie::tourDeJeu(){
    plateau.affiche();
    cout << "\nL'ange Joue \n";
    joueurs[0]->jouer(plateau);
    cout << "\nLe demon Joue \n";
    joueurs[1]->jouer(plateau);

    return joueurs[0]->cantContinue(plateau);
}

void Partie::setAngePuissant(int dimen , int puissance){
    joueurs[0] = new angePuissant(dimen/2 , dimen/2 , puissance);
}

void Partie::setAnge(int dimen){
    joueurs[0] = new Ange(dimen/2 , dimen/2);
}
