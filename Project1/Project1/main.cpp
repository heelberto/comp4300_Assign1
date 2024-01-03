#include <iostream>
#include <SFML/Graphics.hpp>

int main() {

    /*sf::Window window(sf::VideoMode(800, 600), "Test Window");

    while (window.isOpen()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }
    }
    */

    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Bouncing Ball");

    // Create a ball shape
    sf::CircleShape ball(20.f);
    ball.setFillColor(sf::Color::Green);

    // Set the initial position and velocity of the ball
    sf::Vector2f position(100.f, 100.f);
    sf::Vector2f velocity(3.f, 2.f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Update the position of the ball
        position += velocity;

        // Bounce off the window edges
        if (position.x < 0 || position.x > window.getSize().x - 2 * ball.getRadius())
            velocity.x = -velocity.x;

        if (position.y < 0 || position.y > window.getSize().y - 2 * ball.getRadius())
            velocity.y = -velocity.y;

        // Clear the window
        window.clear();

        // Draw the ball
        ball.setPosition(position);
        window.draw(ball);

        // Display the contents of the window
        window.display();
    }

    return 0;
}