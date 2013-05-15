%{
#include "parserEvaluador.h"
#include "Datos.h"
%}
%option noyywrap

NUMBER      ([1-9][0-9]*|0)
ID          [a-zA-Z]([a-zA-Z]|[0-9])*

%%
"Conjunto"      {return SET;}
"+"             {return PLUS;}
"-"             {return LESS;}
"*"             {return FACT;}
"/"             {return SUBS;}
"{"             {return OPENBRACE;}
"}"             {return CLOSEBRACE;}
"("             {return OPENPAR;}
")"             {return CLOSEPAR;}
"="             {return EQUAL;}
";"             {return SEMICOLON;}
{NUMBER}        {yylval.entero = atoi(yytext); return(NUMBER);}
{ID}            {yylval.cadena = nuevoString(yytext); return ID;}
[ \t\n\r]		/*ignore whitespace*/
.               {printf("CARACTER NO RECONOCIDO \n");}
<<EOF>>         {yyterminate();}
%%

