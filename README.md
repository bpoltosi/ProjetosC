# Projetos em C

Repositório de exercícios acadêmicos e projetos práticos em **C**, cobrindo lógica de programação, algoritmos, estruturas de dados básicas, manipulação de arquivos e organização de código.

## Conteúdos

- Condicionais, laços, funções e recursividade.
- Vetores, matrizes e strings.
- Ponteiros e alocação/uso de memória.
- Estruturas (`struct`) e organização de registros.
- Arquivos, leitura e escrita.
- Validação de entrada e tratamento de casos-limite.
- Geração de números aleatórios.

## Organização

| Diretório | Conteúdo |
|---|---|
| `ExercicioArquivos/` | Exercícios de arquivos e dados auxiliares |
| `ExercicioFuncoes/` | Exercícios de modularização e funções |
| `ExercicioPonteiros/`, `ListaPonteiros/` | Estudos de ponteiros |
| `ExerciciosStrings/`, `ListaStrings/` | Manipulação de strings |
| `ExerciciosStruct/`, `ListaStruct/` | Estruturas e registros |
| `ListaMatrizes1/`, `ListaMatrizes2/` | Exercícios com matrizes |
| `ListaPreparatoriaProva/`, `Prova/` | Atividades avaliativas e preparação |
| `TrabalhoBingo/` | Projeto de bingo em terminal |
| `utils.c` | Funções utilitárias compartilhadas |

## Projeto em destaque: TrabalhoBingo

Simulador de bingo em terminal com cadastro de jogadores, cartelas, sorteio e acompanhamento da partida. A documentação específica, os requisitos e as instruções de compilação estão em [TrabalhoBingo/README.md](TrabalhoBingo/README.md).

## Compilação de exercícios

Com GCC e C11:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic arquivo.c -o programa
```

Quando um exercício utilizar funções de `utils.c`, compile os arquivos necessários em conjunto:

```bash
gcc -std=c11 -Wall -Wextra -Wpedantic exercicio.c utils.c -o programa
```

Os comandos podem variar conforme os arquivos e os protótipos utilizados.

## Status

Repositório de estudos em evolução. Os exercícios têm objetivos didáticos; nem todos constituem programas completos ou foram submetidos a uma suíte de testes automatizados.