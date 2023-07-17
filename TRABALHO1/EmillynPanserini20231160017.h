// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Emillyn Souza Panserini
//  email: emillyn2003@gmail.com
//  Matrícula: 20231160017
//  Semestre: 2023.1

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021

// #################################################
#ifndef TRABALHO1_EMILLYNPANSERINI20231160017_H
#define TRABALHO1_EMILLYNPANSERINI20231160017_H

typedef struct DQ
{
    int iDia; 
    int iMes;
    int iAno;
    int valido; // 0 se inválido, e 1 se válido 

} DataQuebrada;

typedef struct Qtd
{
    int qtdDias;
    int qtdMeses;
    int qtdAnos;
    int retorno;

} DiasMesesAnos;

int somar(int x, int y); //função utilizada para testes
int fatorial(int x); //função utilizada para testes
int q1(char data[]);
DiasMesesAnos q2(char datainicial[], char datafinal[]);
int q3(char *texto, char c, int isCaseSensitive);
int q4(char *strTexto, char *strBusca, int posicoes[30]);
int q5(int num);
int q6(int numerobase, int numerobusca);
DataQuebrada quebraData(char data[]);

// funtions for better perform 

int DifAno(DataQuebrada dataIni, DataQuebrada dataFin);
int DifMes(DataQuebrada dataIni, DataQuebrada dataFin);
int DifDia(DataQuebrada dataIni, DataQuebrada dataFin);
int number (int character);
int sureForm(char *data);
int valid(char *stringData);
int trueData(char *data);
int LeapYear(int ano);
int palavra(char *strTexto, char *strBusca, int tam1, int tam2, int posicoes[30], int cont, int cont2, int ocorrencias, int cont3);

#endif  // TRABALHO1_PRIMEIROULTIMONOMEMATRICULA_H