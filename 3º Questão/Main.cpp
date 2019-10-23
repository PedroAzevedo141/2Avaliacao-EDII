#include "Funcoes.cpp"

int main (void){
  Grafo *gr;
  char NomeCidade[100];
  int QtdCidades, escolhaMenu, escolhaRefazer, Aux;
  float precoPedagios, valorPedagio_Pai;

  printf("Informe as quantidades de cidades: ");
  scanf("%d", &QtdCidades);
  printf("Informe o valor maximo a ser pago com pedagios: ");
  scanf("%f", &valorPedagio_Pai);

  gr = cria_Grafo(QtdCidades, QtdCidades * QtdCidades, 1);

  while(true){
    escolhaMenu = Menu(1);
    switch (escolhaMenu) {
      case 1:
        inserirVertice(gr);
        break;
      case 2:
        printf("Informe o nome da cidade de origem: ");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", NomeCidade);
        if (existeVertice(gr, NomeCidade, &Aux)){
          buscaProfundidade_Grafo(gr, Aux, valorPedagio_Pai);
        }else{
          printf("Essa cidade nao existe no grafo!\n");
        }
        break;
      case 3:
        escolhaRefazer = Menu(2);
        switch (escolhaRefazer) {
          case 1:
            printf("Informe o valor maximo a ser pago com pedagios: ");
            scanf("%f", &valorPedagio_Pai);
            break;
          case 2:
            libera_Grafo(gr);
            gr = NULL;
            printf("Informe as quantidades de cidades: ");
            scanf("%d", &QtdCidades);
            printf("Informe o valor maximo a ser pago com pedagios: ");
            scanf("%f", &valorPedagio_Pai);
            gr = cria_Grafo(QtdCidades, QtdCidades * QtdCidades, 1);
            break;            
        }
        break;
      case 4:
        libera_Grafo(gr);
        exit(1);
      default:
        printf("Error: Informacao Incorreta!\n");
    }
  }
  return 0;
}
