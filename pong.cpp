#include <SFML/Graphics.hpp>
using namespace sf;
bool collided_rightpaddle(Sprite paddleright, Sprite ball){return paddleright.getGlobalBounds().intersects(ball.getGlobalBounds());}
bool collided_leftpaddle(Sprite paddleleft, Sprite ball){return paddleleft.getGlobalBounds().intersects(ball.getGlobalBounds());}
bool started = false;
int main(){
    replay:
    Texture t1,t2,t3;
    t1.loadFromFile("C:/Users/wolfr/source/codeblock/pong/pongpaddle.png");
    t2.loadFromFile("C:/Users/wolfr/source/codeblock/pong/pongpaddle.png");
    t3.loadFromFile("C:/Users/wolfr/source/codeblock/pong/ball.png");
    Sprite paddleright(t1),paddleleft(t2),ball(t3);
    sf::RenderWindow window(sf::VideoMode(520, 450), "retardgame");
    paddleright.setPosition(511,226);
    paddleleft.setPosition(0, 225);
    Vector2f rightpos = paddleright.getPosition();
    paddleright.setPosition(rightpos);
    Font font;
    font.loadFromFile("C:/Users/wolfr/OneDrive/Desktop/Bin of bins/scripts/C++/16_Games/03 Arkanoid/images/RadgivareNo1Demo_FREE_FOR_PERSONAL_USE_ONLY.otf");
    sf::Text text;
    text.setFont(font);text.setString("press up and down to move the paddle \n space key to start \n esc to quit");
    text.setCharacterSize(24); // in pixels, not points!
    text.setFillColor(sf::Color::White);
    text.setStyle(sf::Text::Bold);text.setPosition(50, 300);
    ball.setPosition(300,300);
    float vx = -2, vy =2;
    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (Keyboard::isKeyPressed(Keyboard::Escape)){window.close();}
            if (Keyboard::isKeyPressed(Keyboard::Space)){started = true;}
            if (event.type == sf::Event::Closed){window.close();}
            if(!started){if(Keyboard::isKeyPressed(Keyboard::R)){goto replay;}}}
        Vector2f rightpos = paddleright.getPosition();
        if (rightpos.y > 0){if (Keyboard::isKeyPressed(Keyboard::Up)){paddleright.move(0,-4);}}
        if (rightpos.y < 370){if (Keyboard::isKeyPressed(Keyboard::Down)){paddleright.move(0,4);}}
        if(started)ball.move(vx,vy);
        Vector2f ballpos = ball.getPosition();
        if (ballpos.y > 370){paddleleft.setPosition(0,370);}
        else{paddleleft.setPosition(0,ballpos.y);}
        if(ballpos.x < 0){vx = -vx;}
        if(ballpos.x > 520){started = false; text.setString("you lost, press r to restart");}
        if(ballpos.y < 0 || ballpos.y >450){vy = -vy;}
        if(collided_rightpaddle(ball,paddleright)){vx = -vx;}
        if(collided_leftpaddle(ball,paddleleft)){vx = -vx;}
        window.clear();
        if(!started){window.draw(text);}
        window.draw(ball);
        window.draw(paddleright);
        window.draw(paddleleft);
        window.display();}
    return 0;}
