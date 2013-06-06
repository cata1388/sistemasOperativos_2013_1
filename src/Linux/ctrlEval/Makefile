all: analizador ctrlEval

analizador: lex.yy.o sintacticoEvaluador.tab.o Datos.o execSintacticoEvaluador.o evaluador.o
	$(CC) lex.yy.o sintacticoEvaluador.tab.o Datos.o execSintacticoEvaluador.o evaluador.o -o analizador -lfl -lm

ctrlEval: lex.yy.o sintacticoEvaluador.tab.o Datos.o execSintacticoEvaluador.o ctrlEval.o
	$(CC) lex.yy.o sintacticoEvaluador.tab.o Datos.o execSintacticoEvaluador.o ctrlEval.o -o ctrlEval -lfl -lm

sintacticoEvaluador.tab.c sintacticoEvaluador.tab.h: sintacticoEvaluador.y 
	bison -g -d $<
	
lex.yy.c: lexicoEvaluador.l sintacticoEvaluador.tab.h 
	flex --header-file=lexicoEvaluador.h lexicoEvaluador.l

Datos.o: Datos.c Datos.h
	$(CC) -c Datos.c

evaluador.o ctrlEval.o: evaluador.c ctrlEval.c
	$(CC) -c evaluador.c ctrlEval.c
	
clean:
	rm -f sintacticoEvaluador.tab.c sintacticoEvaluador.tab.h lex.yy.c lexico.h \
	analizador execSintacticoEvaluador.o Datos.o lex.yy.o sintacticoEvaluador.tab.o \
	ctrlEval sintacticoEvaluador.dot evaluador.o ctrlEval.o \
	*.~ *~ *.cfg~ *.y~ *.l~ lexicoEvaluador.h

