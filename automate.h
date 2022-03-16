#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <stack>
#include "etat.h"
#include "symbole.h"
#include "lexer.h"

class Automate {
	public:
		Automate(std::string);
		~Automate();
		void lecture(void);
		void push_etat(Etat*);
		void push_symbole(Symbole*);
		Etat * pop_etat(void);
		Symbole * pop_symbole(void);
		void accepter(void);
		void set_resultat(int);
		void kill(void);
		Lexer * getLexer(void) {return lex;};
	protected:
		std::stack<Etat*> pile;
		std::stack<Symbole*> pileSymbole;
		Lexer * lex;
		int resultat;
		bool error = false;
};

#endif
