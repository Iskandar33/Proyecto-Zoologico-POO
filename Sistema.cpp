#include "Sistema.h"

void Sistema::añadirHabitat(){
    string habitat;
    int opc;
    Habitat* pTempHabitat;
    
    cout << "Hay 4 hábitats posibles para crear, estos son:" << endl;
    cout << "1. Desértico \n2. Selvático \n3. Polar \n4.Acuático" << endl;
    cout << "Ingrese el número del hábitat deseado" << endl;
    cin >> opc;
    habitat = cambiarIntHabitat(opc);
    pTempHabitat = new Habitat(habitat);
    this->mapaHabitats.insert(make_pair(this->contHabitats, pTempHabitat));
    this->contHabitats++;
}

string Sistema::cambiarIntHabitat(int opc){
    string habitat;
    try{
        if(opc == 1){
            habitat = "Desertico";
        }
        else if(opc == 2){
            habitat = "Selvatico";
        }
        else if(opc == 3){
            habitat = "Polar";
        }
        else if(opc == 4){
            habitat = "Acuatico";
        }
        else{
            throw(opc);
        }
    }
    catch(int opc2){
        cout << "El valor dado no es correcto, por favor ingrese de nuevo el dato: " << endl;
        cin >> opc;
    }
    return habitat;
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
    this->mapaAnimalesTotal.insert(make_pair(this->contAnimales, pTempAnimal));
}

Animal* Sistema::crearAnimal(){
    Animal* pTempAnimal;
    string nombre, especie, habitat, tipoAlimentacion, comida;
    int horasDormir, opc;
    cout << "Ingrese el nombre: " << endl;
    cin.ignore();
    getline(cin, nombre, '\n');
    cout << "Ingrese la especie: " << endl;
    cin.ignore();
    getline(cin, especie, '\n');
    cout << "1. Desértico \n2. Selvático \n3. Polar \n4.Acuático" << endl;
    cout << "Ingrese el número del habitat al que pertenece" << endl;
    cin >> opc;
    habitat = cambiarIntHabitat(opc);
    cout << "Ingrese el tipo de alimentación\n1. Carnivoros\n2. Herviboros\n3. Omnivoros." << endl;
    cin.ignore();
    getline(cin, tipoAlimentacion, '\n');
    cout << "Ingrese las horas que el animal debe de dormir: " << endl;
    cin >> horasDormir;
    pTempAnimal = new Animal(nombre, especie, this->contAnimales, habitat, tipoAlimentacion, horasDormir);
    cout << "Ingrese 3 comidas que el animal coma según su alimentación: " << endl;
    for(int i = 0; i < 3; i++){
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

void Sistema::ingresarAccionAnimal(){
    string accion;
    Animal* pTempAnimal;
    this->mostrarAnimalTotal();
    pTempAnimal = obtenerAnimalMap();
    cout << "Las acciones que puede realizar un animal son: " << endl;
    cout << "1. Comer.\n2. Jugar.\n3. Dormir." << endl;
    cout << "Ingrese el nombre de la acción a realizar: " << endl; 
    cin.ignore();
    getline(cin, accion, '\n');
    if(accion == "Comer"){
        pTempAnimal->comer(pTempAnimal);
    }
    else if(accion == "Jugar"){
        pTempAnimal->jugar(pTempAnimal);
    }
    else{
        pTempAnimal->dormir(pTempAnimal);
    }
}

void Sistema::mostrarAnimalTotal(){
    unordered_map<int, Animal*>::iterator itMap;
    cout << "Los animales en el zoologico son: " << endl;
    for(itMap = this->mapaAnimalesTotal.begin(); itMap != this->mapaAnimalesTotal.end(); ++itMap){
        cout << "ID:" << itMap->first << endl;
        cout << "Nombre: " << itMap->second->getNombre() << " Especie: " << itMap->second->getEspecie() << " Tipo de alimentación: " << itMap->second->getAlimentacion() << " habitat al que pertenece: " << itMap->second->getHabitatPertenece() << endl;
    }
}

Animal* Sistema::obtenerAnimalMap(){
    int opc;
    Animal* pTempAnimal;
    cout << "Ingrese el ID del animal a seleccionar: " << endl;
    cin >> opc;
    pTempAnimal = this->mapaAnimalesTotal.find(opc)->second;
    return pTempAnimal;
}

void Sistema::editarAlimentacion(){
    Animal* pTempAnimal;
    string opc;
    this->mostrarAnimalTotal();
    pTempAnimal = obtenerAnimalMap();
    cout << "¿Desea agregar o eliminar algún alimento?" << endl;
    cin.ignore();
    getline(cin, opc, '\n');
    if(opc == "Agregar"){
        string comida;
        cout << "Ingrese la comida: " << endl;
        cin.ignore();
        getline(cin, comida, '\n');
        pTempAnimal->agregarComida(comida);
    }
    else if(opc == "Eliminar"){
        int comidaEliminar;
        pTempAnimal->mostrarComida();
        cout << "Ingrese el ID de la comida a eliminar: " << endl;
        cin >> comidaEliminar;
        pTempAnimal->eliminarComida(comidaEliminar);
    }

}