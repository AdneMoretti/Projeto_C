#include<stdio.h>
#include<string.h>
//Apresenta as funcoes e p procedimentos utilizados
void maior_nota();
void printar_matriz();
void media();
typedef struct aluno{
    char nome[20];
    int idade;
    float nota;
}matriz[200][200];
int main(){
struct aluno matriz[200][200];
int linhas, colunas, i, j;
    printf("Digite o numero de linhas da sua matriz\n");
    scanf(" %d", &linhas);
    printf("Digite o numero de colunas da sua matriz\n");
    scanf(" %d", &colunas);

    //Apresentara a opcap de cadastrar o aluno, idade e nota e armazena dentro da matriz de struct
    printf("-------------- CADASTRO ---------------\n");
    for(i=0; i< linhas; i++){
        for(j=0; j < colunas; j++){
            printf("Digite o nome do aluno:\n ");
            scanf(" %[^\n]s", &matriz[i][j].nome);
            printf("Digite a idade do aluno:\n ");
            scanf("%d",&matriz[i][j].idade );
            printf("Digite a nota do aluno:\n ");
            scanf("%f",&matriz[i][j].nota);
            while (matriz[i][j].nota > 10 || matriz[i][j].nota < 0){
                printf("Essa nota nao existe, por favor insira uma nota entre 0 e 10\n");
                scanf("%f",&matriz[i][j].nota);
            }
            printf("----------------------------------\n");
           }}

//Aqui os procedimentos que printam as informações necessarias sao chamados
system("cls || clear");
maior_nota( matriz, linhas,colunas);
media(matriz,linhas,colunas );
printar_matriz(matriz, linhas, colunas);

return 0;}
//Verifica qual a maior e menor nota dentre as armazenadas e printa em qual linha e coluna estas estao armazenadas
void maior_nota(struct aluno matriz[][200], int linhas, int colunas){
    float maior = 0;
    float menor = 10;
    int i, j;
    for(i=0; i< linhas; i++){
        for(j=0; j < colunas; j++){
            if (matriz[i][j].nota > maior){
                maior = matriz[i][j].nota;
            }
            if (matriz[i][j].nota < menor){
                menor = matriz[i][j].nota;
            }}}
    for(i=0; i< linhas; i++){
        for(j=0; j < colunas; j++){
            if (matriz[i][j].nota == maior){
                printf(" - A linha do estudante com a maior nota e %d e a coluna e %d\n", i + 1, j+1);}
            if (matriz[i][j].nota == maior){
                 printf(" - A linha do estudante com a menor nota e %d e a coluna e %d\n", i + 1, j+1);

    }}}

    printf(" - A maior nota foi %2.f\n", maior);
    printf(" - A menor nota foi %2.f\n", menor);
}
//O procedimento printa as notas armazenadas na matriz
void printar_matriz(struct aluno matriz[][200], int linhas, int colunas ){
    printf("-------- notas ----------\n");
    int i;
    int j;
    for(i=0; i< linhas; i++){
        printf("|");
        for(j=0; j < colunas; j++){
            printf("%2.f",matriz[i][j].nota);
            printf("  ");

           }
           printf("|");
           printf("\n");}



}
//Procedimento que verifica qual e a linha que tema a maior e menor media, dentro de um laco de repeticao, quando a media e maior que a maior media ja encontrada, o numero da sua linha e armazenada em uma variavel
void media(struct aluno matriz[][200], int linhas, int colunas ){
    float menor_media = 10;
    float maior_media = 0;
    float soma;
    int i,j,linha_maior, linha_menor;
     for(i=0; i< linhas; i++){
        for(j=0; j < colunas; j++){
            soma = 0;
            soma = soma + matriz[i][j].nota;

           }
        if(soma/colunas > maior_media){
            maior_media = soma/colunas;
            linha_maior = i;
        }
        if(soma/colunas < menor_media){
            menor_media = soma/colunas;
            linha_menor = i;

        }}
        printf(" - A linha com a menor media e %d\n", linha_menor + 1);
        printf(" - A linha com a maior media e %d\n ", linha_maior +1);

}

