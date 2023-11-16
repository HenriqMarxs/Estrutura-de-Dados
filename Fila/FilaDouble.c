 #include <stdio.h>
 #include <stdlib.h>
 #define TAM_MAX 5
 
 typedef struct fila{
     double vetor[TAM_MAX];
     int final;
 }Fila;
 
 Fila f;
 
 void inicializar();
 void inserir(double);
 int verificarCheia();
 int verificarVazia();
 double remover();
 void imprimir();
 
 void inicializar(){
     f.final= -1;
 }
 
 void inserir(double numero){
     if(!verificarCheia()){
        f.final++;
        f.vetor[f.final]=numero;
     }
     else{
         printf("ERRO: FILA ESTA CHEIA\n");
     }
 }
 
 int verificarCheia(){
     if(f.final == TAM_MAX-1){
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
 
double remover(){
     double aux;
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
         for(i=f.final; i>=0; i--){
             printf("%d - %lf\n", (i+1), f.vetor[i]);
         }
     }
 }
 
 void main(){
     double temp;
     double numero;
     int option;
     printf("!!ATIVIDADE DE FILA!!\n");
     do{
        printf("selecione uma das opcoes disponiveis\n");
        printf("1.inicializar\n2.inserir\n3.imprimir\n4.remover\n5.Sair\n");
        scanf("%d", &option);
        switch(option){
            case 1:
            inicializar();
            break;
            
            case 2:
            printf("Digite o numero que deseja inserir na fila:\n");
            scanf("%lf", &numero);
            inserir(numero);
            break;
            
            case 3:
            imprimir();
            break;
            
            case 4:
            temp= remover();
            printf("O numero que foi removido da lista foi: %lf\n", temp);
            break;
            
            case 5:
            printf("Encerrando programa...\n");
            break;
            
            default:
            printf("Digite uma opcao valida\n");
            break;
        }
     }while(option!=5);
 }
 
