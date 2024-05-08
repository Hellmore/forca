#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>

int menu_principal();
char* recebe_palavra();
int inicia_jogo();
void desenha_forca(int contador, int inicio);
int verifica_tamanho(char* palavra);
void verifica_tentativa();


int main()
{
    int inicio_do_jogo, contador_jogadas = 0, tamanho_palavra;
    char* palavra[100];

    setlocale(LC_ALL, "Portuguese");
    inicio_do_jogo = menu_principal();
    if (inicio_do_jogo == 1) {
        system("cls");
        strcpy(palavra, recebe_palavra());
        system("cls");
        if (inicia_jogo() == 1) {
            system("cls");
            tamanho_palavra = verifica_tamanho(palavra);
            printf("%d\n", tamanho_palavra);
            desenha_forca(contador_jogadas, 0);

        }

    } else {
        system("cls");
        menu_principal();
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
    printf("\n#        Bem vindo ao jogo da forca!                     #");
    printf("\n#                                                        #");
    printf("\n#        O jogo deve ser jogado por 2 jogadores!         #");
    printf("\n#        O Jogador 1 escolhe a palavra a ser             #");
    printf("\n#        adivinhada e o Jogador 2 tenta adivinh�-la!     #");
    printf("\n#                                                        #");
    printf("\n#        A forca oferece 6 tentativas, voc� consegue     #");
    printf("\n#        sobreviver?                                     #");
    printf("\n#                                                        #");
    printf("\n#        Boa Sorte!!                                     #");
    printf("\n#                                                        #");
    printf("\n#        (Digite 1 para iniciar o jogo)                  #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n##########################################################");
    printf("\n ###");
    printf("\n ###");
    printf("\n ###");
    printf("\n#####");
    printf("\n ###");
    printf("\n  #\n");
    scanf("%d",&opcao);
    getchar();
    return opcao;
}

char* recebe_palavra(){
    static char palavra[100];
    printf("\n##########################################################");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#       #### #### ####  ##  ###  #### ####      ##       #");
    printf("\n#        ##  #  # #    #  # #  # #  # #  #     ###       #");
    printf("\n#        ##  #  # # ## #### #  # #  # ####      ##       #");
    printf("\n#      # ##  #  # #  # #  # #  # #  # # #       ##       #");
    printf("\n#      ####  #### #### #  # ###  #### #  #     ####      #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#        Voc� deve escolher a palavra a ser              #");
    printf("\n#        adivinhada!                                     #");
    printf("\n#                                                        #");
    printf("\n#        Por favor, utilize apenas letras min�sculas     #");
    printf("\n#        sem acentua��o.                                 #");
    printf("\n#                                                        #");
    printf("\n#        Voc� pode utilizar palavras compostas!          #");
    printf("\n#        Exemplo: Guarda-chuva                           #");
    printf("\n#                                                        #");
    printf("\n#        Digite abaixo a palavra escolhida!              #");
    printf("\n#                                                        #");
    printf("\n#        Boa Sorte!!                                     #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n##########################################################");
    printf("\n ###");
    printf("\n ###");
    printf("\n ###");
    printf("\n#####");
    printf("\n ###");
    printf("\n  #\n");
    fgets(palavra, 100, stdin);
    return palavra;
}

int inicia_jogo(){
    int inicio;
    printf("\n##########################################################");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#       #### #### ####  ##  ###  #### ####     ####      #");
    printf("\n#        ##  #  # #    #  # #  # #  # #  #       ##      #");
    printf("\n#        ##  #  # # ## #### #  # #  # ####     ####      #");
    printf("\n#      # ##  #  # #  # #  # #  # #  # # #      ##        #");
    printf("\n#      ####  #### #### #  # ###  #### #  #     ####      #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#        Voc� deve adivinhar a palavra escolhida!        #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#        Voc� ter� 6 tentativas para acertar,            #");
    printf("\n#                                                        #");
    printf("\n#        ou...                                           #");
    printf("\n#                                                        #");
    printf("\n#        Voc� � enforcado!                               #");
    printf("\n#                                                        #");
    printf("\n#        Boa Sorte!!                                     #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#        Digite 1 para come�ar a adivinhar!              #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n##########################################################");
    printf("\n ###");
    printf("\n ###");
    printf("\n ###");
    printf("\n#####");
    printf("\n ###");
    printf("\n  #\n");
    scanf("%d", &inicio);
    return inicio;
}

void desenha_forca(int contador, int inicio){
    if(inicio == 0){
            switch(contador){
                case 0:
                    printf("Come�ou o jogo! Voc� tem 6 tentativas!\n");
                    printf("_____________   \n|.|         |   \n|.|        _|_\n|.|          \n|.|        \ \n|.|         \n|.| \n|.| \n|.| \n\n");
                    break;

                case 1:
                    printf("Voc� tem 5 tentativas!\n");
                    printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|         \n|.|       \n|.| \n|.| \n|.| \n\n");
                    break;

                case 2:
                    printf("Voc� tem 4 tentativas!\n");
                    printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|         |    \n|.|         \n|.| \n|.| \n|.| \n\n");
                    break;

                case 3:
                    printf("Voc� tem 3 tentativas!\n");
                    printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|        /|    \n|.|         \n|.| \n|.| \n|.| \n\n");
                    break;

                case 4:
                    printf("Voc� tem 2 tentativas!\n");
                    printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|        /|\\    \n|.|         \n|.| \n|.| \n|.| \n\n");
                    break;

                case 5:
                    printf("Voc� tem apenas 1 tentativa!\n");
                    printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|        /|\\    \n|.|        /  \n|.|  \n|.|  \n|.| \n\n");
                    break;

                case 6:
                    printf("FORCA!!!\n");
                    printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|        /|\\    \n|.|        / \\ \n|.|  \n|.|  \n|.| \n\n");
                    break;
            }

    } else {
    puts("_____________ \n|.|         |   \n|.|        _|_\n|.|         O    \t JOGO DA FORCA \n|.|        /|\\           Briena Bertoni \n|.|        / \\           Heloisa Moraes \n|.|                      Jaqueline Neder \n|.|                      Vannilia Santos Lima \n|.|                      Yago Elias Sigognini \n|.| \n|.| \n");
    }

}

int verifica_tamanho(char* palavra){
    int tamanho = 0;
    for (int i = 0; palavra[i] != '\n' && palavra[i] != '\0'; i++){
        tamanho++;
    }
    return tamanho;
}

void verifica_tentativa(){

}


