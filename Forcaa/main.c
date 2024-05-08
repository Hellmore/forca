#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>

int menu_principal();
char* recebe_palavra();
int inicia_jogo();
void desenha_forca(int contador, int inicio);


int main()
{
    int inicio_do_jogo, contador_jogadas = 0;
    char* palavra[100];

    setlocale(LC_ALL, "Portuguese");
    inicio_do_jogo = menu_principal();
    if (inicio_do_jogo == 1) {
        system("cls");
        strcpy(palavra, recebe_palavra());
        system("cls");
        if (inicia_jogo() == 1) {
                system("cls");
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
    printf("\n#        adivinhada e o Jogador 2 tenta adivinhá-la!     #");
    printf("\n#                                                        #");
    printf("\n#        A forca oferece 6 tentativas, você consegue     #");
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
    printf("\n#        Você deve escolher a palavra a ser              #");
    printf("\n#        adivinhada!                                     #");
    printf("\n#                                                        #");
    printf("\n#        Por favor, utilize apenas letras minúsculas     #");
    printf("\n#        sem acentuação.                                 #");
    printf("\n#                                                        #");
    printf("\n#        Você pode utilizar palavras compostas!          #");
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
    printf("\n#        Você deve adivinhar a palavra escolhida!        #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#        Você terá 6 tentativas para acertar,            #");
    printf("\n#                                                        #");
    printf("\n#        ou...                                           #");
    printf("\n#                                                        #");
    printf("\n#        Você é enforcado!                               #");
    printf("\n#                                                        #");
    printf("\n#        Boa Sorte!!                                     #");
    printf("\n#                                                        #");
    printf("\n#                                                        #");
    printf("\n#        Digite 1 para começar a adivinhar!              #");
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


