#ifndef AUTOMATE_H
#define AUTOMATE_H

#include <stack>
#include "etat.h"
#include "symbole.h"
#include "lexer.h"

class Automate {
	public:
		Automate(std::string);
		void lecture(void);
	protected:
		std::stack<Etat*> pile;
		std::stack<Symbole*> pileSymbole;
		Lexer * lex;
};

#endif
