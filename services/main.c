
#include <stdio.h>

int main(void) {

    while (1) {
        int total = 0;
        int total_mai = 0;
        int total_min = 0;
        int caracter_especial = 0;
        int numbers = 0;

        char senha[100];

        fprintf(stderr, "Digite a sua senha:\n");
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

        fprintf(stderr, "Total de caracteres: %d\n", total);
        fprintf(stderr, "Total de maiusculas: %d\n", total_mai);
        fprintf(stderr, "Total de minusculas: %d\n", total_min);
        fprintf(stderr, "Total de numeros: %d\n", numbers);
        fprintf(stderr, "Total de caracteres especiais: %d\n", caracter_especial);

        int opcao;

        fprintf(stderr, "\nO que voce quer fazer agora?\n");
        fprintf(stderr, "1 - Testar nova senha\n");
        fprintf(stderr, "2 - Fazer analise de seguranca na senha\n");
        fprintf(stderr, "3 - Sair\n");

        if (scanf("%d", &opcao) != 1) {
            fprintf(stderr, "Entrada invalida!\n");
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
            fprintf(stderr, "Saindo...\n");
            return 0;
        }
        else {
            fprintf(stderr, "Opcao invalida!\n");
            return 1;
        }
    }

    return 0;
}
