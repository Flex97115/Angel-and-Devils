//
//  Gestion des joueurs.h
//  Angel and Devil
//
//  Created by Gery THRASIBULE on 04/03/2015.
//  Copyright (c) 2015 nowflare. All rights reserved.
//

#ifndef __Angel_and_Devil__Gestion_des_joueurs__
#define __Angel_and_Devil__Gestion_des_joueurs__

#include <stdio.h>
#include <string>
#include <math.h>
#include <iostream>
#include "Gestion du plateau.h"
using namespace std;

/*--------------------------------------JOUEUR----------------------------------------*/

class Joueur{
protected:
    string pseudo;
public:
    Joueur();
    ~Joueur();
    void saisir(int &ligne , int &colonne);
    void choisirCase(int &ligne , int &colonne,Plateau &plateau);
    void jouer(Plateau &plateau);
    void setPseudo(string set_pseudo);
    virtual bool incorrect(int x , int y , Plateau &plateau)=0;
    virtual void modifierCase(int &ligne , int &colonne,Plateau &plateau)=0;
    virtual bool cantContinue(Plateau &plateau)=0;
};

/*--------------------------------------ANGE----------------------------------------*/

class Ange : public Joueur{
private:
    int ligneA;
    int colonneA;
public:
    Ange(int x , int y );
    virtual bool incorrect(int x ,int y, Plateau &plateau);
    virtual void modifierCase(int &ligne , int &colonne, Plateau &plateau);
    virtual bool cantContinue(Plateau &plateau);
    bool won(Plateau &plateau);
    bool loose(Plateau &plateau);
};

/*--------------------------------------DEMON----------------------------------------*/

class Demon : public Joueur{
    
public:
    Demon();
    virtual bool incorrect(int x ,int y, Plateau &plateau);
    virtual void modifierCase(int &ligne , int &colonne,Plateau &plateau);
    virtual bool cantContinue(Plateau &plateau);
    
};

/*--------------------------------------ANGE PUISSANT----------------------------------------*/

class angePuissant : public Ange {
private:
    int ligneA;
    int colonneA;
    int puissance;
public:
    angePuissant( int x , int y , int puiss);
    virtual bool incorrect(int x ,int y, Plateau &plateau);
    virtual void modifierCase(int &ligne , int &colonne, Plateau &plateau);
    virtual bool cantContinue(Plateau &plateau);
    bool won(Plateau &plateau);
    bool loose(Plateau &plateau);
    
};


#endif /* defined(__Angel_and_Devil__Gestion_des_joueurs__) */
