# Conversor de Expressões Infixadas para Pós-fixadas

Este projeto é um programa em C++ que traduz expressões matemáticas da forma **infixada** (notação comum) para a **forma pós-fixada** (notação polonesa reversa). O programa suporta operações básicas, incluindo adição, subtração, multiplicação, divisão e uso de parênteses.

## Funcionalidades
- **Adição (`+`)**
- **Subtração (`-`)**
- **Multiplicação (`*`)**
- **Divisão (`/`)**
- **Parênteses (`(` e `)`)** para controle de precedência

## Pré-requisitos
- Compilador C++ (recomendado: `g++`)

## Como Compilar
Abra um terminal e navegue até o diretório onde o arquivo `postfix.cpp` está localizado. Em seguida, execute o seguinte comando:

```bash
    g++ postfix.cpp -o postfix
```

## Como Executar
Após compilar o programa, você pode executá-lo com o comando:

```bash
    ./postfix
```

## Exemplos de Uso
Aqui estão alguns exemplos de como o programa funciona:

```bash
    entrada
    3+5*2
    saida
    352*+

    entrada
    (1+2)*3
    saida
    12+3*

    entrada
    7*(2+3)/5
    saida
    723+*5/
```

## Tratamento de Erros
O programa lança um erro caso seja inserida uma expressão inválida. Por exemplo:

- **Caracteres não numéricos ou não suportados (`a`, `!`, `etc`.)**
- **Parênteses não balanceados**
- **Uso incorreto de operadores**

A mensagem de erro será exibida da seguinte forma:

```bash
    syntax error
```
