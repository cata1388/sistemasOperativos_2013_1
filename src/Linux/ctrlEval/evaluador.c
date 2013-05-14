//
//  Main.c  
//
//
//  Created by Catalina Sanchez Castaño on 22/04/13.
//
//
#include <stdio.h>
#include <stdlib.h>

void usage(char *progname) {
    fprintf(stderr, "Usage: %s <inputfile>\n", progname);
    exit(1);
}

void evalua(){
	
}

int main(int argc, char *argv[]){
	FILE *archCfg;
	char setArray[100];
	char set[50];
	char *palabra = "Conjunto ";
	int i;
	char *conjunto = argv[2];
	char *numSet;
	if (argc != 3) {
        	usage(argv[0]);
    	}
    	if ((archCfg = fopen(argv[1], "r")) == NULL) {
        	fprintf(stderr, "Error: no pudo abrir archivo \n");
        	exit(1);
    	}
	archCfg = fopen(argv[1], "r");
	while (feof(archCfg) == 0){
			fgets(set,10,archCfg);
			if (strncmp(palabra,set) == 0){
				printf("son iguales %s \n", set);
				numSet = fgets(set,2,archCfg);
				printf("El numero del conjunto es: %s\n", numSet);	
				if (strcmp(conjunto,numSet) == 0)
					printf("los numeros son iguales \n");
				
			}
			
	}


}
