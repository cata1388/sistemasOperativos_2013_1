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

%token <entero> NUMBER
%token <cadena> ID
%token <cadena> SET
%token PLUS
%token LESS
%token FACT
%token SUBS
%token OPENBRACE
%token CLOSEBRACE
%token OPENPAR
%token CLOSEPAR
%token EQUAL
%token SEMICOLON
%token SPACE

/////////////////////////////////////////
/////////////  NO TERMINALES  //////////
///////////////////////////////////////

%type <cadena> ArchCfg
%type <cadena> Exp
%type <cadena> Conjunto
%type <cadena> Assignment
%type <cadena> Assignments
%left PLUS LESS
%left FACT SUBS

////////////////////////////////////////
///////// REGLAS GRAMATICALES /////////
//////////////////////////////////////
%%
ArchCfg:	Conjunto ArchCfg;
		|Conjunto;
Conjunto:	SET NUMBER OPENBRACE Assignments CLOSEBRACE
Assignments:	Assignment Assignments	
		|Assignment 		
Assignment:	ID EQUAL Exp SEMICOLON
Exp:		Exp PLUS Exp		{$$ = $1, $3;}	
		|Exp FACT Exp		{$$ = $1, $3;}
		|Exp LESS Exp		{$$ = $1, $3;}
		|Exp SUBS Exp		{$$ = $1, $3;}
		|NUMBER			{$$ = $1;}
		|ID			{$$ = $1;}
		|OPENPAR Exp CLOSEPAR	{$$ = $2;};
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






