/*Tarefa 2.2*/
#include<stdio.h>
#include<stdlib.h>
#define tam 7
void imprime(int m[tam][tam]);
void imprime1(int m[tam][tam]);
void inicializa(int m[tam][tam], int v);
void conecta(int m[tam][tam], int a, int b, int v);
int adjacente(int m[tam][tam], int a, int b);
void menor_custo(int g[tam][tam], int c[tam][tam], int p[tam][tam]);
void gera_caminhos(int g[tam][tam], int p[tam][tam]);
void exibe_caminho(int m[tam][tam], int a, int b);
void menu(int m[tam][tam]);
void menu1(int g[tam][tam], int c[tam][tam], int p[tam][tam], int Cd[tam][tam]);
int encontra_caminho(int m[tam][tam], int k, int a, int b);
void geraconectividade(int m[tam][tam], int cd[tam][tam]);
int centro(int m[tam][tam]);

int main ()
{
   int g[tam][tam],g1[tam][tam],c[tam][tam],p[tam][tam],cd[tam][tam],a,b,resp,x;
   system("clear");
   inicializa(g,0);
   inicializa(c,0);
   inicializa(p,-1);
   inicializa(g1,0);
   inicializa(cd,0);
   conecta(g1,1,2,1);
   conecta(g1,1,5,1);
   conecta(g1,1,7,1);
   conecta(g1,2,3,1);
   conecta(g1,2,4,1);
   conecta(g1,2,6,1);
   conecta(g1,3,4,1);
   conecta(g1,4,7,1);
   conecta(g1,5,4,1);
   conecta(g1,5,6,1);
   conecta(g1,6,3,1);
   conecta(g1,6,7,1);
   conecta(g1,7,2,1);

   conecta(g,1,2,1);
   conecta(g,1,5,1);
   conecta(g,1,7,9);
   conecta(g,2,3,1);
   conecta(g,2,4,4);
   conecta(g,2,6,5);
   conecta(g,3,4,2);
   conecta(g,4,7,3);
   conecta(g,5,4,10);
   conecta(g,5,6,2);
   conecta(g,6,3,8);
   conecta(g,6,7,3);
   conecta(g,7,2,6);
   menor_custo(g,c,p);
   geraconectividade(g1,cd);
   menu1(g,c,p,cd);
}

/***************************************************************************/

void menu1(int g[tam][tam], int c[tam][tam], int p[tam][tam], int cd[tam][tam])

{
   int opcao,a,b,k,resp,x;
   system("clear");
   printf("                             TRABALHO DE ED II     -     GRAFOS\n\n\n");
   printf("           [1]                  Imprimir Matriz Adjacencia G\n");
   printf("           [2]                  Imprimir Matriz De Menores Custos\n");
   printf("           [3]                  Imprimir Matriz P\n");
   printf("           [4]                  Imprimir Matriz Conectividade\n");
   printf("           [5]                  Calcular o Centro Do Grafo\n");
   printf("           [6]                  Exibir Caminho\n");
   printf("           [7]                  Sair");
   printf("\n\n");
   printf("Digite a sua opcao: ");
   scanf("%d",&opcao);
      while((opcao!=1)&&(opcao!=2)&&(opcao!=3)&&(opcao!=4)&&(opcao!=5)&&(opcao!=6)&&(opcao!=7))
         {
            system("clear");
            printf("                     TRABALHO DE ED II    -     GRAFOS\n\n\n");
            printf("                             TRABALHO DE ED II     -     GRAFOS\n\n\n");
            printf("           [1]            Imprimir Matriz Adjacencia G\n");
            printf("           [2]            Imprimir Matriz De Menores Custos\n");
            printf("           [3]            Imprimir Matriz P\n");
            printf("           [4]            Imprimir Matriz Conectividade\n");
            printf("           [5]            Calcular o Centro Do Grafo\n");
            printf("           [6]            Exibir Caminho\n");
            printf("           [7]            Sair");
            printf("\n\n");
            printf("Digite a sua opcao: ");
            scanf("%d",&opcao);
         }
      if(opcao==1)
         {
            imprime(g);
            getchar();
            getchar();
            menu1(g,c,p,cd);
         }
      if(opcao==2)
         {
            imprime(c);
            getchar();
            getchar();
            menu1(g,c,p,cd);
         }
      if(opcao==3)
         {
            imprime1(p);
            getchar();
            getchar();
            menu1(g,c,p,cd);
         }
      if(opcao==4)
         {
            imprime(cd);
            getchar();
            getchar();
            menu1(g,c,p,cd);
         }
      if(opcao==5)
         {
            x=centro(c);
            printf("\n\n\n                           Centro do grafo: %d",x);
            getchar();
            getchar();
            menu1(g,c,p,cd);
         }
      if(opcao==6)
         {
            printf("Digite o vertice de origem: ");
            scanf("%d",&a);
               while((a<=0)||(a>7))
                  {
                     printf("\n\nVERTICE INVALIDO! DIGITE NOVAMENTE!\n\n");
                     printf("Digite o vertice de origem: ");
                     scanf("%d",&a);
                  }
            printf("Digite o vertice de destino: ");
            scanf("%d",&b);
               while((b<=0)||(b>7))
                  {
                     printf("\n\nVERTICE INVALIDO! DIGITE NOVAMENTE!\n\n");
                     printf("Digite o vertice de destino: ");
                     scanf("%d",&b);
                  }
            printf("%d => ",a);
            exibe_caminho(p,a-1,b-1);
            printf("%d",b);
            getchar();
            getchar();
            menu1(g,c,p,cd);
         }
      if(opcao==7)
         {
            exit(1);
         }
}

/***************************************************************************/

void inicializa(int m[tam][tam], int v)

{
   int i,j;
   i=j=0;
      while(i!=7)
         {
               while(j!=7)
                  {
                     m[i][j]=v;
                     j++;
                  }
            j=0;
            i++;
         }
}

/***************************************************************************/

void imprime(int m[tam][tam])

{
   int i,j,k;
   system("clear");
   i=j=0;
   k=1;
   printf("       ");
      while(k!=8)
         {
            printf("  %d  ",k); //
            k++;
         }
   printf("  \n\n\n  ");
   k=1;
      while(i!=7)
         {
            printf("  %d  ",k);//
               while(j!=7)
                  {
                     printf("  %d  ",m[i][j]); //
                     j++;
                  }
            i++;
            j=0;
            k++;
            printf("  \n\n  ");
         }
}

/***************************************************************************/

void imprime1(int m[tam][tam])

{
   int i,j,k;
   i=j=0;
   k=1;
   system("clear");
   printf("    ");
      while(k!=8)
         {
            printf("%d   ",k);
            k++;
         }
   k=1;
   printf("\n\n\n");
      while(i!=7)
         {
            printf("%d   ",k);
               while(j!=7)
                  {
                     printf("%d   ",(m[i][j]+1));
                     j++;
                  }
            i++;
            j=0;
            k++;
            printf("\n\n");
         }
}

/***************************************************************************/

void conecta(int m[tam][tam], int a, int b, int v)

{
   m[a-1][b-1]=v;
}

/***************************************************************************/

int adjacente(int m[tam][tam], int a, int b)

{
   if(m[a-1][b-1] == 0)
      {
         return(0);
      }
   else
      {
         return(1);
      }
}

/***************************************************************************/

void menor_custo(int g[tam][tam], int c[tam][tam], int p[tam][tam])

{
   int i,j,k;
   i=j=k=0;
      while(i!=7)
         {
               while(j!=7)
                  {
                        if(g[i][j]!=0)
                           {
                              c[i][j]=g[i][j];
                           }
                        else
                           {
                              c[i][j]=99;
                           }
                     j++;
                  }
            i++;
            j=0;
         }
   i=0;
      while(i!=7)
         {
            c[i][i]=0;
            i++;
         }
   i=0;
   j=k=1;
      while(k!=7)
         {
               while(i!=7)
                  {
                        while(j!=7)
                           {
                                 if((c[i][k] + c[k][j]) < c[i][j]) ///erro
                                    {
                                       c[i][j] = c[i][k] + c[k][j];
                                       p[i][j] = k;
                                    }
                              j++;
                           }
                     i++;
                     j=0;
                  }
            k++;
            i=0;
         }
}

/***************************************************************************/

void exibe_caminho(int m[tam][tam], int a, int b)

{
   int k,d,r;
   k=((m[a][b])+1);
      if(k!=0)
         {
            exibe_caminho(m, a, k-1);
            printf("%d => ",k);
            exibe_caminho(m, k-1, b);
         }
}

/***************************************************************************/

void geraconectividade(int m[tam][tam], int cd[tam][tam])

{
   int i,j,k;
      for(i=0;i<=6;i++)
         {
               for(j=0;j<=6;j++)
                  {
                     cd[i][j]=m[i][j];
                  }
         }
      for(k=0;k<=6;++k)
         {
               for(i=0;i<=6;++i)
                  {
                        for(j=0;j<=6;++j)
                           {
                                 if(cd[i][j]==0)
                                    {
                                       cd[i][j]=((cd[i][k]) * (cd[k][j]));
                                    }
                           }
                  }
         }
}

/***************************************************************************/

int centro(int m[tam][tam])

{
   int i,j,x,vetor[tam];
   i=0;
   j=0;
      while(i!=7)
         {
            vetor[i]=0;
            i++;
         }
   i=0;
      while(j!=7)
         {
               while(i!=7)
                  {
                        if((m[i][j]) > vetor[j])
                           {
                              vetor[j]=m[i][j];
                           }
                     i++;
                  }
            j++;
            i=0;
         }
   x=99;
   i=0;
      while(i!=7)
         {
               if(vetor[i] < x)
                  {
                     x=vetor[i];
                  }
            i++;
         }
   return(x+1);
}

/***************************************************************************/
