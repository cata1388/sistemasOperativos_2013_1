#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Data.h"


char* nuevoString(char n[]){
  char *p;
  int longitud;
  p = (char *) malloc(strlen(n)+1);
  strcpy(p,n);
  return p;
}

