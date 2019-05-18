a.out:y.tab.o lex.yy.o 
	gcc -o a lex.yy.o y.tab.o -lfl
y.tab.o:CompilerProject2.y
		bison -y -d CompilerProject2.y
		gcc -c -g y.tab.c
lex.yy.o:CompilerProject1_revise.l
		lex CompilerProject1_revise.l
		gcc -c -g lex.yy.c
clean:
	rm -f *.o