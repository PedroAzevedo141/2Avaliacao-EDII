#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"

int Menu(int x){
  int Aux;
  if (x == 1){
    printf("-=-=- MENU -=-=-\n"
    "1 - Adicionar Cidades\n"
    "2 - Melhor Trajeto (Usando profundidade)\n"
    "3 - Refazer\n"
    "4 - Sair\n"
    ">>> ");
    scanf("%d", &Aux);
    return Aux;
  }else if (x == 2){
    system("clear");
    printf("-=-=- MENU -=-=-\n"
    "1 - Modificar o valor total a ser pago com pegadios.\n"
    "2 - Refazer o grafo.\n"
    ">>> ");
    scanf("%d", &Aux);
    return Aux;
  }
}

Grafo * cria_Grafo (int nro_Vertice, int grau_Max, int ehPonderado){
  Grafo * gr = (Grafo*) malloc (sizeof(Grafo));
  if (gr != NULL){
    int i;
    gr->nro_Vertice = nro_Vertice;
    gr->grau_Max = grau_Max;
    gr->eh_Ponderado = (ehPonderado != 0) ? 1 : 0;
    gCidades = (int*)malloc(nro_Vertice * sizeof(int));
    gr->Grau = (int*)calloc(nro_Vertice, sizeof(int));
    gr->nomeVertice = (char**)malloc(nro_Vertice * sizeof(char*));
    for (i = 0; i < nro_Vertice; i++){
      gr->nomeVertice[i] = (char*)malloc(100 * sizeof(char));
    }
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
    for (i = 0; i < gr->nro_Vertice; i++){
      free(gr->nomeVertice[i]);
      gr->nomeVertice[i] = NULL;
    }
    free(gr->nomeVertice);
    gr->nomeVertice = NULL;

    for(i = 0; i < gr->nro_Vertice; i++){
      free(gr->arestas[i]);
      gr->arestas[i] = NULL;
    }
    free(gr->arestas);
    gr->arestas = NULL;

    if (gr->eh_Ponderado){
      for (i = 0; i < gr->nro_Vertice; i++){
        free(gr->pesos[i]);
        gr->pesos[i] = NULL;
      }
      free(gr->pesos);
      gr->pesos = NULL;
    }
    free(gr->Grau);
    gr->Grau = NULL;
    free(gr);
  }
}

int existeVertice(Grafo *gr, char *Cidade, int *Pos){
  int i;
  if (gr->QtdVertice <= gr->nro_Vertice){
    for (i = 0; i < gr->QtdVertice; i++){
      if (strcmp(gr->nomeVertice[i], Cidade) == 0){
        *Pos = i;
        return 1;
      }
    }
    *Pos = i;
    return 0;
  }else{
    return -1;
  }
}

int inserirVertice(Grafo *gr){
  if (gr->QtdVertice <= gr->nro_Vertice){
    int Aux[2], Existente = 0, Pos1, Pos2, Key;
    float precoPedagio;
    char cidadeOrigem[100], cidadeDestino[100];
    printf("Informe o nome da cidade de origem: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]s", cidadeOrigem);
    printf("Informe o nome da cidade de destino: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]s", cidadeDestino);
    printf("Informe o valor dos pedagios: ");
    scanf("%f", &precoPedagio);
    Key = existeVertice(gr, cidadeOrigem, &Pos1);
    if(Key == -1){
      printf("Quantidade maxima de cidades atingida!\n");
      return 0;
    }else if (!Key){
      if (gr->QtdVertice < gr->nro_Vertice){
        strcpy(gr->nomeVertice[gr->QtdVertice], cidadeOrigem);
        gr->QtdVertice++;
      }else{
        printf("Quantidade maxima de cidades atingida!\n");
        return 0;
      }
    }
    Key = existeVertice(gr, cidadeDestino, &Pos2);
    if(Key == -1){
      printf("Quantidade maxima de cidades atingida!\n");
      return 0;
    }else if (!Key){
      if (gr->QtdVertice < gr->nro_Vertice){
        strcpy(gr->nomeVertice[gr->QtdVertice], cidadeDestino);
        gr->QtdVertice++;
      }else{
        printf("Quantidade maxima de cidades atingida!\n");
        return 0;
      }
    }
    return inserirAresta(gr, Pos1, Pos2, 0, precoPedagio);
  }else{
    printf("Quantidades maxima de cidades atingida!\n");
    return 0;
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

void buscaLargura_Grafo(Grafo *gr, int ini, int *visitado, float precoTotal){
  int i, vert, NV, cont = 1, *fila, IF = 0, FF = 0;
  float Aux = 0;
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
    vert = fila[IF];
    cont++;
    for (i = 0; i < gr->Grau[vert]; i++){
      if (!visitado[gr->arestas[vert][i]]){
        FF = (FF + 1) % NV;
        fila[FF] = gr->arestas[vert][i];
        visitado[gr->arestas[vert][i]] = cont;
        Aux += gr->pesos[vert][i];
        if (Aux <= precoTotal){
          printf("->> %s\n", gr->nomeVertice[gr->arestas[vert][i]]);
        }
      }
    }
  }
  free(fila);
}

// float pesoAresta(Grafo *gr, char *Cidade1, char *Cidade2){
//   int i, pos1, pos2;
//   if (existeVertice(gr, Cidade1, &pos1)){
//     if (existeVertice(gr, Cidade2, &pos2)){
//       for (i = 0; i < gr->Grau[pos1]; i++){
//         if (gr->arestas[pos1][i] == pos2){
//           return gr->pesos[pos1][i];
//         }
//       }
//       return -1;
//     }
//   }
// }
//
// void guardaOcorrecia(int x){
//   gCidades[gCount] = x;
//   gCount++;
// }

// void buscaProfundidade(Grafo *gr, int ini, int *visitado, int cont){
//   int i;
//   visitado[ini] = cont;
//   for (i = 0; i < gr->Grau[ini]; i++){
//     if (!visitado[gr->arestas[ini][i]]){
//       buscaProfundidade(gr, gr->arestas[ini][i], visitado, cont + 1);
//       guardaOcorrecia(gr->arestas[ini][i]);
//     }
//   }
// }
//
// void buscaProfundidade_Grafo(Grafo *gr, int ini, float precoTotal){
//   int i, cont = 1, visitado[gr->nro_Vertice];
//   for (i = 0; i < gr->nro_Vertice; i++){
//     visitado[i] = 0;
//   }
//   buscaProfundidade(gr, ini, visitado, cont);
//   imprimirCidade(gr, ini, precoTotal);
// }

// void imprimirCidade(Grafo *gr, int ini, float precoTotal){
//   char stringAux[100];
//   float Aux = 0, Aux2;
//   printf("Cidades a serem vizitadas:\n");
//   printf("Saindo de %s\n", gr->nomeVertice[ini]);
//   strcpy(stringAux, gr->nomeVertice[ini]);
//   for (int x = gr->nro_Vertice - 2; x >= 0; x--){
//     Aux2 = pesoAresta(gr, stringAux, gr->nomeVertice[gCidades[x]]);
//     if (Aux2 != -1){
//       Aux += pesoAresta(gr, stringAux, gr->nomeVertice[gCidades[x]]);
//       if (Aux <= precoTotal){
//         printf("-- %s\n", gr->nomeVertice[gCidades[x]]);
//       }
//       Aux2 = pesoAresta(gr, gr->nomeVertice[gCidades[x]], gr->nomeVertice[gCidades[x - 1]]);
//       if (Aux2 != -1){
//         strcpy(stringAux, gr->nomeVertice[gCidades[x]]);
//       }
//     }
//   }
//   gCount = 0;
// }
