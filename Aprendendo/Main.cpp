#include "Funcoes.cpp"

int main (void){
  Grafo *gr;
  gr = cria_Grafo(5, 5, 0);
  inserirAresta(gr, 0, 1, 1, 0);
  inserirAresta(gr, 1, 3, 1, 0);
  inserirAresta(gr, 1, 2, 1, 0);
  inserirAresta(gr, 2, 4, 1, 0);
  inserirAresta(gr, 3, 0, 1, 0);
  inserirAresta(gr, 3, 4, 1, 0);
  inserirAresta(gr, 4, 1, 1, 0);


  int Vis[5];

  // buscaProfundidade_Grafo(gr, 0, Vis);

  buscaLargura_Grafo(gr, 0, Vis);

  for (int x = 0; x < 5; x++){
    printf("->> %d\n", Vis[x]);
  }

  libera_Grafo(gr);
  printf("PEGOU!!\n");
  return 0;
}
