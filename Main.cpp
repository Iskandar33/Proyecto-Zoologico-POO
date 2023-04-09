#include "Sistema.h"
#include "Habitat.h"
#include "Animal.h"

using std::cout;
using std::endl;
using std::cin;


void mostrarMenu(Sistema* sistemaZoologico){
    int opc = 0;
    do{
        cout << "\n**** Bienvenidos al Zoologico de Mariana ****\n";
        cout << "1. Añadir un habitat \n";
        cout << "2. Agregar un animal a un habitat\n";
        cout << "3. Listar los habitats junto a sus animales\n";
        cout << "4. Ingresarle una acción a un animal\n";
        cout << "5. Editar la alimentación de un animal\n";
        cout << "0. Salir\n" << endl;

        cin >> opc;

        switch(opc){
            case 1:
                sistemaZoologico->añadirHabitat();
                break;
            case 2:
                try{
                    sistemaZoologico->añadirAnimalHabitat();
                }
                catch(const std::runtime_error e){
                    cout << "SE PRESENTÓ UN ERROR: " << e.what() << endl;
                }
            case 3:
                sistemaZoologico->listarHabitats();
                break;
            case 4:
                try{
                    sistemaZoologico->ingresarAccionAnimal();
                }
                catch(std::invalid_argument e){
                    cout << "SE PRESENTÓ UN ERROR: " << e.what() << endl;
                }
                break;
            case 5:
                try{
                    sistemaZoologico->editarAlimentacion();
                }
                catch(const std::invalid_argument e){
                    cout << "SE PRESENTÓ UN ERROR: " << e.what() << endl;
                }
                break;
        }
    }while(opc != 0);
}

int main(){
    Sistema* pSistema = new Sistema();
    mostrarMenu(pSistema);

    delete pSistema;
    return 0;
}

