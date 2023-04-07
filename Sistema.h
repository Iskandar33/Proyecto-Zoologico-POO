#ifndef SISTEMA_H
#define SISTEMA_H

#include <string>
#include <iostream>
#include "Habitat.h"
#include "Acuatico.h"
#include "Desertico.h"
#include "Polar.h"
#include "Selvatico.h"
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
    int contHabitats;
    unordered_map<int, Habitat*> mapaHabitats;
    
public:
    Sistema() = default;
    void añadirHabitat();
    void añadirAnimalHabitat();
    void mostrarHabitats();
    void listarHabitats();
    void ingresarAccionAnimal();

};
#endif