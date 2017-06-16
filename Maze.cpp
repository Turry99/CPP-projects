#include <iostream>
#include <SFML/Graphics.hpp>

using namespace sf;
int N=30, M=30;
int size = 32;
int w = size*N;
int h = size*M;
int lastMove[] = {0,0};
bool done = true;

int main() {
    RenderWindow window(VideoMode(w, h), "Turtle Maze");

    Texture t1, t2, t3, t4;
    t1.loadFromFile("../white.jpeg");
    t2.loadFromFile("../black.jpeg");
    t3.loadFromFile("../turtle.png");
    t4.loadFromFile("../finish.png");


    std::vector<Sprite> walls(126, Sprite(t2));

    ///Set the walls position
    for( int i =0 ; i <walls.size(); i++)
    {
        walls[i].setTexture(t2);
        walls[i].setPosition(-40,-40);
    }

    Sprite sprite1(t1);
    Sprite turtle(t3);
    Sprite end(t4);
    end.setPosition(Vector2f(928,928));

    for(int i=0;i<10;i++){walls[i].setPosition(i*size,size);}
    for(int i=0;i<5;i++){walls[10+i].setPosition(11*size,i*size);}
    for(int i=0;i<28;i++){walls[15+i].setPosition(32+i*size,7*size);}
    for(int i=0;i<26;i++){walls[43+i].setPosition(96+i*size,96+i*size);}
    for(int i=0;i<28;i++){walls[69+i].setPosition(15*size,32+i*size);}
    for(int i=0;i<29;i++){walls[97+i].setPosition(32+i*size,23*size);}



    while (window.isOpen() && done)
    {
        Event event;
        while (window.pollEvent( event ))
        {
            switch (event.type) {
                case Event::Closed:
                    window.close();
            }

            if (Keyboard::isKeyPressed(Keyboard::Left)){ turtle.move(-32,0); lastMove[0]=32  ; lastMove[1]=0;}
            if (Keyboard::isKeyPressed(Keyboard::Right)){ turtle.move(32,0); lastMove[0]=-32 ; lastMove[1]=0;}
            if (Keyboard::isKeyPressed(Keyboard::Up)){ turtle.move(0,-32);   lastMove[0]=0   ; lastMove[1]=32;}
            if (Keyboard::isKeyPressed(Keyboard::Down)){ turtle.move(0,32);  lastMove[0]=0   ; lastMove[1]=-32;}


        }

        window.clear();
        //////Draw the white tiles everywhere//////
        for (int i=0; i<N; i++)
            for (int j=0; j<M; j++)
            { sprite1.setPosition(i*size, j*size); window.draw(sprite1);}

        //////Draw the walls///////
        for(const auto& wall : walls) window.draw(wall);

        /////Check the colision with the walls
        for(const auto& wall : walls)
        {
            if(turtle.getGlobalBounds().intersects(wall.getGlobalBounds()))
            {
                turtle.move(lastMove[0], lastMove[1]);
            }
        }
        //////Check if it arrived to the finish/////
        if(turtle.getGlobalBounds().intersects(end.getGlobalBounds()))
            {
                done = false;
                window.close();
                break;
            }


        lastMove[0]=0;lastMove[1]=0;
        window.draw(turtle);
        window.draw(end);


        window.display();

    }
    ///////WON/////
    if (!done)
    {
        RenderWindow screen(VideoMode(700, 700), "Congrats");
            Texture fin;
            fin.loadFromFile("../final.png");
            Sprite finale(fin);
        Event eveniment;
        while (screen.isOpen())
        {
            while (window.pollEvent( eveniment ))
            {
                switch (eveniment.type)
                {
                    case Event::Closed:
                        screen.close();
                }
            }
                screen.clear();
                screen.draw(finale);
                screen.display();

            }
        }
    return 0;
}













































































