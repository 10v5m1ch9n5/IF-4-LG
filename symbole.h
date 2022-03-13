#ifndef SYMBOLE_H
#define SYMBOLE_H

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, EXP, FIN, ERREUR };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "EXP", "FIN", "ERREUR" };

class Symbole {
   public:
      Symbole(int i, bool t=false) : ident(i), terminal(t) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void affiche();
      bool isTerminal(void) { return terminal; }

   protected:
      int ident;
      bool terminal;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT, true), valeur(v) { }
      ~Entier() { }
      virtual void affiche();
      int get_val();
   protected:
      int valeur;
};

class Expr : public Symbole {
	public:
		Expr(int val): Symbole(EXP, false), valeur(val) {}
		~Expr() {}
	protected:
		int valeur;
};

#endif
