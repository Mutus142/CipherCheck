
import time
import subprocess

def iniciar_verificacao():

    resultado = subprocess.run(
        ["./ciphercheck"],
        stdout=subprocess.PIPE,
        text=True
    )

    print("Código de encerramento:", resultado.returncode)

    if resultado.returncode == 2:
        dados = resultado.stdout.strip()

        subprocess.run([
            "python3",
            "services/analise.py",
            dados
        ])

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
            print("\n> Inválido! Tente novamente.")
            continue

        if escolha == 1:
            print("\nIniciando...")
            iniciar_verificacao()

        elif escolha == 2:
            print("\n> Encerrando CipherCheck...")
            break

        else:
            print("\n> Opção inválida!")


if __name__ == "__main__":
    menu()