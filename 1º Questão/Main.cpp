#include "Funcoes.cpp"

int main (void){
  Grafo *gr;
  gr = cria_Grafo(27, 27, 0);
  inserirAresta(gr, 11, 31, 0, 0);
  inserirAresta(gr, 11, 21, 0, 0);
  inserirAresta(gr, 31, 32, 0, 0);
  inserirAresta(gr, 31, 21, 0, 0);
  inserirAresta(gr, 21, 23, 0, 0);
  inserirAresta(gr, 32, 22, 0, 0);
  inserirAresta(gr, 32, 12, 0, 0);
  inserirAresta(gr, 23, 13, 0, 0);
  inserirAresta(gr, 23, 33, 0, 0);
  inserirAresta(gr, 12, 13, 0, 0);
  inserirAresta(gr, 22, 12, 0, 0);
  inserirAresta(gr, 13, 33, 0, 0);


  int Vis[5];

  buscaProfundidade_Grafo(gr, 0, Vis);

  // buscaLargura_Grafo(gr, 0, Vis);

  for (int x = 0; x < 5; x++){
    printf("->> %d\n", Vis[x]);
  }

  libera_Grafo(gr);
  printf("PEGOU!!\n");
  return 0;
}
