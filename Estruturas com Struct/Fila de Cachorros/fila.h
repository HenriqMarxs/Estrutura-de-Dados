typedef struct cachorro{
	char nome[50];
	char raca[50];
	int idade;
	char genero;
}cachorro;

void inicialiazar();
void inserir(cachorro);
cachorro remover();
int verificarCheia();
int verificarVazia();
void imprimir();

