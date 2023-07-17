// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Dados do Aluno -----
//  Nome: Emillyn Souza Panserini
//  email: emillynpanserini@ifba.edu.br
//  Matrícula:20231160017
//  Semestre: 2023.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 31/03/2023 - 19/08/2016
// ##################################################

#include "EstruturaVetores.h"
#include <stdlib.h>
#include <stdio.h>

li *Li = NULL;



void getDadosListaEncadeadaComCabecote(No *inicio, int vetAux[])
{
  No *li = inicio;

  int x = 0;

  while (li)
  {
    vetAux[x] = li->conteudo;
    li = li->prox;
    x++;
  }
}
No *montarListaEncadeadaComCabecote()
{
  No *init = NULL;
  No *fim = NULL;

  No *ini = NULL;
  No *dados = NULL;
  No *fi = NULL;

  int x = 0;

  while (x < TAM)
  {
    if (Li[x].auxStructExists && !Li[x].isEmpty)
    {
      auxStruct *li = Li[x].auxStruct;

      dados = (No *)malloc(sizeof(No));
      dados->conteudo = li->value;
      dados->prox = NULL;
      ini = dados;
      fi = dados;

      li = li->next;
      while (li && !li->isEmpty)
      {
        dados = (No *)malloc(sizeof(No));

        dados->conteudo = li->value;
        dados->prox = NULL;
        fi->prox = dados;
        fi = dados;

        li = li->next;
      }
      if (!fi)
        fim = fi;
      
    }
    if (!init)
      init =ini;
    
    if (fim)
      fim->prox = ini;
    
    fim = fi;

    x++;
  }
  fi->prox = NULL;
  return init;
}
int modificarTamanhoEstruturaAuxiliar(int posicao, int tam)
{
  if (num(posicao))
    return POSICAO_INVALIDA;
  
  else if (!Li[posicao - 1].auxStructExists)
    return SEM_ESTRUTURA_AUXILIAR;
  
  else if ((Li[posicao - 1].size_max + tam) < 1)
    return NOVO_TAMANHO_INVALIDO;
  
  else
  {
    int resizeTo = Li[posicao - 1].size_max + tam;
    auxStruct *last = Li[posicao - 1].auxStruct;

    if (resizeTo >Li[posicao - 1].size_max)
    {
      while (last->next)
        last = last->next;
    
      last->next = aux(tam);
      if (tam > 0 && !last->next)
        return SEM_ESPACO_DE_MEMORIA;
      
      else
      {
        Li[posicao - 1].size_max = Li[posicao - 1].size_max + tam;

        if (Li[posicao - 1].isFull)
          Li[posicao - 1].isFull = !Li[posicao - 1].isFull;
      }
    }
    else
    {
      int x = 0;
      while (x < resizeTo-1)
      {
        last = last->next;
        x++;
      }
      deleteL(&last->next);
      last->next = NULL;
     Li[posicao - 1].size_max = resizeTo;

      if (Li[posicao - 1].isFull)
      {
        Li[posicao - 1].length = resizeTo;
      }
      else if( Li[posicao - 1].length > resizeTo ){
        if( !Li[posicao - 1].isFull ){
          Li[posicao - 1].isFull = !Li[posicao - 1].isFull;
        }
        Li[posicao - 1].length = resizeTo;
      }
    }
    return SUCESSO;
  }
}
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
  if (num(posicao))
    return POSICAO_INVALIDA;
  else if (!Li[posicao - 1].auxStructExists)
    return SEM_ESTRUTURA_AUXILIAR;
  
  else if (Li[posicao - 1].isEmpty)
    return ESTRUTURA_AUXILIAR_VAZIA;
  
  else
    return Li[posicao - 1].length;
}
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetAux[])
{
  int result = getDadosDeTodasEstruturasAuxiliares(vetAux);

  if (result == SUCESSO)
    insereListaOrdenada(vetAux, vetTam() );
  return result;
}
int getDadosDeTodasEstruturasAuxiliares(int vetAux[])
{
  int x = 0;

  while (x < TAM)
  {
    if ( !Li[x].isEmpty)
      break;
    x++;
  }
  if (x == TAM)
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;

  else
  {
    int x = 0;
    int totalSize = 0;

    while(Li[x].isEmpty ){
      x++;
    }
    totalSize += Li[x].length;

    getDadosEstruturaAuxiliar(x + 1,vetAux);
    x++;

    while (x < TAM)
    {
      if( !Li[x].isEmpty ){
        getDadosEstruturaAuxiliar(x + 1, &vetAux[totalSize]);
        totalSize +=Li[x].length;
      }
      x++;
    }
    return SUCESSO;
  }
}
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetAux[])
{
  int result = getDadosEstruturaAuxiliar(posicao, vetAux);

  if (result == SUCESSO)
  {
    insereListaOrdenada(vetAux,Li[posicao - 1].length);
  }
  return result;
}
int getDadosEstruturaAuxiliar(int posicao, int vetAux[])
{
  if (num(posicao))
    return POSICAO_INVALIDA;

  else if (!Li[posicao - 1].auxStructExists)
    return SEM_ESTRUTURA_AUXILIAR;
  
  else
  {
    auxStruct *actFloor = Li[posicao - 1].auxStruct;

    int x = 0;
    int length =Li[posicao - 1].length;

    while (x < length && actFloor)
    {
      vetAux[x] = actFloor->value;
      actFloor = actFloor->next;
      x++;
    }
    return SUCESSO;
  }
}
int criarEstruturaAuxiliar(int posicao, int size)
{
  if (num(posicao))
  {
    return POSICAO_INVALIDA;
  }
  else if (size < 1)
  {
    return TAMANHO_INVALIDO;
  }
  else if (Li[posicao - 1].auxStructExists)
  {
    return JA_TEM_ESTRUTURA_AUXILIAR;
  }
  else
  {
   Li[posicao - 1].auxStruct = aux(size);

    if (Li[posicao - 1].auxStruct)
    {
      Li[posicao - 1].size_max = size;
      Li[posicao - 1].isFull = false;
      Li[posicao - 1].isEmpty = true;
      Li[posicao - 1].auxStructExists = true;
      return SUCESSO;
    }
    else
    {
      return SEM_ESPACO;
    }
  }
}
int inserirNumeroEmEstrutura(int posicao, int value)
{
  if (num(posicao))
    return POSICAO_INVALIDA;
  
  else if (Li[posicao - 1].isFull)
    return SEM_ESPACO;
  
  else if (!Li[posicao - 1].auxStructExists)
    return SEM_ESTRUTURA_AUXILIAR;
  
  else
  {
    auxStruct *actFloor = Li[posicao - 1].auxStruct;

    if (Li[posicao - 1].isEmpty)
    {
      actFloor->value = value;
      actFloor->isEmpty = !actFloor->isEmpty;
      Li[posicao - 1].length++;
      Li[posicao - 1].isEmpty = !Li[posicao - 1].isEmpty;
    }
    else
    {
      while (actFloor->next && !actFloor->next->isEmpty)
      {
        actFloor = actFloor->next;
      }
      actFloor = actFloor->next;

      actFloor->isEmpty = !actFloor->isEmpty;
      actFloor->value = value;
      Li[posicao - 1].length++;

      if (!actFloor->next || Li[posicao - 1].length == Li[posicao - 1].size_max)
        Li[posicao - 1].isFull = true;
      
      if (Li[posicao - 1].isEmpty == true)
        Li[posicao - 1].isEmpty = false;
      }
    return SUCESSO;
  }
}
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
  if (num(posicao))
    return POSICAO_INVALIDA;
  
  else if (!Li[posicao - 1].auxStructExists)
    return SEM_ESTRUTURA_AUXILIAR;
  
  else if (Li[posicao - 1].isEmpty)
    return ESTRUTURA_AUXILIAR_VAZIA;
  
  else
  {
    auxStruct *actFloor = Li[posicao - 1].auxStruct;

    while (actFloor->next && !actFloor->next->isEmpty)
    {
      actFloor = actFloor->next;
    }
    actFloor->value = EMPTY;
    actFloor->isEmpty = !actFloor->isEmpty;

    Li[posicao - 1].length--;

    if (Li[posicao - 1].length == 0)
    {
      Li[posicao - 1].isEmpty = true;
    }
    if (Li[posicao - 1].isFull)
    {
      Li[posicao - 1].isFull = false;
    }
    return SUCESSO;
  }
}
int excluirNumeroEspecificoDeEstrutura(int posicao, int value)
{
  if (num(posicao))
  {
    return POSICAO_INVALIDA;
  }
  else if (!Li[posicao - 1].auxStructExists)
  {
    return SEM_ESTRUTURA_AUXILIAR;
  }
  else if (Li[posicao - 1].isEmpty)
  {
    return ESTRUTURA_AUXILIAR_VAZIA;
  }
  else
  {
    auxStruct *li = Li[posicao - 1].auxStruct;

    while (li)
    {
      if (li->value == value)
      {
        while (li->next && !li->isEmpty)
        {
          li->value = li->next->value;
          li = li->next;
        }

        li->isEmpty = !li->isEmpty;
        li->value = EMPTY;
        Li[posicao- 1].length--;

        if (Li[posicao - 1].isFull)
          Li[posicao - 1].isFull = false;

        if (Li[posicao - 1].length == 0)
          Li[posicao - 1].isEmpty = true;
        
        return SUCESSO;
      }
      if (!li->next || li->next->isEmpty)
        return NUMERO_INEXISTENTE;
      
      li = li->next;
    }
    return NUMERO_INEXISTENTE;
  }
}
void inicializar()
{
  Li = (li*)malloc(sizeof(li) * TAM);
  int i = 0;

  while (i < TAM)
  {
    Li[i].auxStruct = NULL;
    Li[i].auxStructExists = false;
    Li[i].length = 0;
    Li[i].size_max = 0;
    Li[i].isEmpty = true;
    Li[i].isFull = false;
    i++;
  }
}
bool num(int posicao)
{
  if (posicao < 1 || posicao > TAM)
    return true;
  
  else
    return false;
  
}
auxStruct *aux(int tam)
{
  auxStruct *new = (auxStruct *)malloc(sizeof(auxStruct));
  auxStruct *first = new;
  auxStruct *last = first;

  first->next = NULL;
  first->value = EMPTY;
  first->isEmpty = true;

  while (tam > 1)
  {
    new = (auxStruct *)malloc(sizeof(auxStruct));
    new->value = EMPTY;
    new->isEmpty = true;
    new->next = NULL;

    last->next = new;
    last = new;

    tam--;
  }
  return first;
}
void imprimeAux(int posicao)
{
  printf("\nConteudo:\n");
  auxStruct *li = Li[posicao - 1].auxStruct;
  while (li != NULL)
  {
    if (li->value == EMPTY)
      puts("EMPTY");
    
    else
    {
      printf("%d -> %s\n", li->value, (li->isEmpty ? "vazio" : "nao vazio"));
    }
    li = li->next;
  }
}
void insereListaOrdenada(int *vet, int tam)
{
  int num;

  for (int x = 1; x < tam; x++)
  {
    num = vet[x];
    int y = x - 1;
    while (y >= 0 && vet[y] > num)
    {
      vet[y + 1] = vet[y];
      y--;
    }
    vet[y + 1] = num;
  }
}
int vetTam()
{
  int x = 0;
  int tam = 0;
  
  while ( x < TAM){
    tam += Li[x].length;
    x++;
  }
  return tam;
}
int liTam(No *init)
{
  No *li = init;
  int x = 0;

  while (li)
  {
    x++;
    li = li->prox;
  }
  return x;
}
void deleteL(auxStruct **init)
{
  auxStruct *Aux = *init;
  auxStruct *aux = NULL;

  while (Aux)
  {
    aux = Aux;
    Aux = Aux->next;
    free(aux);
    aux = NULL;
  }
  *init = NULL;
}
void finalizar()
{
  int i = 0;

  while (i < TAM)
  {
    deleteL(&Li[i].auxStruct);
    i++;
  }
}

void destruirListaEncadeadaComCabecote(No **init)
{
  No *li = *init;
  No *lis = NULL;

 while (li)
  {
    lis = li;
    li = li->prox;
    free(lis);
    lis = NULL;
  }
  *init = NULL;
}