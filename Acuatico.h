#ifndef ACUATICO_H
#define ACUATICO_H

#include <string>
#include <iostream>
#include "Habitat.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;


class Acuatico : public Habitat{
protected:
    

public:
    Acuatico() = default;
    Habitat* crearHabitat(int opc) override;


};
#endif