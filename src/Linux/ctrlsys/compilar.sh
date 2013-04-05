#!/bin/bash
bison -d sintactico.y
flex --header-file=lexico.h lexico.l
cc lex.yy.c sintactico.tab.c -o analizador -lfl -lm
./analizador ctrlSys.cfg


