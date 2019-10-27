struct grafo{
  int eh_Ponderado;
  int nro_Vertice;
  int grau_Max;
  int ** arestas;
  float ** pesos;
  int * Grau;
};

typedef struct grafo Grafo;

Grafo * cria_Grafo (int nro_Vertice, int grau_Max, int ehPonderado);
void libera_Grafo(Grafo* gr);
int inserirAresta(Grafo *gr, int orig, int dest, int eh_Digrafo, float peso);
int removeAresta(Grafo* gr, int orig, int dest, int eh_Digrafo);
void buscaProfundidade(Grafo *gr, int ini, int *visitado, int cont);
void buscaProfundidade_Grafo(Grafo *gr, int ini, int *visitado);
void buscaLargura_Grafo(Grafo *gr, int ini, int *visitado);

int procuraMenorDistancia(float *dist, int *visitado, int NV);
void menorCaminho_Grafo(Grafo *gr, int ini, int *ant, float *dist);
