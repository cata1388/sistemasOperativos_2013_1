#ifndef _DATOS_H
#define _DATOS_H

///////////////////////////////////////////////////////////////////////////////
//////////////////////                                   /////////////////////
/////////////////////   definicion de las estructuras   /////////////////////
////////////////////                                   /////////////////////
///////////////////////////////////////////////////////////////////////////

enum Operador{O_SUMA, O_RESTA, O_MULTIPLICACION, O_DIVISION};
enum tipoNodo{T_NUMERO, T_OPERADOR, T_ID};

union infoNodo{
	enum operador oper;
	int numero;
	char *id;
};

struct Expresion{
	enum tipoNodo tipoNodo;
	union infoNodo infoNodo;	
	struct Expresion *expreIzq, *expreDer;
};

struct Conjunto{
	int numeroConjunto;
	struct ListaAsignaciones *asignaciones;
};

struct Asignacion{
	char *idAsignacion;
	struct Expresion *expresion;
};

struct ListaAsignaciones{
	punteroAsignacion punAsignacion;
	punteroAsignaciones punteroAsignacionesSiguiente;
};

struct ListaConjuntos{
	punteroConjunto punConjunto;
	punteroConjuntos punteroConjuntosSiguiente;
};

///////////////////////////////////////////////////////////////////////////////
//////////////////////                                   /////////////////////
/////////////////////   declaracion de las estructuras  /////////////////////
////////////////////                                   /////////////////////
///////////////////////////////////////////////////////////////////////////

typedef struct Conjunto conjunto;
typedef struct Conjunto* punteroConjunto;

typedef struct ListaAsignaciones asignaciones;
typedef struct ListaAsignaciones* punteroAsignaciones;

typedef struct Asignacion asignacion;
typedef struct Asignacion* punteroAsignacion;

typedef struct Expresion expresion;
typedef struct Expresion* punteroExpresion;

typedef struct ListaConjuntos conjuntos;
typedef struct ListaConjuntos* punteroConjuntos;

///////////////////////////////////////////////////////////////////////////////
//////////////////////                                   /////////////////////
/////////////////////      declaracion de funciones     /////////////////////
////////////////////                                   /////////////////////
///////////////////////////////////////////////////////////////////////////

char* nuevoString(char n[]);

punteroConjunto nuevoConjunto(int numero, punteroAsignaciones asignaciones);
punteroAsignaciones agregarListaAsignaciones(punteroAsignacion asignacion, punteroAsignaciones asignaciones);
punteroAsignacion nuevaAsignacion(char* id, punteroExpresion expre);
punteroExpresion crearSuma(punteroExpresion izq, punteroExpresion der);
punteroExpresion crearMult(punteroExpresion izq, punteroExpresion der);
punteroExpresion crearResta(punteroExpresion izq, punteroExpresion der);
punteroExpresion crearDiv(punteroExpresion izq, punteroExpresion der);
punteroExpresion nuevoNumero(int);
punteroExpresion nuevaVariable(char*);

#endif
