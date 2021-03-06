#include <iostream>
#include "automate.h"
#include "etat.h"

Automate::Automate(std::string chaine) {
	pile.push(new E0);
	lex = new Lexer(chaine);
	pileSymbole.push(lex->Consulter());
}

Automate::~Automate() {
	delete(lex);
}

void Automate::lecture(void) {
	while( *(pileSymbole.top()) != FIN) {
#ifdef VERBOSE
		cout << "Transition pour : ";
		pileSymbole.top()->affiche();
		// cout << " | ";
		// pile.top()->affiche();
		cout << endl;
#endif
		pile.top()->transition(this, pileSymbole.top());
		if(error) break;
	}
#ifdef VERBOSE
	cout << "Sortie boucle main !" << endl;
	cout << "Transition pour : ";
	pileSymbole.top()->affiche();
	cout << endl;
#endif
	pile.top()->transition(this, pileSymbole.top());
}

void Automate::push_etat(Etat * e) {
	pile.push(e);
}

void Automate::push_symbole(Symbole * s) {
	pileSymbole.push(s);
}

Etat * Automate::pop_etat() {
	Etat * tmp = pile.top();
	pile.pop();
	return tmp;
}

Symbole * Automate::pop_symbole() {
	Symbole * tmp = pileSymbole.top();
	pileSymbole.pop();
	return tmp;
}

void Automate::accepter() {
#ifdef VERBOSE
	cout << "Resultat = ";
#endif	
	cout << resultat << endl;
	Etat * e1 = pile.top();
	pile.pop();
	Etat * e2 = pile.top();
	pile.pop();
	delete(e1);
	delete(e2);
}

void Automate::set_resultat(int r) {
	resultat = r;
}

void Automate::kill() {
	error = true;
}
