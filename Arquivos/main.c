#include <stdio.h>
#include <stdlib.h>
#define max_jogadores 2



typedef struct{
    int dia, mes, ano;
}DataNas;

typedef struct{
    DataNas dataNas;
    int numero;
    float peso;
    float altura;
    char nacionalidade[100];
    char clube [100];
    char posicao [100];
    char nome[100];
}Jogador;

//1) Imprimir os dados
void imprimirJogador(Jogador J){


    printf("\n\n-------------------------\n\n");
    printf("\tNome: %s \n", J.nome);
    printf("\tNumero: %d\n", J.numero);
    printf("\tClube: %s\n", J.clube);
    printf("\tPosicao: %s\n", J.posicao);
    printf("\tNacionalidade: %s\n", J.nacionalidade);
    printf("\tData de nas.: %d/%d/%d\n\n", J.dataNas.dia, J.dataNas.mes, J.dataNas.ano);
    printf("\tAltura: %0.2fm\n", J.altura);
    printf("\tPeso: %0.2fkg\n", J.peso);
    printf("\n\n-------------------------\n\n");



}
// 2) cadastro de dados
Jogador DadosJogador(){
    Jogador J;

    printf("\n\n-----------------------\n\n");
    printf("\nNome: ");
    setbuf(stdin,NULL); //buffer do teclado
    gets(J.nome);
    printf("\nNumero: ");
    scanf(" %d", &J.numero);
    printf("\nClube: ");
    setbuf(stdin,NULL);
    gets(J.clube);
    printf("\nPosicao: ");
    setbuf(stdin,NULL);
    gets(J.posicao);
    printf("\nNacionalidade:");
    setbuf(stdin, NULL);
    gets(J.nacionalidade);
    printf("\nData de nascimento (dd mm aaaa):");
    scanf("%d%d%d", &J.dataNas.dia, &J.dataNas.mes, &J.dataNas.ano);
    printf("\nAltura(m): ");
    scanf("%f", &J.altura);
    printf("\nPeso(kg): ");
    scanf("%f",&J.peso);
    printf("\n\n-----------------------\n\n");

     return J;
}

//3)Menu de opcao
int menu() {
    int opcao;

    printf("\n\n =*=*=*= MENU  =*=*=*=\n");
    printf("0 - SAIR \n");
    printf("1 - CADASTRAR\n");
    printf("2 - MOSTRAR \n");
    printf("\nO que deseja executar? ");
    scanf("%d", &opcao);

    return opcao;
}
int main() {
    int i;
    Jogador jogadores[max_jogadores];
    int opcao_selecionada;


    do {
        opcao_selecionada=menu();
        switch(opcao_selecionada){
            case 0: break;
            case 1:
                for(i=0;i<max_jogadores;i++){
                    jogadores[i] = DadosJogador();
                }

                break;

            case 2:
                for(i=0;i<max_jogadores;i++){
                    imprimirJogador(jogadores[i]);
                }

                break;
            default:
                printf("----- OPCAO INVALIDA -----");

        }

    }while(opcao_selecionada!=0);



    return 0;
    }
