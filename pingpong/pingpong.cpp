#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

// Ukuran jendela
const int window_width = 800;
const int window_height = 600;

// Paddle (raket)
const float paddle_width = 15.0f;
const float paddle_height = 100.0f;
const float paddle_speed = 5.0f;

// Bola
const float ball_radius = 10.0f;
const float ball_speed = 0.4f;

int main() {
    // Membuat window
    sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Ping Pong");

    // Paddle kiri
    sf::RectangleShape left_paddle(sf::Vector2f(paddle_width, paddle_height));
    left_paddle.setPosition(30.0f, window_height / 2 - paddle_height / 2);
    left_paddle.setFillColor(sf::Color::Green);

    // Paddle kanan
    sf::RectangleShape right_paddle(sf::Vector2f(paddle_width, paddle_height));
    right_paddle.setPosition(window_width - 30.0f - paddle_width, window_height / 2 - paddle_height / 2);
    right_paddle.setFillColor(sf::Color::Red);

    // Bola
    sf::CircleShape ball(ball_radius);
    ball.setFillColor(sf::Color::White);
    ball.setPosition(window_width / 2 - ball_radius, window_height / 2 - ball_radius);
    sf::Vector2f ball_velocity(ball_speed, ball_speed);

    // Game loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Menggerakkan paddle
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && left_paddle.getPosition().y > 0)
            left_paddle.move(0, -paddle_speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && left_paddle.getPosition().y < window_height - paddle_height)
            left_paddle.move(0, paddle_speed);

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && right_paddle.getPosition().y > 0)
            right_paddle.move(0, -paddle_speed);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && right_paddle.getPosition().y < window_height - paddle_height)
            right_paddle.move(0, paddle_speed);

        // Menggerakkan bola
        ball.move(ball_velocity);

        // Memantulkan bola dari atas dan bawah
        if (ball.getPosition().y <= 0 || ball.getPosition().y >= window_height - ball_radius * 2)
            ball_velocity.y = -ball_velocity.y;

        // Memantulkan bola dari paddle kiri
        if (ball.getGlobalBounds().intersects(left_paddle.getGlobalBounds()))
            ball_velocity.x = -ball_velocity.x;

        // Memantulkan bola dari paddle kanan
        if (ball.getGlobalBounds().intersects(right_paddle.getGlobalBounds()))
            ball_velocity.x = -ball_velocity.x;

        // Jika bola keluar dari layar (game over)
        if (ball.getPosition().x <= 0 || ball.getPosition().x >= window_width - ball_radius * 2) {
            ball.setPosition(window_width / 2 - ball_radius, window_height / 2 - ball_radius);
            ball_velocity.x = -ball_velocity.x; // Reset bola ke tengah dengan arah yang berbeda
        }

        // Membersihkan layar dan menggambar objek
        window.clear();
        window.draw(left_paddle);
        window.draw(right_paddle);
        window.draw(ball);
        window.display();
    }

    return 0;
}
