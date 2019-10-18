#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){
  int a;
  char **Nome;

  Nome = (char**)malloc(5 * sizeof(char*));
  for (int x = 0; x < 5; x++){
    Nome[x] = (char*)malloc(25 * sizeof(char));
  }

  scanf("%[^\n]s", Nome[3]);

  a = strlen(Nome[3]);

  printf("%d\n", a);

  printf("%s\n", Nome[3]);



  return 0;
}
