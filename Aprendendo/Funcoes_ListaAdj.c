#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca_ListaAdj.h"

void cria_grafo(Grafo* g, int n)  {
  g->lista = (No**)calloc(n, sizeof(No*));
  g->n = n;
}

void destroi(Grafo *g) {
  int i;
  for (i = 0; i < g->n; i++) {
    No* l = g->lista[i];
    while (l) {
      No *r = l;
      l = l->prox;
      free(r);
    }
  }
  free(g->lista);
}

void inserir_Nome(Grafo *g, int v, char *Nome){
  No **ap_l = &g->lista[v];
  strcpy((*ap_l)->Nome, Nome);
}

void adiciona_aresta(Grafo *g, int v1, int v2) {
  No **ap_l = &g->lista[v1];
  while (*ap_l != NULL && (*ap_l)->v < v2)
    ap_l = &(*ap_l)->prox;
  if (*ap_l == NULL || (*ap_l)->v != v2) {
    No* n = (No*)malloc(sizeof(No));
    n->v = v2;
    n->prox = *ap_l;
    *ap_l = n;
  }
}

int existe_aresta(Grafo *g, int v1, int v2) {
  No *l = g->lista[v1];
  while (l != NULL && l->v < v2)
    l = l->prox;
  if (l != NULL && l->v == v2)
    return 1;
  return 0;
}

void imprimirSequencia(Grafo *g, int v1) {
  if (g->lista[v1] != NULL){
    No *l = g->lista[v1];
    while (l != NULL){
      printf("-=-=-=-=-=-=-=-=-\n");
      printf("--> %d\n---> %s\n", l->v, l->Nome);
      printf("-=-=-=-=-=-=-=-=-\n");
      imprimirSequencia(g, l->v);
      l = l->prox;
    }
  }
}

void remove_aresta(Grafo *g, int v1, int v2) {
  No **ap_l = &g->lista[v1];
  while (*ap_l != NULL &&
	 (*ap_l)->v < v2)
    ap_l = &(*ap_l)->prox;
  if (*ap_l != NULL && (*ap_l)->v == v2) {
    No* r = *ap_l;
    *ap_l = (*ap_l)->prox;
    free(r);
  }
}
