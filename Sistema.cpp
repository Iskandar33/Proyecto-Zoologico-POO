#include "Sistema.h"

/*
* Para crear y añadir el habitat al sistema
*/

void Sistema::añadirHabitat(){
    string habitat;
    int opc;
    Habitat* pTempHabitat;
    
    cout << "Hay 4 hábitats posibles para crear, estos son:" << endl;
    cout << "1. Desértico \n2. Selvático \n3. Polar \n4. Acuático" << endl;
    cout << "Ingrese el número del hábitat deseado" << endl;
    cin >> opc;
    try{
        habitat = cambiarIntHabitat(opc);
        pTempHabitat = new Habitat(habitat);
        this->mapaHabitats.insert(make_pair(this->contHabitats, pTempHabitat));
        this->contHabitats++;
        cout << "El habitat fue añadido." << endl;
    }
    catch(const std::invalid_argument e){
        cout << "SE PRESENTÓ UN ERROR: " << e.what() << endl;
    }
    
}

/*
* Para saber que habitat se escogió
*/

string Sistema::cambiarIntHabitat(int opc){
    string habitat;
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
        throw std::invalid_argument("Se ingresó un dato erroneo.");
    }
    return habitat;
}

/*
* Primero se crea un animal y luego se añade al habitat escogido
*/

void Sistema::añadirAnimalHabitat(){
    int opc;
    Animal* pTempAnimal = this->crearAnimal();
    Habitat* habitatEscogido;
    this->mostrarHabitats();
    cout << "Ingrese el ID del habitat a escoger: " << endl;
    cin >> opc;
    if(this->mapaHabitats.find(opc) == this->mapaHabitats.end()){
        throw std::runtime_error("El elemento ingresado no esta en el mapa.");
    }
    else{
        habitatEscogido = this->mapaHabitats.find(opc)->second;
        habitatEscogido->agregarAnimal(pTempAnimal);
        this->mapaAnimalesTotal.insert(make_pair(this->contAnimales, pTempAnimal));
        this->contAnimales++;
        cout << "dx" << endl;
    }
}

/*
* Para crear al animal y tenerlo a la mano para lo otro que se necesita de él
*/

Animal* Sistema::crearAnimal(){
    Animal* pTempAnimal;
    string nombre, especie, habitat, tipoAlimentacion, comida;
    int horasDormir, opc;
    cout << "Ingrese el nombre: " << endl;
    cin.ignore();
    getline(cin, nombre, '\n');
    cout << "Ingrese la especie: " << endl;
    fflush;
    cin.ignore();
    getline(cin, especie, '\n');
    cout << "1. Desértico \n2. Selvático \n3. Polar \n4.Acuático" << endl;
    cout << "Ingrese el número del habitat al que pertenece" << endl;
    cin >> opc;
    habitat = cambiarIntHabitat(opc);
    cout << "Ingrese las horas que el animal debe de dormir: " << endl;
    cin >> horasDormir;
    cout << "Ingrese el tipo de alimentación\n1. Carnivoros\n2. Herviboros\n3. Omnivoros." << endl;
    fflush;
    cin.ignore();
    getline(cin, tipoAlimentacion, '\n');
    pTempAnimal = new Animal(nombre, especie, this->contAnimales, habitat, tipoAlimentacion, horasDormir);
    cout << "Ingrese 3 comidas que el animal coma según su alimentación: " << endl;
    for(int i = 0; i < 3; i++){
        cout << "Ingrese la comida: " << endl;
        fflush;
        cin.ignore();
        getline(cin, comida, '\n');
        pTempAnimal->agregarComida(comida);
    }
    return pTempAnimal;
}

/*
* Para mostrar los habitats solamente
*/

void Sistema::mostrarHabitats(){
    unordered_map<int, Habitat*>::iterator itMap;
    for(itMap = this->mapaHabitats.begin(); itMap != this->mapaHabitats.end(); ++itMap){
        cout << "ID: " << itMap->first << endl;
        cout << "Habitat " << itMap->second->getTipoHabitat() << " con " << itMap->second->getContAnimal() << " animales en este"<< endl;
    }
}

/*
* Para mostrar los habitats junto a sus animales
*/

void Sistema::listarHabitats(){
    if(this->mapaHabitats.size() == 0){
        cout << "No hay habitats en el zoologico aún." << endl;
    }
    else{
        unordered_map<int, Habitat*>::iterator itMap;
        for(itMap = this->mapaHabitats.begin(); itMap != this->mapaHabitats.end(); ++itMap){
            cout << "ID: " << itMap->first << endl;
            cout << "Habitat " << itMap->second->getTipoHabitat() << " con " << itMap->second->getContAnimal() << " animales en este"<< endl;
            cout << "Los animales son: " << endl;
            itMap->second->listarAnimales();
        }
    }
}

/*
* Para poder ingresar e invocar a la función que se requiera según la opción escogida
*/

void Sistema::ingresarAccionAnimal(){
    if(this->mapaAnimalesTotal.size() == 0){
        cout << "No hay animales en el zoologico actualmente." << endl;
    }
    else{
        int accion;
        Animal* pTempAnimal;
        this->mostrarAnimalTotal();
        try{
            pTempAnimal = obtenerAnimalMap();
            cout << "Las acciones que puede realizar un animal son: " << endl;
            cout << "1. Comer.\n2. Jugar.\n3. Dormir." << endl;
            cout << "Ingrese el número de la acción a realizar: " << endl; 
            cin >> accion;
            if(accion == 1){
                pTempAnimal->comer(pTempAnimal);
            }
            else if(accion == 2){
                pTempAnimal->jugar(pTempAnimal);
            }
            else if(accion == 3){
                pTempAnimal->dormir(pTempAnimal);
            }
            else{
                throw std::invalid_argument("Se ingresó un dato erroneo.");
            }
        }
        catch(const std::runtime_error e){
            cout << "SE PRESENTÓ UN ERROR: " << e.what() << endl;
        }
        
    }
}

/*
* Para mostrar a los animales en el mapa de animales del sistema
*/

void Sistema::mostrarAnimalTotal(){
    unordered_map<int, Animal*>::iterator itMap;
    cout << "Los animales en el zoologico son: " << endl;
    for(itMap = this->mapaAnimalesTotal.begin(); itMap != this->mapaAnimalesTotal.end(); ++itMap){
        cout << "ID:" << itMap->first << endl;
        cout << "Nombre: " << itMap->second->getNombre() << " Especie: " << itMap->second->getEspecie() << " Tipo de alimentación: " << itMap->second->getAlimentacion() << " habitat al que pertenece: " << itMap->second->getHabitatPertenece() << endl;
    }
}

/*
* Para obtener al animal del mapa del sistema con try
*/

Animal* Sistema::obtenerAnimalMap(){
    Animal* pTempAnimal;
    if(this->mapaAnimalesTotal.size() == 0){
        cout << "No hay animales en el zoologico actualmente." << endl;
    }
    else{
        int opc;
        cout << "Ingrese el ID del animal a seleccionar: " << endl;
        cin >> opc;
        if(this->mapaHabitats.find(opc) == this->mapaHabitats.end()){
            throw std::runtime_error("El elemento ingresado no esta en el mapa.");
        }
        else{
            pTempAnimal = this->mapaAnimalesTotal.find(opc)->second;
        }       
    } 
    return pTempAnimal;
}

/*
* Para invocar a la función requerida según la elección
*/

void Sistema::editarAlimentacion(){
    if(this->mapaAnimalesTotal.size() == 0){
        cout << "No hay animales en el zoologico aún." << endl;
    }
    else{
        Animal* pTempAnimal;
        int opc;
        this->mostrarAnimalTotal();
        try{
            pTempAnimal = obtenerAnimalMap();
        }
        catch(const std::runtime_error e){
            cout << "SE PRESENTÓ UN ERROR: " << e.what() << endl;
        }
        cout << "1. Agregar alimento\n2. Eliminar alimento" << endl;
        cin >> opc;
        if(opc == 1){
            string comida;
            cout << "Ingrese la comida: " << endl;
            cin.ignore();
            fflush;
            getline(cin, comida, '\n');
            pTempAnimal->agregarComida(comida);
        }
        else if(opc == 2){
            int comidaEliminar;
            pTempAnimal->mostrarComida();
            cout << "Ingrese el ID de la comida a eliminar: " << endl;
            cin >> comidaEliminar;
            try{
                pTempAnimal->eliminarComida(comidaEliminar);
            }
            catch(const std::invalid_argument e){
                cout << "SE PRESENTÓ UN ERROR: " << e.what() << endl;
            }
        }
        else{
            throw std::invalid_argument("Se ingresó un dato erroneo.");
        }
    }
}