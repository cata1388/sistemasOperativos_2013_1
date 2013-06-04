.phony: all clean

all: ctrlEval

CFLAGS=-wall
LDFLAGS=

SRC=parserEval.c ctrlEval.c Datos.c execEval.c 
OBJECTS=$(SRC:.c=.o)

parserEval.c parserEval.h: sintacticoEvaluador.y Tokens.h
	bison --verbose --warnings --output=parserEval.c \
	--defines=parserEval.h sintacticoEvaluador.y

lexicoEval.c lexicoEval.h: lexicoEvaluador.l
	flex --outfile=$@ --header-file=lexicoEvaluador.h $<

ctrlEval: $(OBJECTS)
	gcc $(LDFLAGS) -o $@ $(OBJECTS)

clean:
	rm -f *.o parserEval.c lexicoEval.h lexicoEval.c lexicoEval.h *.c~ *.l~ *.y~ Makefile~ \
	ctrlEval execEval.o

