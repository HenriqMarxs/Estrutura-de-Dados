#include <stdio.h>
#include "fila.h"
#define TAM_MAX 10

typedef struct fila{
	cachorro vetor[TAM_MAX];
	int final;
}fila;

fila f;

void inicialiazar(){
	f.final = -1;
}

void inserir(cachorro cach){
	if(!verificarCheia()){
		f.final++;
		f.vetor[f.final]=cach;
	}else{
		printf("!!!ERRO: FILA ESTA CHEIA!!!");
	}
}
cachorro remover(){
	cachorro aux;
	int i;
	if(!verificarVazia()){
		aux=f.vetor[0];
		for(i=0;i<=f.final;i++){
			f.vetor[i]=f.vetor[i+1];
		}
		f.final--;
		return aux;
	}else{
		printf("!!!ERRO: FILA ESTA VAZIA!!!");
	}
}

int verificarVazia(){
	if(f.final==-1){
		return 1;
	}else return 0;
}

int verificarCheia(){
	if(f.final==TAM_MAX-1){
		return 1;
	}else return 0;
}

void imprimir(){
	int i;
	if(!verificarVazia()){
		for(i=0; i<=f.final;i++){
			printf("_____________________\n POSICAO DA FILA %d\nNome:%s\nRaca:%s\nIdade:%d\nGenero:%c\n", i, f.vetor[i].nome, f.vetor[i].raca, f.vetor[i].idade, f.vetor[i].genero);
			
		}
	}
}
