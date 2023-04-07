#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>
#include <unordered_map>
#include "Habitat.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Animal{
protected:
    string nombre;
    string especie;
    int id;
    string habitatPertenece;
    string tipoAlimentacion;
    int horasDormir;
    int verificadorJugar;
    int contComida;
    unordered_map<int, string> mapaComidas;

public:
    Animal() = default;
    Animal(string nombre, string especie, int id, string habitatPertenece, string tipoAlimentacion, int horasDormir);
    int getId();
    string getHabitatPertenece();
    string getNombre();
    string getAlimentacion();
    void agregarComida(string comida);
    void comer(Animal* pAnimal);
    void mostrarComida();
    void jugar(Animal* pAnimal);
    void dormir(Animal* pAnimal);
    int getHorasDormir();
};
#endif