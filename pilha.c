#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>

struct pilha{
    int *valor;
    int tamanho;
    int topo;
};

//procedimento que cria uma pilha
void criar(struct pilha *p, int tamanho);

//procedimento que inserir na pilha
void inserir(struct pilha *p, int valor);

//procedimento mostra os valores inserido na pilha
void mostrar(struct pilha *p);

//menu de opcoes
void menu(struct pilha *p);

//remover elemento da pilha
int remover(struct pilha *p);

//verificar se a pilha está vazia!
bool pilhaVazia(struct pilha *p);

//verificar se a pilha está cheia!
bool pilhaCheia(struct pilha *p);

int main(void){
    struct pilha p;
    int tam;
    printf("Digite o tamanho da pilha: \n");
    scanf("%d", &tam);
    criar(&p, tam);
    menu(&p);
    return 0;
}

//menu de opcoes
void menu(struct pilha *p)
{
    int opcoes, valor;
    while(opcoes)
    {
        system("cls");
        printf(
        "%s %s %s %s",
        "\n[1] - Inserir\n",
        "\n[2] - Remover\n",
        "\n[3] - Mostrar\n",
        "\n[0] - Sair\n"
        );
        scanf("%d", &opcoes);
        switch(opcoes)
        {
            case 0:
                exit(0);
            break;
            
            case 1: //inserir
                system("cls");
                if(!pilhaCheia(p))
                {
                    printf("Digite o valor: \n");
                    scanf("%d", &valor);
                    inserir(p, valor);
                }
                else{
                    printf("Pilha Cheia!\n");
                }
                getch();
            break;
            
            case 2: //remover
                system("cls");
                if(!pilhaVazia(p))
                {
                    printf("Digite o valor: \n");
                    valor = remover(p);
                    printf("O valor removido foi %d", valor);
                }
                else{
                    printf("Pilha Vazia!\n");
                }
                getch();
            break;
            
            case 3: //mostrar
                system("cls");
                if(!pilhaVazia(p)){
                    mostrar(p);
                }
                else{
                    printf("Pilha vazia!\n");
                }
                getch();
            break;
            
            default:
                system("cls");
                printf("Opcao invalida!\n");
                getch();
            break;
        }
    }
}

//procedimento que cria uma pilha
void criar(struct pilha *p, int tamanho)
{
    p->topo = -1;
    p->tamanho = tamanho;
    p->valor = (int*)calloc(tamanho, sizeof(int));
}

//procedimento que inserir na pilha
void inserir(struct pilha *p, int valor)
{
    p->topo++;
    p->valor[p->topo] = valor;
}

//procedimento mostra os valores inserido na pilha
void mostrar(struct pilha *p)
{
    int i;
    for(i = p->topo; i >= 0 ; i--)
    {
        printf("[%d]\n", p->valor[i]);
    }
    
}
//remover elemento da pilha
int remover(struct pilha *p)
{
    int valorRemovido = p->valor[p->topo];
    p->topo--;
    return valorRemovido;
}

//verificar se a pilha está vazia!
bool pilhaVazia(struct pilha *p)
{
    if(p->topo == -1){
        return true;
    }
    else{
        return false;
    }
}

//verificar se a pilha está cheia!
bool pilhaCheia(struct pilha *p)
{
    if(p->topo == p->tamanho-1)
    {
        return true;
    }
    else{
        return false;
    }
}

