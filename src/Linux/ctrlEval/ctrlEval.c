#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "execEval.h"
#include "Datos.h"


void usage(char *progname) {
  fprintf(stderr, "Usage %s <cfg file> <expr file>\n", progname);
  exit(1);
}

int main(int argc, char *argv[]) {

  if (argc != 2) {
    usage(argv[0]);
  }

  FILE *inFile   = fopen(argv[1], "r");

  if (!inFile) {
    usage(argv[0]);
  }
	punteroConjuntos conjuntos = NULL;
	if((conjuntos ==execEval(inFile))){
		fprintf(stdout, "Sintactico conjuntos si funciona \n");
	}
	else{
		fprintf(stderr, "sintactico conjuntos no funciona \n")
}


}


