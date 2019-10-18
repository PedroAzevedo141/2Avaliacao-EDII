#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

Grafo * cria_Grafo (int nro_Vertice, int grau_Max, int ehPonderado){
  Grafo * gr = (Grafo*) malloc (sizeof(Grafo));
  if (gr != NULL){
    int i;
    gr->nro_Vertice = nro_Vertice;
    gr->grau_Max = grau_Max;
    gr->eh_Ponderado = (ehPonderado != 0) ? 1 : 0;
    gr->Grau = (int*)calloc(nro_Vertice, sizeof(int));
    gr->arestas = (int**)malloc(nro_Vertice * sizeof(int*));
    for(i = 0; i < nro_Vertice; i++){
      gr->arestas[i] = (int*)malloc(grau_Max * sizeof(int));
    }
    if (gr->eh_Ponderado){
      gr->pesos = (float**)malloc(nro_Vertice * sizeof(float*));
      for(i = 0; i < nro_Vertice; i++){
        gr->pesos[i] = (float*)malloc(grau_Max * sizeof(float));
      }
    }
  }
  return gr;
}

void libera_Grafo(Grafo* gr){
  if (gr != NULL){
    int i;
    for(i = 0; i < gr->nro_Vertice; i++){
      free(gr->arestas[i]);
    }
    free(gr->arestas);

    if (gr->eh_Ponderado){
      for (i = 0; i < gr->nro_Vertice; i++){
        free(gr->pesos[i]);
      }
      free(gr->pesos);
    }
    free(gr->Grau);
    free(gr);
  }
}

int inserirAresta(Grafo *gr, int orig, int dest, int eh_Digrafo, float peso){
  if (gr == NULL){
    return 0;
  }
  if (orig < 0 || orig >= gr->nro_Vertice){
    return 0;
  }
  if (dest < 0 || dest >= gr->nro_Vertice){
    return 0;
  }

  gr->arestas[orig][gr->Grau[orig]] = dest;
  if (gr->eh_Ponderado){
    gr->pesos[orig][gr->Grau[orig]] = peso;
  }
  gr->Grau[orig]++;

  if (!eh_Digrafo){
    inserirAresta(gr, dest, orig, 1, peso);
  }
  return 1;
}

int removeAresta(Grafo* gr, int orig, int dest, int eh_Digrafo){
  if (gr == NULL){
    return 0;
  }
  if (orig < 0 || orig >= gr->nro_Vertice){
    return 0;
  }
  if (dest < 0 || dest >= gr->nro_Vertice){
    return 0;
  }

  int i = 0;
  while (i < gr->Grau[orig] && gr->arestas[orig][i] != dest){
    i++;
  }
  if (i == gr->Grau[orig]){
    return 0;
  }
  gr->Grau[orig]--;
  gr->arestas[orig][i] = gr->arestas[orig][gr->Grau[orig]];
  if (gr->eh_Ponderado){
    gr->pesos[orig][i] = gr->pesos[orig][gr->Grau[orig]];
  }
  if (!eh_Digrafo){
    removeAresta(gr, dest, orig, 1);
  }
  return 1;
}

void buscaProfundidade(Grafo *gr, int ini, int *visitado, int cont){
  int i;
  visitado[ini] = cont;
  for (i = 0; i < gr->Grau[ini]; i++){
    if (!visitado[gr->arestas[ini][i]]){
      buscaProfundidade(gr, gr->arestas[ini][i], visitado, cont + 1);
    }
  }
}

void buscaProfundidade_Grafo(Grafo *gr, int ini, int *visitado){
  int i, cont = 1;
  for (i = 0; i < gr->nro_Vertice; i++){
    visitado[i] = 0;
  }
  buscaProfundidade(gr, ini, visitado, cont);
}

void buscaLargura_Grafo(Grafo *gr, int ini, int *visitado){
  int i, vert, NV, cont = 1, *fila, IF = 0, FF = 0;
  for (i = 0; i < gr->nro_Vertice; i++){
    visitado[i] = 0;
  }
  NV = gr->nro_Vertice;
  fila = (int*)malloc(NV * sizeof(int));
  FF++;
  fila[FF] = ini;
  visitado[ini] = cont;
  while (IF != FF){
    IF = (IF + 1) % NV;
    vert = fila[FF];
    cont++;
    for (i = 0; i < gr->Grau[vert]; i++){
      if (!visitado[gr->arestas[vert][i]]){
        FF = (FF + 1) % NV;
        fila[FF] = gr->arestas[vert][i];
        visitado[gr->arestas[vert][i]] = cont;
      }
    }
  }
  free(fila);
}

























//
