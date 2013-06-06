#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "execSintacticoEntorno.h"
#include "Datos.h"

extern punteroAsignaciones execEntorno(FILE *inFile);

void usage(char *progname) {
    fprintf(stderr, "Usage: %s <inputfile>\n", progname);
    exit(1);
}

int main(int argc, char *argv[]) {
	char *dirDeTrabajo = getenv("DIRDETRABAJO");
	char *ficheroCfg = getenv("FICHEROCFG");
	FILE *archEntorno;
	char arg[3];
	arg[0] = "./analizador";

	char entornoBuffer[2000];
	int *entrada[2];
	int *salida[2];
	int *error[2];
	pid_t   pid;
		
	printf("leyendo el archivo de configuracion: %s \n",ficheroCfg);
	printf("leyendo direccion de trabajo: %s \n",dirDeTrabajo);
	

	if (argc != 2) {
		usage(argv[0]);
	}

	//se ubica en el directorio dado por DIRDETRABAJO
	if(chdir(dirDeTrabajo) < 0) {
	    fprintf(stderr, "CtrlEval: No existe el directorio del Evaluador: %s\n", dirDeTrabajo);
	}
	else{
		fprintf(stdout, "CtrlEval: ubicado en nuevo directorio %s \n", dirDeTrabajo);
	}

	//por el momento recibo el entorno de arch de cfg: ./ctrlEval archEntorno.cfg
	if ((archEntorno = fopen(argv[1], "r")) == NULL) {
        	fprintf(stderr, "ctrlEval: no pudo abrir archivo de entorno: %s \n",argv[1]);
    	}

	//creacion de los pipes	
	if ((pipe(entrada[0])) < 0){
		fprintf(stderr, "error abriendo pipe de entrada");	
	}
	if ((pipe(entrada[1])) < 0){
		fprintf(stderr, "error abriendo pipe de entrada");	
	}
	if ((pipe(salida[0])) < 0){
		fprintf(stderr, "error abriendo pipe de salida");	
	}
	if ((pipe(salida[1])) < 0){
		fprintf(stderr, "error abriendo pipe de salida");	
	}
	if ((pipe(error[0])) < 0){
		fprintf(stderr, "error abriendo pipe de error");	
	}
	if ((pipe(error[1])) < 0){
		fprintf(stderr, "error abriendo pipe de error");	
	}


	punteroAsignaciones entorno = execEntorno(archEntorno);

	if ((pid = fork()) == 0){
		close(entrada[0]); //cierra lectura del pipe
		dup2(entrada[1],1); //stdout = salida del pipe
		close(entrada[1]);
	
		close(salida[1]);
		dup2(salida[0],0);
		close(salida[0]);

		close(error[2]);
		dup2(error[1],2);
		close(error[1]);
		if ((execve("./analizador")) == -1){
			fprintf("Ingresar archCfg y numero de conjuntos a evaluar \n");
			scanf("%s", arg[1]);
			scanf("%s", arg[2]);
			execve("./analizador", arg);
		}	
	}
	else{
		close(entrada[1]);
		dup2(entrada[0],0); // stdin = entrada pipe
		close(entrada[0]);

		close(salida[0]);
		dup2(salida[1],1);
		close(salida[1]);

		close(error[2]);
		dup2(error[0],2);
		close(error[0]);

		while(1){
			read(0,entornoBuffer,strlen(entornoBuffer));
      		fprintf(stdout, "ControlEval: entorno recibido: %s\n", entornoBuffer);
      		entorno = entorno->punteroAsignacionesSiguiente;
      		strcpy(entornoBuffer, entorno);
      		while (entorno != NULL){
      			write(1, entornoBuffer, strlen(entornoBuffer));
      			entorno = entorno->punteroAsignacionesSiguiente;
      			read(0,entornoBuffer,strlen(entornoBuffer));
      		}
		}	
	}
	
	if(entorno){
		fprintf(stdout, "Sintactico entorno si funciona \n");
	}
	else{
		fprintf(stderr, "sintactico entorno no funciona \n");
	}
}


