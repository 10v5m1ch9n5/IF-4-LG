#ifndef ETAT_H
#define ETAT_H

#include "symbole.h"
#include <iostream>

class Automate;

class Etat {
	public:
		virtual void transition(Automate*, Symbole*) = 0;
		virtual void affiche(void) = 0;
		virtual ~Etat() {};
};

class E0 : public Etat {
	public:
		void transition(Automate*, Symbole*) ;
		void affiche(void) { std::cout << "E0"; } ;
		~E0() {};
};
class E1 : public Etat {
	public:
		void transition(Automate*, Symbole*) ;
		void affiche(void) { std::cout << "E1"; } ;
		~E1() {};
};
class E2 : public Etat {
	public:
		void transition(Automate*, Symbole*) ;
		void affiche(void) { std::cout << "E2"; } ;
		~E2() {};
};
class E3 : public Etat {
	public:
		void transition(Automate*, Symbole*) ;
		void affiche(void) { std::cout << "E3"; } ;
		~E3() {};
};
class E4 : public Etat {
	public:
		void transition(Automate*, Symbole*) ;
		void affiche(void) { std::cout << "E4"; } ;
		~E4() {};
};
class E5 : public Etat {
	public:
		void transition(Automate*, Symbole*) ;
		void affiche(void) { std::cout << "E5"; } ;
		~E5() {};
};
class E6 : public Etat {
	public:
		void transition(Automate*, Symbole*) ;
		void affiche(void) { std::cout << "E6"; } ;
		~E6() {};
};
class E7 : public Etat {
	public:
		void transition(Automate*, Symbole*) ;
		void affiche(void) { std::cout << "E7"; } ;
		~E7() {};
};
class E8 : public Etat {
	public:
		void transition(Automate*, Symbole*) ;
		void affiche(void) { std::cout << "E8"; } ;
		~E8() {};
};
class E9 : public Etat {
	public:
		void transition(Automate*, Symbole*) ;
		void affiche(void) { std::cout << "E9"; } ;
		~E9() {};
};

#endif
