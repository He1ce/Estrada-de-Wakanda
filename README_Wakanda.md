
# 🛣️ Estrada de Wakanda

Projeto desenvolvido como parte da disciplina de **Estruturas de Dados (2025/1)**, com foco na implementação de TADs, leitura de arquivos e cálculos com base em estruturas organizadas. O código em C simula o controle da vizinhança de cidades dispostas ao longo de uma estrada fictícia em Wakanda.

---

## 🎯 Objetivo

O objetivo principal do projeto é ler os dados de uma estrada com cidades posicionadas em diferentes pontos e determinar:

- A menor vizinhança de estrada entre as cidades.
- Qual cidade possui essa menor vizinhança.
- Organizar os dados lidos em estruturas adequadas.

Essas operações são baseadas no conceito de "vizinhança da estrada", que representa a área da estrada mais próxima do centro de determinada cidade do que de qualquer outra.

---

## ✅ Funcionalidades Implementadas

- Leitura de dados de um arquivo texto contendo informações da estrada e das cidades.
- Validação dos dados de entrada conforme as restrições do problema.
- Organização das cidades em ordem crescente de posição ao longo da estrada.
- Cálculo da menor vizinhança entre todas as cidades.
- Identificação da cidade com a menor vizinhança.

---

## 🗃️ Estrutura dos Dados

Foram utilizados dois Tipos Abstratos de Dados (TADs):

```c
typedef struct {
    char Nome[256]; // Nome da cidade
    int Posicao;    // Posição da cidade ao longo da estrada
} Cidade;

typedef struct {
    int N;          // Número de cidades
    int T;          // Comprimento total da estrada
    Cidade *C;      // Vetor dinâmico com as cidades
} Estrada;
```

---

## 🧪 Tecnologias e Técnicas Utilizadas

- Linguagem C
- Alocação dinâmica de memória
- Vetores de structs
- Manipulação de arquivos `.txt`
- Implementação de ordenação (Bubble Sort)
- Verificação de restrições
- Organização modular:
  - `cidades.c` (implementações)
  - `cidades.h` (interface fornecida pelo professor)

---

## ⚙️ Como Executar

1. Compile o código com um `main.c` que use as funções de `cidades.c`. Exemplo de compilação:

```bash
gcc main.c cidades.c -o estrada
```

2. Certifique-se de que o arquivo de entrada (ex: `teste01.txt`) esteja na mesma pasta.

3. Execute o programa:

```bash
./estrada
```

---

## 📥 Exemplo de Entrada

Exemplo de arquivo `teste01.txt`:

```
10
2
8 Birnin Zana
5 Birnin S'Yan
```

Saída esperada:

- Menor vizinhança: `3.5`
- Cidade com menor vizinhança: `Birnin Zana`

---

## 👨‍💻 Autoria

Desenvolvido por:

- Eduardo Gonçalves – [eduardouc388@gmail.com](mailto:eduardouc388@gmail.com) – [@eduuardo1st](https://github.com/eduuardo1st)  
- Arthur Vieira – [arthurVsousa@outlook.com](mailto:arthurVsousa@outlook.com) – [@He1ce](https://github.com/He1ce)  

Curso de Engenharia de Software - 2025, Universidade Católica de Brasília.

---

## 📄 Licença

Este projeto está licenciado sob a **MIT License**. Consulte o arquivo `LICENSE` para mais informações.
