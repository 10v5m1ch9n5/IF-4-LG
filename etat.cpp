#include <iostream>
#include "symbole.h"
#include "automate.h"

void E0::transition(Automate * a, Symbole * s) {
	switch(int(*s)) {
		case INT:
			a->push_etat(new E3);
			break;
		case OPENPAR:
			a->push_etat(new E2);
			break;
		case EXP:
			a->push_etat(new E1);
			break;
		default:
			std::cerr << "E0: default" << std::endl;
	}
}

void E1::transition(Automate * a, Symbole * s) {
	switch(int(*s)) {
		case PLUS:
			a->push_etat(new E4);
			break;
		case MULT:
			a->push_etat(new E5);
			break;
		case FIN:
			a->accepter();
			break;
		default:
			std::cerr << "E1: default" << std::endl;
	}
}

void E2::transition(Automate * a, Symbole * s) {
	switch(int (*s)) {
		case INT:
			a->push_etat(new E3);
			break;
		case OPENPAR:
			a->push_etat(new E2);
			break;
		case EXP:
			a->push_etat(new E6);
			break;
		default:
			std::cerr << "E2: default" << std::endl;
	}
}

void E3::transition(Automate * a, Symbole * s) {
	switch(int(*s)) {}
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
