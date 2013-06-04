
#include "execEval.h"
#include "lexicoEvaluador.h"
#include "Datos.h"

extern int yyparse();

punteroExpresion execEval(FILE* infile){
	yyin = infile;
	
	if(!yyparse()){
		return yylval.expresion;
	}
	return null;
}
	void yyerror(char* s){
		fprintf(stderr, "%s at %d in '%s' \n", s, yylineno, yytext);
	}


