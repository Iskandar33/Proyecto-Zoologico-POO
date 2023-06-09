#include "Habitat.h"

string Habitat::getTipoHabitat(){
    return this->tipoHabitat;
}

Habitat::Habitat(string tipoHabitat)
        : tipoHabitat(tipoHabitat){}

/*
* Para agregar el animal al habitat
*/

void Habitat::agregarAnimal(Animal* pAnimal){
    if(pAnimal->getHabitatPertenece() == this->tipoHabitat){
        this->mapaAnimales.insert(make_pair(pAnimal->getId(), pAnimal));
        this->contAnimal++;
        cout << "El animal fue ingresado con exito." << endl;
    }
    else{
        cout << "El animal no pertenece a este habitat, por favor, intentelo de nuevo con el habitat correcto." << endl;
    }
}

int Habitat::getContAnimal(){
    return this->contAnimal;
}

/*
* Para imprimir a los animales
*/

void Habitat::listarAnimales(){
    unordered_map<int, Animal*>::iterator itMap;
    for(itMap = this->mapaAnimales.begin(); itMap != this->mapaAnimales.end(); ++itMap){
        cout << "ID:" << itMap->first << endl;
        cout << "Nombre: " << itMap->second->getNombre() << " Especie: " << itMap->second->getEspecie() << " Tipo de alimentación: " << itMap->second->getAlimentacion() << " habitat al que pertenece: " << itMap->second->getHabitatPertenece()<< endl;
    }
}