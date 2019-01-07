_Celia Arias Martínez_  
_Lucía Salamanca López_  
# **Práctica Final**
---

## Introducción

La finalidad de esta práctica ha sido elaborar tres ejecutables, _letras_, _testdiccionario_ y *cantidad_letras*.  
 Para ello hemos necesitado implementar
cuatro módulos:  

* Letra
* ConjuntoLetras
* BolsaLetras
* Diccionario

## **Letra**

El TDA Letra es un objeto formado por tres elementos:
* Un `char` que representa el carácter de la letra
* Un `int` que representa la cantidad de veces que puede aparecer
* Un `double` que representa la puntuación de la letra


En la clase `Letra` tenemos dos constructores: el de por defecto y uno a partir de un `char`, un `int` y un `double`. También tenemos tres métodos que modifican los elementos de la clase y tres métodos que observan dichos elementos.

También tenemos un operador `<` que devuelve un booleano indicando si una letra es menor que otra léxicamente y dos operadores `>>` y `<<` para leer y escribir en el flujo de entrada o salida.


## **ConjuntoLetras**

El TDA ConjuntoLetras es un `set<Letra>`.

Vamos a comentar los métodos más relevantes dentro de esta clase:

~~~c++
set<Letra>::iterator BuscarLetra(char letra) const;
~~~

Su función es devolver un iterador apuntando al tipo de dato `Letra` cuyo campo `carac` coincida con el `char` letra. Para ello recorremos el `ConjuntoLetras` que lo invoca y comparamos cada `Letra` con `letra`.

~~~c++
bool leerDeFichero(const char *fichero);
~~~

Su función es modificar el `ConjuntoLetras` que lo invoca para que tenga los valores guardados en el fichero `fichero`. Hace uso del operador `>>`.

~~~c++
int Puntuacion(string palabra);
~~~

Su función es asignar una puntuación a una palabra dependiendo de los valores guardados en el campo `Puntuación` para cada una de sus letras. Para ello recorremos cada letra de la palabra, buscamos la letra en `ConjuntoLetras` y si la letra existe sumamos la puntuación de esa letra a la puntuación total.

~~~c++
pair<int,set<string> > MejoresPalabras(const set<string> & palabras, char modo)
~~~
Este método busca entre las palabras que le pasamos en el `set<string> palabras`  y devuelve solo las mejores según el modo que le pasemos. Para ello


### _testdiccionario_

En este programa leemos de un fichero un diccionario.  Cuando hemos cargado el diccionario le pedimos al usuario una longitud para así mostrar por pantalla las palabras con dicha longitud incluidas en el diccionario.  
En segundo lugar se le pide al usuario una palabra para comprobar si dicha palabra se encuentra en el diccionario.
