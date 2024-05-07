#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>

typedef struct {
    char palavra[100];
    struct Palavra *prox;
} Palavra;

Palavra *primeiraPalavra;
Palavra *ultimaPalavra;
int tamanho;

void desenha_forca(int contador, int inicio);
int menu_principal();
char* buscar_palavra(char nome_arquivo[]);
void criar_lista_vazia();
void insere_na_lista(Palavra palavra);
int sorteia_palavra(int faixa);

int main(){

    setlocale(LC_ALL, "Portuguese");
    int contador, opcao;
    char frase[100];

    do {
        MENU:
        system("cls");
        desenha_forca(contador, 1);
        opcao = menu_principal();
        if (opcao==0)
        {
        exit(0);
        }
        else if(opcao==1)
        {
            strcpy(frase,buscar_palavra("animais.txt"));
        }
        else if(opcao==2)
        {
            strcpy(frase,buscar_palavra("profissoes.txt"));
        }
        else if(opcao==3)
        {
            strcpy(frase,buscar_palavra("paises.txt"));
        }
        else if(opcao==4)
        {
            strcpy(frase,buscar_palavra("filmes.txt"));
        }
        else if(opcao==5)
        {
            strcpy(frase,buscar_palavra("seriados.txt"));
        }else{
            printf("\nOpção Invalida tente Novamente");
           // system("cls");
            goto MENU;
        }

    } while (contador = 1);
}

desenha_forca(int contador, int inicio){
    if(inicio == 0){
            switch(contador){
                case 0:
                    printf("_____________   \n|.|         |   \n|.|        _|_\n|.|          \n|.|        \ \n|.|         \n|.| \n|.| \n|.| \n\n");
                    break;

                case 1:
                    printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|         \n|.|       \n|.| \n|.| \n|.| \n\n");
                    break;

                case 2:
                    printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|         |    \n|.|         \n|.| \n|.| \n|.| \n\n");
                    break;

                case 3:
                    printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|        /|    \n|.|         \n|.| \n|.| \n|.| \n\n");
                    break;

                case 4:
                    printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|        /|\\    \n|.|         \n|.| \n|.| \n|.| \n\n");
                    break;

                case 5:
                    printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|        /|\\    \n|.|        /  \n|.|  \n|.|  \n|.| \n\n");
                    break;

                case 6:
                    printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|        /|\\    \n|.|        / \\ \n|.|  \n|.|  \n|.| \n\n");
                    break;
            }

    } else {
    puts("_____________ \n|.|         |   \n|.|        _|_\n|.|         O    \t JOGO DA FORCA \n|.|        /|\\           Briena Bertoni \n|.|        / \\           Heloisa Moraes \n|.|                      Jaqueline Neder \n|.|                      Vannilia Santos Lima \n|.|                      Yago Elias Sigognini \n|.| \n|.| \n");
    }

}

int menu_principal(){
    int opcao;
    printf("\n##########################################################");
    printf("\n#                                                        #");
    printf("\n#                                             ###        #");
    printf("\n#                                             # #        #");
    printf("\n#                                             ###        #");
    printf("\n#        ####  ####  ####  ####   ##           #         #");
    printf("\n#        #     #  #  #  #  #     #  #          #         #");
    printf("\n#        ##    #  #  ####  #     ####        # # #       #");
    printf("\n#        #     #  #  # #   #     #  #      #   #   #     #");
    printf("\n#        #     ####  #  #  ####  #  #          #         #");
    printf("\n#                                            #   #       #");
    printf("\n#                                          #       #     #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#        Digite um comando para prosseguir:              #");
    printf("\n#                                                        #");
    printf("\n#        1 – Animais                                     #");
    printf("\n#        2 – Profissões                                  #");
    printf("\n#        3 – Países                                      #");
    printf("\n#        4 – Filmes                                      #");
    printf("\n#        5 – Sériados                                    #");
    printf("\n#        0 – Sair                                        #");
    printf("\n#                                                        #");
    printf("\n##########################################################\n");
    scanf("%d",&opcao);
    return opcao;
}

char* buscar_palavra(char nomeArquivo[]){
    FILE *pont_arq;
    char linha[1024];
    char palavraSorteada[100];
    Palavra palavra;
    pont_arq = fopen(nomeArquivo, "r");
    if(pont_arq == NULL){
        printf("Erro na abertura do arquivo!");
        return 1;
    }
    int i = 0;
    tamanho = 0;
    criar_lista_vazia();
    while(fscanf(pont_arq, " %[^\n]s",linha)!= EOF){
        char *ptr;
        ptr = strtok(linha, ";");
        strcpy(palavra.palavra,ptr);
        ptr = strtok(NULL, ";");
        insere_na_lista(palavra);
        tamanho++;
    }

    fclose(pont_arq);
    Palavra lista[tamanho-1];
    Palavra *palavraAux;
    palavraAux = primeiraPalavra->prox;
    i = 0;

    int numero = sorteia_palavra(tamanho-1);

    while(palavraAux != NULL){
        if(i == numero){
             strcpy(palavraSorteada, palavraAux->palavra);
        }
        palavraAux = palavraAux->prox;
        i++;
    }
    limpar_lista();
    return palavraSorteada;
}

void criar_lista_vazia(){
    primeiraPalavra = (Palavra *)malloc(sizeof(Palavra));
    ultimaPalavra = primeiraPalavra;
}

void insere_na_lista(Palavra palavra){
    Palavra *palavraAux;
    palavraAux = (Palavra *)malloc(sizeof(Palavra));

    strcpy( palavraAux->palavra,palavra.palavra);

    ultimaPalavra->prox=palavraAux;
    ultimaPalavra=ultimaPalavra->prox;
    palavraAux->prox=NULL;
}

int sorteia_palavra(int faixa){
    srand( (unsigned)time(NULL) );
    return  rand() % faixa;
}

void limpar_lista(){
    Palavra *no = primeiraPalavra, *aux;
    while (no != NULL)
    {
        aux = no;
        no = no->prox;
        free (aux);
    }
    primeiraPalavra = NULL;
    ultimaPalavra = NULL;
}
