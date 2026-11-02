 <div align="center">

# 🔐 CipherCheck

### Analisador de segurança de senhas com C e Python

![C](https://img.shields.io/badge/C-GCC-00599C?style=for-the-badge&logo=c&logoColor=white)
![Python](https://img.shields.io/badge/Python-3-3776AB?style=for-the-badge&logo=python&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-Debian-FCC624?style=for-the-badge&logo=debian&logoColor=black)
![Version](https://img.shields.io/badge/Version-1.0-8A2BE2?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Funcional-22C55E?style=for-the-badge)

**Analise a composição de senhas, identifique seus critérios de complexidade e obtenha uma classificação de segurança diretamente pelo terminal.**

[Sobre](#-sobre-o-projeto) • [Funcionalidades](#-funcionalidades) • [Instalação](#-instalação-e-execução) • [Arquitetura](#-como-funciona) • [Versões](#-histórico-de-versões)

</div>

---

## 📌 Sobre o projeto

O **CipherCheck** é um analisador de senhas executado pelo terminal, desenvolvido utilizando **C e Python**.

O projeto foi criado para praticar lógica de programação, manipulação de caracteres, integração entre linguagens e conceitos iniciais de segurança cibernética.

A aplicação utiliza uma arquitetura híbrida: o **C** realiza a leitura da senha e a contagem dos caracteres, enquanto o **Python** recebe os dados processados e determina o nível de segurança.

A comunicação entre as linguagens é realizada por meio do módulo `subprocess`, utilizando a saída padrão (`stdout`) para transmitir somente os dados numéricos da análise.

> [!NOTE]
> Projeto educacional em evolução. A versão 1.0 apresenta a estrutura inicial de análise e integração entre C e Python.

## 🚀 Funcionalidades

| Recurso | Descrição | Principais recursos técnicos |
|:--|:--|:--|
| 🔐 **Verificação de senha** | Recebe uma senha informada pelo usuário | `scanf()` |
| 🔠 **Letras maiúsculas** | Identifica e contabiliza letras de A até Z | Condições `if` |
| 🔡 **Letras minúsculas** | Identifica e contabiliza letras de a até z | Condições `if` |
| 🔢 **Números** | Identifica e contabiliza caracteres numéricos | Comparações ASCII |
| 🔣 **Caracteres especiais** | Identifica caracteres que não pertencem às demais categorias | Condições `else` |
| 📊 **Classificação** | Determina o nível de segurança da senha | `if`, `elif`, `else` |
| 🔄 **Nova verificação** | Permite testar outras senhas sem reiniciar a aplicação | `while` |
| 🔗 **Integração C + Python** | Transmite os contadores para o analisador Python | `subprocess` |

### ⚙️ Recursos adicionais

- Classificação em três níveis: **Baixa**, **Média** e **Alta**.
- Contagem individual dos cinco critérios analisados.
- Separação entre processamento e classificação.
- Comunicação entre processos por meio de `stdout`.
- Mensagens e menus padronizados no terminal.
- Não utiliza banco de dados.
- Não necessita de bibliotecas externas.

## 🛠️ Tecnologias utilizadas

| Tecnologia | Utilização |
|:--|:--|
| **C** | Leitura da senha e processamento dos caracteres |
| **Python 3** | Classificação e gerenciamento da aplicação |
| **GCC** | Compilação do código C |
| **subprocess** | Execução e comunicação entre processos |
| **sys** | Recebimento dos argumentos enviados ao Python |
| **Linux / Debian** | Ambiente de desenvolvimento |
| **Git / GitHub** | Versionamento e documentação |

## 📂 Estrutura do projeto

```text
CipherCheck/
├── main.py                 # Entrada principal e menu da aplicação
├── ciphercheck             # Executável compilado do código C
├── README.md
│
├── docs/
│
└── services/
    ├── main.c              # Leitura e processamento da senha
    └── analise.py           # Classificação do nível de segurança
```

## 🖥️ Prévia do terminal

### Menu principal

```text
================================
       BEM-VINDO AO CIPHERCHECK
================================

1 - Verificar minha senha
2 - Sair do programa

================================

Escolha uma opção:
```

### Verificação de senha

```text
================================
       VERIFICACAO DE SENHA
================================

Digite sua senha: ********

--------------------------------
       RESULTADO DA ANALISE
--------------------------------

 Total de caracteres: 13
 Letras maiusculas:   2
 Letras minusculas:   4
 Numeros:             5
 Caracteres especiais: 2

================================
          MENU DE OPCOES
================================

 1 - Testar nova senha
 2 - Fazer analise de seguranca
 3 - Sair
```

### Resultado da análise

```text
================================
       ANALISE DE SEGURANCA
================================

 Comprimento da senha: 13
 Letras maiusculas:    2
 Letras minusculas:    4
 Numeros:              5
 Caracteres especiais: 2

--------------------------------
       RESULTADO FINAL
--------------------------------

       SEGURANCA ALTA

================================
```

*As telas são ilustrativas; os resultados dependem da senha informada.*

## 📊 Critérios de classificação

O CipherCheck utiliza critérios de complexidade definidos no módulo `services/analise.py`.

| Critério | Segurança Média | Segurança Alta |
|:--|:--:|:--:|
| Comprimento | ≥ 7 | ≥ 12 |
| Letras maiúsculas | ≥ 1 | ≥ 2 |
| Letras minúsculas | ≥ 1 | ≥ 2 |
| Números | ≥ 1 | ≥ 2 |
| Caracteres especiais | ≥ 1 | ≥ 2 |

A classificação segue uma ordem de prioridade:

1. **Segurança Alta:** atende a todos os critérios definidos para o nível alto.
2. **Segurança Média:** não atende ao nível alto, mas atende a todos os critérios do nível médio.
3. **Segurança Baixa:** não atende aos critérios necessários para os níveis superiores.

> [!IMPORTANT]
> A classificação representa uma avaliação simplificada de complexidade. O CipherCheck não verifica vazamentos de senhas, padrões previsíveis, entropia ou resistência real contra ataques. Portanto, não deve ser utilizado como ferramenta profissional de auditoria de senhas.

## 🔍 Como funciona

O projeto utiliza dois processos independentes que trabalham em conjunto.

### Fluxo de execução

```text
       ┌─────────────────────┐
       │       main.py       │
       │    Menu principal   │
       └──────────┬──────────┘
                  │
                  ▼
       ┌─────────────────────┐
       │       main.c        │
       │    Recebe a senha   │
       └──────────┬──────────┘
                  │
                  ▼
       ┌─────────────────────┐
       │  Contagem de        │
       │  caracteres         │
       └──────────┬──────────┘
                  │
                  ▼
       ┌─────────────────────┐
       │  Transmissão dos    │
       │  contadores (stdout)│
       └──────────┬──────────┘
                  │
                  ▼
       ┌─────────────────────┐
       │     analise.py      │
       │  Recebe os valores  │
       └──────────┬──────────┘
                  │
                  ▼
       ┌─────────────────────┐
       │  Classificação de   │
       │  segurança          │
       └──────────┬──────────┘
                  │
                  ▼
       ┌─────────────────────┐
       │  Resultado final    │
       └─────────────────────┘
```

### Comunicação entre as linguagens

Após realizar a contagem dos caracteres, o programa C transmite somente os valores numéricos, separados por vírgulas.

Exemplo:

```text
13,2,4,5,2
```

O Python recebe os dados por meio de `sys.argv`, utiliza `split()` para separar os valores e `map()` para convertê-los em inteiros.

Dessa forma, o módulo de análise não precisa receber a senha original para executar a classificação.

## 📥 Instalação e execução

### 1. Pré-requisitos

- Linux.
- Python 3.
- GCC.
- Git.

### 2. Clonar o repositório

```bash
git clone https://github.com/Mutus142/CipherCheck.git
cd CipherCheck
```

### 3. Compilar o código C

Na raiz do projeto, execute:

```bash
gcc services/main.c -o ciphercheck
```

Esse comando gera o executável `ciphercheck`.

### 4. Executar o CipherCheck

```bash
python3 main.py
```

A aplicação iniciará pelo menu principal e permitirá realizar as verificações de senha.

## 📝 Histórico de versões

### ✅ v1.0 — Estrutura inicial

- Desenvolvimento do menu principal em Python.
- Implementação da leitura e contagem de caracteres em C.
- Identificação de maiúsculas, minúsculas, números e caracteres especiais.
- Desenvolvimento do módulo de classificação em Python.
- Integração entre C e Python utilizando `subprocess`.
- Transmissão exclusiva dos contadores para o analisador.
- Classificação em três níveis de segurança.
- Padronização das mensagens e menus no terminal.

## ⚠️ Limitações conhecidas

- **Análise simplificada:** a classificação considera apenas comprimento e composição dos caracteres.
- **Padrões previsíveis:** não identifica sequências, repetições ou combinações comuns.
- **Senhas vazadas:** não consulta
