#include <SFML/Graphics.hpp>


class view{
    public:
    view(int janelaX, int janelaY, int m, int n){
        JanelaX = janelaX; JanelaY = janelaY;M = m;N=n;
        window = new sf::RenderWindow(sf::VideoMode(JanelaX, JanelaY), "Conway vive!");
        InsereShapes();
    }
    void atualiza(){
        doEvents();

        window->clear();
        DesenhaShapes();

        window->display();
        sleep(0.012f);
        
    }
    bool aberta(){
        return window->isOpen();
    }
    private:
    int JanelaX, JanelaY,M,N;
    sf::Event event;
    sf::RenderWindow *window;
    sf::RectangleShape *shape;
    sf::RectangleShape ***shapes;
    float largura(){
        return (float)JanelaX/M;
    }
    float altura(){
        return (float)JanelaY/N;
    }
    void InsereShapes(){
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
    void DesenhaShapes(){
        int i,j;
        for(i=0;i<M;i++)
            for(j=0;j<N;j++)
                window->draw(*shapes[i][j]);
    }

    //se os eventos não ficarem sendo tratados constantemente a janela trava e o sistema emite msg falando que o programa não está respondendo.
    void doEvents(){
        while (window->pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window->close();
        }
    }

    void sleep(float segundos){
        sf::Time refresh = sf::seconds(segundos);
        sf::sleep (refresh);
    }
    

};



int main(){
    view janela(600,600,12,12);

    while (janela.aberta()){
        janela.atualiza();
        sf::Time refresh = sf::seconds(0.048f);
        sf::sleep (refresh);
    }
    

    return 0;
}
