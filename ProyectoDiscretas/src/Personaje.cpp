#include "Personaje.h"


Personaje::Personaje(std::string nombreArchivo, float alto, float ancho,sf::Event * evento, sf::RenderWindow * win, int ** matriz,float alto_bloque,float ancho_bloque){
    this->alto=alto;
    this->ancho=ancho;
    this ->textura.loadFromFile(nombreArchivo);
    this ->setTexture(textura);
    this->matriz=matriz;
    this->Coordenadas=this->getPosition();
    this->win=win;
    this->alto_bloque=alto_bloque;
    this->ancho_bloque=ancho_bloque;
    this->evento=evento;
    this->velocidad_ataque=new sf::Clock;
}


void Personaje::setEvento(sf::Event*evento){
    this->evento=evento;

}


void Personaje::update(){
    this->Mover();
    cout<<velocidad_ataque->getElapsedTime().asSeconds()<<endl;
}

void Personaje::Mover(){


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
        this->velocidad_eje_x={4,0};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
        this->velocidad_eje_x={-4,0};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
        this->velocidad_eje_y={0,-10};
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
        this->disparar();
        this->draw_bala=true;
    }



    ///////////////////////verificar colisiones

    sf::Vector2i esquina_sup_izq, esquina_sup_der, esquina_inf_izq, esquina_inf_der;

    esquina_sup_izq=sf::Vector2i(Coordenadas+this->velocidad_eje_y+this->gravedad);
    esquina_sup_der=sf::Vector2i(Coordenadas+this->velocidad_eje_y+this->gravedad)+sf::Vector2i{ancho,0};
    esquina_inf_izq=sf::Vector2i(Coordenadas+this->velocidad_eje_y+this->gravedad)+sf::Vector2i{0,alto};
    esquina_inf_der=sf::Vector2i(Coordenadas+this->velocidad_eje_y+this->gravedad)+sf::Vector2i{ancho,alto};

    if ((*(*(matriz+esquina_sup_izq.y/alto_bloque)+esquina_sup_izq.x/ancho_bloque)!=0)&&(*(*(matriz+esquina_sup_der.y/alto_bloque)+esquina_sup_der.x/ancho_bloque)!=0)&&(*(*(matriz+esquina_inf_der.y/alto_bloque)+esquina_inf_der.x/ancho_bloque)!=0)&&(*(*(matriz+esquina_inf_izq.y/alto_bloque)+esquina_inf_izq.x/ancho_bloque)!=0)){
        this->setPosition(Coordenadas+this->velocidad_eje_y+this->gravedad);
        this->Coordenadas=this->getPosition();
    }

    esquina_sup_izq=sf::Vector2i(Coordenadas+velocidad_eje_x);
    esquina_sup_der=sf::Vector2i(Coordenadas+velocidad_eje_x)+sf::Vector2i{ancho,0};
    esquina_inf_izq=sf::Vector2i(Coordenadas+velocidad_eje_x)+sf::Vector2i{0,alto};
    esquina_inf_der=sf::Vector2i(Coordenadas+velocidad_eje_x)+sf::Vector2i{ancho,alto};

    if ((*(*(matriz+esquina_sup_izq.y/alto_bloque)+esquina_sup_izq.x/ancho_bloque)!=0)&&(*(*(matriz+esquina_sup_der.y/alto_bloque)+esquina_sup_der.x/ancho_bloque)!=0)&&(*(*(matriz+esquina_inf_der.y/alto_bloque)+esquina_inf_der.x/ancho_bloque)!=0)&&(*(*(matriz+esquina_inf_izq.y/alto_bloque)+esquina_inf_izq.x/ancho_bloque)!=0)){
        this->setPosition(Coordenadas+velocidad_eje_x);
        this->Coordenadas=this->getPosition();

    }



    /////velocidades
    this->velocidad_eje_x={0,0};

    if (this->velocidad_eje_y.y<=0){

        this->velocidad_eje_y.y+=3;;
    }

    if (this->draw_bala==true){
        for (int i=0;i<this->proyectiles.size();i++){
            proyectiles.at(i)->update();
            win->draw(*proyectiles.at(i));
        }
    }


}

void Personaje::disparar(){
    sf::Time t1;
    t1= sf::seconds(0.3);
    if (this->velocidad_ataque->getElapsedTime()>t1){
        this->velocidad_ataque->restart();
        Proyectil * nuevo= new Proyectil("bala2.png",30,30,evento,win,Coordenadas);
        this->proyectiles.push_back(nuevo);
    }
}
Personaje::Personaje()
{
    //ctor
}

Personaje::~Personaje()
{
    //dtor
}
