#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "execSintacticoEvaluador.h"
#include "Datos.h"

extern punteroConjuntos execEval(FILE *inFile);

void usage(char *progname) {
    fprintf(stderr, "Usage: %s <inputfile>\n", progname);
    exit(1);
}

int main(int argc, char *argv[]) {
	char *dirDeTrabajo = getenv("DIRDETRABAJO");
	char *ficheroCfg = getenv("FICHEROCFG");
	
	printf("leyendo el archivo de configuracion: %s \n",ficheroCfg);
	printf("leyendo direccion de trabajo: %s \n",dirDeTrabajo);
	

  if (argc != 2) {
    usage(argv[0]);
  }

  FILE *inFile = fopen(ficheroCfg, "r");

  if (!inFile) {
    usage(argv[0]);
  }
	punteroConjuntos conjuntos = NULL;
	if((conjuntos ==execEval(inFile))){
		fprintf(stdout, "Sintactico conjuntos si funciona \n");
	}
	else{
		fprintf(stderr, "sintactico conjuntos no funciona \n");
}

if(chdir(dirDeTrabajo) == -1) {
	    fprintf(stderr, "CtrlEval: No existe el directorio del Evaluador: %s\n", dirDeTrabajo);
	}
  

}


