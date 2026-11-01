# Projetos em C

Repositório dedicado aos meus estudos, exercícios e projetos desenvolvidos em **linguagem C**. O objetivo é registrar minha evolução prática em lógica de programação, algoritmos, estruturas de dados, manipulação de dados e organização de código.

## 📚 Conteúdos praticados

- Lógica de programação e algoritmos.
- Estruturas condicionais e laços de repetição.
- Funções, modularização e recursividade.
- Vetores e matrizes.
- Strings e manipulação de caracteres.
- Ponteiros e estruturas (`struct`).
- Entrada, validação e tratamento de dados.
- Geração de números aleatórios.
- Organização e reutilização de funções.

## 📁 Organização do repositório

| Diretório/arquivo | Descrição |
| --- | --- |
| `ListaMatrizes1/` | Exercícios de lógica e manipulação de matrizes. |
| `ListaMatrizes2/` | Exercícios complementares envolvendo matrizes. |
| `ListaStrings/` | Exercícios de manipulação e processamento de strings. |
| `TrabalhoBingo/` | Projeto de bingo executado no terminal, com cadastro de jogadores, geração de cartelas, sorteio e acompanhamento das partidas. |
| `utils.c` | Implementações de funções utilitárias para manipulação e validação de strings, entre outros exercícios com caracteres. |

## 🎲 Projeto em destaque: Bingo

O projeto em `TrabalhoBingo/` simula uma partida de bingo no terminal. Entre os recursos implementados estão:

- Cadastro de **2 a 5 jogadores**, com validação das entradas.
- Geração de cartelas com 15 números distintos entre 1 e 60.
- Sorteio de números sem repetição.
- Marcação automática dos números sorteados nas cartelas.
- Identificação dos vencedores e registro da rodada em que cada um completou a cartela.
- Exibição do andamento da partida e ranking final.
- Avanço rodada a rodada ou modo de avanço automático até surgir um novo vencedor.

Consulte o README dentro de `TrabalhoBingo/` para instruções específicas de compilação, execução e controles.

## 🛠️ Compilação e execução

É necessário ter um compilador C instalado, como o **GCC**.

Para compilar um exercício individual:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic arquivo.c -o programa
```

Para executar no Linux/macOS:

```bash
./programa
```

No Windows, execute o arquivo gerado:

```powershell
.\programa.exe
```

Se um exercício utilizar funções implementadas em `utils.c`, compile os arquivos correspondentes juntos e disponibilize os protótipos dessas funções:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic exercicio.c utils.c -o programa
```

Os comandos podem variar conforme os arquivos e as dependências de cada exercício. Para o Bingo, siga as instruções específicas de seu diretório.

## 🚧 Status

**Em desenvolvimento contínuo.**

Este repositório reúne atividades acadêmicas e projetos de estudo. Cada exercício pode ter um foco didático específico; portanto, nem todos seguem necessariamente uma arquitetura de aplicação de produção.

## 🎯 Objetivo

Consolidar os fundamentos da programação em C por meio de prática contínua, resolução de problemas e desenvolvimento de projetos que demonstrem a aplicação dos conceitos estudados.
