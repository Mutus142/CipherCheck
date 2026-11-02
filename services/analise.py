import sys

dados = sys.argv[1]
dados = dados.split(",")
dados = list(map(int, dados))

total = dados[0]
total_mai = dados[1]
total_min = dados[2]
numbers = dados[3]
caracter_especial = dados[4]


def avaliacao_senha():

    if (
        total >= 12
        and total_mai >= 2
        and total_min >= 2
        and caracter_especial >= 2
        and numbers >= 2
    ):
        avaliacao = "Segurança Alta"

    elif (
        total >= 7
        and total_mai >= 1
        and total_min >= 1
        and caracter_especial >= 1
        and numbers >= 1
    ):
        avaliacao = "Segurança Média"

    else:
        avaliacao = "Segurança Baixa"

    print("Resultado de segurança:", avaliacao)

avaliacao_senha()