typedef struct no {
  int v; /* Vértice */
  char Nome[20];
  struct no* prox;
} No;

typedef struct grafo {
  int n;      /* Número de nós */
  No** lista;
} Grafo;


void cria_grafo(Grafo* g, int n);
void destroi(Grafo *g);
void adiciona_aresta(Grafo *g, int v1, int v2);
int existe_aresta(Grafo *g, int v1, int v2);
void remove_aresta(Grafo *g, int v1, int v2);
void imprimirSequencia(Grafo *g, int v1);
void inserir_Nome(Grafo *g, int v, char *Nome);
