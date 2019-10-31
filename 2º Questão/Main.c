#include "Funcao.c"

int main (void){
  char String[20];
  listaGrafos *l_gr;
  l_gr = CriaLista_Grafos();


  l_gr = InserirListaGrafos(l_gr, "+1+1+1+1", 5, "---", "+1+1+1+1", "+1+1+1", "+1+1", "+1");
  l_gr = InserirListaGrafos(l_gr, "-1+1+1+1", 4, "---", "-1+1+1+1", "+1+1", "+1", "0");
  l_gr = InserirListaGrafos(l_gr, "-1-1+1+1", 3, "---", "-1-1+1+1", "-1+1", "0", "0");
  l_gr = InserirListaGrafos(l_gr, "-1-1-1+1", 4, "---", "-1-1-1+1", "-1-1", "-1", "0");
  l_gr = InserirListaGrafos(l_gr, "-1-1-1-1", 5, "---", "-1-1-1-1", "-1-1-1", "-1-1", "-1");
  l_gr = InserirListaGrafos(l_gr, "+1-1-1-1", 5, "---", "+1-1-1-1", "-1+1-1-1", "-1+1-1", "-1+1");
  l_gr = InserirListaGrafos(l_gr, "+1+1-1-1", 5, "---", "+1+1-1-1", "+1-1+1-1", "-1+1-1+1", "-1+1");
  l_gr = InserirListaGrafos(l_gr, "+1+1+1-1", 5, "---", "+1+1+1-1", "+1+1-1-1", "+1-1+1", "-1+1");
  l_gr = InserirListaGrafos(l_gr, "+1-1+1-1", 4, "---", "+1-1+1-1", "-1+1-1+1", "-1+1", "0");
  l_gr = InserirListaGrafos(l_gr, "-1+1-1+1", 3, "---", "-1+1-1+1", "-1+1", "0", "0");
  l_gr = InserirListaGrafos(l_gr, "-1+1+1-1", 4, "---", "-1+1+1-1", "+1-1+1", "-1+1", "0");
  l_gr = InserirListaGrafos(l_gr, "+1-1-1+1", 4, "---", "+1-1-1+1", "-1+1-1", "-1+1", "0");

  printf("Informe a configuracao desejada das formigas no tubo: ");
  setbuf(stdin, NULL);
  scanf("%[^\n]s", String);

  BuscarListaGrafos(l_gr, String);


  // ImprimirLista(l_gr);

  return 0;
}
