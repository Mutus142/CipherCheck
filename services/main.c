#include <stdio.h>

int main(void) {

while(1) {
    int total = 0;
    int total_mai = 0;
    int total_min = 0;
    int caracter_especial = 0;
    int numbers = 0;

    char senha[100];

    printf("Digite a sua senha: \n");
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

    printf("Total de caracter: %d\n", total);
    printf("Total Maisculas: %d\n", total_mai);
    printf("Total Minusculas: %d\n", total_min);
    printf("Total de numeros: %d\n", numbers);
    printf("Total de caracter especial: %d\n", caracter_especial);


    int opcao;

    printf("O que voce quer fazer agora?\n");
    printf("1 - Testar nova senha\n");
    printf("2 - Fazer analise de segurança na senha\n");
    printf("3 - Sair\n");

    scanf("%d", &opcao);

    if (opcao == 1) {
        continue;
    }

    else if (opcao == 2) {
        printf("%d,%d,%d,%d,%d\n",
            total,
            total_mai,
            total_min,
            numbers,
            caracter_especial);

        return 2;
    }

    else if (opcao == 3) {
        printf("Saindo...\n");
        return 0;
    }

    else {
        printf("Opção invalida!\n");
        break;
    }

    return 0;
}
}