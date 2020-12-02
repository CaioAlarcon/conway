#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

typedef void(*fptr)(int);

class view{
    public:
    view(int janelaX, int janelaY, int m, int n);
    ~view();
    void atualiza();
    bool aberta();
    sf::RectangleShape *** getViews();
    sf::RenderWindow * getWindow();
    void getMessenger(fptr);
    int linhas();
    int colunas();
    void randomizaShapes();
    void limpaShapes();
    private:
    fptr Messenger;
    int JanelaX, JanelaY,M,N;
    sf::RenderWindow *window;
    
    sf::RectangleShape ***shapes=NULL;
    float largura();
    float altura();
    void InsereShapes();
    void DesenhaShapes();
    
    void sleep(float segundos);

    
    void onClick();
    void onMove();
    
};
