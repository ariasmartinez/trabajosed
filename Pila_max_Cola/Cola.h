
/**
Cola<T>
TDA queue::queue, empty, clear, front, push, pop, size,
swap, ~queue
Cada objeto del TDA cola, modela una cola de elementos
de la clase T.
Una cola es un tipo particular de secuencia en la que los
elementos se insertan por un extremo (final) y se
consultan y suprimen por el otro (frente). Son secuencias
del tipo FIFO (First In, First Out).
Son objetos mutables. Residen en memoria dinámica.
*/

/**
@brief Constructor primitivo.
Crea una cola vacía
*/
Cola();

/**
@brief Constructor de copia.
@param c: cola que se copia.
Crea una cola que es copia de c.
*/
Cola(const Cola<T> & c);

/**
@brief Destructor.
@post El receptor es MODIFICADO.
El receptor es destruido liberando todos los
recursos que usaba.
*/
~Cola();
/**
@brief Informa si la cola está vacía.
@return true, si la cola está vacía.
false, en otro caso.
*/
bool vacia() const;
/**
@brief Borra todos los elementos del contenedor.
Deja el contenedor completamente vacío.
*/
void borrar();

/**
@brief Acceso al elemento al principio de la cola.
@pre El receptor no puede estar vacío.
@return Referencia al elemento en el frente de la cola.
*/
T & primerElemento ();
/**
@brief Acceso al elemento al principio de la cola.
@pre El receptor no puede estar vacío.
@return Referencia constante al frente de la cola.
*/
const T & primerElemento () const;

/**
@brief Añade un elemento en la cola.
@param elem: Elemento que se inserta.
Inserta un nuevo elemento al end de la cola.
*/
void aniadir (const T & elem);
/**
@brief Quita un elemento de la cola.
@pre El receptor no puede estar vacío.
Elimina el elemento en el frente de la cola.
*/
void quitar();
/**
@brief Obtiene el número de elementos en la cola.
@return número de elementos incluidos en la cola.
*/
size_type size() const;
/**
@brief Intercambia el contenido del receptor y argumento.
@param c: cola a intercambiar con el receptor.
ES MODIFICADO.
Asigna el contenido del receptor al del parámetro y
viceversa.
*/
void intercambiar (queue<T> & c);
