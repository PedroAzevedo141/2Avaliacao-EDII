#include "Funcoes.c"

int main (void){

  Grafo *gr;

  gr = cria_Grafo(81, 81, 0);

  inserirAresta(gr, 1111, 3111, 0);
  inserirAresta(gr, 1111, 2111, 0);
  inserirAresta(gr, 3111, 2111, 0);
  inserirAresta(gr, 3111, 3211, 0);
  inserirAresta(gr, 3211, 2211, 0);
  inserirAresta(gr, 2211, 1211, 0);
  inserirAresta(gr, 3211, 1211, 0);
  inserirAresta(gr, 2111, 2311, 0);
  inserirAresta(gr, 2311, 1311, 0);
  inserirAresta(gr, 3311, 1311, 0);
  inserirAresta(gr, 2311, 3311, 0);
  inserirAresta(gr, 1211, 1311, 0);
  inserirAresta(gr, 2211, 2231, 0);
  inserirAresta(gr, 3311, 3321, 0);
  inserirAresta(gr, 2231, 1231, 0);
  inserirAresta(gr, 2231, 3231, 0);
  inserirAresta(gr, 3321, 2321, 0);
  inserirAresta(gr, 3321, 1321, 0);
  inserirAresta(gr, 1231, 1331, 0);
  inserirAresta(gr, 1321, 1221, 0);
  inserirAresta(gr, 3231, 3131, 0);
  inserirAresta(gr, 2321, 2121, 0);
  inserirAresta(gr, 1231, 3231, 0);
  inserirAresta(gr, 2321, 1321, 0);
  inserirAresta(gr, 1331, 3331, 0);
  inserirAresta(gr, 1331, 2331, 0);
  inserirAresta(gr, 3331, 2331, 0);
  inserirAresta(gr, 3131, 2131, 0);
  inserirAresta(gr, 3131, 1131, 0);
  inserirAresta(gr, 2131, 1131, 0);
  inserirAresta(gr, 2331, 2131, 0);
  inserirAresta(gr, 2121, 1121, 0);
  inserirAresta(gr, 2121, 3121, 0);
  inserirAresta(gr, 1121, 3121, 0);
  inserirAresta(gr, 1221, 3221, 0);
  inserirAresta(gr, 1221, 2221, 0);
  inserirAresta(gr, 3221, 2221, 0);
  inserirAresta(gr, 3121, 3221, 0);
  inserirAresta(gr, 3331, 3332, 0);
  inserirAresta(gr, 2221, 2223, 0);
  inserirAresta(gr, 1131, 1121, 0);

  inserirAresta(gr, 3332, 1332, 0);
  inserirAresta(gr, 3332, 2332, 0);
  inserirAresta(gr, 1332, 2332, 0);
  inserirAresta(gr, 1332, 1232, 0);
  inserirAresta(gr, 1232, 2232, 0);
  inserirAresta(gr, 1232, 3232, 0);
  inserirAresta(gr, 2332, 2132, 0);
  inserirAresta(gr, 2132, 1132, 0);
  inserirAresta(gr, 2132, 3132, 0);
  inserirAresta(gr, 3232, 3132, 0);
  inserirAresta(gr, 2232, 3232, 0);
  inserirAresta(gr, 3132, 1132, 0);
  inserirAresta(gr, 2232, 2212, 0);
  inserirAresta(gr, 1132, 1122, 0);
  inserirAresta(gr, 2212, 3212, 0);
  inserirAresta(gr, 2212, 1212, 0);
  inserirAresta(gr, 3212, 1212, 0);
  inserirAresta(gr, 1122, 2122, 0);
  inserirAresta(gr, 1122, 3122, 0);
  inserirAresta(gr, 2122, 3122, 0);
  inserirAresta(gr, 2122, 2322, 0);
  inserirAresta(gr, 1212, 1312, 0);
  inserirAresta(gr, 3122, 3222, 0);
  inserirAresta(gr, 3112, 1112, 0);
  inserirAresta(gr, 3112, 2112, 0);
  inserirAresta(gr, 1112, 2112, 0);
  inserirAresta(gr, 1312, 2312, 0);
  inserirAresta(gr, 1312, 3312, 0);
  inserirAresta(gr, 2312, 3312, 0);
  inserirAresta(gr, 2112, 2312, 0);
  inserirAresta(gr, 2322, 3322, 0);
  inserirAresta(gr, 2322, 1322, 0);
  inserirAresta(gr, 3322, 1322, 0);
  inserirAresta(gr, 3222, 1222, 0);
  inserirAresta(gr, 3222, 2222, 0);
  inserirAresta(gr, 1222, 2222, 0);
  inserirAresta(gr, 1322, 1222, 0);
  inserirAresta(gr, 3212, 3112, 0);
  inserirAresta(gr, 3312, 3322, 0);

  inserirAresta(gr, 2223, 3223, 0);
  inserirAresta(gr, 2223, 1223, 0);
  inserirAresta(gr, 3223, 1223, 0);
  inserirAresta(gr, 3223, 3123, 0);
  inserirAresta(gr, 1223, 1323, 0);
  inserirAresta(gr, 3123, 1123, 0);
  inserirAresta(gr, 3123, 2123, 0);
  inserirAresta(gr, 1123, 2123, 0);
  inserirAresta(gr, 1323, 2323, 0);
  inserirAresta(gr, 1323, 3323, 0);
  inserirAresta(gr, 2323, 3323, 0);
  inserirAresta(gr, 2123, 2323, 0);
  inserirAresta(gr, 1123, 1133, 0);
  inserirAresta(gr, 3323, 3313, 0);
  inserirAresta(gr, 1133, 2133, 0);
  inserirAresta(gr, 1133, 3133, 0);
  inserirAresta(gr, 2133, 3133, 0);
  inserirAresta(gr, 2133, 2333, 0);
  inserirAresta(gr, 3313, 1313, 0);
  inserirAresta(gr, 3313, 2313, 0);
  inserirAresta(gr, 1313, 2313, 0);
  inserirAresta(gr, 3133, 3233, 0);
  inserirAresta(gr, 1313, 1213, 0);
  inserirAresta(gr, 2313, 2113, 0);
  inserirAresta(gr, 2333, 3333, 0);
  inserirAresta(gr, 2333, 1333, 0);
  inserirAresta(gr, 3333, 1333, 0);
  inserirAresta(gr, 3233, 1233, 0);
  inserirAresta(gr, 3233, 2233, 0);
  inserirAresta(gr, 1333, 1233, 0);
  inserirAresta(gr, 1213, 2213, 0);
  inserirAresta(gr, 1213, 3213, 0);
  inserirAresta(gr, 2213, 3213, 0);
  inserirAresta(gr, 2113, 3113, 0);
  inserirAresta(gr, 2113, 1113, 0);
  inserirAresta(gr, 3113, 1113, 0);
  inserirAresta(gr, 3213, 3113, 0);
  inserirAresta(gr, 2233, 2213, 0);
  inserirAresta(gr, 1233, 2233, 0);
  inserirAresta(gr, 1112, 1113, 0);

  int ant[81], Config, posicao, x = 0, n1 = 0, n2;
  float dist[81];

  printf("Informe a configuracao atual:\n>>> ");
  scanf("%d", &Config);
  if (existeVertice(gr, Config, &posicao, 2)){
    menorCaminho_Grafo(gr, posicao, ant, dist);
    // for (int i = 0; i < 81; i++){
    //   printf("%d --> ant: %d --||-- dist: %.2f\n", i, ant[i], dist[i]);
    // }
    if (dist[54] < dist[73]){
      x = 54;
    }else{
      x = 73;
    }
    n2 = x;
    n1 = (int)dist[x];
    int Aux[n1 + 1];
    for (int i = 0; i < n1; i++){
      x = ant[x];
      Aux[i] = x;
    }
    printf("Melhor Caminho:\n");
    for (int i = n1 - 1; i >= 0; i--){
      printf(">>> %d\n", gr->nomeVertice[Aux[i]]);
    }
    printf(">>> %d\n", gr->nomeVertice[n2]);
  }else{
    printf("Error: Configuracao Incorreta!!\n");
  }

  libera_Grafo(gr);
  return 0;
}
