CC := g++
CPPFLAGS := -Wall -DVERBOSE

anal.elf: main.o lexer.o symbole.o automate.o etat.o
	$(CC) -o $@ $^

main.o: main.cpp
lexer.o: lexer.cpp lexer.h
symbole.o: symbole.cpp symbole.h
automate.o: automate.cpp automate.h
etat.o: etat.cpp etat.h

clean:
	rm -vf *.gch *.o *.elf *.out
