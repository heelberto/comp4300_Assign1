#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

int N = 30, M = 20;
int size = 16;
int w = size * N;
int h = size * M;

void displayFrameRate();

int main() {

    //create a window variable
    //with WxH dimesions
    RenderWindow window(VideoMode(w, h), "Snake Game!");

    //create 2 textures from the white/red images
    Texture t1, t2;
    t1.loadFromFile("images/white.png");
    t2.loadFromFile("images/red.png");

    //create a sprite w/ the texture of t1/t2
    Sprite sprite1(t1);
    Sprite sprite2(t2);

    window.setFramerateLimit(60);

    //main loop
    while (window.isOpen())
    {
        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }

        window.clear();

        //set up background
        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < M; j++)
            {
                sprite1.setPosition(i * size, j * size);  window.draw(sprite1);
            }
            
        }

        window.display();
    }
    return 0;
}