#include <SFML/Graphics.hpp>
#include <optional>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800u, 600u}), "SFML 3.x Example");

    sf::CircleShape circle(100.f);
    circle.setFillColor(sf::Color::Red);
    circle.setPosition({350.f, 250.f});

    while (window.isOpen())
    {
        // Используем std::optional для события
        std::optional<sf::Event> event;
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }
        }
        
        window.clear(sf::Color::Black);
        window.draw(circle);
        window.display();
    }

    return 0;
}
