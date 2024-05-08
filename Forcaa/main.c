#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale.h>
#include <string.h>

int menu_principal();
char* recebe_palavra(char *palavra);
int inicia_jogo();
void desenha_forca(int contador, int inicio);
int verifica_tamanho(char* palavra);
char* cria_string_vazia(char* string_vazia, int tamanho);
void verifica_tentativa(char* palavra, char* palavra_vazia, char* erros);


int main()
{
    int inicio_do_jogo, contador_jogadas = 0, tamanho_palavra;
    char palavra[100], palavra_vazia[100], erros[6] = {' '};

    setlocale(LC_ALL, "Portuguese");
    inicio_do_jogo = menu_principal();
    if (inicio_do_jogo == 1) {
        system("cls");
        recebe_palavra(palavra);
        system("cls");
        if (inicia_jogo() == 1) {
            system("cls");
            tamanho_palavra = verifica_tamanho(palavra);
            strcpy(palavra_vazia, cria_string_vazia(palavra_vazia, tamanho_palavra));
            desenha_forca(contador_jogadas, 0);
            verifica_tentativa(palavra, palavra_vazia, erros);


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

char* recebe_palavra(char *palavra){
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
                    printf("Começou o jogo! Você tem 6 tentativas!\n");
                    printf("_____________   \n|.|         |   \n|.|        _|_\n|.|          \n|.|        \ \n|.|         \n|.| \n|.| \n|.| \n\n");
                    break;

                case 1:
                    printf("Você tem 5 tentativas!\n");
                    printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|         \n|.|       \n|.| \n|.| \n|.| \n\n");
                    break;

                case 2:
                    printf("Você tem 4 tentativas!\n");
                    printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|         |    \n|.|         \n|.| \n|.| \n|.| \n\n");
                    break;

                case 3:
                    printf("Você tem 3 tentativas!\n");
                    printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|        /|    \n|.|         \n|.| \n|.| \n|.| \n\n");
                    break;

                case 4:
                    printf("Você tem 2 tentativas!\n");
                    printf("_____________   \n|.|         |   \n|.|        _|_\n|.|         O    \n|.|        /|\\    \n|.|         \n|.| \n|.| \n|.| \n\n");
                    break;

                case 5:
                    printf("Você tem apenas 1 tentativa!\n");
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

char* cria_string_vazia(char* string_vazia, int tamanho){
    for (int i = 0; i < tamanho; i++){
        string_vazia[i] = '_';
    }
    string_vazia[tamanho] = '\0';
    return string_vazia;
}

void verifica_tentativa(char* palavra, char* palavra_vazia, char* erros){
    char chute;
    int acertos = 0;
    int erros_cometidos = 0;
    printf("Digite a letra que deseja chutar:\n");
    getchar();
    scanf("%c", &chute);
    getchar();
    for (int i = 0; palavra[i] != '\n' && palavra[i] != '\0'; i++){
        if (chute == palavra[i]){
            palavra_vazia[i] = chute;
            acertos++;
        }
    }
    if (acertos == 0) {
        for (int j = 0; erros != ' '; j++){
            erros_cometidos++;
        }
        if (erros_cometidos < 6){
            erros[erros_cometidos] = chute;
        }
    }

}


