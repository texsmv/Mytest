#include "Objeto.h"

Objeto::Objeto(std::string nombreArchivo, float alto, float ancho){

    this->alto = alto;
    this->ancho = ancho;



    this ->textura.loadFromFile(nombreArchivo);
    this ->setTexture(textura);

    this->Coordenadas=this->getPosition();



}
void Objeto::update(){

}



Objeto::Objeto()
{
    //ctor
}

Objeto::~Objeto()
{
    //dtor
}
