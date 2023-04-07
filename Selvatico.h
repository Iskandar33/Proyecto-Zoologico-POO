#ifndef SELVATICO_H
#define SELVATICO_H

#include <string>
#include <iostream>
#include "Habitat.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;


class Selvatico : public Habitat{
protected:
    

public:
    Selvatico() = default;
    void agregarAnimal(Animal*);
    string getTipoHabitat();
    int getContAnimal();

};
#endif