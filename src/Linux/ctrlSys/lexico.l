%{
#include <stdio.h>
#include <stdlib.h>
#include "sintactico.tab.h"
%}
%option noyywrap


DIGIT		[0-9]+
ID		[a-zA-Z]([a-zA-Z]|{DIGIT})*
EVALCFG		{ID}+".cfg"
PATH		"."([/]{ID})+


%%
"Evaluador"	{return EVALUATOR;}
{ID}		{return(ID);}
{DIGIT}		{yytext; return(DIGIT);}
"{"		{return OPENPAR;}
"}"		{return CLOSEPAR;}
{PATH}		{return(PATH);}
{EVALCFG}	{return(EVALCFG);}
[ \t\n\r]	/*ignore whitespace*/
.           	{printf("CARACTER NO RECONOCIDO \n"),yytext;}
<<EOF>>		{return EOF;}
%%






