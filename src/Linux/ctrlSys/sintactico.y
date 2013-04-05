%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "lexico.h"
    extern int yylex(void);
    extern char *yytext;
    extern FILE *yyin;
    void yyerror(char *s);
%}

%union{
    int entero;
    char cadena;
}

%start ArchCfg

/////////////////////////////////////////
////////////   TERMINALES    ///////////
///////////////////////////////////////

%token <entero> DIGIT
%token <cadena> ID
%token <cadena> EVALCFG
%token <cadena> PATH
%token <cadena> EVALUATOR
%token OPENPAR
%token CLOSEPAR


/////////////////////////////////////////
/////////////  NO TERMINALES  //////////
///////////////////////////////////////

%type <cadena> ArchCfg
%type <cadena> Evaluator

////////////////////////////////////////
///////// REGLAS GRAMATICALES /////////
//////////////////////////////////////

%%
ArchCfg:    Evaluator ArchCfg;
            |Evaluator;
            |error"\n" {yyerrok;}
Evaluator:  EVALUATOR ID OPENPAR PATH EVALCFG CLOSEPAR {$$= $2, $4, $5;}

%%

//////////////////////////
/////////////////////////

void yyerror(char *s){
    printf("ERROR SINTACTICO, SE ENCONTRO: %s Y SE ESPERABA OTRA COSA\n",yytext);
}

void usage(char *progname) {
  fprintf(stderr, "Usage: %s <inputfile>\n", progname);
  exit(1);
}

int main(int argc, char *argv[]){
    FILE *file;
    int win = 0;
    int p;
    
    if (argc != 2) {
        usage(argv[0]);
    }
    
    if ((file = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Error: no pudo abrir archivo \n");
        exit(1);
    }
    yyin = file;
    win = yyparse();
    if (win == 0)
        printf("NO HAY ERRORES!!! \n");
}
