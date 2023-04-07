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
    
}

void Sistema::mostrarHabitats(){
    unordered_map<int, Habitat*>::iterator itMap;
    for(itMap = this->mapaHabitats.begin(); itMap != this->mapaHabitats.end(); ++itMap){
        cout << "ID: " << itMap->first << endl;
        cout << "Habitat " << itMap->second->getTipoHabitat() << " con " << itMap->second->getContAnimal() << endl;
    }

    
}