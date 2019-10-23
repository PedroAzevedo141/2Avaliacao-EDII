#include "Funcoes.cpp"

int main (void){
  Grafo *gr;
  gr = cria_Grafo(5, 5, 1);
  inserirAresta(gr, 0, 1, 1, 2);
  inserirAresta(gr, 1, 3, 1, 3);
  inserirAresta(gr, 1, 2, 1, 3);
  inserirAresta(gr, 2, 4, 1, 4);
  inserirAresta(gr, 3, 0, 1, 5);
  inserirAresta(gr, 3, 4, 1, 5);
  inserirAresta(gr, 4, 1, 1, 6);


  int Vis[5];
  float Aux = 0;

  buscaProfundidade_Grafo(gr, 0, Vis, &Aux);

  // buscaLargura_Grafo(gr, 0, Vis);

  for (int x = 0; x < 5; x++){
    printf("->> %d\n", Vis[x]);
  }

  printf("--> %f\n", Aux);

  libera_Grafo(gr);
  printf("PEGOU!!\n");
  return 0;
}
