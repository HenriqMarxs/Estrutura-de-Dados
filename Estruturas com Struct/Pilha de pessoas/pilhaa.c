#include <stdio.h>
#include "pilhaa.h"
#define TAM_MAX 5

typedef struct pilha{
	pessoa vetor[TAM_MAX];
	int topo;
}pilha;

pilha p;

void inicializar(){ 
	p.topo=-1;
}

int verificarCheia(){
	if(p.topo==TAM_MAX-1){
		return 1;
	}else return 0;
}

int verificarVazia(){
	if(p.topo==-1){
		return 1;
	}else return 0;
}

void inserir(pessoa pes){
	if(!verificarCheia()){
		p.topo++;
		p.vetor[p.topo]=pes;
	}else{
		printf("!!!ERRO: PILHA ESTA CHEIA!!!\n");
	}
}

pessoa remover(){
	pessoa aux;
	int i;
	if(!verificarVazia()){
		aux = p.vetor[0];
		for(i=0; i<=p.topo; i++){
			p.vetor[i]=p.vetor[i+1];
		}
		p.topo--;
		return aux;
	}else{
		printf("!!!ERRO: PILHA VAZIA!!!\n");
	}
}

void imprimir(){
	int i;
	if(!verificarVazia()){
		for(i=0;i<=p.topo;i++){
			printf("________________\n POSICAO NA PILHA %d\nNome:%s\nIdade:%d\nGenero:%c\nPeso:%.2f\n", (i+1), p.vetor[i].nome, p.vetor[i].idade, p.vetor[i].genero, p.vetor[i].peso);
		}
	}else{
		printf("!!!ERRO: PILHA ESTA VAZIA!!!\n");
	}
}
