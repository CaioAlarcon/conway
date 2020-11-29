#include <SFML/Graphics.hpp>

#ifndef _view_
#define _view_
class view{
    public:
    view(int janelaX, int janelaY, int m, int n);
    void atualiza();
    bool aberta();
    sf::RectangleShape *** getViews();
    sf::RenderWindow * getWindow();
    
    private:
    int JanelaX, JanelaY,M,N;
    sf::Event event;
    sf::RenderWindow *window;
    sf::RectangleShape *shape;
    sf::RectangleShape ***shapes;
    float largura();
    float altura();
    void InsereShapes();
    void DesenhaShapes();
    void doEvents();
    void sleep(float segundos);
    void lidaComMouse(sf::Event);
    void lidaComTeclado(sf::Event);
};
#endif