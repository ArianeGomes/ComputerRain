#pragma once
#include <iostream>

// ********************************************STRUCT PILHA******************************************** //

typedef struct Pilha1{
    int Elementos[5];
    int Topo;
} Pilha;

bool Vazia(Pilha &P);

bool Cheia(Pilha &P);

void Cria(Pilha &P);

void Empilha(Pilha &P, int X, bool &DeuCerto);

void Desempilha(Pilha &P, int &X, bool &DeuCerto);
