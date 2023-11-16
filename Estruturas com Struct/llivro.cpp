#include <stdio.h>
#define TAM_MAX 10

typedef struct Livro {
	char isbn [50];
	char titulo[100];
	float preco;
} livro;


typedef struct Pilha{
	livro vetor[TAM_MAX];
	int topo;
}pilha;

pilha p;

void push(livro lv);
int pop();
void imprimir();
int verificarCheia();
int verificarVazia();
void inicializar();

void inicializar(){
	p.topo = -1;
}

int verificarVazia(){
	if(p.topo == -1)
		return 1;
	else return 0;
}

int verificarCheia(){
	if(p.topo == TAM_MAX - 1)
		return 1;
	else return 0;
}

void push(livro lv){
	//verificar se a pilha nao estah cheia
	if(!verificarCheia()) {
		//atualiza o topo da pilha
		p.topo++;
		//insere o elemento no vetor na posi??o topo
		p.vetor[p.topo] = lv;
	} else {
		//se estiver cheia, informa o usu?rio
		printf("\nNao eh possivel inserir, pilha cheia.");
	}
}

int pop(){
	//verificar se a pilha nao estah vazia
	if(!verificarVazia()) {
		//define vari?vel uma variavel auxiliar
		//variavel auxiliar ira guardar o elemento do topo da pilha
		//atualiza o topo da pilha
		p.topo--;
		//retorna o numero removido
		return p.topo;
	} else {
		//se estiver vazia, informa o usu?rio
		printf("\nA pilha estah vazia.");
		return 0;
	}
}

void imprimir(){
	//verificar se a pilha n?o est? vazia
	if(!verificarVazia()) {
		//define uma vari?vel auxiliar
		int i;
		printf("\nOs elementos na pilha sao:");
		//percorrer o vetor do topo ate a base
		for(i = p.topo; i >= 0; i--){
			//imprimir o elemento na posicao i
			printf("\n isbn:%s", p.vetor[i].isbn);
			printf("\n Titulo:%s", p.vetor[i].titulo);
			printf("\n Preco:%.2f", p.vetor[i].preco);
		}
	} else {
		//se estiver vazia, informa o usuario
		printf("\nA pilha esta vazia.");
	}
}

int main(int argc, char *argv[]) {
	livro temp;
	int temp2;
	int opcao;
	inicializar();

	do {
		//exibir o menu
		printf("\n    MENU");
		printf("\n1. Inicializar");
		printf("\n2. Inserir");
		printf("\n3. Remover");
		printf("\n4. Imprimir");
		printf("\n5. Sair");
		printf("\nDigite a opcao desejada: ");
		
		//ler a opcao desejada pelo usuario
		scanf("%d", &opcao);
		
		//processar a funcionalidade
		switch(opcao) {
			case 1:
				inicializar();
				break;
			case 2:
				printf("Digite o isbn do livro: ");
				scanf("%s", temp.isbn);
				printf("Digite o titulo do livro: ");
				scanf("%s", temp.titulo);
				printf("Digite o preco do livro: ");
				scanf("%f", &temp.preco);
				printf("\n%s", temp.titulo);
				printf("\n%f", temp.preco);
				push(temp);
				break;
			case 3:
				temp2 = pop();
				printf("Numero removido: %d", temp);
				break;
			case 4:
				imprimir();
				break;
			case 5:
				printf("Encerrando o programa...");
				break;
			default:
				printf("\nOpcao invalida. Escolha um numero valido de opcao.");
		}
		
	} while(opcao != 5);
}

