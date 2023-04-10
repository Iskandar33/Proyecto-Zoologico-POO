# Proyecto-Zoologico-POO
#### Proyecto 1 POO	

Para compilar y ejecutar el proyecto:   
    **make**  //Compila el proyecto en base un makefile creado  
    **./papu** //Ejecuta el ejecutable creado de la instrucción anterior.
    
La funcionalidad del makefile es compilar los 4 .cpp y que se genere un ejecutable de forma rápida y con un solo comando(en el terminal).

## ***Resumen de las funciones***
Este Zoológico deja actuar con bastante **libertad al usuario**, al no haber predefinido animales, el usuario puede agregar un pez y hacer que este viva en un desierto, de esta forma, es según el usuario, como se le da uso a este Zoológico.

### ***Funcionalidades del zoológico***
Menú principal del Zoológico:
![menuZoo](/Imagenes/menuZoo.png)

Las opciones se mostraran a continuación: 

### ***Añadir Hábitat***
Se le pregunta al usuario que hábitat desea crear de los 4 hábitats posibles.
![opcion1](/Imagenes/opcion1.png)

### ***Agregar un Animal a un Hábitat***
En esta opción, se crea primero un Animal con los datos que se le ingresan como se puede ver a continuación
![crearAnimal](/Imagenes/crearAnimal.png)
Luego, se procede a preguntar en que hábitat se desea guardar
![guardarAnimal](/Imagenes/guardarAnimal.png)

### ***Listar los hábitats y sus animales***
En esta opción, se muestra cada hábitat con los animales que tienen guardados
![listarHabitats](/Imagenes/listarHabitats.png)

### ***Darle una orden a un animal***
En esta opción se procede a escoger un animal del zoológico, para luego darle una orden(comer, dormir o jugar)
Elección del animal
![eleccionAnimal](/Imagenes/eleccionAnimal.png)
Menú de ordenes
![menuOrdenes](/Imagenes/menuOrdenes.png)
Después, según la orden, se procede a hacer lo pedido
**Comer**
    Menú para escoger la comida
    ![menuComidas](/Imagenes/menuComidas.png)
    Luego de comer
    ![finComida](/Imagenes/finComida.png)
**Jugar**
    Al escoger la opción jugar, se procede a dar un mensaje del animal jugando
    ![mensajeJugar](/Imagenes/mensajeJugar.png)

**Dormir**
    Al escoger la opción de dormir, se le pide al usuario las horas que el animal debe dormir, tienen que ser más de las horas mínimas para que el animal pueda dormir sino, se le notifica que las horas ingresadas es menor a las horas mínimas
    ![dormirBien](/Imagenes/dormirBien.png)
    Notificación de horas menores a las mínimas
    ![dormirMal](/Imagenes/dormirMal.png)



***Diagrama UML***
![UML](/Imagenes/imagen.jpg)

