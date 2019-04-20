#include "Pilha.h"

// ********************************************STRUCT PILHA******************************************** //

bool Vazia(Pilha &P){
    if(P.Topo == -1)
        return true;
    return false;
}

bool Cheia(Pilha &P){
    if(P.Topo == 4)
        return true;
    return false;
}

void Cria(Pilha &P){
    P.Topo = -1;
}

void Empilha(Pilha &P, int X, bool &DeuCerto){
    if(Cheia(P))
        DeuCerto = false;
    else{
        P.Topo++;
        P.Elementos[P.Topo] = X;
        DeuCerto = true;
    }
}

void Desempilha(Pilha &P, int &X, bool &DeuCerto){
    if(Vazia(P))
        DeuCerto = false;
    else{
        X = P.Elementos[P.Topo];
        P.Topo--;
        DeuCerto = true;
    }
}
