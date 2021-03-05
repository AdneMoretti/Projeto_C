#include<stdio.h>
#include<string.h>
#include<stdbool.h>
//Declarando todas as funcoes antes do main para avisar que estas existem no codigo
int menu();
void pesquisar_associado();
int quantidade_natacao = 0;
int quantidade_futsal = 0;
int quantidade_tenis = 0;
void cadastrar_associado();
void cadastrar_dependente();
void listar_associado();
void gerar_relatorio();
bool faz_aula();
void listar_por_modalidade();
typedef struct Dependente {
    char nome[20];
    int idade;
}dependente[3];
typedef struct Associado  {
    int id;
    char nome[20];
    int idade;
    int qtdDep;
    struct Dependente dependente[3];
    bool natacao;
    bool futsal;
    bool tenis;
    int quantaulas;
    float mensalidade;
}associado[200];

//A funcao main vai apresentar os casos e os procedimentos para que cada caso se realize, estara em um laço de repeticao que so se encerra ao inserir o numero 7, de fim do programa
int main(){
    char aula[10];
    struct Associado associado[200];
    struct Dependente dependente[3];
    int escolha, quantidade, quantidade_d;
    quantidade = 0;
    quantidade_d = 0;
    do{

       escolha = menu();
        switch(escolha){
            case 1:
                 system("cls || clear");
                cadastrar_associado(associado, quantidade);
                quantidade++;
                break;
            case 2:
                 system("cls || clear");
                 //Se o numero de dependentes cadastrados ultrapassar 3, aparecera um aviso de ultrapassar o limite de dependentes permitidos
                if(quantidade_d <= 2){
                    cadastrar_dependente(associado, quantidade );}
                if(quantidade_d >= 3){
                    printf("O numero maximo de dependentes e 3, nao e possivel inserir mais.\n");
                }
                quantidade_d ++;
                break;
            case 3:
                system("cls || clear");
                listar_associado(associado, quantidade);
                break;
            case 4:
                system("cls || clear");
                listar_por_modalidade( associado, quantidade);
                break;
            case 5:
                system("cls || clear");
                pesquisar_associado(quantidade, associado);
                break;
            case 6:
                gerar_relatorio(quantidade, quantidade_d, associado);
                break;
            case 7:
                system("cls || clear");
                printf("----------------FIM---------------\n");
                printf("O programa chegou ao fim, muito obrigada e ate a proxima! :)\n" );
                break;
            default:
                system("cls || clear");
                printf("Esse numero nae esta entre os listados, por favor insira um numero valido\n");

        }

    }while(escolha != 7);





return 0;}
//Menu do programa, vai mostrar as opcoes e retornar a opcao escolhida
int menu(){
    int escolha;
    printf("1. Cadastrar associado\n");
    printf("2. Cadastrar dependente\n");
    printf("3. Listar associados\n");
    printf("4. Listar associados por modalidade\n");
    printf("5. Pesquisar associados\n");
    printf("6. Gerar relatorio de associados\n");
    printf("7. Finalizar programa\n");
    scanf("%d", &escolha);
    return escolha;

}
//CASO 1, o procedimento vai cadastrar os associados dentro da struct Associado associado[200]
void cadastrar_associado(struct Associado associado[],int quantidade){
    printf("----------CADASTRAR ASSOCIADO-------------\n");
    associado[quantidade].quantaulas = 0;
    printf("Digite o identificador:\n");
    scanf("%d", &associado[quantidade].id );
    printf("Digite o nome : \n");
    scanf(" %[^\n]s", &associado[quantidade].nome);
    printf("Digite a idade: \n");
    scanf("%d", &associado[quantidade].idade);
    associado[quantidade].qtdDep = 0;
    while (associado[quantidade].idade < 0){

            printf("Voce digitou uma idade invalida, por favor insira uma idade valida!\n");
            scanf("%d", &associado[quantidade].idade);
        }
    associado[quantidade].natacao = faz_aula("natacao");
    if(associado[quantidade].natacao == true){
        associado[quantidade].quantaulas ++;
        quantidade_natacao ++;
            }
    associado[quantidade].futsal = faz_aula("futsal");
    if(associado[quantidade].futsal== true){
        associado[quantidade].quantaulas ++;
        quantidade_futsal ++;
    }
    associado[quantidade].tenis = faz_aula("tenis");
    if(associado[quantidade].tenis == true){
        associado[quantidade].quantaulas ++;
        quantidade_tenis++;
    }

}


//A funçao vai perguntar, durante o cadastro de associados, quais sao as aulas que estes participam e retornar true ou false
bool faz_aula(char aula[10]){
    char resposta_aula;
    printf("O associado faz aula de %s ?  s/n\n", aula);
    scanf(" %c", &resposta_aula );
    while(resposta_aula != 'S' && resposta_aula !='N' && resposta_aula!= 's' && resposta_aula != 'n'){
        printf("Voce digitou uma resposta invalida, por favor digite s para sim e n para nao!\n");
        scanf(" %c", &resposta_aula );
    }
    if (resposta_aula == 'S'|| resposta_aula== 's'){
        return true;
    }

    if(resposta_aula == 'N' || resposta_aula== 'n'){
        return false;
    }

}



//CASO 2, o procedimento ira cadastrar os dependentes e relacionar aos determinados associados
void cadastrar_dependente(struct Associado associado[],int quantidade ){
    int i, pesquisar_id;
    printf("----------CADASTRAR DEPENDENTE------------\n");
    printf("Digite a id do associado que deseja cadastrar os dependentes\n");
    scanf("%d", &pesquisar_id);
    for(i=0; i< (quantidade); i ++){
        if(associado[i].id == pesquisar_id){
            printf("O associado e %s!\n", associado[i].nome);
            printf("Digite o nome do dependente:\n");
            scanf(" %[^\n]s", &associado[i].dependente[associado[i].qtdDep].nome);
            printf("Digite a idade: \n");
            scanf("%d", &associado[i].dependente[associado[i].qtdDep].idade);
                while (associado[i].dependente[associado[i].qtdDep].idade < 0){
                    printf("Voce digitou uma idade invalida, por favor insira uma idade valida!\n");
                    scanf("%d", &associado[i].dependente[associado[i].qtdDep].idade);

                }
            associado[i].qtdDep ++;
                }}

}



//CASO 3, o procedimento vai listar todos os associados ja cadastrados
void listar_associado(struct Associado associado[],int quantidade){
    printf("ASSOCIADOS: \n");
    int i;
    for(i=0; i< quantidade; i ++){
        printf("%d", associado[i].id );
        printf("-");
        printf("%s", associado[i].nome);
        printf("-");
        printf("%d", associado[i].idade);
        printf("-");
        printf("%d", associado[i].qtdDep);
        printf("-");
        if(associado[i].natacao == false){
            printf("Nao faz natacao");
        }
        else{
            printf("Faz natacao");
        }
        printf("-");
        if(associado[i].futsal == false){
            printf("Nao faz futsal");
        }
        else{
            printf("Faz futsal");
        }
        printf("-");
        if(associado[i].tenis == false){
            printf("Nao faz tenis\n");
        }
        else{
            printf("Faz tenis\n");
        }

    }
}
//CASO 4, a funcao vai apresentar um pequeno menu para saber qual a modalidade que se deseja saber, assim, vai apresentar todos os associados que participam desta
void listar_por_modalidade(struct Associado associado[],int quantidade){
    int modalidade_desejada, i;
    printf("Por qual modalidade deseja procurar?\n");
    printf("1. Natacao\n");
    printf("2. Futsal\n");
    printf("3. Tenis\n");
    scanf("%d", &modalidade_desejada);
    printf("Essa modalidade tem como alunos: \n");
    switch(modalidade_desejada){
        case 1:
            for(i=0; i< (quantidade);i++){
                if(associado[i].natacao == true){
                    printf("%d - %s\n", associado[i].id, associado[i].nome);
            }
            break;
        case 2:
            for(i=0; i< (quantidade);i++){
                if(associado[i].futsal == true){
                    printf("%d - %s\n", associado[i].id, associado[i].nome);
            }
            break;
        case 3:
            for(i=0; i< (quantidade);i++){
                if(associado[i].tenis == true){
                    printf("%d - %s\n", associado[i].id, associado[i].nome);}
            }
            break;
        default:
            printf("Por favor digite um numero dentre as opcoes\n");
        }
        }}}

//CASO 5, o procedimento vai pesquisar por um associado especifico e apresentar todas as informacoes, caso o associado nao seja encontrado, apresentara uma mensagem de erro.
void pesquisar_associado(int quantidade, struct Associado associado[]){

    char pesquisa_nome[20];
    int i;
    bool achou = false;
    printf("Digite o nome do associado que deseja procurar\n");
    scanf(" %[^\n]s ", &pesquisa_nome);
    for(i=0; i<(quantidade );i++){
        if (strcmp(associado[i].nome,pesquisa_nome) == 0 ){
            achou = true;
            associado[i].mensalidade = 100 + 50 *(associado[i].qtdDep) + 30 *(associado[i].quantaulas);
            printf("%d - %s - %d - %d - %d - %.2f\n", associado[i].id, associado[i].nome, associado[i].idade, associado[i].qtdDep,
                    associado[i].quantaulas, associado[i].mensalidade);}
    }

    if(achou == false){
       printf("Associado nao encontrado!\n");}
}
//CASO 6, o procedimento abaixo ir gerar um relatorio com as principais informacoes de todo o programa
void gerar_relatorio(int quantidade, int quantidade_d, struct Associado associado[]){
    float soma = 0;
    int i;
    float maior_mensalidade = 0;
    int mais_aula = 1;
    bool fazer_aula = false;
    printf("O numero total de associados registrados e: %d\n", quantidade);
    printf("O numero total de dependentes registrados e :%d\n",  quantidade_d);
    printf("A quantidade de associados que fazem aula de natacao e: %d\n", quantidade_natacao);
    printf("A quantidade de associados que fazem aula de futsal e: %d\n", quantidade_futsal);
    printf("A quantidade de associados que fazem aula de tenis e: %d\n", quantidade_tenis);
    //Determina o valor da maior mensalidade percorrendo um laço pela struct, do maior numero de aulas e determina a soma de todas as mensalidades
     for(i=0; i<quantidade; i++){
        associado[i].mensalidade = 100 + 50 *(associado[i].qtdDep) + 30 *(associado[i].quantaulas);
        soma = soma + associado[i].mensalidade;
        if(associado[i].mensalidade > maior_mensalidade){
            maior_mensalidade = associado[i].mensalidade;}
        if(associado[i].quantaulas > mais_aula){
            mais_aula = associado[i].quantaulas;
        }}
    printf("O valor total das mensalidades dos associados e: %2.fR$\n", soma);
    printf("O valor medio das mensalidades dos associados e: %2.fR$\n", soma/quantidade);
    printf("O valor de mensalidade mais alto pago por um associado e: %2.fR$\n", maior_mensalidade);
    printf("Os associados que fazem mais aulas sao: \n");
    for(i=0; i<quantidade; i++){
        if(associado[i].quantaulas == mais_aula){
            fazer_aula = true;
            printf("-%s\n", associado[i].nome);}}
    //Se nenhum associado participar de nenhuma aula, aparecera um aviso de que nao ha associados inscritos em aulas
    if(fazer_aula == false){
        printf("Nenhum associado faz aula!");
    }
}




