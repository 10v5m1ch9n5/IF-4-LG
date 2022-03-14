#include <iostream>
#include "symbole.h"
#include "automate.h"

void E0::transition(Automate * a, Symbole * s) {
	switch(int(*s)) {
		case INT:
			a->push_etat(new E3);
			a->getLexer()->Avancer();
#ifdef VERBOSE
			std::cout << "E0: Empile E3" << std::endl;
#endif
			break;
		case OPENPAR:
			a->push_etat(new E2);
#ifdef VERBOSE
			std::cout << "E0: Empile E2" << std::endl;
#endif
			break;
		case EXP:
			a->push_etat(new E1);
			a->getLexer()->Avancer();
			a->push_symbole(a->getLexer()->Consulter());
#ifdef VERBOSE
			std::cout << "E0: Empile E1" << std::endl;
#endif
			break;
		default:
			std::cerr << "E0: default" << std::endl;
			a->kill();
	}
}

void E1::transition(Automate * a, Symbole * s) {
	switch(int(*s)) {
		case PLUS:
			a->push_etat(new E4);
#ifdef VERBOSE
			std::cout << "E1: Empile E4" << std::endl;
#endif
			break;
		case MULT:
			a->push_etat(new E5);
#ifdef VERBOSE
			std::cout << "E1: Empile E5" << std::endl;
#endif
			break;
		case FIN:
#ifdef VERBOSE
			std::cout << "E1: Accepter" << std::endl;
#endif
			a->accepter();
			break;
		default:
			std::cerr << "E1: default" << std::endl;
			a->kill();
	}
}

void E2::transition(Automate * a, Symbole * s) {
	switch(int (*s)) {
		case INT:
			a->push_etat(new E3);
#ifdef VERBOSE
			std::cout << "E2: Empile E3" << std::endl;
#endif
			break;
		case OPENPAR:
			a->push_etat(new E2);
#ifdef VERBOSE
			std::cout << "E2: Empile E2" << std::endl;
#endif
			break;
		case EXP:
			a->push_etat(new E6);
#ifdef VERBOSE
			std::cout << "E2: Empile E6" << std::endl;
#endif
			break;
		default:
			std::cerr << "E2: default" << std::endl;
	}
}

void E3::transition(Automate * a, Symbole * s) {
	Symbole * tmp;
	Symbole * next = a->getLexer()->Consulter();
	Entier * val;
	switch(int(*next)) {
		case PLUS:
		case MULT:
		case CLOSEPAR:
		case FIN:
#ifdef VERBOSE
			std::cout << "E3: Reduction r5 pour ";
			next->affiche();
			std::cout << std::endl;
#endif
			tmp = a->pop_symbole();
			val = dynamic_cast<Entier*>(tmp);
			a->pop_etat();
			a->push_symbole(new Expr(val->get_val()));
			a->set_resultat(val->get_val());
			break;
		default:
			std::cerr << "E3: default" << std::endl;
	}
}

void E4::transition(Automate * a, Symbole * s) {
	switch(int(*s)) {}
}
void E5::transition(Automate * a, Symbole * s) {
	switch(int(*s)) {}
}
void E6::transition(Automate * a, Symbole * s) {
	switch(int(*s)) {}
}
void E7::transition(Automate * a, Symbole * s) {
	switch(int(*s)) {}
}
void E8::transition(Automate * a, Symbole * s) {
	switch(int(*s)) {}
}
void E9::transition(Automate * a, Symbole * s) {
	switch(int(*s)) {}
}
