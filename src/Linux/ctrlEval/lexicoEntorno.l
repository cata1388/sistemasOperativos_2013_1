%{
#include "sintactticoEntorno.tab.h"
#include "Datos.h"
%}
%option noyywrap

NUMBER      (-)?([1-9][0-9]*|0)
ID          [a-zA-Z]([a-zA-Z]|[0-9])*

%%
{ID}		{return(ID);}
{NUMBER}	{yytext; return(NUMBER);}
"{"			{return OPENBRACE;}
"}"			{return CLOSEBRACE;}
"="			{return EQUAL;}
";"			{return SEMICOLON;}
[ \t\n\r]	/*ignore whitespace*/
.           {printf("CARACTER NO RECONOCIDO \n"),yytext;}
<<EOF>>		{yyterminate();}
%%
