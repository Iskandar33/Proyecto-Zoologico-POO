#include "Animal.h"

Animal::Animal(string nombre, string especie, int id, string habitatPertenece, string tipoAlimentacion, int horasDormir)
        : nombre(nombre), especie(especie), id(id), habitatPertenece(habitatPertenece), tipoAlimentacion(tipoAlimentacion), horasDormir(horasDormir){}

int Animal::getId(){
        return this->id;
}

string Animal::getHabitatPertenece(){
        return this->habitatPertenece;
}

string Animal::getNombre(){
        return this->nombre;
}

string Animal::getAlimentacion(){
        return this->tipoAlimentacion;
}

void Animal::agregarComida(string comida){
        this->mapaComidas.insert(make_pair(this->contComida, comida));
        this->contComida++;
}