#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ListaDinEncad.h"
int main(){

   int opcao, matriculac, z, y, choice1, op;
   Aluno alun;
   Professor pro;
   Disciplina dis;

   // cria lista
    Lista* li = cria_lista();
    Lista* li2 = cria_listaprof();
    Lista* li3= cria_listadis();
  
    printf("Tamanho: %d\n\n\n\n",tamanho_lista(li));
    
     do{
        printf("Digite o numero de quem voce deseja acessar\n");
        printf("1.Alunos\n\n2.Professores\n\n3.Disciplina\n");
        scanf("%d", &choice1);

       if(choice1 == 1){
         Menu_op_alun();
       }
       else if (choice1 == 2)
         Menu_op_prof();
       else if (choice1 == 3){
         Menu_op_dis();
       }
       else
         printf("Invalido\n");
        scanf("%d",&opcao);
        switch(opcao){

          case 1://Novo 
            NovoAlun (li); break;
       
          case 2://Consultar a lista
            printf("Digite a matricula\n");
            scanf("%d", &matriculac);
            z = consulta_lista_mat(li, matriculac, &alun);
            if(z == 0)
             printf("\nNao encontrado\n");
              
            else
             printf("\nEncontrado\n\n");
             imprime_consulta(li, matriculac,&alun); break;
       
          case 3://Editar os dados da lista
            printf("Digite a matricula\n");
            scanf("%d", &matriculac);
            Menu_editar(li, li2);
            Editar_dados_alun(li,matriculac, li2); break;
          
          case 4://Excluir da lista e arquivo
           y = Excluir(li, li2);
            printf("\nLista atualizada:\n\n");
            imprime_lista(li); break;
       
          case 5:; break;

          case 6:; break;
            
          case 7://listar
            imprime_lista(li); break;      
           
          case 9://Finalizar procedimento
               opcao = 17;
              break;    
          case 10://Novo 
             NovoProf (li2); break;
     
          case 11://Consultar a lista
             printf("Digite a matricula do professor\n");
             scanf("%d", &matriculac);
            z = consulta_lista_mat(li, matriculac, &alun);
  
            if(z == 0)
              printf("\nNao encontrado\n");
            
            else
              printf("\nAluno encontrado\n\n");
              imprime_consulta(li2, matriculac,&alun); break;
     
          case 12://Editar os dados da lista
            printf("Digite a matricula\n");
            scanf("%d", &matriculac);
            Menu_editar(li, li2);
            Editar_dados_prof(li2,matriculac, li); break;
        
          case 13://Exlcuir da lista e arquivo
            y = Excluir(li, li2);
            printf("\nLista atualizada:\n\n");
            imprime_lista(li); break;
     
          case 14: break;
        
          case 15: break;
            
          case 16://listar 
            imprime_lista(li); break;      
           
          case 17://Finalizar procedimento
            break;
          case 18:
            Nova(li3);
            break;
          case 19: break;
          case 20: break;
          case 21: break;
          case 22: break;
          case 23: break;
          case 0: break;
          default:
             printf("OPCAO INVALIDA!!!\n"); break;
        }           
    }while(opcao != 17 );
  do{
   
   printf("Deseja listar alguma dessas opcoes? Se sim qual numero? Se nao aperte 0\n");
   printf("1.Lista de alunos\n2.Lista de professores\n3.Lista de disciplinas\n4.Alunos matriculados na disciplina\n5.Alunos por sexo\n6.Alunos ordenados por nome\n7.Professores por data de nascimento\n8.Professores por data de nascimento\n9.Aniversariantes\n10.Alunos matriculados em menos de 3 disciplinas\n11.Disciplinas que extrapolam 40 vagas\n\n\n\n");
   scanf("%d", &op);

   switch(op){
     case 1:
       imprime_lista(li);
       break;
     case 2:
       imprime_listaProf(li2);
       break;
     case 3:
       imprime_disciplina(li3);
       break;
     case 4: 
       imprime_disciplinaAlun(li3, dis);
       break;
     case 5:
       break;
     case 6: 
       insere_lista_ordenada(li,alun);
       imprime_lista(li); break;
     case 7: break;
     case 8: break;
     case 0: break;
     
     
     
     
     
     
     
     

   }
  }while(op != 0);
 
  
  
    libera_lista(li, li2, li3);
    
    system("pause");
    return 0;
}

