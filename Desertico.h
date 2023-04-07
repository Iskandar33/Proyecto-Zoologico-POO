#ifndef DESERTICO_H
#define DESERTICO_H

#include <string>
#include <iostream>
#include "Habitat.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;


class Desertico : public Habitat{
protected:
    

public:
    Desertico() = default;
    void agregarAnimal(Animal*);
    string getTipoHabitat();
    int getContAnimal();

};
#endif