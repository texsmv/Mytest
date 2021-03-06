#ifndef MAPA_H
#define MAPA_H
#include <iostream>

#include <SFML/Graphics.hpp>
using namespace std;

class Mapa
{
    public:
        Mapa(float, float,std::string[],int, int, int,int**,sf::RenderWindow*);
        void dibujar();
        virtual ~Mapa();
    private:
        int filas;
        int columnas;
        std::string* imagenes;
        float alto, ancho;
        int num_imagenes;
        sf::RenderWindow* win;
        int**Matriz;
        sf::Sprite ** images;
        friend class Fantasma;
        friend class Pacman;
};

#endif // MAPA_H
