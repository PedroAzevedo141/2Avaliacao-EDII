#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"

listaGrafos * CriaLista_Grafos(){
  return NULL;
}

listaGrafos * InserirListaGrafos(listaGrafos *Lista, char *Nome, int Vertice, char *Aux1, char *Aux2, char *Aux3, char *Aux4, char *Aux5){
  int x;
  listaGrafos *novo;
  novo = (listaGrafos*)malloc(sizeof(listaGrafos));
  novo->QtdVertice = Vertice;
  strcpy(novo->Nome, Nome);
  cria_grafo(&novo->g, Vertice);
  for (x = 0; x < Vertice; x++){
    adiciona_aresta(&novo->g, x, x+1);
  }
  if (strlen(Aux1) >= 2){
    inserir_Nome(&novo->g, 0, Aux1);
  }
  if (strlen(Aux2) >= 2){
    inserir_Nome(&novo->g, 1, Aux2);
  }
  if (strlen(Aux3) >= 2){
    inserir_Nome(&novo->g, 2, Aux3);
  }
  if (strlen(Aux4) >= 2){
    inserir_Nome(&novo->g, 3, Aux4);
  }
  if (strlen(Aux5) >= 2){
    inserir_Nome(&novo->g, 4, Aux5);
  }
  novo->Prox = Lista;
  return novo;
}

void ImprimirLista(listaGrafos *Lista){
  listaGrafos *Aux;
  for (Aux = Lista; Aux != NULL; Aux = Aux->Prox){
    printf("-> %s\n", Aux->Nome);
  }
}

void BuscarListaGrafos(listaGrafos *Lista, char *Nome){
  listaGrafos *Aux = Lista;
  while (Aux != NULL){
    if (strcmp(Aux->Nome, Nome) == 0){
      imprimirSequencia(&Aux->g, 0, Aux->QtdVertice);
      return;
    }
    Aux = Aux->Prox;
  }
  printf("Error: Informacao Incorreta!!\n");
}

// Grafo usando lista de Adjacencia

void cria_grafo(Grafo* g, int n)  {
  g->lista = (No**)calloc(n, sizeof(No*));
  g->n = n;
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

void imprimirSequencia(Grafo *g, int v1, int Qtd) {
  if (g->lista[v1] != NULL && v1 < Qtd){
    No *l = g->lista[v1];
    while (l != NULL){
      if (strcmp(l->Nome, "---") != 0){
        printf("-=-=-=-=-=-=-=-=-\n");
        printf("---> %s\n", l->Nome);
        printf("-=-=-=-=-=-=-=-=-\n");
      }
      imprimirSequencia(g, l->v, Qtd);
      l = l->prox;
    }
  }
}
