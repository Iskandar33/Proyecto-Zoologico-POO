#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>
#include "Habitat.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Animal{
protected:
    string nombre;
    string especie;
    Habitat* pHabitat;
    int id;
    string habitatPertenece;
    int tipoAlimentacion;

public:
    Animal() = default;
    void comer(Habitat* habitatAn, int idAn, string nombreAcc);
    void jugar(Habitat* habitatAn, int idAn, string nombreAcc);
    void dormir(Habitat* habitatAn, int idAn, string nombreAcc);

};
#endif