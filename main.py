# MENU INICIAL CIPHER CHECK 1.0

import time

def menu():

    while True:

        print('''
        Bem vindo ao CipherCheck!

        1 - Verificar minha senha
        2 - Sair do programa

        ''')

        try:
            escolha = int(input("Escolha uma opção: "))

        except ValueError:
            print("Invalido! tente novamente.")
            continue

        if escolha == 1:
            print("Iniciando...")
            time.sleep(2)            
            # função para tocar o arquivo em C
        
        elif escolha == 2:
            print("Saindo...")
            break

        else:
            print("Opção invalida!")
