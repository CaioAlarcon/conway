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

    private:
    fptr Messenger;
    int JanelaX, JanelaY,M,N;
    sf::Event event;
    sf::RenderWindow *window;
    sf::RectangleShape *shape;
    sf::RectangleShape ***shapes;
    float largura();
    float altura();
    void InsereShapes();
    void DesenhaShapes();
    void eventos();
    void sleep(float segundos);
    void lidaComMouse(sf::Event);
    void lidaComTeclado(sf::Event);
    sf::Thread * threadEventos;
    void onClick();
    void onMove();
    
};
