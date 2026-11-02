
#include <stdio.h>

int main(void) {

    while (1) {
        int total = 0;
        int total_mai = 0;
        int total_min = 0;
        int caracter_especial = 0;
        int numbers = 0;

        char senha[100];

        fprintf(stderr, "\n");
        fprintf(stderr, "================================\n");
        fprintf(stderr, "       VERIFICACAO DE SENHA\n");
        fprintf(stderr, "================================\n\n");

        fprintf(stderr, "Digite sua senha: ");
        scanf("%99s", senha);

        for (int i = 0; senha[i] != '\0'; i++) {

            total++;

            if (senha[i] >= 'A' && senha[i] <= 'Z') {
                total_mai++;
            }
            else if (senha[i] >= 'a' && senha[i] <= 'z') {
                total_min++;
            }
            else if (senha[i] >= '0' && senha[i] <= '9') {
                numbers++;
            }
            else {
                caracter_especial++;
            }
        }

        fprintf(stderr, "\n");
        fprintf(stderr, "--------------------------------\n");
        fprintf(stderr, "       RESULTADO DA ANALISE\n");
        fprintf(stderr, "--------------------------------\n\n");

        fprintf(stderr, " Total de caracteres: %d\n", total);
        fprintf(stderr, " Letras maiusculas:   %d\n", total_mai);
        fprintf(stderr, " Letras minusculas:   %d\n", total_min);
        fprintf(stderr, " Numeros:             %d\n", numbers);
        fprintf(stderr, " Caracteres especiais:%d\n", caracter_especial);

        int opcao;

        fprintf(stderr, "\n================================\n");
        fprintf(stderr, "          MENU DE OPCOES\n");
        fprintf(stderr, "================================\n\n");

        fprintf(stderr, " 1 - Testar nova senha\n");
        fprintf(stderr, " 2 - Fazer analise de seguranca\n");
        fprintf(stderr, " 3 - Sair\n");

        fprintf(stderr, "\nEscolha uma opcao: ");

        if (scanf("%d", &opcao) != 1) {
            fprintf(stderr, "\nEntrada invalida!\n");
            return 1;
        }

        if (opcao == 1) {
            continue;
        }
        else if (opcao == 2) {

            // Envia somente os contadores para o Python
            printf("%d,%d,%d,%d,%d\n",
                   total,
                   total_mai,
                   total_min,
                   numbers,
                   caracter_especial);

            return 2;
        }
        else if (opcao == 3) {
            fprintf(stderr, "\nEncerrando verificacao...\n");
            return 0;
        }
        else {
            fprintf(stderr, "\nOpcao invalida!\n");
            return 1;
        }
    }

    return 0;
}
