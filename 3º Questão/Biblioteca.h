struct grafo{
  int eh_Ponderado;
  int nro_Vertice;
  int grau_Max;
  int ** arestas;
  float ** pesos;
  int * Grau;
  char **nomeVertice;
  int QtdVertice;
};

typedef struct grafo Grafo;

int Menu(int x);

int * gCidades, gCount = 0;
void guardaOcorrecia(int x);

Grafo * cria_Grafo (int nro_Vertice, int grau_Max, int ehPonderado);
void libera_Grafo(Grafo* gr);
int inserirVertice(Grafo *gr);
int existeVertice(Grafo *gr, char *Cidade, int *Pos);
int inserirAresta(Grafo *gr, int orig, int dest, int eh_Digrafo, float peso);
void buscaProfundidade(Grafo *gr, int ini, int *visitado, int cont);
void buscaProfundidade_Grafo(Grafo *gr, int ini, float precoTotal);
void imprimirCidade(Grafo *gr, int ini, float precoTotal);
float pesoAresta(Grafo *gr, char *Cidade1, char *Cidade2);
