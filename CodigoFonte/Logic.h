#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
//SFML
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Pilha.h"
#include "TAD.h"

#define velMovimento 4
#define larguraTela 1250
#define alturaTela 660
#define alturaPersonagem 350
#define larguraPersonagem 100
#define alturaPeca 48
#define larguraPeca 48

using namespace std;

// ********************************************CLASSE RAIN******************************************** //

class Logic{
    public:
        Logic();

        void carregaImagens();

        void carregaMusicas();

        void eventos();

        void cairPeca();

        void moverPersonagem();

        void colide();

        void DesenhaPilhaFixa();

        void DesenhaPilhaConstruindo();

        void DesenhaEstrela();

        void MouseTracker();

        void Reseta();

        void run();

    private:
        sf::RenderWindow Window;
        sf::Event event;
        sf::Texture FTexture, BTexture, PTexture[6], textura[5], GTexture, WTexture, CantoTexture;
        sf::Sprite FSprite, BSprite, PSprite[6], DesenhoImagem[6], menu[4], instrucoes, GSprite, WSprite, CantoSprite;
        sf::Clock clock; // Controle da continuidade ao personagem andar
        sf::Clock clock3; //Controle da animaçãozinha da personagem
        sf::Vector2f velocidade; // Cria plano (x, y) para controlar velocidade das peças
        sf::Vector2i comecoGirl;
        sf::SoundBuffer VBuffer, GOBuffer, PEBuffer, PCBuffer, EBuffer;
        sf::Sound VSound, GOSound, PESound, PCSound, ESound;
        sf::Music MusicJogo;

        Pilha PAux, P;

        int indice, teste, teste2, teste3, posX, posY, winner, TipoDeMenu, MenuEscolhido;

        float frameCounter, switchFrame, frameSpeed; // Controle da continuidade ao personagem andar
        float frameCounter3, switchFrame3, frameSpeed3; //Controla animaçãozinha da personagem
        float posicaoBoneco1, posicaoBoneco2;
        float posicaoPecaX1, posicaoPecaX2, posicaoPecaY; // Vetor de peça 1
        float posicaoPecaX3, posicaoPecaX4, posicaoPecaY2; // Vetor de peça 2
        float posicaoPecaX5, posicaoPecaX6, posicaoPecaY3; // Vetor de peça 3

        bool Estrela, colisao, colisao2, colisao3, gameOver, DeuCerto, inicia, jogar, aux, naTela[6];
};
