#ifndef PERSONAJE_H
#define PERSONAJE_H
#include <Objeto.h>
#include <Proyectil.h>
class Personaje : public Objeto
{
    public:
        Personaje();
        Personaje(string, float,float,sf::Event*, sf::RenderWindow*,int**,float,float);
        void update();
        void Mover();
        void disparar();
        virtual ~Personaje();
        void setEvento(sf::Event *);
    protected:
    private:

        sf::Vector2f velocidad_eje_x={0,0};
        sf::Vector2f velocidad_eje_y={0,0};
        sf::Vector2f gravedad={0,2};
        int ** matriz;
        int alto_bloque, ancho_bloque;
        vector <Proyectil*> proyectiles;
        bool draw_bala=false;
        sf::Clock *velocidad_ataque ;


};

#endif // PERSONAJE_H
