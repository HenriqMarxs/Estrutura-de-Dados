
#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 5


typedef struct fila{
    int vetor[TAM_MAX];
    int final;
}fila;

fila f;

void inicializar();
void inserir(int);
int verificarVazia();
int verificarCheia();
void imprimir();
int remover();

void inicializar(){
    f.final=-1;
}

void inserir(int numero){
    if(!verificarCheia()){
    f.final++;
    f.vetor[f.final] = numero;
    
    }
    else{
        printf("Nao e possivel escreve dado a fila, fila esta cheia\n");
    }
}

int verificarVazia(){
    if(f.final==-1){
        return 1;
    }
    else return 0;
}

int verificarCheia(){
    if(f.final==TAM_MAX-1){
        return 1;
    }
    else return 0;
}
void imprimir(){
    if(!verificarVazia()){
            int i;
            printf("Os elementos presentes na fila sao:\n");
            for(i=0; i<=f.final;i++){
            printf("%d - %d\n", (1+i), f.vetor[i]);
        }
        
    }else{
        printf("A pilha esta vazia\n");
    }

}

int remover(){
    if(!verificarVazia()){
        int aux;
        int i;
        aux=f.vetor[0];
        for(i=0; i<f.final;i++){
            f.vetor[i]=f.vetor[i+1];
        }
        f.final--;
        return aux;
    }
    else{
        printf("A fila esta vazia.\n");
        return 0;
    }
}



void main(){
    int temp;
    int select;
    int numero;
    printf("Atividade de Fila\n");
    do{
        printf("Selecione uma das funcoes disponiveis\n");
        printf("1.inicializar\n2.inserir\n3.imprimir\n4.remover\n5.Sair\n");
        scanf("%d",&select);
        switch(select){
            
            
        case 1:
            inicializar();
            break;
        case 2:
        printf("Digite um valor INTEIRO para adicionar a fila\n");
        scanf("%d", &numero);
            inserir(numero);
            break;
        case 3:
            imprimir();
            break;
        case 4:
            temp=remover();
            printf("Numero removido:%d\n", temp);
            break;
        case 5:
            printf("Encerrando o programa...\n");
            break;
        default:
            printf("opcao invalida. Escolha um numero de opcao valido\n");
        }
        
    }while(select!=5);
}
