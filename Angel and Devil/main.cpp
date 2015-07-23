//
//  main.cpp
//  Angel and Devil
//
//  Created by Gery THRASIBULE on 04/03/2015.
//  Copyright (c) 2015 nowflare. All rights reserved.
//

#include <iostream>
#include "Gestion d'une partie.h"


int main(int argc, const char * argv[]) {
    bool game = false;
    string pseudo1 = "";
    string pseudo2 = "";
    int numOfAnge = 0;
    int puissance = 0;
    int choix = 0;
    bool canResize = false;
    
    Partie partie = *new Partie();
    
    cout << "\nEntrez le pseudo du premier joueur (l\'ange) : ";
    cin >> pseudo1;
    
    cout << "\nEntrez le pseudo du deuxième joueur (le demon) : ";
    cin >> pseudo2;
    
    do {
        cout << "\n1. Oui \n2. Non\nLe demon veut t'il agrandir le plateau de 2 rang ( Tapez le chiffre ) ? ";
        cin >> choix;
    } while (choix != 1 && choix != 2);
    
    if (choix == 1) {
        canResize = true;
    }
    else if (choix == 2){
        canResize = false;
    }
    
    
    do {
        cout << "\n1. Ange simple \n2. Ange puissant\nJouer avec ( Tapez le chiffre ) : ";
        cin >> numOfAnge;
    } while (numOfAnge != 1 && numOfAnge != 2);
    
    if (numOfAnge == 1) {
        partie = *new Partie(35, pseudo1, pseudo2 , true , 0 , canResize);
    }
    else if (numOfAnge == 2){
        do {
            cout << "\nDe quel puissance voulez-vous que votre ange soit ( Tapez un nombre ) : ";
            cin >> puissance;
        } while (puissance == 0);
        partie = *new Partie(35, pseudo1, pseudo2 , false , puissance , canResize);
    }
    
    do {
        game = partie.tourDeJeu();
    } while (game == false);
    
    
    
    
    return 0;
}

