import sys

dados = sys.argv[1]
dados = dados.split(",")
dados = list(map(int, dados))

total = dados[0]
total_mai = dados[1]
total_min = dados[2]
numbers = dados[3]
caracter_especial = dados[4]