#include"SFML/Graphics.hpp"
#include<iostream>


using namespace std;
using namespace sf;

void PlayerControl(Event &event,RectangleShape &Player)
{
    if(event.type == Event::KeyPressed)
      {
          switch(event.key.code)
          {
          case Keyboard::A:
            Player.move(-10,0);
            break;
          case Keyboard::Left:
            Player.move(-10,0);
            break;
          case Keyboard::D:
            Player.move(10,0);
            break;
          case Keyboard::Right:
            Player.move(10,0);
            break;
          case Keyboard::W:
            Player.move(0,-10);
            break;
          case Keyboard::Up:
            Player.move(0,-10);
            break;
          case Keyboard::S:
            Player.move(0,10);
            break;
          case Keyboard::Down:
            Player.move(0,10);
            break;
          }
      }
}

int main()
{
    RenderWindow window (VideoMode(1920,1080),"PHEONYX PROTOTYPE");

    RectangleShape Player (Vector2f(100,100));
    Player.setOrigin(-910,-540);
    Player.setFillColor(Color::Red);
    Player.setOutlineThickness(5);
    Player.setOutlineColor(Color::White);

    CircleShape FireBall(10.f);
    FireBall.setOrigin(Player.getPosition());
    FireBall.setFillColor(Color::Yellow);
    FireBall.setOutlineThickness(2);
    FireBall.setOutlineColor(Color::White);

    while(window.isOpen())
    {
        window.clear();
        window.draw(Player);
        window.display();

        Event event;

        while(window.pollEvent(event))
        {
            if((event.type == Event::Closed) || ((event.type == Event::KeyPressed) && (event.key.code == Keyboard::Escape)))
                window.close();
            else
            {
              PlayerControl(event,Player);
              if(event.type == Event::MouseButtonPressed)
              {
                  if(event.mouseButton.button == Mouse::Left)
                  {
                      cout<<"draw"<<endl;
                       window.draw(FireBall);
                  }


              }
            }
        }
    }
    return 0;
}
