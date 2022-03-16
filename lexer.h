#ifndef LEXER_H
#define LEXER_H

#include <string>
#include "symbole.h"
using namespace std;

class Lexer {

   public:
      Lexer(string s) : flux(s), tete(0), tampon(nullptr) { }
      ~Lexer() {
	      delete(tampon);
      }

      Symbole * Consulter();
      void Avancer();
      void setTampon(Symbole*);

   protected:
      string flux;
      long unsigned int tete;
      Symbole * tampon;
};

#endif
