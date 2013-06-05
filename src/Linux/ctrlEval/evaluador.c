//
//  evaluador.c  
//
//
//  Created by Catalina Sanchez Castaño on 22/04/13.
//
//
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Datos.h"
#include "execEval.h"

extern punteroConjuntos execEval(FILE *infile);

void usage(char *progname) {
    fprintf(stderr, "Usage: %s <inputfile>\n", progname);
    exit(1);
}

int evaluar(punteroExpresion expresion, punteroAsignaciones asignaciones){
	switch(expresion->tipoNodo){
		case T_NUMERO:
			return expresion->infoNodo.numero;
			break;
		
		case T_OPERADOR:
			switch(expresion->infoNodo.oper){
				case O_SUMA:
					return evaluar(expresion->expreIzq, asignaciones) + evaluar(expresion->expreDer, asignaciones);
					break;
				case O_RESTA:
					return evaluar(expresion->expreIzq, asignaciones) - evaluar(expresion->expreDer, asignaciones);
					break;
				case O_MULTIPLICACION:
					return evaluar(expresion->expreIzq, asignaciones) * evaluar(expresion->expreDer, asignaciones);
					break;
				case O_DIVISION:
					return evaluar(expresion->expreIzq, asignaciones) / evaluar(expresion->expreDer, asignaciones);
					break;
			}
		case T_ID:
			return valorId(expresion->infoNodo.id, asignaciones);
			break;	
	}
	return 0;
}

int main(int argc, char *argv[]){
	printf("empezando \n");
	int resultado = 0;
	int conjExiste = 1;
	FILE *archCfg;
	if (argc != 3) {
        	usage(argv[0]);
    	}
		//archivo q contiene los conjuntos a evaluar
    	if ((archCfg = fopen(argv[1], "r")) == NULL) {
        	fprintf(stderr, "Evaluador: no pudo abrir archivo: %s \n",argv[0]);
    	}
	printf("abriendo archivo \n");
	int numConjunto = atoi(argv[2]); //numero de conjunto a evaluar
	punteroConjuntos listaConjuntos = execEval(archCfg);
	punteroConjunto conjunto = listaConjuntos->punConjunto;
	
	//verificar si el archivo tiene conjuntos, de ser así busca y evalúa el indicado 	
	if (!listaConjuntos){
		fprintf(stderr,"Evaluador: no hay conjuntos para evaluar!! \n");
	}
	else{
		int num = conjunto->numeroConjunto;
		while (listaConjuntos != NULL && num != numConjunto){
			listaConjuntos = listaConjuntos->punteroConjuntosSiguiente;
			if(listaConjuntos == NULL){
				conjExiste = 0;
				fprintf(stderr, "Evaluador: No existe el conjunto %d \n", numConjunto);			
			}
			else{
				conjunto = listaConjuntos->punConjunto;
				num = conjunto->numeroConjunto;
			}	
		}
	}
	if (conjExiste){
		//me queda por obtener la lista de asignaciones para evaluarlas
		punteroAsignaciones asignaciones = conjunto->asignaciones;
		while (asignaciones != NULL){
			punteroAsignacion asignacion = asignaciones->punAsignacion;
			resultado = evaluar(asignacion->expresion, asignaciones);
			asignaciones = asignaciones->punteroAsignacionesSiguiente;
		}
		printf("el resultado del conjunto es: %d \n", resultado);
	}
}
