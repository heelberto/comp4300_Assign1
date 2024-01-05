#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

int N = 30, M = 20;
int size = 16;
int w = size * N;
int h = size * M;

//void displayFrameRate();

//dir will be used for direction
    //num will be used to keep track of the 
    //size of the snake, intitial is 4
int dir = 0, num = 4;

//create a snake with a size of up to 100
//each section of the snake will have an x
// and y position
struct Snake
{
    int x, y;
} s[100];

struct fruit
{
    int x, y;
} f1,f2;

//function to update the snake's position
//handles collision detection with the 
//fruit and the boundaires
//if the snake encounters fruit, it will 
//grow per fruit eaten and a random 
//fruit will be placed
void Tick()
{
    //create the snake effect of each
    //body segment following the
    //segment before itseld
    //start loop from the back 
    for (int i = num; i > 0; --i)
    {
        s[i].x = s[i - 1].x;
        s[i].y = s[i - 1].y;
    }

    if (dir == 0) s[0].y += 1;
    if (dir == 1) s[0].x -= 1;
    if (dir == 2) s[0].x += 1;
    if (dir == 3) s[0].y -= 1;

    //check for collission of the head with the fruit1
    if ((s[0].x == f1.x) && s[0].y == f1.y)
    {
        num++;
        f1.x = rand() % N;
        f1.y = rand() % M;
    }

    //check for collission of the head with the fruit2
    if ((s[0].x == f2.x) && s[0].y == f2.y)
    {
        num++;
        f2.x = rand() % N;
        f2.y = rand() % M;
    }
}

int main() {

    srand(time(0));

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
    Sprite sprite3(t2);

    //create a clock for fps
    Clock clock;
    float timer = 0, delay = 0.1;

    //window.setFramerateLimit(60);

    //place fruit1
    f1.x = 10;
    f1.y = 10;

    //place fruit2
    f2.x = 20;
    f2.y = 20;

    //main game loop
    while (window.isOpen())
    {
        //get time since last restart() in seconds
        float time = clock.getElapsedTime().asSeconds();
        clock.restart();
        timer += time;

        

        Event e;
        while (window.pollEvent(e))
        {
            if (e.type == Event::Closed)
                window.close();
        }

        //handling keyboard input
        if (Keyboard::isKeyPressed(Keyboard::Left)) dir = 1;
        if (Keyboard::isKeyPressed(Keyboard::Right)) dir = 2;
        if (Keyboard::isKeyPressed(Keyboard::Up)) dir = 3;
        if (Keyboard::isKeyPressed(Keyboard::Down)) dir = 0;

        

        if (timer > delay)
        {
            //once the timer meets the desired fps
            //restart the timer
            //and reset the game logic
            timer = 0;
            Tick();
        }

        //draw section
        window.clear();

        //set up background
        for (int i = 0; i < N; i++) 
        {
            for (int j = 0; j < M; j++)
            {
                sprite1.setPosition(i * size, j * size);  window.draw(sprite1);
            }
            
        }

        //set start position of snake
        for (int i = 0; i < num; i++)
        {
            sprite2.setPosition(s[i].x* size, s[i].y* size);
            window.draw(sprite2);
        }

        //set up fruit1
        sprite2.setPosition(f1.x * size, f1.y * size);
        window.draw(sprite2);

        //set up fruit2
        sprite3.setPosition(f2.x * size, f2.y * size);
        window.draw(sprite2);

        window.display();
    }
    return 0;
}