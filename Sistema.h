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
    unordered_map<int, Animal*> mapaAnimales;
    
public:
    Sistema() = default;
    void añadirHabitat();
    void añadirAnimalHabitat();
    void listarHabitats();
    void ingresarAccionAnimal();

};
#endif