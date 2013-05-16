%{
    #include <stdio.h>
    #include <stdlib.h>
	#include "Datos.h"

    void yyerror(char *s);
%}

%union{
    int entero;
    char *cadena;
	struct Conjunto* conjunto;
	struct ListaConjuntos* ListaConjuntos;
	
	struct Asignacion* asignacion;
	struct ListaAsignaciones* ListaAsignaciones;
	
	struct Expresion* expresion;

		
}

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
%start abssyn
%type <ListaConjuntos> abssyn
%type <ListaConjuntos> ArchCfg
%type <expresion> Exp
%type <conj> Conjunto
%type <asignacion> Assignment
%type <ListaAsignaciones> Assignments

////////////////////////////////////////
///////// REGLAS GRAMATICALES /////////
//////////////////////////////////////
%%

abssyn: ArchCfg {$$ = yyval.ListaConjuntos = $1;};

ArchCfg: Conjunto ArchCfg {$$ = agregarListaConjuntos($1, $2;}
		 |Conjunto {$$ = $1};

Conjunto: SET NUMBER OPENBRACE Assignments CLOSEBRACE {$$ = nuevoConjunto($2, $4);};

Assignments: Assignment Assignments {$$ = agregarListaAsignaciones($1, $2);}	
            |Assignment {$$ = $1};
		
Assignment:	ID EQUAL Exp SEMICOLON {$$ = nuevaAsignacion($1, $3);};

Exp: Exp PLUS Exp {$$ = crearSuma($1, $3);}	
    |Exp FACT Exp {$$ = crearMult($1, $3);}
    |Exp LESS Exp {$$ = crearResta($1, $3);}
    |Exp SUBS Exp {$$ = crearDiv($1, $3);}
    |NUMBER {$$ = nuevoNumero($1);}
    |ID {$$ = nuevaVariable($1);}
    |OPENPAR Exp CLOSEPAR {$$ = $2;};
%%

//////////////////////////
/////////////////////////

void yyerror(char *s){
    printf("ERROR SINTACTICO, SE ENCONTRO: %s Y SE ESPERABA OTRA COSA\n",yytext);
}

