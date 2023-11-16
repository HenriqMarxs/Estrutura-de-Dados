typedef struct pessoa{
	char nome[50];
	int idade;
	char genero;
	float peso;
}pessoa;

void inicializar();
void inserir(pessoa);
void imprimir();
pessoa remover();
int verificarCheia();
int verificarVazia();
