#ifndef OBJETO_H
#define OBJETO_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

using namespace std;

class Objeto: public sf::Sprite
{
    public:
        Objeto(string, float, float);
        Objeto();
        virtual void update();
        virtual ~Objeto();
    protected:

    private:
        sf::Texture textura;
        sf::Event* evento;
        sf::RenderWindow* win;
        float alto;
        float ancho;
        sf::Vector2f Coordenadas;
    friend class Proyectil;
    friend class Personaje;
};

#endif // OBJETO_H
