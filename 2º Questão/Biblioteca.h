// Grafo usando lista de Adjacencia

typedef struct no {
  int v;
  char Nome[20];
  struct no* prox;
} No;

typedef struct grafo {
  int n;
  No** lista;
} Grafo;

void cria_grafo(Grafo* g, int n);
void adiciona_aresta(Grafo *g, int v1, int v2);
void imprimirSequencia(Grafo *g, int v1, int Qtd);
void inserir_Nome(Grafo *g, int v, char *Nome);

// Lista para separar os grafos

typedef struct lista listaGrafos;

struct lista{
  int QtdVertice;
  char Nome[20];
  Grafo g;
  listaGrafos *Prox;
};

listaGrafos * CriaLista_Grafos();
listaGrafos * InserirListaGrafos(listaGrafos *Lista, char *Nome, int Vertice, char *Aux1, char *Aux2, char *Aux3, char *Aux4, char *Aux5);
void BuscarListaGrafos(listaGrafos *Lista, char *Nome);
void ImprimirLista(listaGrafos *Lista);
