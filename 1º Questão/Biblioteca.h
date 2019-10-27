struct grafo{
  int eh_Ponderado;
  int nro_Vertice;
  int grau_Max;
  int ** arestas;
  float ** pesos;
  int * Grau;
  int *nomeVertice;
  int QtdVertice;
};

typedef struct grafo Grafo;

Grafo * cria_Grafo (int nro_Vertice, int grau_Max, int ehPonderado);
void libera_Grafo(Grafo* gr);
int inserirAresta(Grafo *gr, int orig, int dest, int eh_Digrafo);
int existeVertice(Grafo *gr, int Numero, int *posicao, int Key);

int procuraMenorDistancia(float *dist, int *visitado, int NV);
void menorCaminho_Grafo(Grafo *gr, int ini, int *ant, float *dist);
