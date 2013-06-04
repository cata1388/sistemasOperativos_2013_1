#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Datos.h"



char* nuevoString(char *viejo){
  char *nuevo;
  nuevo = malloc(strlen(viejo)+1);
  strcpy(nuevo,viejo);
  return nuevo;
}

punteroConjunto nuevoConjunto(int numero, punteroAsignaciones asignaciones){
	punteroConjunto p = (punteroConjunto) malloc(sizeof(conjunto));
	p->numeroConjunto = numero;
	p->asignaciones = asignaciones;
	return p;
}

punteroConjuntos agregarListaConjuntos(punteroConjunto conjunto, punteroConjuntos conjuntos){
	punteroConjuntos p = (punteroConjuntos) malloc(sizeof(conjuntos));
	p->punConjunto = conjunto;
	p->punteroConjuntosSiguiente = conjuntos;
	return p;
}

punteroConjuntos crearListaConjuntos(punteroConjunto conjunto){
	punteroConjuntos p = (punteroConjuntos) malloc(sizeof(conjuntos));
	p->punConjunto = conjunto;
	p->punteroConjuntosSiguiente = NULL;
	return p;
}

punteroAsignaciones agregarListaAsignaciones(punteroAsignacion asignacion, punteroAsignaciones asignaciones){
	punteroAsignaciones p = (punteroAsignaciones) malloc(sizeof(asignaciones));
	p->punAsignacion = asignacion;
	p->punteroAsignacionesSiguiente = asignaciones;
	return p;
}

punteroAsignaciones crearListaAsignaciones(punteroAsignacion asignacion){
	punteroAsignaciones p = (punteroAsignaciones) malloc(sizeof(asignaciones));
	p->punAsignacion = asignacion;
	p->punteroAsignacionesSiguiente = NULL;
	return p;
}

punteroAsignacion nuevaAsignacion(char* id, punteroExpresion expre){
	punteroAsignacion p = (punteroAsignacion) malloc(sizeof(asignacion));
	p->idAsignacion = id;
	p->expresion = expre;
	return p;
}

punteroExpresion crearExpresion(){
	punteroExpresion p = (punteroExpresion) malloc(sizeof(expresion));
	p->expreIzq = p->expreDer = NULL;
	return p;
}

punteroExpresion crearSuma(punteroExpresion izq, punteroExpresion der){
	punteroExpresion p;
	p = crearExpresion();
	p->tipoNodo = T_OPERADOR;
	p->infoNodo.oper = O_SUMA;
	p->expreIzq = izq;
	p->expreDer = der;
	return p;	
}

punteroExpresion crearMult(punteroExpresion izq, punteroExpresion der){
	punteroExpresion p;
	p = crearExpresion();
	p->tipoNodo = T_OPERADOR;
	p->infoNodo.oper = O_MULTIPLICACION;
	p->expreIzq = izq;
	p->expreDer = der;
	return p;
}

punteroExpresion crearResta(punteroExpresion izq, punteroExpresion der){
	punteroExpresion p;
	p = crearExpresion();
	p->tipoNodo = T_OPERADOR;
	p->infoNodo.oper = O_RESTA;
	p->expreIzq = izq;
	p->expreDer = der;
	return p;
}

punteroExpresion crearDiv(punteroExpresion izq, punteroExpresion der){
	punteroExpresion p; 
	p = crearExpresion();
	p->tipoNodo = T_OPERADOR;
	p->infoNodo.oper = O_DIVISION;
	p->expreIzq = izq;
	p->expreDer = der;
	return p;
}

punteroExpresion nuevoNumero(int num){
	punteroExpresion p;
	p = crearExpresion();
	p->tipoNodo = T_NUMERO;
	p->infoNodo.numero = num;
	return p;
}

punteroExpresion nuevaVariable(char* var){
	punteroExpresion p;
	p = crearExpresion();
	p->tipoNodo = T_ID;
	p->infoNodo.id = var;
	return p;	
}



