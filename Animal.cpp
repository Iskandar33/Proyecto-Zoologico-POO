#include "Animal.h"

Animal::Animal(string nombre, string especie, int id, string habitatPertenece, string tipoAlimentacion, int horasDormir)
        : nombre(nombre), especie(especie), id(id), habitatPertenece(habitatPertenece), tipoAlimentacion(tipoAlimentacion), horasDormir(horasDormir){}

int Animal::getId(){
        return this->id;
}

string Animal::getHabitatPertenece(){
        return this->habitatPertenece;
}

string Animal::getNombre(){
        return this->nombre;
}

string Animal::getEspecie(){
        return this->especie;
}

string Animal::getAlimentacion(){
        return this->tipoAlimentacion;
}

int Animal::getHorasDormir(){
        return this->horasDormir;
}

void Animal::agregarComida(string comida){
        this->mapaComidas.insert(make_pair(this->contComida, comida));
        this->contComida++;
}

/*
* Para decidir la comida y darsela
*/
void Animal::comer(Animal* pAnimal){
        int opc;
        cout << "Se mostrará las comidas que puede escoger para alimentar al animal." << endl;
        pAnimal->mostrarComida();
        cout << "Seleccione mediante el ID, la comida que desea darle: " << endl;
        cin >> opc;
        if(this->mapaComidas.find(opc) == this->mapaComidas.end()){
                throw std::invalid_argument("El dato ingresado no esta en el mapa");
        }
        else{
                cout << "El animal fue alimentado con " << this->mapaComidas.find(opc)->second;
        }
}

/*
* Para mostrar la comida que tiene el animal en su dieta
*/

void Animal::mostrarComida(){
        unordered_map<int, string>::iterator itMap;
        for(itMap = this->mapaComidas.begin(); itMap != this->mapaComidas.end(); ++itMap){
                cout << "ID:" << itMap->first << endl;
                cout << itMap->second << endl;
        }
}

/*
* Para verificar si el animal ya jugó y si no es así, jugar
*/

void Animal::jugar(Animal* pAnimal){
        if(this->verificadorJugar == 1){
                cout << "El animal ya jugó hoy por lo que esta cansado y no puede jugar más." << endl;
        }
        else{
                cout << "El animal jugó mucho a Overwatchgod y se volvió top 500" << endl;
                this->verificadorJugar = 1;
        }
}

/*
* Para verificar las horas que se escojan para que el animal duerma, si son suficientes que duerma sino, que se notifique
*/

void Animal::dormir(Animal* pAnimal){
        int horas;
        cout << "Ingrese las horas que el animal va a dormir: " << endl;
        cin >> horas;
        if(horas < this->horasDormir){
                cout << "El animal debe de dormir más horas" << endl;
                cout << "Las horas mínimas que el animal duerme son " << this->getHorasDormir() << endl;
        }
        else{
                cout << "El animal durmió placidamente." << endl;
        }
}

/*
* Para eliminar la comida que se escogió
*/

void Animal::eliminarComida(int eliminar){
        if(this->mapaComidas.find(eliminar) == this->mapaComidas.end()){
                throw std::invalid_argument("El dato ingresado no esta en el mapa de comidas");
        }
        else{
                cout << "Se eliminará la comida seleccionada." << endl;
                this->mapaComidas.erase(eliminar);
                cout << "La comida fue eliminada.";
        }
}
