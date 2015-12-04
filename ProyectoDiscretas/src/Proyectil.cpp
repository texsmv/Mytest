#include "Proyectil.h"

Proyectil::Proyectil(string nombreArchivo,float alto, float ancho, sf::Event* evento,sf::RenderWindow* win,sf::Vector2f posicion){
    this->alto = alto;
    this->ancho = ancho;
    this->win=win;


    this ->textura.loadFromFile(nombreArchivo);
    this ->setTexture(textura);

    this->Coordenadas=this->getPosition();
    this->setPosition(posicion);

}


void Proyectil::update(){
    this->move(14,0);
    this->Coordenadas=this->getPosition();

}




Proyectil::Proyectil()
{
    //ctor
}

Proyectil::~Proyectil()
{
    //dtor
}
