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
		// s->Affiche();
		pileSymbole.push(s);
		pile.top()->transition(this, s);
		lex->Avancer();
	}
}

void Automate::push_etat(Etat * e) {
	pile.push(e);
}

void Automate::push_symbole(Symbole * s) {
	pileSymbole.push(s);
}

void Automate::accepter() {
	pileSymbole.pop();
	cout << "Resultat = " << int(*pileSymbole.top()) << endl;
}
