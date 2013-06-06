%{
#include <stdio.h>
#include <stdlib.h>
#include "Datos.h"

int yylex();
void yyerror(char *s);
%}

%union {
  char *cadena;
  int entero;
  struct ListaAsignaciones* ListaAsignaciones;
  struct Asignacion* asignacion;
  struct Expresion* expresion;
}

/////////////////////////////////////////
////////////   TERMINALES    ///////////
///////////////////////////////////////

%token <cadena> ID
%token <numero> NUMBER
%token OPENBRACE
%token CLOSEBRACE
%token EQUAL
%token SEMICOLON

/////////////////////////////////////////
/////////////  NO TERMINALES  //////////
///////////////////////////////////////

%start entorno
%type <ListaAsignaciones> entorno
%type <ListaAsignaciones> variables
%type <asignacion> variable
%type <expresion> exp


////////////////////////////////////////
///////// REGLAS GRAMATICALES /////////
//////////////////////////////////////
%%

entorno: OPENBRACE variables CLOSEBRACE { yylval.ListaAsignaciones = $2;};

variables: variable variables { $$ = agregarListaAsignaciones($1, $2);};

variable: ID EQUAL exp SEMICOLON {$$ = nuevaAsignacion($1, $3);};

exp: NUMBER {$$ = nuevoNumero($1);};

%%
