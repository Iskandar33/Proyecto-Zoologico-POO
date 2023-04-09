#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include <iostream>
#include "Habitat.h"
#include "Animal.h"
#include <unordered_map>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::unordered_map;
using std::make_pair;
using std::getline;



class Sistema{
protected:
    int contHabitats; //Contador para agregar los habitats
    int contAnimales; //Contador para agregar los animales
    unordered_map<int, Animal*> mapaAnimalesTotal; //Mapa de animales para acceder a los animales de forma rápida sin tener que acceder a cada habitat
    unordered_map<int, Habitat*> mapaHabitats;  //Mapa de habitats
    
public:
    Sistema() = default;
    void añadirHabitat();
    string cambiarIntHabitat(int opc);
    void añadirAnimalHabitat();
    Animal* crearAnimal();
    void mostrarHabitats();
    void listarHabitats();
    void ingresarAccionAnimal();
    void mostrarAnimalTotal();
    void editarAlimentacion();
    Animal* obtenerAnimalMap();

};
#endif