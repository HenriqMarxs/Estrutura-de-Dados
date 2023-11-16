#include <stdio.h>
#include <stdlib.h>
#include "pilhaa.h"

void main(){
	pessoa temp;
	int option;
	pessoa insert;
	do{
		printf("\n!!!ATIVIDADE DE PILHA PARA PROVA!!!\n");
		printf("Selecione uma das opcoes abaixo\n");
		printf("1.Inicializar\n2.Inserir\n3.Remover\n4.Imprimir\n5.Sair\n");
		scanf("%d", &option);
		switch(option){
			case 1:
				system("cls");
				inicializar();
				break;
			case 2:
				system("cls");
				printf("Para inseirir uma pessoa a pilha informe os dados abaixo\nNome:");
				scanf("%s", insert.nome);
				printf("\nIdade:");
				scanf("%d", &insert.idade);
				printf("\nGenero:");
				scanf(" %c", &insert.genero);
				printf("\nPeso:");
				scanf("%f", &insert.peso);
				inserir(insert);
				break;
			case 3:
				system("cls");
				temp=remover();
				printf("Pessoa removida da pilha\n");
				printf("Nome:%s\nIdade:%d\nGenero:%c\nPeso:%.2f\n", temp.nome, temp.idade, temp.genero, temp.peso);	
				break;
			case 4:
				system("cls");
				imprimir();
				break;
			case 5:
				system("cls");
				printf("ENCERRANDO PROGRAMA......\n");
				break;
		}
	}while(option!=5);
	
}
