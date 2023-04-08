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
    string tipoHabitat;
    int contAnimal;
    unordered_map<int, Animal*> mapaAnimales;

public:
    Habitat() = default;
    Habitat(string tipoHabitat);
    string getTipoHabitat();
    void agregarAnimal(Animal* pAnimal);
    int getContAnimal();
    void listarAnimales();

};
#endif