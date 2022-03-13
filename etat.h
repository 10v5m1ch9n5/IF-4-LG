#ifndef ETAT_H
#define ETAT_H

#include "symbole.h"

class Automate;

class Etat {
	public:
		virtual void transition(Automate*, Symbole*) = 0;
};

class E0 : public Etat {
	public:
		void transition(Automate*, Symbole*) ;
};
class E1 : public Etat {
	public:
		void transition(Automate*, Symbole*) ;
};
class E2 : public Etat {
	public:
		void transition(Automate*, Symbole*) ;
};
class E3 : public Etat {
	public:
		void transition(Automate*, Symbole*) ;
};
class E4 : public Etat {
	public:
		void transition(Automate*, Symbole*) ;
};
class E5 : public Etat {
	public:
		void transition(Automate*, Symbole*) ;
};
class E6 : public Etat {
	public:
		void transition(Automate*, Symbole*) ;
};
class E7 : public Etat {
	public:
		void transition(Automate*, Symbole*) ;
};
class E8 : public Etat {
	public:
		void transition(Automate*, Symbole*) ;
};
class E9 : public Etat {
	public:
		void transition(Automate*, Symbole*) ;
};

#endif
