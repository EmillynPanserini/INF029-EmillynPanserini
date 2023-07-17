// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Dados do Aluno -----
//  Nome: Emillyn Souza Panserini
//  email: emillynpanserini@ifba.edu.br
//  Matrícula: 20231160017
//  Semestre: 2023.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include <stdio.h>
#include "EmillynPanserini20231160017.h"
#include <stdlib.h>
#include <string.h>
/*
## função utilizada para testes  ##
 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##
 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}
int DifAno(DataQuebrada dataIni, DataQuebrada dataFin){
  int difAno;
  if(dataFin.iAno >= dataIni.iAno){
    difAno = dataFin.iAno - dataIni.iAno;
    return difAno;
  }else
    return 4;
}


int DifMes(DataQuebrada dataIni, DataQuebrada dataFin){
  int difMes;
  if(dataFin.iMes >= dataIni.iMes){
    int difMes = dataFin.iMes - dataIni.iMes;
    return difMes;
  }else{
    difMes = (12 - (dataIni.iMes - dataFin.iMes)) ;
    return difMes;
  } 
}


int DifDia(DataQuebrada dataIni, DataQuebrada dataFin){
  int difDia;
  if(dataFin.iDia >= dataIni.iDia){
    difDia = dataFin.iDia - dataIni.iDia;
    return difDia;
  }else{
    int difDia = (dataIni.iDia - dataFin.iDia);
    return difDia; // subtrair da quantidade de dias do mes
  }
}



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}
/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válidac
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    Pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  //quebrar a string data em strings sDia, sMes, sAno

  //DataQuebrada dataQuebrada = quebraData(data);
  //if (dataQuebrada.valido == 0) return 0;

  //printf("%s\n", data);

 if(trueData(data)) 
 { if (sureForm(data)){
    if(valid(data)){
      return 1;
    }
  }  }
  return 0;
}


/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */

// ARRUMAR
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;
    DataQuebrada dataIni = quebraData(datainicial);
    DataQuebrada dataFin =quebraData(datafinal);
    DiasMesesAnos result;
    int mes[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int difAno, difMes, difDia;
    int leapYear = 0;
    int conv;
  
    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
      if(dataIni.iAno > dataFin.iAno){
        dma.retorno = 4;
        return dma;
      }
    if(dataIni.iAno == dataFin.iAno){
        if(dataIni.iMes > dataFin.iMes)
          dma.retorno = 4;
          return dma;
      }
      else if(dataIni.iMes == dataFin.iMes){
        if(dataIni.iDia > dataFin.iDia){
          dma.retorno = 4;
        }
      }

      difAno = DifAno(dataIni, dataFin);
      difMes = DifMes(dataIni, dataFin);
      difDia = DifDia(dataIni, dataFin);

      conv = dataIni.iAno;

      for(int x = 0; x<= (dataFin.iAno - dataIni.iAno) + 1; x++ ){
        leapYear += LeapYear(dataIni.iAno);
        dataIni.iAno++;
      }
      dataIni.iAno = conv;
        if(dataIni.iMes > dataFin.iMes)
          difAno -= 1;
        if(dataIni.iDia > dataFin.iDia)
          difMes -= 1;
        if(dataIni.iDia > dataFin.iDia){
          if(LeapYear(dataIni.iAno)){
            difDia = mes[dataIni.iMes] - difDia;
          }else{
            difDia = mes[dataIni.iMes] - difDia + leapYear;
          }
        }  
        dma.qtdDias = difDia;
        dma.qtdMeses = difMes;
        dma.qtdAnos = difAno;
        dma.retorno = 1;
        return dma;
    }

    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;

    if(isCaseSensitive != 1){
      for(int x; texto[x] != '\0'; x++){
        if(texto[x] == c || texto[x] -32 == c || texto[x] +32 == c)
          qtdOcorrencias++;
      }
    }
    else
        {
        for(int x; texto[x] != '\0'; x++){
          if(texto[x] == c)
            qtdOcorrencias++;
        }
    }

    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;
 */

int q4(char *strTexto, char *strBusca, int posicoes[30]){
 
  int qtdOcorrencias = -1;
  int tam1 =0, tam2 =0;
  int cont =0, cont2 = 0, cont3 = 0;
  int ocorrencias = 0;

  for (int x = 0; strBusca[x] != '\0'; x++){
    tam1++;
  }
  qtdOcorrencias = palavra(strTexto, strBusca, tam1, tam2, posicoes, 
  cont, cont2, ocorrencias, cont3);
  return qtdOcorrencias;
}


/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num){
  int v = 0;
   int aux, res;

    do{
      v *=10;
      v += num %10;
      num /=10;
    }
    while(num);
    return v;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
  int qtdOcorrencias=0;
  int vetor[10], x;
  int res;

  while(numerobase % 10 != 0){
    res= numerobase % 10;
    if(res == numerobusca)
      qtdOcorrencias++;
    numerobase /=10;

  }  
    return qtdOcorrencias;
}

int valid(char *stringData){
  DataQuebrada data = quebraData(stringData);
 
  if(data.iDia<= 31 && data.iMes <= 12)
  {  
    if(data.iDia <31 && data.iMes != 2)
      return 1;
    else if (data.iDia > 28 && data.iMes == 2){
      if(LeapYear(data.iAno))
        return 1;
    else
        return 0;
  } 

  else if (data.iDia > 30 && data.iMes != 1  && data.iMes != 3  && data.iMes != 5 && data.iMes != 7  && data.iMes != 8 && data.iMes != 10 && data.iMes != 12)
    return 0;
  else
    return 1;

  return 0;
}
}
int sureForm(char *data){ 
  int b =0;
 for(int x =1; data[x] != '\0'; x++){
  if (data[x-1] == '/')
    b++;
  if(b == 1)
    if((x-1) != 1 && (x - 1) !=2)
      return 0;
    if(data[x-1] != '/' && data[x+2] != '/')
      return 0;

 if(b > 2)
   return 0;
 if(data[x+1] == '\0' && (data[x-2] != '/' && data[x-4] != '/'))
   return 0;

 }
  return 1;
}

int LeapYear (int ano){
  if(ano % 4 == 0){
    if(ano % 100 == 0){
      if(ano % 400 == 0)
         return 1;
    }
  else
    return 1;
  }
  return 0;
}
int trueData(char *data){
  for(int x = 0; data[x] != '\0'; x++){
    if(!number(data[x]&& data[x] != '/'))
      return 0;
  }
  return 1;
}
int number (int character){
  if(47 <character && character <58)
    return 1;
  return 0;
}

int palavra(char *strTexto, char *strBusca, int tam1, int tam2, int posicoes[30], int cont, int cont2, int ocorrencias, int cont3){

  if(*strTexto == '\0'){
    return ocorrencias;
  }
  if(*strTexto == *strBusca){
    cont3++;
    if(tam2 % 2 == 0 || cont == tam1 - 1){
      posicoes[tam2] = cont2 +1;
      tam2++;
    }
    if (tam2 % 2 == 0 && tam2 != 0){
      ocorrencias = tam2 /2;
      cont3 = 0;

      return palavra(strTexto +1 , strBusca + 1, tam1, tam2, posicoes, 
      cont +1, cont2 +1,  ocorrencias, cont3);
    }
      return palavra(strTexto +1 , strBusca + 1, tam1, tam2, 
      posicoes, cont +1, cont2 +1,  ocorrencias, cont3);}
    else {
      if(tam2 % 2 != 0){
        tam2 -= 1;
        return palavra(strTexto +1 , strBusca - cont3, tam1, tam2, 
        posicoes, cont = 0, cont2 +1,  ocorrencias, cont3 );
      }
       return palavra(strTexto +1 , strBusca - cont3, tam1, tam2, 
        posicoes, cont = 0, cont2 +1,  ocorrencias, cont3 = 0);
    }
  
}