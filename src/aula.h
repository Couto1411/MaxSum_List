#ifndef AULA
#define AULA

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Bloco Bloco;
typedef struct Item{
    int value;
}Item;

struct Bloco{
    Item dado;
    Bloco *prox;
};

typedef struct Lista{
    Bloco* cabeca;
    Bloco* cauda;
}Lista;

//Bloco maxSumPos;

void FLVazia(Lista *l);
void preencheLista(Lista *l);
void maiorSoma(Lista *l);
void printLista(Lista *l);
void printCodon(Bloco *b,int cont);
#endif