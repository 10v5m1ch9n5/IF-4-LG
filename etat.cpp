#include <iostream>
#include "etat.h"
#include "symbole.h"

void E0::Transition(Automate * a, Symbole * s) {
	switch(int(*s)) {
		case INT:
			std::cout << "E0: val" << std::endl;
			break;
		case OPENPAR:
			std::cout << "E0 : openpar" << std::endl;
			break;
		default:
			std::cout << "E0: default" << std::endl;
	}
}
