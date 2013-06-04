all: analizador

analizador: lex.yy.o sintacticoEvaluador.tab.o data.o
	$(CC) lex.yy.o sintacticoEvaluador.tab.o  -o analizador -lfl -lm

sintacticoEvaluador.tab.c: sintacticoEvaluador.y
	bison -g -d $<

lex.yy.c: lexicoEvaluador.l
	flex --header-file=lexico.h lexicoEvaluador.l

clean:
	rm -f sintacticoEvaluador.tab.c sintacticoEvaluador.tab.h lex.yy.c \
	analizador 

