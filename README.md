<div align="center">

🔐 CipherCheck

Analisador de segurança de senhas em C e Python

Uma aplicação de terminal desenvolvida para analisar a composição de senhas, identificar seus critérios de complexidade e classificá-las em níveis de segurança.

<br>







</div>

📑 Índice

📌 Sobre o projeto

⚙️ Funcionalidades

🛠️ Tecnologias utilizadas

🏗️ Estrutura do projeto

🚀 Instalação e execução

🔍 Como funciona

📊 Critérios de classificação

🗺️ Roadmap

📌 Sobre o projeto

O CipherCheck é um projeto desenvolvido em C e Python com o objetivo de praticar programação, integração entre linguagens e conceitos iniciais de segurança cibernética.

A aplicação utiliza uma arquitetura híbrida:

C: responsável pela leitura da senha, identificação dos caracteres e geração das estatísticas.

Python: responsável pelo processamento dos dados recebidos e classificação do nível de segurança.

A comunicação entre as linguagens acontece por meio do subprocess, utilizando a saída padrão do C para transmitir os dados ao Python.

Um dos princípios do projeto é não enviar a senha original para o analisador Python. Somente os contadores de caracteres são transmitidos.

⚙️ Funcionalidades

Menu principal interativo.

Verificação da composição de senhas.

Contagem de caracteres totais.

Identificação de letras maiúsculas e minúsculas.

Identificação de números.

Identificação de caracteres especiais.

Integração entre C e Python.

Classificação em três níveis de segurança.

Opção para testar novas senhas.

Interface de terminal organizada.

🛠️ Tecnologias utilizadas

Tecnologia

Aplicação

C

Processamento e análise dos caracteres

Python 3

Classificação de segurança

Subprocess

Comunicação entre C e Python

GCC

Compilação do código C

Linux

Ambiente de desenvolvimento

Bibliotecas utilizadas

C

stdio.h

Python

sys

subprocess

O projeto utiliza somente bibliotecas padrão, sem dependências externas.

🏗️ Estrutura do projeto

CipherCheck/
│
├── docs/
│
├── services/
│   ├── analise.py
│   └── main.c
│
├── main.py
├── ciphercheck
└── README.md

Arquivo

Responsabilidade

main.py

Menu principal e inicialização do programa C

services/main.c

Leitura e contagem dos caracteres da senha

services/analise.py

Classificação do nível de segurança

ciphercheck

Executável gerado pela compilação do código C

docs/

Diretório destinado à documentação técnica

🚀 Instalação e execução

1. Pré-requisitos

Certifique-se de possuir Python 3 e GCC instalados.

No Debian:

su -
apt update
apt install python3 gcc

2. Clonar o repositório

git clone https://github.com/Mutus142/CipherCheck.git

Entre no diretório:

cd CipherCheck

3. Compilar o código C

gcc services/main.c -o ciphercheck

4. Executar o projeto

python3 main.py

🔍 Como funciona

O CipherCheck utiliza uma comunicação entre dois processos para realizar a análise.

Fluxo de execução

          ┌──────────────────┐
          │     main.py      │
          │   Menu principal│
          └────────┬─────────┘
                   │
                   ▼
          ┌──────────────────┐
          │    main.c        │
          │  Leitura senha   │
          └────────┬─────────┘
                   │
                   ▼
          ┌──────────────────┐
          │ Processamento C  │
          │ Contagem de      │
          │ caracteres       │
          └────────┬─────────┘
                   │
                   ▼
          ┌──────────────────┐
          │  Dados numéricos │
          │  13,2,4,5,2      │
          └────────┬─────────┘
                   │
                   ▼
          ┌──────────────────┐
          │   analise.py     │
          │ Classificação    │
          └────────┬─────────┘
                   │
                   ▼
          ┌──────────────────┐
          │ Resultado final  │
          │ Segurança Alta   │
          └──────────────────┘

Exemplo de comunicação

O programa C calcula os seguintes dados:

Total: 13
Maiúsculas: 2
Minúsculas: 4
Números: 5
Especiais: 2

Ao selecionar a opção de análise, C transmite:

13,2,4,5,2

O Python recebe os valores por meio de sys.argv, converte os dados para inteiros e executa a classificação.

📊 Critérios de classificação

O CipherCheck utiliza critérios de complexidade definidos no próprio código.

Critério

Segurança Baixa

Segurança Média

Segurança Alta

Comprimento

Não atende aos critérios superiores

≥ 7

≥ 12

Maiúsculas

—

≥ 1

≥ 2

Minúsculas

—

≥ 1

≥ 2

Números

—

≥ 1

≥ 2

Especiais

—

≥ 1

≥ 2

A classificação é feita por prioridade: primeiro é verificada a segurança alta, depois a média e, caso nenhuma das condições seja atendida, a senha é classificada como baixa.

[!IMPORTANT]
Os critérios representam uma avaliação simplificada de complexidade. O CipherCheck é um projeto educacional e não substitui ferramentas profissionais de auditoria de senhas. A classificação não considera, por enquanto, senhas vazadas, padrões previsíveis ou ataques de força bruta.

🗺️ Roadmap

v1.0 — Estrutura inicial, processamento em C, classificação em Python e integração entre linguagens.

v1.1 — Aprimoramento dos critérios de segurança e validações de entrada.

v1.5 — Implementação de novos recursos de análise e melhorias na arquitetura.

v2.0 — Expansão do projeto com funcionalidades voltadas à segurança cibernética.

<div align="center">

🔐 CipherCheck

Desenvolvido para praticar programação, integração entre linguagens e conceitos de segurança cibernética.

C + Python | Linux

</div>
