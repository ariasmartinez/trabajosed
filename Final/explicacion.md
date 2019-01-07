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
* Dos `int`:
  * Uno representa la cantidad de veces que puede aparecer.
  * Otro que representa la puntuación de la letra.

En la clase `Letra` tenemos dos constructores: el de por defecto y uno a partir de un `char` y dos `int`. También tenemos tres métodos que modifican los elementos de la clase y tres métodos que observan dichos elementos.

También tenemos un operador `<` que devuelve un booleano indicando si una letra es menor que otra léxicamente y dos operadores `>>` y `<<` para leer y escribir en el flujo de entrada o salida.


## **ConjuntoLetras**

El TDA ConjuntoLetras es un `set<Letra>` como su propio nombre indica.

Vamos a comentar los métodos más relevantes dentro de esta clase:

~~~c++
set<Letra>::iterator BuscarLetra(char letra) const;
~~~







// Esto no se si lo ponemos después de explicar cada método

### _testdiccionario_

En este programa leemos de un fichero un diccionario.  Cuando hemos cargado el diccionario le pedimos al usuario una longitud para así mostrar por pantalla las palabras con dicha longitud incluidas en el diccionario.  
En segundo lugar se le pide al usuario una palabra para comprobar si dicha palabra se encuentra en el diccionario.
