#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void main(){ 
	int option;
	cachorro temp;
	do{
		printf("\n!!!ATIVIDADE DE FILA ANTES DA PROVA!!!\n");
		printf("Selecione uma das opcoes abaixo\n");
		printf("1.incializar\n2.inserir\n3.remover\n4.imprimir\n5.sair\n");
		scanf("%d", &option);
		switch(option){
			case 1:
			system("cls");
			inicialiazar();
				break;
			case 2:
				system("cls");
				printf("Digite as informacoes do seu pet abaixo\n");
				printf("Nome:");
				scanf("%s", temp.nome);
				printf("\nRaca:");
				scanf("%s", temp.raca);
				printf("\nidade:");
				scanf("%d", &temp.idade);
				printf("\nGenero:");
				scanf(" %c", &temp.genero);
				inserir(temp);
				break;
			case 3:
				temp=remover();
				if(!verificarVazia()){
					printf("___________________________Pet removido da fila\nNome:%s\nRaca:%s\nidade:%d\nGenro:%c\n", temp.nome, temp.raca, temp.idade, temp.genero);
				}	
				break;
			case 4:
				system("cls");
				imprimir();	
				break;
			case 5:
				system("cls");
				printf("ENCERRANDO O PROGRAMA....");	
				break;
			
		}
	}while(option!=5);
}
