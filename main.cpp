#include <iostream>
#include "lexer.h"
#include "automate.h"

int main(int argc, char* argv[]) {
   if(argc < 2) {
	   cout << "./anal.elf <expression>" << endl;
	   return 1;
   }
   string chaine(argv[1]);

   Automate a(chaine);
   a.lecture();

   return 0;
}

