#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"

Grafo * cria_Grafo (int nro_Vertice, int grau_Max, int ehPonderado){
  Grafo * gr = (Grafo*) malloc (sizeof(Grafo));
  if (gr != NULL){
    int i;
    gr->nro_Vertice = nro_Vertice;
    gr->grau_Max = grau_Max;
    gr->eh_Ponderado = (ehPonderado != 0) ? 1 : 0;
    gr->Grau = (int*)calloc(nro_Vertice, sizeof(int));
    gr->nomeVertice = (int*)calloc(nro_Vertice, sizeof(int));
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
    gr->QtdVertice = 0;
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

int existeVertice(Grafo *gr, int Numero, int *posicao, int Key){
  int i;
  if (Key == 1){
    for (i = 0; i < gr->QtdVertice; i++){
      if (gr->nomeVertice[i] == Numero){
        *posicao = i;
        return 1;
      }
    }
    gr->nomeVertice[i] = Numero;
    *posicao = i;
    return 0;
  }else if (Key == 2){
    for (i = 0; i < gr->QtdVertice; i++){
      if (gr->nomeVertice[i] == Numero){
        *posicao = i;
        return 1;
      }
    }
    return 0;
  }
}

int inserirAresta(Grafo *gr, int orig, int dest, int eh_Digrafo){
  if (gr == NULL){
    return 0;
  }

  int Key = 0, pOrig, pDest;
  Key = existeVertice(gr, orig, &pOrig, 1);
  if (!Key){
    gr->QtdVertice++;
  }
  Key = existeVertice(gr, dest, &pDest, 1);
  if (!Key){
    gr->QtdVertice++;
  }
  // printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-\n");
  // printf("Origem: %d \t\t--\tDestino: %d\nPosicao Origem: %d \t--\tPosicao Destino: %d\n", orig, dest, pOrig, pDest);
  // printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-=-=-\n");

  if (pOrig < 0 || pOrig >= gr->nro_Vertice){
    return 0;
  }
  if (pDest < 0 || pDest >= gr->nro_Vertice){
    return 0;
  }

  gr->arestas[pOrig][gr->Grau[pOrig]] = pDest;
  gr->Grau[pOrig]++;

  if (!eh_Digrafo){
    inserirAresta(gr, dest, orig, 1);
  }

  return 1;
}

int procuraMenorDistancia(float *dist, int *visitado, int NV){
  int i, menor = -1, primeiro = 1;
  for (i = 0; i < NV; i++){
    if (dist[i] >= 0 && visitado[i] == 0){
      if (primeiro){
        menor = i;
        primeiro = 0;
      }else{
        if(dist[menor] > dist[i]){
          menor = i;
        }
      }
    }
  }
  return menor;
}

void menorCaminho_Grafo(Grafo *gr, int ini, int *ant, float *dist){
  int i, cont, NV, ind, *visitado, u;
  cont = NV = gr->nro_Vertice;
  visitado = (int*)malloc(NV * sizeof(int));
  for (i = 0; i < NV; i++){
    ant[i] = -1;
    dist[i] = -1;
    visitado[i] = 0;
  }
  dist[ini] = 0;
  while(cont > 0){
    u = procuraMenorDistancia(dist, visitado, NV);
    if (u == -1){
      break;
    }
    visitado[u] = 1;
    cont--;
    for (i = 0; i < gr->Grau[u]; i++){
      ind = gr->arestas[u][i];
      if(dist[ind] < 0){
        dist[ind] = dist[u] + 1;
        // dist[ind] = dist[u] + gr->pesos[u][i];
        ant[ind] = u;
      }else{
        if(dist[ind] > dist[u] + 1){
        // if (dist[ind] > dist[u] + 1){
          dist[ind] = dist[u] + 1;
          dist[ind] = dist[u] + gr->pesos[u][i];
          ant[ind] = u;
        }
      }
    }
  }
  free(visitado);
}
