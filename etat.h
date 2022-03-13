#ifndef ETAT_H
#define ETAT_H

#include "symbole.h"

class Automate;

class Etat {
	public:
		virtual void Transition(Automate*, Symbole*) = 0;
};

class E0 : public Etat {
	public:
		void Transition(Automate*, Symbole*) ;
};

#endif
