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

    avaliacao = 'Nenhuma'

    if total <= 6 or total_mai == 0 or total_min == 0 or (numbers >= 0 and numbers >= 2) or caracter_especial == 0:
        avaliacao = "Segurança Baixa"

    elif total >= 7 and total_min >= 1 or total_mai >= 1 and caracter_especial >= 1:
        avaliacao = "Segurança Média"

    elif total >= 12 and total_mai >= 2 and total_min >= 2 and caracter_especial >= 2 and numbers >= 2:
        avaliacao = "Segurança Alta"

    else:
        avaliacao = "N/A"

    print("Resultado de segurança:", avaliacao)

avaliacao_senha()