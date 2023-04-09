#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>
#include <unordered_map>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::unordered_map;

class Animal{
protected:
    string nombre;
    string especie;
    int id; 
    string habitatPertenece;
    string tipoAlimentacion;
    int horasDormir;
    int verificadorJugar;
    int contComida;
    unordered_map<int, string> mapaComidas; //Mapa para guardar las comidas

public:
    Animal() = default;
    Animal(string nombre, string especie, int id, string habitatPertenece, string tipoAlimentacion, int horasDormir);
    int getId();
    string getHabitatPertenece();
    string getNombre();
    string getAlimentacion();
    string getEspecie();
    void agregarComida(string comida);
    void comer(Animal* pAnimal);
    void mostrarComida();
    void jugar(Animal* pAnimal);
    void dormir(Animal* pAnimal);
    int getHorasDormir();
    void eliminarComida(int eliminar);
};
#endif