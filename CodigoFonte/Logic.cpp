#include "Logic.h"

#define velMovimento 4
#define larguraTela 1250
#define alturaTela 660
#define alturaPersonagem 350
#define larguraPersonagem 100
#define alturaPeca 48
#define larguraPeca 48

using namespace std;

// ********************************************CLASSE RAIN******************************************** //


Logic::Logic(){
    velocidade.x = 0;
    velocidade.y = velMovimento;
    indice = 0;
    teste = 0;
    teste2 = 0;
    teste3 = 0;
    posX = 0;
    posY = 0;
    winner = 0;
    MenuEscolhido = 0;

    frameCounter = 0;
    switchFrame = 100;
    frameSpeed = 2500;

    frameCounter3 = 0;
    switchFrame3 = 100;
    frameSpeed3 = 1000;

    posicaoBoneco1 = 0;
    posicaoBoneco2 = 0;
    posicaoPecaX1 = 0;
    posicaoPecaX2 = 0;
    posicaoPecaX3 = 0;
    posicaoPecaX4 = 0;
    posicaoPecaX5 = 0;
    posicaoPecaX6 = 0;
    posicaoPecaY = 0;
    posicaoPecaY2 = 0;
    posicaoPecaY3 = 0;

    Estrela = false;
    colisao = false;
    colisao2 = false;
    colisao3 = false;
    gameOver = false;
    inicia = true;
    jogar = false;
    aux = false;

    for (int i = 0; i < 6; i++)
        naTela[i] = false;

    comecoGirl.x = 1;
    comecoGirl.y = 0;
};

void Logic::carregaImagens(){

    //MENU
    if(!textura[0].loadFromFile("Imagem/noSelect.png"))
        std::cout << "Error could not load 1 image" << std::endl;

    if(!textura[1].loadFromFile("Imagem/jogarSelected.png"))
        std::cout << "Error could not load 2 image" << std::endl;

    if(!textura[2].loadFromFile("Imagem/instruSelected.png"))
        std::cout << "Error could not load 3 image" << std::endl;

    if(!textura[3].loadFromFile("Imagem/sairSelected.png"))
        std::cout << "Error could not load 4 image" << std::endl;

    if(!textura[4].loadFromFile("Imagem/instrucoes.png"))
        cout << "Erro" << endl;

    menu[0].setTexture(textura[0]);
    menu[1].setTexture(textura[1]);
    menu[2].setTexture(textura[2]);
    menu[3].setTexture(textura[3]);
    instrucoes.setTexture(textura[4]);

    // CENÁRIO
    if(!FTexture.loadFromFile("Imagem/fundo.jpg")){
       cout << "Erro no carregamento da imagem";
    }

    FSprite.setTexture(FTexture);

    // PERSONAGEM
    if(!BTexture.loadFromFile("Imagem/boneco.png")){
       cout << "Erro no carregamento da imagem";
    }

    BSprite.setTexture(BTexture);
    BSprite.setPosition(350,450); // Depende do tamanho da imagem do personagem
    BSprite.setScale(0.5,0.5);

    //BLOQUINHO DO CANTO
    if(!CantoTexture.loadFromFile("Imagem/canto.png")){
       cout << "Erro no carregamento da imagem";
    }

    CantoSprite.setTexture(CantoTexture);

    CantoSprite.setScale(0.85,0.85);
    CantoSprite.setPosition(larguraTela - 260, 50);

    // PEÇAS
    if(!PTexture[0].loadFromFile("Imagem/elemento1.png")){
       cout << "Erro no carregamento da imagem";
    }

    if(!PTexture[1].loadFromFile("Imagem/elemento2.png")){
       cout << "Erro no carregamento da imagem";
    }

    if(!PTexture[2].loadFromFile("Imagem/elemento3.png")){
       cout << "Erro no carregamento da imagem";
    }

    if(!PTexture[3].loadFromFile("Imagem/elemento4.png")){
       cout << "Erro no carregamento da imagem";
    }

    if(!PTexture[4].loadFromFile("Imagem/elemento5.png")){
       cout << "Erro no carregamento da imagem";
    }

    PSprite[0].setTexture(PTexture[0]);
    PSprite[1].setTexture(PTexture[1]);
    PSprite[2].setTexture(PTexture[2]);
    PSprite[3].setTexture(PTexture[3]);
    PSprite[4].setTexture(PTexture[4]);

    DesenhoImagem[0].setTexture(PTexture[0]);
    DesenhoImagem[1].setTexture(PTexture[1]);
    DesenhoImagem[2].setTexture(PTexture[2]);
    DesenhoImagem[3].setTexture(PTexture[3]);
    DesenhoImagem[4].setTexture(PTexture[4]);

    //Redimensiona todas as imagens das peças
    for(int i=0; i<5; i++){
        PSprite[i].setScale(0.1, 0.1);
        DesenhoImagem[i].setScale(0.1, 0.1);
    }

    // ESTRELA
    if(!PTexture[5].loadFromFile("Imagem/estrela.png")){
       cout << "Erro no carregamento da imagem";
    }

    PSprite[5].setTexture(PTexture[5]);

    DesenhoImagem[5].setTexture(PTexture[5]);
    DesenhoImagem[5].setPosition(1094, 86);

    // WINNER
    if(!WTexture.loadFromFile("Imagem/venceu.png"))
        std::cout << "Erro no carregamento da imagem" << endl;
    WSprite.setTexture(WTexture);

    // GAMEOVER
    if(!GTexture.loadFromFile("Imagem/GameOver.png"))
        std::cout << "Erro no carregamento da imagem" << endl;
    GSprite.setTexture(GTexture);
}

void Logic::carregaMusicas(){
    //Game Over
    if(!GOBuffer.loadFromFile("Som/GameOver.wav"))
        std::cout << "Erro no carregamento do som" << endl;
    GOSound.setBuffer(GOBuffer);
    GOSound.setVolume(200);

    //Winner
    if(!VBuffer.loadFromFile("Som/Vitoria.wav"))
        std::cout << "Erro no carregamento do som1" << endl;
    VSound.setBuffer(VBuffer);
    VSound.setVolume(200);

    //Estrela
    if(!EBuffer.loadFromFile("Som/Estrela.wav"))
        std::cout << "Erro no carregamento do som" << endl;
    ESound.setBuffer(EBuffer);
    ESound.setVolume(200);

    //Peca certa
    if(!PCBuffer.loadFromFile("Som/PecaCerta.wav"))
        std::cout << "Erro no carregamento do som" << endl;
    PCSound.setBuffer(PCBuffer);
    PCSound.setVolume(200);

    //Peca errada
    if(!PEBuffer.loadFromFile("Som/PecaErrada.wav"))
        std::cout << "Erro no carregamento do som" << endl;
    PESound.setBuffer(PEBuffer);
    PESound.setVolume(200);

    //Jogo
    if(!MusicJogo.openFromFile("Som/Jogo.wav")){
        std::cout << "Erro no carregamento do somwijdi" << endl;
    }
    MusicJogo.setVolume(30);
}

void Logic::eventos(){

    // Fechar janela
    while(Window.pollEvent(event)){
        if(event.type == sf::Event::Closed){
            Window.close();
        }
    }
}

void Logic::cairPeca(){
    // Se o jogador pegou peça errada, para de cair peças, pois deu game over
    if ((!gameOver) && (winner != 5)){

        // Se a peça não foi pega e chegou ao fim da tela OU a peça foi pega
        if ((PSprite[teste].getPosition().y >= alturaTela) || (colisao) || (inicia)){
            naTela[teste] = false;
            colisao = false;
            velocidade.y = velMovimento;

            // Gera posição da peça, X começando aleatório quando voltar a cair
            posX = rand() % (larguraTela - 350);
            posY = 0;

            // Se o jogador já tiver uma estrela, ela não aparecerá de novo, omitindo o indice dela

            do{
                if (Estrela)
                    indice = rand()%5;
                else
                    indice = rand()%6;
            }while (naTela[indice] == true);


            switch (indice){
                case 0: teste = 0;
                        break;
                case 1: teste = 1;
                        break;
                case 2: teste = 2;
                        break;
                case 3: teste = 3;
                        break;
                case 4: teste = 4;
                        break;
                case 5: teste = 5;
                        break;
            }
            if (teste != 5)
                naTela[teste] = true;
            PSprite[teste].setPosition(posX, posY);
        }

        if ((PSprite[teste2].getPosition().y >= alturaTela) || (colisao2) || (inicia)){
            naTela[teste2] = false;
            colisao2 = false;
            velocidade.y = velMovimento;

            //Gera posição da peça, X começando aleatório quando voltar a cair
            do{
                posX = rand() % (larguraTela - 350);
            }while( abs(posX - PSprite[teste].getPosition().x) < larguraPeca);

            if(inicia)
                posY = -300;
            else
                posY = 0;

            do{
                indice = rand()%5;
            }while(naTela[indice] == true);

            switch (indice){
                case 0: teste2 = 0;
                        break;
                case 1: teste2 = 1;
                        break;
                case 2: teste2 = 2;
                        break;
                case 3: teste2 = 3;
                        break;
                case 4: teste2 = 4;
                        break;
                case 5: teste2 = 5;
                        break;
            }

            naTela[teste2] = true;
            PSprite[teste2].setPosition(posX, posY);
        }

        if ((PSprite[teste3].getPosition().y >= alturaTela) || (colisao3) || (inicia)){
            naTela[teste3] = false;
            colisao3 = false;
            velocidade.y = velMovimento;

            // Gera posição da peça, X começando aleatório quando voltar a cair
            do{
                posX = rand() % (larguraTela - 350);
            }while((abs(posX - PSprite[teste].getPosition().x) < larguraPeca) ||(abs(posX - PSprite[teste2].getPosition().x) < larguraPeca));

            if(inicia)
                posY = -600;
            else
                posY = 0;

            inicia = false;

            do{
                indice = rand()%5;
            }while(naTela[indice] == true);

            switch (indice){
                case 0: teste3 = 0;
                        break;
                case 1: teste3 = 1;
                        break;
                case 2: teste3 = 2;
                        break;
                case 3: teste3 = 3;
                        break;
                case 4: teste3 = 4;
                        break;
                case 5: teste3 = 5;
                        break;
            }

            naTela[teste3] = true;
            PSprite[teste3].setPosition(posX, posY);
        }

        PSprite[teste].move(0, velocidade.y);
        PSprite[teste2].move(0, velocidade.y);
        PSprite[teste3].move(0, velocidade.y);
    }
}

void Logic::moverPersonagem(){
    // Movimenta para a esquerda
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){

        // Verifica se não está no fim da tela pela esquerda
        if(7 < BSprite.getPosition().x){
            // Controla a continuidade do movimento do personagem
            frameCounter += frameSpeed*clock.restart().asSeconds();

            if(frameCounter >= switchFrame){
                frameCounter = 0;
                comecoGirl.y = 0;
                BSprite.move(-15,0);
            }
        }
    }
    // Movimenta para a direita
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){

        // Verifica se não está no fim da tela pela direita
        if(BSprite.getPosition().x < larguraTela - 350){
            // Controla a continuidade do movimento do personagem
            frameCounter += frameSpeed*clock.restart().asSeconds();
            if(frameCounter >= switchFrame){
                frameCounter = 0;
                comecoGirl.y = 1;
                BSprite.move(15.0,0);
            }
        }
    }
    frameCounter3 += frameSpeed3*clock3.restart().asSeconds();
    if((frameCounter3 >= switchFrame3) && (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right))){
        frameCounter3 = 0;
        comecoGirl.x++;
        if(comecoGirl.x*170 >= 1000)
            comecoGirl.x = 0;
    }
}

 void Logic::colide(){
    // Pega a posição do x inicial e x final do personagem
    posicaoBoneco1 = BSprite.getPosition().x - 20;
    posicaoBoneco2 = BSprite.getPosition().x + larguraPersonagem;

    // Para diminuir a área de colisão da peça com o personagem, dividimos a largura pela metade da metade
    // Pega a posição do x inicial e desloca para direita
    posicaoPecaX1 = PSprite[teste].getPosition().x + (larguraPeca/2)/2;
    posicaoPecaX3 = PSprite[teste2].getPosition().x + (larguraPeca/2)/2;
    posicaoPecaX5 = PSprite[teste3].getPosition().x + (larguraPeca/2)/2;

    // Pega a posição do x final e desloca para esquerda
    posicaoPecaX2 = PSprite[teste].getPosition().x + larguraPeca - (larguraPeca/2)/2;
    posicaoPecaX4 = PSprite[teste2].getPosition().x + larguraPeca - (larguraPeca/2)/2;
    posicaoPecaX6 = PSprite[teste3].getPosition().x + larguraPeca - (larguraPeca/2)/2;

    // Pega a posição do y inicial da peça e soma com a altura da peça
    posicaoPecaY = PSprite[teste].getPosition().y + alturaPeca;
    posicaoPecaY2 = PSprite[teste2].getPosition().y + alturaPeca;
    posicaoPecaY3 = PSprite[teste3].getPosition().y + alturaPeca;

    // Se as posições da peça estiverem delimitada pela largura do personagem
    // E o personagem não pegou peça errada
    if(((posicaoPecaX1 > posicaoBoneco1) && (posicaoPecaX2 < posicaoBoneco2)) && (!gameOver) && (winner < 5)){

        // Se a posição do y final da peça e inicial do personagem se encontrarem
        if((posicaoPecaY >= BSprite.getPosition().y) && (posicaoPecaY < BSprite.getPosition().y + 5)){
            velocidade.y = 0; // Para a peça
            colisao = true;
            naTela[teste] = false;

            // Se a peça for diferente da estrela
            // Verifica se a peça pega é correspondente à peça de mesmo índice na pilha definitiva
            if(teste != 5){
                Empilha(PAux, teste, DeuCerto);
                if(DeuCerto){
                    aux = Estrela;
                    if(Iguais(P, PAux, Estrela, gameOver, winner)){
                        winner++;
                        if(aux == true && Estrela == false)
                            PESound.play();
                        else{
                            if(winner<5)
                                PCSound.play();
                            else
                                VSound.play();
                        }
                    }
                    else
                        GOSound.play();
                }
            }else{
                Estrela = true;
                ESound.play();
            }
        }
    }
    if(((posicaoPecaX3 > posicaoBoneco1) && (posicaoPecaX4 < posicaoBoneco2)) && (!gameOver) && (winner < 5)){
        // Se a posição do y final da peça e inicial do personagem se encontrarem
        if((posicaoPecaY2 >= BSprite.getPosition().y) && (posicaoPecaY2 < BSprite.getPosition().y + 5)){
            velocidade.y = 0; // Para a peça
            colisao2 = true;
            naTela[teste2] = false;

            // Se a peça for diferente da estrela
            // Verifica se a peça pega é correspondente à peça de mesmo índice na pilha definitiva
            Empilha(PAux, teste2, DeuCerto);
            if(DeuCerto){
                aux = Estrela;
                if(Iguais(P, PAux, Estrela, gameOver, winner)){
                    winner++;
                    if(aux == true && Estrela == false)
                        PESound.play();
                    else{
                        if(winner<5)
                            PCSound.play();
                        else
                            VSound.play();
                    }
                }
                else
                    GOSound.play();
            }
        }
    }
    if(((posicaoPecaX5 > posicaoBoneco1) && (posicaoPecaX6 < posicaoBoneco2)) && (!gameOver) && (winner < 5)){
        // Se a posição do y final da peça e inicial do personagem se encontrarem
        if((posicaoPecaY3 >= BSprite.getPosition().y) && (posicaoPecaY3 < BSprite.getPosition().y + 5)){
            velocidade.y = 0; // Para a peça
            colisao3 = true;
            naTela[teste3] = false;

            // Se a peça for diferente da estrela
            // Verifica se a peça pega é correspondente à peça de mesmo índice na pilha definitiva
            Empilha(PAux, teste3, DeuCerto);
            if(DeuCerto){
                aux = Estrela;
                if(Iguais(P, PAux, Estrela, gameOver, winner)){
                    winner++;
                    if(aux == true && Estrela == false)
                        PESound.play();
                    else{
                        if(winner<5)
                            PCSound.play();
                        else
                            VSound.play();
                    }
                }
                else
                    GOSound.play();
            }
        }
    }
}

void Logic::DesenhaPilhaFixa(){
    for(int i=0; i<=P.Topo; i++){
        DesenhoImagem[P.Elementos[i]].setPosition(1135, (84*(P.Topo-i))+189);
        Window.draw(DesenhoImagem[P.Elementos[i]]);
    }
}

void Logic::DesenhaPilhaConstruindo(){
    for(int i=0; i<=PAux.Topo; i++){
        DesenhoImagem[PAux.Elementos[i]].setPosition(1050, (85*(P.Topo-i))+189);
        Window.draw(DesenhoImagem[PAux.Elementos[i]]);
    }
}

void Logic::DesenhaEstrela(){
    if(Estrela){
        Window.draw(DesenhoImagem[5]);}
}

void Logic::MouseTracker(){
    if((335<sf::Mouse::getPosition(Window).x && sf::Mouse::getPosition(Window).x<633)&&
       (283<sf::Mouse::getPosition(Window).y && sf::Mouse::getPosition(Window).y<402)){
        TipoDeMenu = 1;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            MenuEscolhido = 1;
        }
    }else if((752<sf::Mouse::getPosition(Window).x && sf::Mouse::getPosition(Window).x<1113)&&
       (421<sf::Mouse::getPosition(Window).y && sf::Mouse::getPosition(Window).y<469)){
        TipoDeMenu = 2;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            MenuEscolhido = 2;
        }

    }else if((865<sf::Mouse::getPosition(Window).x && sf::Mouse::getPosition(Window).x<999)&&
       (552<sf::Mouse::getPosition(Window).y && sf::Mouse::getPosition(Window).y<593)){
        TipoDeMenu = 3;
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            MenuEscolhido = 3;
        }
    }else{
        TipoDeMenu = 0;
    }
}

void Logic::Reseta(){
    inicia = true;
    Estrela = false;
    winner = 0;
    Cria(PAux);
    Cria(P);
    IniciaRandom(P);
    MusicJogo.setLoop(true);
    MusicJogo.play();
}

void Logic::run(){
    srand(time(NULL));

    // Cria a janela .exe
    Window.create(sf::VideoMode(larguraTela, alturaTela), "Computer Rain");
    Window.setFramerateLimit(60);

    // Cria pilha definitiva e a pilha a ser empilhada pelo jogador
    Cria(PAux);
    Cria(P);
    IniciaRandom(P);

    carregaImagens();

    carregaMusicas();

    while (Window.isOpen()){

        if((!jogar) && (!gameOver) && (winner<5)){

            eventos();

            MouseTracker();

            if(MenuEscolhido == 0){
                 switch(TipoDeMenu)
                {
                case 0: Window.clear();
                        Window.draw(menu[0]);
                        break;

                case 1: Window.clear();
                        Window.draw(menu[1]);
                        break;

                case 2: Window.clear();
                        Window.draw(menu[2]);
                        break;

                case 3: Window.clear();
                        Window.draw(menu[3]);
                        break;
                }
            }
            else{
                switch(MenuEscolhido){
                    case 0: break;

                    case 1: jogar = true;
                            break;

                    case 2: Window.clear();
                            Window.draw(instrucoes);
                            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                                MenuEscolhido = 0;
                            }
                            break;

                    case 3: Window.close();
                            break;
                }
            }
            Window.display();
        }

        if((jogar) && (!gameOver) && (winner < 5)){

            MusicJogo.setLoop(true);

            if(!MusicJogo.getStatus())
                MusicJogo.play();

            eventos();
            cairPeca();
            moverPersonagem();
            colide();
            BSprite.setTextureRect(sf::IntRect(comecoGirl.x*170, comecoGirl.y*375, 170, 375));

            // Limpa a tela
            Window.clear();

            // Renderiza imagens
            Window.draw(FSprite);
            Window.draw(BSprite);
            Window.draw(PSprite[teste]);
            Window.draw(PSprite[teste2]);
            Window.draw(PSprite[teste3]);
            Window.draw(CantoSprite);
            DesenhaPilhaFixa();
            DesenhaPilhaConstruindo();
            DesenhaEstrela();

            // Mostra imagens renderizadas
            Window.display();
        }

        //se deu game over
        if(gameOver){
            MusicJogo.pause();
            Window.clear();
            eventos();
            Window.draw(GSprite);
            Window.display();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                Reseta();
                gameOver = !gameOver;
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                Window.clear();
                Window.close();
            }
        }

        //se ganhou
        if(winner == 5){
            MusicJogo.pause();
            Window.clear();
            eventos();
            Window.draw(WSprite);
            Window.display();
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                Reseta();
            }

            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
                Window.clear();
                Window.close();
            }
        }
    }
}

