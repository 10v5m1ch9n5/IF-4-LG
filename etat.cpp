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
			a->getLexer()->Avancer();
			a->push_symbole(a->getLexer()->Consulter());
#ifdef VERBOSE
			std::cout << "E0: Empile E2" << std::endl;
#endif
			break;
		case EXP:
			a->push_etat(new E1);
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
			a->getLexer()->Avancer();
			a->push_symbole(a->getLexer()->Consulter());
#ifdef VERBOSE
			std::cout << "E1: Empile E4" << std::endl;
#endif
			break;
		case MULT:
			a->push_etat(new E5);
			a->getLexer()->Avancer();
			a->push_symbole(a->getLexer()->Consulter());
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
			a->getLexer()->Avancer();
#ifdef VERBOSE
			std::cout << "E2: Empile E3" << std::endl;
#endif
			break;
		case OPENPAR:
			a->push_etat(new E2);
			a->getLexer()->Avancer();
			a->push_symbole(a->getLexer()->Consulter());
#ifdef VERBOSE
			std::cout << "E2: Empile E2" << std::endl;
#endif
			break;
		case EXP:
			a->push_etat(new E6);
			a->push_symbole(a->getLexer()->Consulter());
#ifdef VERBOSE
			std::cout << "E2: Empile E6" << std::endl;
#endif
			break;
		default:
			std::cerr << "E2: default" << std::endl;
			a->kill();
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
			delete(a->pop_etat());
			a->push_symbole(new Expr(val->get_val()));
			a->set_resultat(val->get_val());
			delete(tmp);
			break;
		default:
			std::cerr << "E3: default" << std::endl;
			a->kill();
	}
}

void E4::transition(Automate * a, Symbole * s) {
	switch(int(*s)) {
		case INT:
			a->push_etat(new E3);
			a->getLexer()->Avancer();
#ifdef VERBOSE
			std::cout << "E4: Empile E3" << std::endl;
#endif
			break;
		case OPENPAR:
			a->push_etat(new E2);
			a->getLexer()->Avancer();
			a->push_symbole(a->getLexer()->Consulter());
#ifdef VERBOSE
			std::cout << "E4: Empile E2" << std::endl;
#endif
			break;
		case EXP:
			a->push_etat(new E7);
#ifdef VERBOSE
			std::cout << "E4: Empile E7" << std::endl;
#endif
			break;
		default:
			std::cerr << "E4: default" << std::endl;
			a->kill();
	}
}

void E5::transition(Automate * a, Symbole * s) {
	switch(int(*s)) {
		case INT:
			a->push_etat(new E3);
			a->getLexer()->Avancer();
#ifdef VERBOSE
			std::cout << "E5: Empile E3" << std::endl;
#endif
			break;
		case OPENPAR:
			a->push_etat(new E2);
			a->getLexer()->Avancer();
			a->push_symbole(a->getLexer()->Consulter());
#ifdef VERBOSE
			std::cout << "E5: Empile E2" << std::endl;
#endif
			break;
		case EXP:
			a->push_etat(new E8);
#ifdef VERBOSE
			std::cout << "E5: Empile E8" << std::endl;
#endif
			break;
		default:
			std::cerr << "E5: default" << std::endl;
			a->kill();
	}
}

void E6::transition(Automate * a, Symbole * s) {
	switch(int(*s)) {
		case PLUS:
#ifdef VERBOSE
			std::cout << "E6: Empile E4" << std::endl;
#endif
			a->push_etat(new E4);
			a->getLexer()->Avancer();
			a->push_symbole(a->getLexer()->Consulter());
			break;
		case MULT:
#ifdef VERBOSE
			std::cout << "E6: Empile E5" << std::endl;
#endif
			a->push_etat(new E5);
			a->getLexer()->Avancer();
			a->push_symbole(a->getLexer()->Consulter());
			break;
		case CLOSEPAR:
#ifdef VERBOSE
			std::cout << "E6: Empile E9" << std::endl;
#endif
			a->push_etat(new E9);
			a->getLexer()->Avancer();
			break;
		default:
			std::cerr << "E6: default" << std::endl;
			a->kill();
	}
}

void E7::transition(Automate * a, Symbole * s) {
	Symbole * next = a->getLexer()->Consulter();
	Expr * terme1;
	Expr * terme2;
	Symbole * s1;
	Symbole * s2;
	int somme;
	switch(int(*next)) {
		case PLUS:
		case CLOSEPAR:
		case FIN:
#ifdef VERBOSE
			std::cout << "E7: reduction pour : ";
			next->affiche();
			std::cout << std::endl;
#endif
			delete(a->pop_etat());
			delete(a->pop_etat());
			delete(a->pop_etat());
			s1 = a->pop_symbole();
			terme1 = dynamic_cast<Expr*>(s1);
			delete(a->pop_symbole());
			s2 = a->pop_symbole();
			terme2 = dynamic_cast<Expr*>(s2);

			somme = terme1->get_val()+terme2->get_val();
			a->push_symbole(new Expr(somme));
			a->set_resultat(somme);

			delete(terme1);
			delete(terme2);
			break;
		case MULT:
#ifdef VERBOSE
			std::cout << "E7: Empile E5" << std::endl;
#endif
			a->push_etat(new E5);
			a->push_symbole(a->getLexer()->Consulter());
			a->getLexer()->Avancer();
			a->push_symbole(a->getLexer()->Consulter());
			break;
		default:
			std::cerr << "E7: default" << endl;
			a->kill();
	}
}

void E8::transition(Automate * a, Symbole * s) {
	Symbole * next = a->getLexer()->Consulter();
	Expr * facteur1;
	Expr * facteur2;
	Symbole * s1;
	Symbole * s3;
	int produit;
	switch(int(*next)) {
		case PLUS:
		case MULT:
		case CLOSEPAR:
		case FIN:
#ifdef VERBOSE
			std::cout << "E8: reduction pour : ";
			next->affiche();
			std::cout << std::endl;
#endif
			delete(a->pop_etat());
			delete(a->pop_etat());
			delete(a->pop_etat());
			s1 = a->pop_symbole();
			delete(a->pop_symbole());
			s3 = a->pop_symbole();
			facteur1 = dynamic_cast<Expr*>(s1);
			facteur2 = dynamic_cast<Expr*>(s3);


			produit = facteur1->get_val()*facteur2->get_val();
			a->push_symbole(new Expr(produit));
			a->set_resultat(produit);

			delete(s1);
			delete(s3);
	}
}

void E9::transition(Automate * a, Symbole * s) {
	Expr * val;
	Symbole * next = a->getLexer()->Consulter();
	Symbole * tmp;
	switch(int(*next)) {
		case PLUS:
		case MULT:
		case CLOSEPAR:
		case FIN:
#ifdef VERBOSE
			std::cout << "E9: reduction pour : ";
			next->affiche();
			std::cout << std::endl;
#endif
			delete(a->pop_etat());
			delete(a->pop_etat());
			delete(a->pop_etat());
			delete(a->pop_symbole());
			tmp = a->pop_symbole();
			delete(a->pop_symbole());

			val = dynamic_cast<Expr*>(tmp);
			a->push_symbole(tmp);
			a->set_resultat(val->get_val());
			break;
		default:
			std::cerr << "E9: default" << std::endl;
			a->kill();
	}
}
