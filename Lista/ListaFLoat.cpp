#include <stdio.h>
#define TAM_MAX 5

typedef struct lista{
	float vetor[TAM_MAX];
	int final;
}lista;

lista l;

void inserir(float, int);
void remover(int);
void imprimir();
int verificarCheia();
int verificarVazia();
void inicializar();

void inicializar(){
	l.final = -1;
			
}

void inserir(float numero, int pos){ 
	int i;
	if(!verificarCheia()){
		if(pos>=l.final){
			l.final++;
			l.vetor[l.final] = numero;
		}
		else{
			for(i=pos; i<l.final; i++){
				l.vetor[i]=l.vetor[i+1];
			}
			l.final++;
			l.vetor[pos]=numero;
		}
	}
	else{
		printf("\n!!!ERRO: LISTA CHEIA!!!\n ");
	}
}


void remover(int posi){
	int i;
	if(!verificarVazia()){
		for(i=posi;i<l.final; i++){
			l.vetor[i]=l.vetor[i+1];
		}
		l.final--;
	}
	else{
		printf("!!!ERRO: LISTA ESTA VAZIA!!!");
	}
	
}

int verificarVazia(){
	if(l.final==-1){
		return 1;
	}
	else return 0; 
}

int verificarCheia(){ 
	if(l.final==TAM_MAX-1){
		return 1;
	}
	else return 0;
}

void imprimir(){ 
	int i;
	if(!verificarVazia()){
		for(i=0; i<=l.final;i++){
			printf("Posicao: %d: %.2f", (i+1), l.vetor[i]);
		}
	}
}

void main(){
	int option;
	int posicao;
	float numero;
	do{
		printf("!!!ATIVIDADE DE LISTA!!!\n");
		printf("Selecione uma das opcoes abaixo\n");
		printf("1.Inicializar\n2.Inserir\n3.Remover\n4.Imprimir\n5.Sair");
		scanf("%d", &option);
		switch(option){
			case 1:
				system("cls");
				inicializar();
				break;
				
			case 2:
				system("cls");
				printf("Em qual posicao deseja inserir o numero?\n1--\n 2--\n3--\n4--\n5--\n");
				scanf("%d", &posicao);
				printf("Digite o numero que deseja inserir\n");
				scanf("%f", &numero);
				inserir(numero, posicao-1);
				break;
				
			case 3:
				system("cls");
				printf("De qual posiçao deseja remover o numero\n");
				scanf("%d", &posicao);
				break;
				
			case 4:
				system("cls");
				imprimir();
				break;
				
			case 5:
				printf("ENCERRANDO O PROGRAMA....\n");
				break;
				
			default:
				printf("!!!ERRO: INSIRA UMA POSICAO VALIDA!!!\n");
				break;
		}
	}while(option!=5);
}
