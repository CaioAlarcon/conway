#include "viewgame.h"

view::view(int janelaX, int janelaY, int m, int n){
        JanelaX = janelaX; JanelaY = janelaY;M = m;N=n;
        window = new sf::RenderWindow(sf::VideoMode(JanelaX, JanelaY), "Conway vive!");
        InsereShapes();
    }
void view::atualiza(){
    doEvents();

    window->clear();
    DesenhaShapes();

    window->display();
    sleep(0.012f);
    
}
bool view::aberta(){
    return window->isOpen();
}

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
            if(i%2 == j%2)
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
void view::doEvents(){
    while (window->pollEvent(event)){
        if (event.type == sf::Event::Closed)
            window->close();
    }
}

void view::sleep(float segundos){
    sf::Time refresh = sf::seconds(segundos);
    sf::sleep (refresh);
}


