
#include "lexicoEvaluador.h"
#include "sintacticoEvaluador.tab.h"
#include "Datos.h"

extern int yyparse();

punteroConjuntos execEval(FILE* infile) {

  yyin = infile;
	printf("antes de ejecutar yyparse \n");
  if(!yyparse()){
  	printf("despues de ejecutar yyparse \n");
    return yylval.ListaConjuntos;
  }
  return NULL;
}

void yyerror(char* s){
  fprintf(stderr, "%s at %d in '%s' \n", s, yylineno, yytext);
}


