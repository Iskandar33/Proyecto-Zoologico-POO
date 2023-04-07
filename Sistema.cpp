#include "Sistema.h"

void Sistema::añadirHabitat(){
    int opc;
    Habitat* pTempHabitat;
    
    cout << "Hay 4 hábitats posibles para crear, estos son:" << endl;
    cout << "1. Desértico \n2. Selvático \n3. Polar \n4.Acuático" << endl;
    cout << "Ingrese el hábitat deseado" << endl;
    cin >> opc;
    if(opc == 1){
        Desertico* pTempHabitat = new Desertico();
    }
    else if(opc == 2){
        Selvatico* pTempHabitat = new Selvatico();
    }
    else if(opc == 3){
        Polar* pTempHabitat = new Polar();
    }
    else{
        Acuatico* pTempHabitat = new Acuatico();
    }
    this->mapaHabitats.insert(make_pair(this->contHabitats, pTempHabitat));
    this->contHabitats++;
}

void Sistema::añadirAnimalHabitat(){
    int opc;
    Animal* pTempAnimal = this->crearAnimal();
    Habitat* habitatEscogido;
    this->mostrarHabitats();
    cout << "Ingrese el ID del habitat a escoger: " << endl;
    cin >> opc;
    habitatEscogido = this->mapaHabitats.find(opc)->second;
    habitatEscogido->agregarAnimal(pTempAnimal);
}

Animal* Sistema::crearAnimal(){
    Animal* pTempAnimal;
    string nombre, especie, habitatPertenece, tipoAlimentacion, comida;
    cout << "Ingrese el nombre: " << endl;
    cin.ignore();
    getline(cin, nombre, '\n');
    cout << "Ingrese la especie: " << endl;
    cin.ignore();
    getline(cin, especie, '\n');
    cout << "Ingrese el habitat al que pertenece: " << endl;
    cin.ignore();
    getline(cin, habitatPertenece, '\n');
    cout << "La alimentación va de la siguiente forma\n 1. Carnivoros\n2. Herviboros\n3. Omnivoros." << endl;
    cin.ignore();
    getline(cin, tipoAlimentacion, '\n');
    pTempAnimal = new Animal(nombre, especie, this->contAnimales, habitatPertenece, tipoAlimentacion);
    cout << "Ingrese 3 comidas que el animal coma según su alimentación: " << endl;
    for(int i = 0; i <= 3; i++){
        cout << "Ingrese la comida: " << endl;
        cin.ignore();
        getline(cin, comida, '\n');
        pTempAnimal->agregarComida(comida);
    }
    return pTempAnimal;
}

void Sistema::mostrarHabitats(){
    unordered_map<int, Habitat*>::iterator itMap;
    for(itMap = this->mapaHabitats.begin(); itMap != this->mapaHabitats.end(); ++itMap){
        cout << "ID: " << itMap->first << endl;
        cout << "Habitat " << itMap->second->getTipoHabitat() << " con " << itMap->second->getContAnimal() << " animales en este"<< endl;
    }
}

void Sistema::listarHabitats(){
    unordered_map<int, Habitat*>::iterator itMap;
    for(itMap = this->mapaHabitats.begin(); itMap != this->mapaHabitats.end(); ++itMap){
        cout << "ID: " << itMap->first << endl;
        cout << "Habitat " << itMap->second->getTipoHabitat() << " con " << itMap->second->getContAnimal() << " animales en este"<< endl;
        cout << "Los animales son: " << endl;
        itMap->second->listarAnimales();
    }
}