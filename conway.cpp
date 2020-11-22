#include <SFML/Graphics.hpp>

int main(){
    sf::RenderWindow window(sf::VideoMode(800, 800), "Conway vive!");
    sf::RectangleShape shape(sf::Vector2f(100, 100));
    shape.setFillColor(sf::Color::Green);
    sf::Time refresh = sf::seconds(0.012f);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        shape.setPosition(sf::Vector2f(0, 0));
        window.draw(shape);
        shape.setPosition(sf::Vector2f(100, 100));
        window.draw(shape);

        window.display();
        sf::sleep (refresh);
    }

    return 0;
}
