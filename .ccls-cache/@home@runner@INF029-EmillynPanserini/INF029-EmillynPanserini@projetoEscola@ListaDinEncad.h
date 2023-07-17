//Arquivo ListaDinEncad.h


typedef struct{
    int matricula;
    char nome[30];
    float data;
    char sexo[20];
    int CPF;
} Aluno;

typedef struct{
    int matricula;
    char nome[30];
    float data;
    char sexo[30];
    int CPF;
} Professor;

typedef struct{
  char nome[30];
  int semestre;  
  int codigo;
  char professor[30];
  Aluno alun;
  int qtd;
}Disciplina;

typedef struct elemento* Lista;

Lista* cria_lista();
Lista* cria_listadis();
Lista* cria_listaprof();

void libera_lista(Lista* li, Lista* li2, Lista* li3);

int insere_lista_final(Lista* li, Aluno al);
int insere_lista_inicio(Lista* li, Aluno al);
int insere_lista_inicio_prof(Lista* li2, Professor prof);
int insere_lista_inicio_dis(Lista *li3, Disciplina dis);


int insere_lista_ordenada(Lista* li, Aluno al);
int insere_lista_final_dis(Lista* li3, Disciplina dis);
int insere_lista_final_prof(Lista* li2,Professor prof);


int remove_lista(Lista* li, int mat);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);

int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
int lista_cheia(Lista* li);

void imprime_lista(Lista* li);
void imprime_consulta(Lista* li, int matriculac, Aluno *al);
void imprime_listaProf(Lista* li2);
void imprime_disciplina(Lista* li3);
void imprime_disciplinaAlun(Lista* li3, Disciplina dis);


int consulta_lista_mat(Lista* li, int mat, Aluno *al);
int consulta_lista_pos(Lista* li, int pos, Aluno *al);


void Menu_editar(Lista* li, Lista *li2);
void Menu_editar_dis(Lista *li3);
void Menu_op_alun(void);
void Menu_op_prof(void);
void Menu_op_dis(void);

void Editar_dados_alun(Lista* li, int matriculac, Lista* li2);
void Editar_dados_prof(Lista* li2, int matriculac, Lista* li);
void Editar_dados_dis(Lista* li2, int matriculac, Lista* li, Lista* li3);



void NovoAlun (Lista* li);
void NovoProf ( Lista* li2);
void Nova (Lista* li3);

int Excluir (Lista* li, Lista* li2);
