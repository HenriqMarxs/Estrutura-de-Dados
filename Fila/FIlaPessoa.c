#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 5

typedef struct Pessoa{
	char nome[50];
	int idade;
	char genero;
}pessoa;

typedef struct fila{
	pessoa vetor[TAM_MAX];
	int final;
}Fila;

Fila f;

void incializar();
void inserir(pessoa);
int verficarVazia();
int verificarCheia();
void remover();
void imprimir();

void inicializar(){
	f.final=-1;
}

void inserir(pessoa p){
	if(!verificarCheia()){
		f.final++;
		f.vetor[f.final]= p;
	}
	else{
		printf("\n!!!ERRO; FILA CHEIA!!!\n");
	}
}
int verificarVazia(){
	if(f.final==-1){
		return 1;
		
	}else return 0;
}

int verificarCheia(){
	if(f.final == TAM_MAX-1){
		return 1;
	}else return 0;
}

void remover(){
	pessoa aux;
	int i;
	if(!verificarVazia()){
		aux = f.vetor[0];
		for(i=0; i<=f.final; i++){
			f.vetor[i]=f.vetor[i+1];
		}
		printf("\n--------------------------\n  Pessoa Removida da fila:\nNome: %s\nIdade: %d\nGenero: %c\n:--------------------------\n", aux.nome, aux.idade, aux.genero);
		f.final--;
		
	}
	else printf("\n!!! ERRO: FILA VAZIA!!!\n");	
}

void imprimir(){
	int i;
	if(!verificarVazia()){ 
		for(i=0; i<=f.final; i++){
		printf("\n--------------------------\n  PESSOA %d\nNome: %s\nIdade: %d\nGenero: %c\n--------------------------\n",(i+1), f.vetor[i].nome, f.vetor[i].idade, f.vetor[i].genero);
		}
	}
	else{ 
		printf("!!!ERRO: FILA VAZIA!!!\n");
	}
}

void main(){
	int option;
	pessoa remov;
	pessoa insert;

	do{
		printf("!!!ATIVIDADE DE FILA DE PESSOAS!!!");
		printf("\nSelecione uma das opcoes abaixo\n");
		printf("1.Inicializar\n2.Inserir Pessoa\n3.Imprimir Fila\n4.Remover Pessoa da fila\n5.Sair\n");
		scanf("%d", &option);
		switch(option){
			case 1:
				system("cls");
				inicializar();
				break;
			case 2:
				system("cls");
				printf("Digite o nome\n");
				scanf("%s", insert.nome);
				printf("\nDigite a idade\n");
				scanf("%d", &insert.idade);
				printf("\nGenero H:Homen ou M:Mulher\n");
				scanf(" %c", &insert.genero);
				while(insert.genero!='h'&& insert.genero!='m'){
					printf("!!!ERRO GENERO INVALIDO!!!\nPor favor insira um genero valido\nGenero H:Homen ou M:Mulher\n");
					fflush(stdin);
					scanf(" %c", &insert.genero);
				}
				inserir(insert);
				break;
				
			case 3:
				system("cls");
				imprimir();
				break;
			
			case 4:
				system("cls");
				remover();	
				break;
				
			case 5:
				system("cls");
				printf("ENCERRANDO PROGRAMA....\n");
				break;
			
			default:
				printf("ERRO: SELECIONE UMA OPCAO VALIA\n");
				break;
		}

	}while(option!=5);
}
