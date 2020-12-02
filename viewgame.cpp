#include "viewgame.h"
#include <stdlib.h>

//Public
view::view(int janelaX, int janelaY, int m, int n){
        JanelaX = janelaX; JanelaY = janelaY;M = m;N=n;
        window = new sf::RenderWindow(sf::VideoMode(JanelaX, JanelaY), "Conway vive!");
        InsereShapes();
}
view::~view(){
    int i, j;
    window->close();
    
    
}
void view::atualiza(){
    window->clear();
    DesenhaShapes();

    window->display();
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
int view::linhas(){
    return M;
}
int view::colunas(){
    return N;
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
void view::randomizaShapes(){
    int i, j,k=0;
    
    for (i=0;i<M;i++)
        for (j=0;j<N;j++){
            if(rand()%2==0)
                shapes[i][j]->setFillColor(sf::Color::Red);
            else
                shapes[i][j]->setFillColor(sf::Color::Blue);
        }
}
void view::limpaShapes(){
    int i, j,k=0;
    for (i=0;i<M;i++)
        for (j=0;j<N;j++)
            shapes[i][j]->setFillColor(sf::Color::Red);
}
void view::DesenhaShapes(){
    int i,j;
    for(i=0;i<M;i++)
        for(j=0;j<N;j++)
            window->draw(*shapes[i][j]);
}


void view::sleep(float segundos){
    sf::Time refresh = sf::seconds(segundos);
    sf::sleep (refresh);
}