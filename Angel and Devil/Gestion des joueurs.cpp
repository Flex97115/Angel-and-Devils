//
//  Gestion des joueurs.cpp
//  Angel and Devil
//
//  Created by Gery THRASIBULE on 04/03/2015.
//  Copyright (c) 2015 nowflare. All rights reserved.
//

#include "Gestion des joueurs.h"

/*--------------------------------------JOUEUR----------------------------------------*/

Joueur::Joueur(){
}

void Joueur::saisir(int &ligne , int &colonne){
    ligne =0;
    colonne = 0;
    cout << "\nEntrez une ligne puis une colonne :"<< endl;
    cout << "Ligne : ";
    cin >> ligne;
    cout << "Colonne : ";
    cin >> colonne;
    
}

void Joueur::choisirCase( int &ligne , int &colonne, Plateau &plateau){
    bool isCorrect = false;
    do{
        saisir(ligne , colonne);
        isCorrect = incorrect(ligne, colonne , plateau);
    }while ( isCorrect == false);
}
void Joueur::jouer(Plateau &plateau){
    int ligne = NULL;
    int colonne = NULL;
    choisirCase(ligne , colonne, plateau);
    modifierCase(ligne ,colonne, plateau);
}

void Joueur::setPseudo(string set_pseudo){
    pseudo = set_pseudo;
}

/*--------------------------------------ANGE----------------------------------------*/

Ange::Ange(int x , int y ){
    ligneA = x;
    colonneA = y;
}

bool Ange::incorrect(int x , int y , Plateau &plateau) {
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (ligneA+i == x && colonneA+j == y ) {
                if (plateau.getBrokenCase(x, y) == false && plateau.getFreeCase(x, y) == true) {
                    return true;
                }
            }
        }
    }
    cout << "\nVoila vos coordonnées recommencez\nligne :" << ligneA << "\nColonne :" << colonneA << "\n";
    return false;
}

void Ange::modifierCase( int &ligne , int &colonne, Plateau &plateau){
    plateau.setCase(ligneA, colonneA, true, false);
    ligneA = ligne;
    colonneA = colonne;
    plateau.setCase(ligneA, colonneA, false, false);
}

bool Ange::cantContinue( Plateau &plateau ){
    return (won(plateau)||loose(plateau));
}

bool Ange::won(Plateau &plateau){
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (ligneA+i < 1 || ligneA+i > plateau.getDim() || colonneA+j < 1 || colonneA+j > plateau.getDim() ) {
                cout << "\n\nL\'Ange a gagné ! \n";
                return true;
            }
        }
    }
    
    return false;
}
bool Ange::loose(Plateau &plateau){
    
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (plateau.getFreeCase(ligneA+i, colonneA+j) == true) {
                return false;
            }
        }
    }
    cout << "\n\nLe Demon a gagné ! \n";
    return true;
}

/*--------------------------------------DEMON----------------------------------------*/

Demon::Demon(){
}

bool Demon::incorrect(int x ,int y, Plateau &plateau ){
    
    if (x >= 1 && x <= plateau.getDim() && y >= 1 && y <= plateau.getDim() ) {
        if (plateau.getFreeCase(x, y) == true && plateau.getBrokenCase(x, y) == false) {
            return true;
        }
    }
    return false;
}

void Demon::modifierCase(int &ligne , int &colonne,Plateau &plateau){
    plateau.setCase(ligne, colonne, false, true);
}
bool Demon::cantContinue(Plateau &plateau){
    return false;
}

/*--------------------------------------ANGE PUISSANT----------------------------------------*/

angePuissant::angePuissant(int x , int y, int puiss) : Ange(x , y){
    ligneA = x;
    colonneA = y;
    puissance = puiss;
}

bool angePuissant::incorrect(int x , int y , Plateau &plateau) {
    for (int i = -puissance; i <= puissance; i++) {
        for (int j = -puissance; j <= puissance; j++) {
            if (ligneA+i == x && colonneA+j == y ) {
                if (plateau.getBrokenCase(x, y) == false && plateau.getFreeCase(x, y) == true) {
                    return true;
                }
            }
        }
    }
    cout << "\nVoila vos coordonnées recommencez\nligne :" << ligneA << "\nColonne :" << colonneA << "\n";
    return false;
}

void angePuissant::modifierCase( int &ligne , int &colonne, Plateau &plateau){
    plateau.setCase(ligneA, colonneA, true, false);
    ligneA = ligne;
    colonneA = colonne;
    plateau.setCase(ligneA, colonneA, false, false);
}

bool angePuissant::cantContinue( Plateau &plateau ){
    return (won(plateau)||loose(plateau));
}

bool angePuissant::won(Plateau &plateau){
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (ligneA+i < 1 || ligneA+i > plateau.getDim() || colonneA+j < 1 || colonneA+j > plateau.getDim() ) {
                cout << "\n\nL\'Ange a gagné ! \n";
                return true;
            }
        }
    }
    
    return false;
}
bool angePuissant::loose(Plateau &plateau){
    
    for (int i = -puissance; i <= puissance; i++) {
        for (int j = -puissance; j <= puissance; j++) {
            if (plateau.getFreeCase(ligneA+i, colonneA+j) == true) {
                return false;
            }
        }
    }
    cout << "\n\nLe Demon a gagné ! \n";
    return true;
}