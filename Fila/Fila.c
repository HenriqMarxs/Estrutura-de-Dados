#include <stdlib.h>
#define TAM_MAX 5

typedef struct fila{
	int vetor[TAM_MAX];
	int final;
}Fila;

Fila f;

void inicializar();
void inserir(int);
void imprimir();
int verificarCheia();
int verificarVazia();
int remover();
int maior();
 

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

int verificarCheia(){
	if(f.final==TAM_MAX-1){
		return 1;
	}
	else return 0;
}

int verificarVazia(){
	if(f.final==-1){
		return 1;
	}
	else return 0;
}



int remover(){
	int i;
	int aux;
	aux=f.vetor[0];
	if(!verificarVazia()){
		for(i=0; i<=f.final; i++){
			f.vetor[i]=f.vetor[i+1];
		}
		f.final--;
	}
	else printf("\n!!!ERRO: FILA ESTA VAZIA!!!\n");
	
	return aux;
}

void imprimir(){
	int i;
	if(!verificarVazia()){
		printf("\n");
		for(i=0; i<=f.final;i++){
			printf("!!VALORES INSERIDOS NA FILA!!\n%d -- %d\n", (i+1), f.vetor[i]);
		}
	}
	else printf("\n!!!ERRO: FILA ESTA VAZIA!!!\n");
}

int maior(){
	int i;
	for(i=0; i<=f.final; i++){
		if(f.vetor[i]>=f.vetor[0]&&f.vetor[i]>=f.vetor[1]&&f.vetor[i]>=f.vetor[2]&&f.vetor[i]>=f.vetor[3]&&f.vetor[i]>=f.vetor[4]&&f.final>-1){
			printf("\nO maior valor inserido na fila eh: %d\n",f.vetor[i]);
			return 0;
		}	
	}
	if(f.final==-1){
		printf("\n!!!ERRO: FILA VAZIA!!!\n");
	}
		
}

void main(){
	int numero;
	int temp;
	int option;
	printf("!!!ATIVIDADE DE FILA!!!\n");
	do{
		printf("\nSelecione uma das opcoes\n");
		printf("\n1.Inicializar\n2.Inserir\n3.Imprimir\n4.Remover\n5.Maior valor\n6.Sair\n");
		scanf("%d", &option);
		switch(option){
			case 1:
				system("cls");
				inicializar();
				break;
			case 2:
				system("cls");
				printf("\nDigite um valor INTEIRO que deseje inserir na fila:\n");
				scanf("%d",&numero);
				inserir(numero);
				break;
			case 3:
				system("cls");
				imprimir();
				break;
			case 4:
				system("cls");
				temp=remover();
				printf("\nNumero removido da fila: %d\n", temp);
				break;
			case 5:
				system("cls");
				maior();
				break;
			case 6:
				system("cls");
				printf("\nENCERRANDO PROGRAMA....\n");
				break;
			default:
				printf("\nPor favor insira uma opcao valida!!!\n");
				break;
			}
		}while(option!=6);
	}

