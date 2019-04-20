#include "TAD.h"

bool Iguais(Pilha &P, Pilha &PAux, bool &Estrela, bool &gameOver, int &winner){
    int i, X = 0, XAux = 0, cont = 0;
    Pilha P1, P2;
    bool DeuCerto, DeuCertoAux, DeuCerto1, DeuCerto2;

    Cria(P1);
    Cria(P2);

    while(!Vazia(P)) {
        Desempilha(P, X, DeuCerto);
        Empilha(P1, X, DeuCerto1);
    }

    while(!Vazia(PAux)) {
        Desempilha(PAux, XAux, DeuCertoAux);
        Empilha(P2, XAux, DeuCerto2);
        cont++;
    }

    for(i = 0; i < cont; i++) {
        Desempilha(P1, X, DeuCerto1);
        Empilha(P, X, DeuCerto);
    }

    while(!Vazia(P2)) {
        Desempilha(P2, XAux, DeuCerto2);
        Empilha(PAux, XAux, DeuCertoAux);
    }

    if(DeuCerto && DeuCertoAux){
        if(X != XAux){
            if(Estrela){
                Estrela = !Estrela;
                Desempilha(PAux, XAux, DeuCerto);
                winner--;
                if(DeuCerto) {
                    while(!Vazia(P1)) {
                        Desempilha(P1, X, DeuCerto1);
                        Empilha(P, X, DeuCerto);
                    }
                    return true;
                }
            }
        }
        else {
            while(!Vazia(P1)) {
                Desempilha(P1, X, DeuCerto1);
                Empilha(P, X, DeuCerto);
            }
            return true;
        }
    }
    gameOver = true;
    return false;
}

void Destroi(Pilha &P){

    int X;
    bool DeuCerto;

    while(!Vazia(P))
        Desempilha(P, X, DeuCerto);
}

void IniciaRandom(Pilha &P){

    int N;
    bool DeuCerto;

    if(Vazia(P)){
        while(!Cheia(P)){
            N = rand()% 5; //confirmas quantidade de peças
            Empilha(P, N, DeuCerto);
        }
    }
}
