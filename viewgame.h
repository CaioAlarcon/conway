#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

typedef void(*fptr)(int);

class view{
    public:
    view(int janelaX, int janelaY, int m, int n);
    void atualiza();
    bool aberta();
    sf::RectangleShape *** getViews();
    sf::RenderWindow * getWindow();
    void getMessenger(fptr);
    int linhas();
    int colunas();
    
    private:
    fptr Messenger;
    int JanelaX, JanelaY,M,N;
    sf::RenderWindow *window;
    sf::RectangleShape *shape;
    sf::RectangleShape ***shapes;
    float largura();
    float altura();
    void InsereShapes();
    void DesenhaShapes();
    
    void sleep(float segundos);

    
    void onClick();
    void onMove();
    
};
