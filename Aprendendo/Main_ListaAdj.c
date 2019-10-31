#include "Funcoes_ListaAdj.c"

int main (void){
  Grafo g;
  cria_grafo(&g, 6);
  adiciona_aresta(&g,0,1);
  adiciona_aresta(&g,1,2);
  adiciona_aresta(&g,2,3);
  adiciona_aresta(&g,3,4);
  adiciona_aresta(&g,4,5);
  // adiciona_aresta(&g,5,0);

  inserir_Nome(&g, 0, "a");
  inserir_Nome(&g, 1, "b");
  inserir_Nome(&g, 2, "c");
  inserir_Nome(&g, 3, "d");
  inserir_Nome(&g, 4, "e");
  // inserir_Nome(&g, 5, "f");

  // adiciona_aresta(&g,5,6);
  // adiciona_aresta(&g,6,7);
  // adiciona_aresta(&g,7,8);
  // adiciona_aresta(&g,8,9);

  imprimirSequencia(&g, 0);

  // printf("PEGOU!!\n");

  return 0;
}
