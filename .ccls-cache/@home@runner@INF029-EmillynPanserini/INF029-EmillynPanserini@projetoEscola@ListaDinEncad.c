#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListaDinEncad.h" //inclui os Prot�tipos

//Definição do tipo lista
   struct elemento {
    Aluno dados;
    Professor dados2;
    Disciplina dados3;
    struct elemento *prox;
} ;

typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}
Lista* cria_listaprof(){
    Lista* li2 = (Lista*) malloc(sizeof(Lista));
    if(li2 != NULL)
        *li2 = NULL;
    return li2;
}
Lista* cria_listadis(){
    Lista* li3 = (Lista*) malloc(sizeof(Lista));
    if(li3 != NULL)
        *li3 = NULL;
    return li3;
}
void libera_lista(Lista* li, Lista* li2, Lista* li3){
    if(li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
   }
        free(li);
      if(li2 != NULL){
        Elem* no;
        while((*li2) != NULL){
            no = *li;
            *li = (*li2)->prox;
            free(no);
        }
        free(li2);
    }
    if(li2 != NULL){
        Elem* no;
        while((*li3) != NULL){
            no = *li;
            *li = (*li3)->prox;
            free(no);
        }
        free(li3);
    }
}

int consulta_lista_pos(Lista* li, int pos, Aluno *al){
    if(li == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while(no != NULL && i < pos){
        no = no->prox;
        i++;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int consulta_lista_mat(Lista* li, int mat, Aluno *al){
    if(li == NULL)
        return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        no = no->prox;
    }
    if(no == NULL)
        return 0;
    else{
        *al = no->dados;
        return 1;
    }
}

int insere_lista_final(Lista* li, Aluno al){
    if(li == NULL)
        return 0;
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = NULL;
    if((*li) == NULL){//lista vazia: insere in�cio
        *li = no;
    }else{
        Elem *aux;
        aux = *li;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}
int insere_lista_final_dis(Lista* li3, Disciplina dis){
    if(li3 == NULL)
        return 0;
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados3 = dis;
    no->prox = NULL;
    if((*li3) == NULL){//lista vazia: insere inicio
        *li3 = no;
    }else{
        Elem *aux;
        aux = *li3;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}
int insere_lista_final_prof(Lista* li2,Professor prof){
    if(li2 == NULL)
        return 0;
    Elem *no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados2 = prof;
    no->prox = NULL;
    if((*li2) == NULL){//lista vazia: insere in�cio
        *li2 = no;
    }else{
        Elem *aux;
        aux = *li2;
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = no;
    }
    return 1;
}
int insere_lista_inicio(Lista* li, Aluno al){
    if(li == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    no->prox = (*li);
    *li = no;
    return 1;
} 
int insere_lista_inicio_dis(Lista* li3, Disciplina dis){
    if(li3 == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados3 = dis;
    no->prox = (*li3);
    *li3 = no;
    return 1;
}
int insere_lista_inicio_prof(Lista* li2, Professor prof){
  if(li2 == NULL)
        return 0;
    Elem* no;
    no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados2 = prof;
    no->prox = (*li2);
    *li2 = no;
    return 1;
}



int insere_lista_ordenada(Lista* li, Aluno al){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = al;
    if((*li) == NULL){//lista vazia: insere inicio
        no->prox = NULL;
        *li = no;
        return 1;
    }
    else{
        Elem *ant, *atual = *li;
        while(atual != NULL && 0 < (strcmp(atual->dados.nome, atual->prox->dados.nome)
)){
            ant = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere inicio
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = atual;
            ant->prox = no;
        }
        return 1;
    }
}

int remove_lista(Lista* li, int mat){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elem *ant, *no = *li;
    while(no != NULL && no->dados.matricula != mat){
        ant = no;
        no = no->prox;
    }
    if(no == NULL)//não encontrado
        return 0;

    if(no == *li)//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *ant, *no = *li;
    while(no->prox != NULL){
        ant = no;
        no = no->prox;
    }

    if(no == (*li))//remover o primeiro?
        *li = no->prox;
    else
        ant->prox = no->prox;
    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while(no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Lista* li){
    if(li == NULL)
        return;
    Elem* no = *li;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados.matricula);
        printf("Nome: %s\n",no->dados.nome);
        printf("Data de nascimento: %f\n",no->dados.data);
        printf("Sexo: %s\n", no->dados.sexo);
        printf("CPF: %d\n\n", no->dados.CPF);
        printf("-------------------------------\n\n\n");

        no = no->prox;
    }
}
void imprime_listaProf(Lista* li2){
    if(li2 == NULL)
        return;
    Elem* no = *li2;
    while(no != NULL){
        printf("Matricula: %d\n",no->dados2.matricula);
        printf("Nome: %s\n",no->dados2.nome);
        printf("Data de nascimento: %f\n",no->dados2.data);
        printf("Sexo: %s\n", no->dados2.sexo);
        printf("CPF: %d", no->dados2.CPF);
        printf("-------------------------------\n");

        no = no->prox;
    }
}
void imprime_disciplina(Lista* li3){
    if(li3 == NULL)
        return;
    Elem* no = *li3;
    while(no != NULL){
        printf("Nome: %s\n",no->dados3.nome);
        printf("Codigo: %d\n",no->dados3.codigo);
        printf("Semestre: %d\n",no->dados3.semestre);
        printf("Professor: %s\n", no->dados3.professor);
        printf("-------------------------------\n");
        no = no->prox;
    }
}

// novo prof ou aluno
void NovoAlun (Lista* li){
  int sexo[tamanho_lista(li)] ;
  Aluno novoAlun;
  int i=0,j,igual,num_aleatorio[1000];
  srand(time(NULL));

  do{
      num_aleatorio[i] = 1+ rand()%999;
      igual=0;
      for(j=0; j<i; j++){
         if(num_aleatorio[j]==num_aleatorio[i])
            igual=1;
      }
      if(igual==0)
         i++; 
      
      novoAlun.matricula = num_aleatorio[i-1];      
  }while(i<999);
  
  
  printf("---------------Primeiro os dados do aluno---------------\n");
  printf(" Insira seu nome:\n");
  scanf("%s", novoAlun.nome);   
  printf("Insira seu CPF:\n");
  scanf("%d", &novoAlun.CPF);
  printf(" Insira seu sexo:\n");
  scanf("%s", novoAlun.sexo);   
  for(int i=0; i<tamanho_lista(li); i++){
    if(novoAlun.sexo == 'feminino'){
    sexo[i] = novoAlun.sexo;
  }
  }
   
  printf("Insira sua data de nascimento:\n");
  scanf("%f", &novoAlun.data);
  
  if(lista_vazia(li))
     insere_lista_inicio(li,novoAlun);
  else  
     insere_lista_final(li, novoAlun);
  return;
}
void NovoProf ( Lista* li2){

  Professor novoProf;
  int i=0,j,igual,num_aleatorio[1000];
  srand(time(NULL));

  do{
      num_aleatorio[i] = 1+ rand()%999;
      igual=0;
      for(j=0; j<i; j++){
         if(num_aleatorio[j]==num_aleatorio[i])
            igual=1;
      }
      if(igual==0)
         i++; 
      
      novoProf.matricula = num_aleatorio[i-1];
      
  }while(i<999);
  
  
  printf("---------------Primeiro os dados do aluno---------------\n");
  printf(" Insira seu nome:\n");
  scanf("%s", novoProf.nome);   
  printf("Insira seu CPF:\n");
  scanf("%d", &novoProf.CPF);
  printf(" Insira seu sexo:\n");
  scanf("%s", novoProf.sexo);   
  printf("Insira sua data de nascimento:\n");
  scanf("%f", &novoProf.data);
  
  if(lista_vazia(li2))
     insere_lista_inicio_prof(li2, novoProf);
  else  
     insere_lista_final_prof(li2, novoProf);
  return;
}

// arrumar
void Nova (Lista* li3){

  Disciplina nvdis;
  int i=0,j,igual,num_aleatorio[1000];
  srand(time(NULL));
   
  do{
      num_aleatorio[i] = 1+ rand()%999;
      igual=0;
      for(j=0; j<i; j++){
         if(num_aleatorio[j]==num_aleatorio[i])
            igual=1;
      }
      if(igual==0)
         i++; 
      
      nvdis.codigo = num_aleatorio[i-1];      
  }while(i<999);
  
  
  printf("---------------Disciplina cadastrar---------------\n");
  printf("Insira o nome da disciplina:\n");
  scanf("%s", nvdis.nome);   
  printf("Insira o semestre da disciplina:\n");
  scanf("%d", &nvdis.semestre);
  printf(" Insira o professor da disciplina:\n");
  scanf("%s", nvdis.professor);   
  printf("Insira a quantidade maxima de alunos:\n");
  scanf("%d", &nvdis.qtd);
  int c;
  do{
    printf("Alunos participantes:\n");
    scanf("%s", nvdis.alun.nome);
    printf("Deseja parar? Se sim aperte 0");
    scanf("%d", &c);
    
  }while(c != 0);
  
  if(lista_vazia(li3))
     insere_lista_inicio_dis(li3, nvdis);
  else  
     insere_lista_final_dis(li3, nvdis);
  return;
}

void imprime_consulta(Lista* li, int matriculac, Aluno *al){
  
    if(li == NULL)
        return;
    Elem *no = *li;

    while(no != NULL && no->dados.matricula != matriculac){
        no = no->prox;
    }
    if(no == NULL)
        return;
    else {
        *al = no->dados;}
  
      printf("Nome do aluno: %s\n", no->dados.nome);
    	printf("Numero de matricula: %d\n", no->dados.matricula);
      printf("Data de nascimento: %f\n", no->dados.data);
    	printf("Sexo: %s\n", no->dados.sexo);
      printf("CPF: %d\n", no->dados.CPF); 
}
void imprime_disciplinaAlun(Lista* li3, Disciplina dis){
  Elem *no = *li3;
  if(li3 == NULL)
        return;
    while(no != NULL){
        printf("Nome: %s\n",no->dados3.nome);
        printf("Codigo: %d\n",no->dados3.codigo);
        printf("Semestre: %d\n",no->dados3.semestre);
        printf("Professor: %s\n", no->dados3.professor);
        printf("Alunos na disciplina: %s\n", no->dados3.alun.nome);
        printf("-------------------------------\n");
        no = no->prox;
    }

}


void Editar_dados_alun(Lista* li, int matriculac, Lista* li2){
     int opcao, x=0;
     if(lista_vazia(li))
        return;

      
      Elem *no = *li;
      while(no->dados.matricula != matriculac){
           no = no->prox;
      }
      
     do{
       scanf("%d",&opcao);
       switch(opcao){
        case 1:
           printf("Altere o nome:\n");
           scanf("%s", no->dados.nome); break;
        case 2:
           printf("Altere a data de nascimento\n");
           scanf("%f", &no->dados.data); break;
        case 3:
           printf("Altere a matricula:\n");
           scanf("%d",&no->dados.matricula); break;
        case 4:
           printf("Alterar o CPF:\n");
           scanf("%d", &no->dados.CPF);break;
        case 5:
           printf("Altere o sexo:\n");
           scanf("%s", no->dados.sexo);break;
        case 9:
          x=1; break;
         default:
           printf("opcao invalida\n"); break;
         }
       Menu_editar(li, li2);
      }while(x==0);
     
}
// opcao de qual excluir
int Excluir (Lista* li, Lista* li2)
{
  int escolha;
  printf("Para deseja confirmar a exclusao de 1.professor ou 2.aluno? \n");
  scanf("%d", &escolha);
  int choice;

  if(escolha == 1){
    if(lista_vazia(li)){
      printf("lista vazia!");
      return 0;
    }
    
     else{
       printf("\n Digite a matricula de quais desses alunos voce deseja excluir?\n\n");
       imprime_lista(li);
       scanf("%d", &choice);
       remove_lista(li, choice);

      return choice;}
    }
  else if(escolha == 2){
     if(lista_vazia(li2)){
       printf("lista vazia!");
       return 0;}
    
     else
       printf("\n Digite a matricula. Quais desses prof voce deseja excluir?\n\n");
       imprime_lista(li2);
       scanf("%d", &choice);
       remove_lista(li2, choice);

    return choice;
  }     
  return 0;
}

void Menu_editar(Lista *li, Lista *li2){
    if(lista_vazia(li)){
        printf("\n\nLista vazia\n\n"); 
        return;}
  
    printf("\n-------QUE DADOS DESEJA MUDAR?---------\n");
    printf("1-Alterar nome\n2-Alterar data de nascimento\n3-Alterar matricula\n");
    printf("4-Alterar CPF\n5-Alterar o sexo\n9-Sair\n");
}
void Menu_editar_dis(Lista *li3){
    if(lista_vazia(li3)){
        printf("\n\nLista vazia\n\n"); 
        return;}
  
    printf("\n-------QUE DADOS DESEJA MUDAR?---------\n");
    printf("1-Alterar nome\n2-Alterar o professor\n3-Alterar codigo\n");
    printf("4-Alterar semestre\n9-Sair\n");
}

void Menu_op_alun(void){
        printf("\n================MENU DE OPCOES================\n");
        printf("1-Deseja cadastrar?\n2-Deseja procurar?\n");
        printf("3-Deseja alterar os dados?\n4-Deseja excluir?\n");
        printf("5-Salvar dados\n6-Abrir arquivo\n7-Lista\n9-Sair\n");
        printf("obs: digite o numero da opcao para escolhe la\n");
}

void Menu_op_prof(void){
      printf("\n================MENU DE OPCOES================\n");
      printf("10-Deseja cadastrar um professor?\n11-Deseja procurar um professor ?\n");
      printf("12-Deseja alterar os dados do professor?\n13-Deseja excluir um professor?\n");
      printf("14-Salvar dados do professor\n15-Abrir arquivo\n16-Lista de professor\n17-Sair\n");
      printf("obs: digite o numero da opcao para escolhe la\n");
        
}
void Menu_op_dis(void){
      printf("\n================MENU DE OPCOES================\n");
      printf("18-Deseja cadastrar uma disciplina?\n19-Deseja excluir uma disciplina?\n");
      printf("20-Deseja alterar os dados da disciplina?\n21-Deseja excluir um aluno da disciplina?\n");
      printf("22-Salvar dados editados\n23-Adicionar um aluno na disciplina\n0-Sair\n");
      printf("obs: digite o numero da opcao para escolhe la\n");
        
}
void Editar_dados_prof(Lista* li2, int matriculac, Lista* li){
  int opcao, x=0;
     if(lista_vazia(li2))
        return;

      
      Elem *no = *li2;
      while(no->dados2.matricula != matriculac){
           no = no->prox;
      }
      
     do{
       scanf("%d",&opcao);
       switch(opcao){
        case 1:
           printf("Altere o nome:\n");
           scanf("%s", no->dados2.nome); break;
        case 2:
           printf("Altere a data de nascimento\n");
           scanf("%f", &no->dados2.data); break;
        case 3:
           printf("Altere a matricula:\n");
           scanf("%d",&no->dados2.matricula); break;
        case 4:
           printf("Alterar o CPF:\n");
           scanf("%d", &no->dados2.CPF);break;
        case 5:
           printf("Altere o sexo:\n");
           scanf("%s", no->dados2.sexo);break;
        case 9:
          x=1; break;
         default:
           printf("opcao invalida\n"); break;
         }
       Menu_editar(li, li2);
      }while(x==0);
     
}
void Editar_dados_dis(Lista* li2, int matriculac, Lista* li, Lista* li3){
  int opcao, x=0;
     if(lista_vazia(li3))
        return;

      
      Elem *no = *li3;
      while(no->dados2.matricula != matriculac){
           no = no->prox;
      }
      
     do{
       scanf("%d",&opcao);
       switch(opcao){
        case 1:
           printf("Altere o nome:\n");
           scanf("%s", no->dados3.nome); break;
        case 2:
           printf("Altere o professor da disciplina\n");
           scanf("%s", no->dados3.professor); break;
        case 3:
           printf("Altere o codigo:\n");
           scanf("%d",&no->dados3.codigo); break;
        case 4:
           printf("Alterar o semestre:\n");
           scanf("%d", &no->dados3.semestre);break;
        
        case 9:
          x=1; break;
         default:
           printf("opcao invalida\n"); break;
         }
       Menu_editar_dis(li3);
  }while(x==0);
     
}

