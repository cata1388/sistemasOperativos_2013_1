%{
#include <stdio.h>
#include <stdlib.h>
#include "sintactico.tab.h"
%}
%option noyywrap

NUMBER      ([1-9][0-9]*|"0")
ID          [a-zA-Z]([a-zA-Z]|[0-9])*
EXP         ({EXP}("+"|"*"|"-"|"/")+{EXP})|({NUMBER})|({ID})|("("{EXP}")")
ASSIGNMENT  {ID}"="{EXP}";"
ASSIGNMENTS {ASSIGNMENT}({ASSIGNMENTS}|{ASSIGNMENT})+
CONJUNTO    "Conjunto"{NUMBER}"{"{ASSIGNMENTS}"}"


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
{NUMBER}        {return(NUMBER);}
{ID}            {return ID;}
[ \t\n\r]	/*ignore whitespace*/
.               {printf("CARACTER NO RECONOCIDO \n");}
<<EOF>>         {return EOF;}
%%

