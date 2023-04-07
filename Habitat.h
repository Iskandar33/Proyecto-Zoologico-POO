#ifndef HABITAT_H
#define HABITAT_H

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

class Habitat{
protected:
    string tipoHabitat;
    int contAnimal;
    

public:
    Habitat() = default;
    virtual Habitat* crearHabitat(int opc) = 0;
    virtual string getTipoHabitat() = 0;
    virtual int getContAnimal() = 0;


};
#endif