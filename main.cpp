#include <iostream>
#include "lexer.h"
#include "automate.h"

int main(int argc, char* argv[]) {
   string chaine(argv[1]);

   Automate a(chaine);
   a.lecture();

   return 0;
}

