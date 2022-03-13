#include <iostream>
#include "lexer.h"
#include "automate.h"

int main(void) {
   //string chaine("(1+34)*123");
   string chaine("123");

   Automate a(chaine);
   a.lecture();

   return 0;
}

