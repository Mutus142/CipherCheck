
import time
import subprocess

def iniciar_verificacao():
    subprocess.run("./ciphercheck")

def menu():

    while True:

        print("""
================================
       BEM-VINDO AO CIPHERCHECK
================================

1 - Verificar minha senha
2 - Sair do programa

================================
""")

        try:
            escolha = int(input("Escolha uma opção: ").strip())

        except ValueError:
            print("\nInválido! Tente novamente.")
            continue

        if escolha == 1:
            time.sleep(2)
            print("\nIniciando...")
            iniciar_verificacao()

        elif escolha == 2:
            print("\nEncerrando CipherCheck...")
            break

        else:
            print("\nOpção inválida!")


if __name__ == "__main__":
    menu()