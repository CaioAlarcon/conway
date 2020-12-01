#include "viewgame.h"
#include <stdlib.h>

//Public
view::view(int janelaX, int janelaY, int m, int n){
        JanelaX = janelaX; JanelaY = janelaY;M = m;N=n;
        window = new sf::RenderWindow(sf::VideoMode(JanelaX, JanelaY), "Conway vive!");
        InsereShapes();

        threadEventos = new sf::Thread(&view::eventos, this);
        threadEventos->launch();
        
    }
void view::atualiza(){
    window->clear();
    DesenhaShapes();

    window->display();
    sleep(0.012f);
    
}
bool view::aberta(){
    return window->isOpen();
}
sf::RectangleShape *** view::getViews(){
    return shapes;
}
sf::RenderWindow * view::getWindow(){
    return window;
}

//Private
float view::largura(){
    return (float)JanelaX/M;
}
float view::altura(){
    return (float)JanelaY/N;
}
void view::InsereShapes(){
    int i, j,k=0;
    
    shapes = (sf::RectangleShape***)calloc(M,sizeof(sf::RectangleShape**));
    for (i=0;i<M;i++)
        shapes[i] = (sf::RectangleShape**)calloc(N,sizeof(sf::RectangleShape*));

    for (i=0;i<M;i++)
        for (j=0;j<N;j++){
            shapes[i][j] = new sf::RectangleShape (sf::Vector2f(largura(), altura()));
            
            shapes[i][j]->setPosition(sf::Vector2f(i*largura(), j*altura()));
            //if(i%2 == j%2)//padrão xadrez
            if(rand()%2==0)
                shapes[i][j]->setFillColor(sf::Color::Red);
            else
                shapes[i][j]->setFillColor(sf::Color::Blue);
        }
            
    
}
void view::DesenhaShapes(){
    int i,j;
    for(i=0;i<M;i++)
        for(j=0;j<N;j++)
            window->draw(*shapes[i][j]);
}


//se os eventos não ficarem sendo tratados constantemente a janela trava e o sistema emite msg falando que o programa não está respondendo.
void view::eventos(){
    while(true){
        while (window->pollEvent(event)){//lembrar de tratar o evento da barra do espaço para pausar o jogo
            switch (event.type){
                case sf::Event::MouseButtonPressed:
                case sf::Event::MouseMoved :
                    lidaComMouse(event);break;
                case sf::Event::KeyPressed: lidaComTeclado(event); break;
                case (sf::Event::Closed): window->close();

            }
            
        }
        sf::sleep(sf::milliseconds(12.0f));
    }
}
void view::sleep(float segundos){
    sf::Time refresh = sf::seconds(segundos);
    sf::sleep (refresh);
}
void view::lidaComTeclado(sf::Event event){
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space )){
        window->setTitle("teclou!");
    }
}
void view::onClick(){
    int i, j;
    sf::Color cor;
    for(i=0;i<M;i++)
            for(j=0;j<N;j++){
                sf::FloatRect Box(shapes[i][j]->getPosition().x, shapes[i][j]->getPosition().y, 
                                                shapes[i][j]->getSize().x, shapes[i][j]->getSize().y);
                
                if(Box.contains(event.mouseButton.x,event.mouseButton.y)){
                    shapes[i][j]->setFillColor(cor.Blue);
                }
                
            }
}
void view::onMove(){
    int i, j;
    sf::Color cor;
    for(i=0;i<M;i++)
            for(j=0;j<N;j++){
                sf::FloatRect Box(shapes[i][j]->getPosition().x, shapes[i][j]->getPosition().y, 
                                                shapes[i][j]->getSize().x, shapes[i][j]->getSize().y);
                
                if(Box.contains(event.mouseMove.x,event.mouseMove.y)){
                    shapes[i][j]->setFillColor(cor.Green);
                }
                
            }
}
void view::lidaComMouse(sf::Event event){
    int i, j;
    sf::Color cor;
    
    if(event.type == sf::Event::MouseButtonPressed)
        onClick();
    else if (event.type == sf::Event::MouseMoved) {
        onMove();
    }
    
}

