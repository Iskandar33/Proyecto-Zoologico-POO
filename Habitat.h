#ifndef HABITAT_H
#define HABITAT_H

#include <string>
#include <iostream>
#include <unordered_map>
#include "Animal.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::unordered_map;
using std::make_pair;
using std::getline;

class Habitat{
protected:
    string tipoHabitat; //Lo que define si es Selvático, Desértico, etc. No es necesario la creación de subclases
                        /* debido a que la única diferencia entre los habitats, es el nombre, no hay ningun atributo
                        * que sea solo de cierto habitat o alguna función que sea única de un habitat en especifico
                        */
    int contAnimal; //Contador de animales para agregarlos al mapa
    unordered_map<int, Animal*> mapaAnimales; //Mapa de animales para tener los animales pertenecientes a un habitat

public:
    Habitat() = default;
    Habitat(string tipoHabitat);
    string getTipoHabitat();
    void agregarAnimal(Animal* pAnimal);
    int getContAnimal();
    void listarAnimales();

};
#endif