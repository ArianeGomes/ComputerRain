#pragma once
#include <iostream>
#include <stdlib.h>
#include "Pilha.h"

bool Iguais(Pilha &P, Pilha &PAux, bool &Estrela, bool &gameOver, int &winner);

void Destroi(Pilha &P);

void IniciaRandom(Pilha &P);
