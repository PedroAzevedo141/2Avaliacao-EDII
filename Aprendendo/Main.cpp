#include "Funcoes.cpp"

int main (void){
  Grafo *gr;
  gr = cria_Grafo(5, 5, 1);
  inserirAresta(gr, 0, 1, 1, 0);
  inserirAresta(gr, 1, 3, 1, 0);
  inserirAresta(gr, 1, 2, 1, 0);
  inserirAresta(gr, 2, 4, 1, 0);
  inserirAresta(gr, 3, 0, 1, 0);
  inserirAresta(gr, 3, 4, 1, 0);
  inserirAresta(gr, 4, 1, 1, 0);

  int ant[5];
  float dist[5];
  // float Aux = 0;

  // buscaProfundidade_Grafo(gr, 0, Vis, &Aux);

  // buscaLargura_Grafo(gr, 0, Vis);

  menorCaminho_Grafo(gr, 0, ant, dist);

  for (int x = 0; x < 5; x++){
    printf("--> ant: %d --||-- dist: %.2f\n", ant[x], dist[x]);
  }

  // printf("--> %f\n", Aux);

  libera_Grafo(gr);
  printf("PEGOU!!\n");
  return 0;
}
