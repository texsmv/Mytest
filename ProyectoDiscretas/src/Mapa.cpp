#include "Mapa.h"
#include <vector>


Mapa::Mapa( float alto, float ancho,std::string nombres[],int num_imagenes ,int filas, int columnas, int**matriz, sf::RenderWindow*win)
{
    this-> columnas=columnas;
    this-> filas=filas;
    this-> ancho=ancho;
    this-> alto=alto;
    this-> Matriz=matriz;
    this->imagenes=nombres;
    this->num_imagenes=num_imagenes;
    this->win=win;

    sf::Texture * texturas[num_imagenes];
    images=new sf::Sprite*[num_imagenes];

    for(int i=0;i<num_imagenes;i++){
        texturas[i]=new sf::Texture;
        images[i]=new sf::Sprite;
        if(!texturas[i]->loadFromFile(*(imagenes+i)))
            std::cout<<"No se pudo cargar la imagen personaje"<<std::endl;
        images[i]->setTexture(*(texturas[i]));
    }
}

void Mapa::dibujar()
{




    for (int i=0;i<filas;i++){
        for (int j=0;j<columnas;j++){
            for (int k=0;k<num_imagenes;k++){

                if(*(*(Matriz+i)+j)==k){

                    images[k]->setPosition(j*alto,i*ancho);
                    win->draw(*(images[k]));
                }
            }
        }
    }


}

Mapa::~Mapa()
{
    //dtor
}
