# Proyecto-Zoologico-POO
#### Proyecto 1 POO	

Para compilar y ejecutar el proyecto:   
    **make**  //Compila el proyecto en base un makefile creado  
    **./papu** //Ejecuta el ejecutable creado de la instrucción anterior.
    
La funcionalidad del makefile es compilar los 4 .cpp y que se genere un ejecutable de forma rápida y con un solo comando(en el terminal).

## ***Resumen de las funciones***
Este Zoológico deja actuar con bastante **libertad al usuario**, al no haber predefinido animales, el usuario puede agregar un pez y hacer que este viva en un desierto, según como haya ingresado la información de su hábitat perteneciente, de esta forma, es según el usuario, como se le da uso a este Zoológico.

### ***Funcionalidades del zoológico***
Menú principal del Zoológico

![menuZoo.png](/Imagenes/menuZoo.png)

Las opciones se mostraran a continuación: 

### ***Añadir Hábitat***
Se le pregunta al usuario que hábitat desea crear de los 4 hábitats posibles

![opcion1.png](/Imagenes/opcion1.png)

### ***Agregar un Animal a un Hábitat***
En esta opción, se crea primero un Animal con los datos que se le ingresan como se puede ver a continuación

![crearAnimal.png](/Imagenes/crearAnimal.png)

Luego, se procede a preguntar en que hábitat se desea guardar

![guardarAnimal.png](/Imagenes/guardarAnimal.png)

### ***Listar los hábitats y sus animales***
En esta opción, se muestra cada hábitat con los animales que tienen guardados

![listarHabitats.png](/Imagenes/listarHabitats.png)

### ***Darle una orden a un animal***
En esta opción se procede a escoger un animal del zoológico, para luego darle una orden(comer, dormir o jugar)

Elección del animal

![eleccionAnimal.png](/Imagenes/eleccionAnimal.png)

Menú de ordenes

![menuOrdenes.png](/Imagenes/menuOrdenes.png)

Después, según la orden, se procede a hacer lo pedido

**Comer**
Menú para escoger la comida

![menuComidas.png](/Imagenes/menuComidas.png)

Luego de comer

![finComida.png](/Imagenes/finComida.png)

**Jugar**
Al escoger la opción jugar, se procede a dar un mensaje del animal jugando

![mensajeJugar.png](/Imagenes/mensajeJugar.png)

**Dormir**
Al escoger la opción de dormir, se le pide al usuario las horas que el animal debe dormir, tienen que ser más de las horas mínimas para que el animal pueda dormir sino, se le notifica que las horas ingresadas es menor a las horas mínimas

![dormirBien.png](/Imagenes/dormirBien.png)

Notificación de horas menores a las mínimas

![dormirMal.png](/Imagenes/dormirMal.png)

### ***Editar la alimentación de un animal***
Al escoger esta opción, se escogera un animal del zoológico como en el punto anterior, después de esto aparecerá un minimenú para escoger si agregar alguna comida o eliminar

![miniMenuComida.png](/Imagenes/miniMenuComida.png)

***Agregar***
Al escoger agregar, se pide el nombre de la comida a agregar, para luego agregarla a la dieta del animal

![agregarComida.png](/Imagenes/agregarComida.png)

Prueba de que agregó

![comidaAgregada.png](/Imagenes/comidaAgregada.png)

***Eliminar***
Al escoger eliminar, se pide al usuario que ingrese el número de la comida a eliminar, luego se procede a eliminarse de la dieta del animal

![eliminarComida](/Imagenes/eliminarComida.png)

***Diagrama UML***
![UML](/Imagenes/imagen.jpg)

