#include <stdio.h>

int main(void) {

    int total = 0;
    int total_mai = 0;
    int total_min = 0;
    int caracter_especial = 0;
    int numbers = 0;

    char senha[100];

    printf("Digite a sua senha: \n");
    scanf("%99s", senha);

    for (int i = 0; senha[i] != 0; i++) {

        if (senha[i] >= 'A' && senha[i] <= 'Z') {
            total_mai++;
            total_mai +1;
        }

        else if (senha[i] >= 'a' && senha[i] <= 'z') {
            total_min++;
            total_min +1;
        }

        else if (senha[i] >= '0' && senha[i] <= '9') {
            numbers++;
            numbers +1
        }
    }

    return 0;
}