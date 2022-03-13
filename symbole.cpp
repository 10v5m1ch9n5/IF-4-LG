#include "symbole.h"
#include <iostream>

void Symbole::affiche() {
   cout<<Etiquettes[ident];
}

void Entier::affiche() {
   Symbole::affiche();
   cout<<"("<<valeur<<")";
}

int Entier::get_val() {
	return valeur;
}

