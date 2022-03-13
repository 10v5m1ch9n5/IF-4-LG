#include <iostream>
#include "automate.h"
#include "etat.h"

Automate::Automate(std::string chaine) {
	pile.push(new E0);

	lex = new Lexer(chaine);
}

void Automate::lecture(void) {
	Symbole * s;
	while( *(s=lex->Consulter()) != FIN) {
		s->Affiche();
		std::cout<<endl;
		lex->Avancer();
	}
}
