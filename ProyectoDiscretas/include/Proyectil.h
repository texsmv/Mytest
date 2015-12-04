#ifndef PROYECTIL_H
#define PROYECTIL_H
#include "Objeto.h"

class Proyectil: public Objeto
{
    public:
        Proyectil();
        Proyectil(string, float, float, sf::Event*,sf::RenderWindow*, sf::Vector2f);
        virtual ~Proyectil();
        void update();

    protected:
    private:
};

#endif // PROYECTIL_H
