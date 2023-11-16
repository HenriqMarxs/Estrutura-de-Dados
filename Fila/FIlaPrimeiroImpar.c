#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 5

typedef struct fila{
	int vetor[TAM_MAX];
	int final;
}Fila;

Fila f;

void inicializar();
void inserir(int);
int verificarVazia();
int verificarCheia();
int remover();
void imprimir();
int primeiroImpar();

void inicializar(){
	f.final=-1;
}

void inserir(int numero){ 
	if(!verificarCheia()){
		f.final++;
		f.vetor[f.final]=numero;
	}
	else{
		printf("\n!!!ERRO: FILA ESTA CHEIA!!!\n");
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

int remover(){
	int aux;
	int i;
	aux= f.vetor[0];
	for(i=0; i<=f.final;i++){
		f.vetor[i]=f.vetor[i+1];
	}
	f.final--;
	return aux;
}

void imprimir(){ 
	int i;
	if(!verificarVazia()){
		printf("\n!VALORES INSERIDOS NA FILA!!\n");
		for(i=0; i<=f.final;i++){
			printf("\n%d -- %d", (i+1), f.vetor[i]);
		}
	}
	else{
		printf("\n!!!ERRO FILA ESTA VAZIA!!!\n");
	}
}

int primeiroImpar(){
	int i;
	int auxi;
	if(!verificarVazia()){
			for(i=0; i<=f.final; i++){
				if(f.vetor[i]%2!=0){
					auxi=f.vetor[i];
					return auxi;
			}
			else{
				return 0;
			}
		}
	}
	else{
		printf("\n!!!ERRO FILA VAZIA!!!\n");
	}
	return 0;
}


void main(){
	int temp;
	int imp;
	int insert;
	int option;
	printf("!!!ATIVIDADE DE FILAA!!!\n");
	do{ 
		printf("\nSelecione uma das opcoes abaixo\n");
		printf("\n1.inicializar\n2.Inserir\n3.Imprimir\n4.Remover\n5.Num impar\n6.Sair\n");
		scanf("%d", &option);
		switch(option){
			case 1:
				system("cls");
				inicializar();	
				break;
				
			case 2:
				system("cls");
				printf("Digite um valor INTEIRO:");
				scanf("%d", &insert);
				inserir(insert);	
				break;
				
			case 3:
				system("cls");
				imprimir();
				break;
				
			case 4:
				system("cls");
				temp=remover(); 
				if(!verificarVazia()){
					printf("\nValore removido da fila: %d", temp);
				}
				break;
				
			case 5:
				system("cls");
				imp = primeiroImpar();
				if(!verificarVazia() && imp!=0){
					printf("Primeiro valor impar encontrado: %d", imp);
				}
				else{
					if(!verificarVazia()&&imp==0){
					printf("\nNENHUM VALOR IMPAR ENCONTRADO NA FILA\n");
					}
				}
				break;
				
			case 6:
				system("cls");
				printf("ENCERRANDO O PROGRAMA....\n");
				break;
				
			default:
				system("cls");
				printf("\n!!!ERRO: SELECIONE UMA OPCAO VALIDA!!!\n");	
				break;
		}
	}while(option!=6);
}
