#ifndef POLAR_H
#define POLAR_H

#include <string>
#include <iostream>
#include "Habitat.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;


class Polar : public Habitat{
protected:
    

public:
    Polar() = default;
    Habitat* crearHabitat(int opc) override;


};
#endif