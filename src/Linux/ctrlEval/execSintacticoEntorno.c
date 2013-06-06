#include "lexicoEntorno.h"
#include "sintacticoEntorno.tab.h"
#include "Datos.h"

extern int yyparse();

punteroAsignaciones execEntorno(FILE* infile) {

  yyin = infile;
	printf("antes de ejecutar yyparse \n");
  if(!yyparse()){
  	printf("despues de ejecutar yyparse \n");
    return yylval.ListaAsignaciones;
  }
  return NULL;
}

void yyerror(char* s){
  fprintf(stderr, "%s at %d in '%s' \n", s, yylineno, yytext);


