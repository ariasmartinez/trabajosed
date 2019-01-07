src = ./src
inc =./include
bin = ./bin
datos = ./datos
obj = ./obj
CPPFLAGS = -Wall -g  -I$(inc) -c


#makefile prov

all:  $(bin)/letras $(bin)/cantidad_letras $(bin)/testdiccionario 

$(bin)/testdiccionario: $(obj)/testdiccionario.o $(obj)/Diccionario.o $(obj)/ConjuntoLetras.o $(obj)/Letra.o
	g++  $(obj)/testdiccionario.o  $(obj)/Diccionario.o $(obj)/ConjuntoLetras.o $(obj)/Letra.o -o $(bin)/testdiccionario

$(bin)/letras: $(obj)/letras.o $(obj)/Diccionario.o $(obj)/BolsaLetras.o $(obj)/ConjuntoLetras.o $(obj)/Letra.o 
	g++  $(obj)/letras.o  $(obj)/Diccionario.o $(obj)/BolsaLetras.o $(obj)/ConjuntoLetras.o $(obj)/Letra.o -o $(bin)/letras

$(bin)/cantidad_letras: $(obj)/cantidad_letras.o $(obj)/Letra.o $(obj)/Diccionario.o $(obj)/ConjuntoLetras.o
	g++  $(obj)/cantidad_letras.o  $(obj)/Diccionario.o $(obj)/ConjuntoLetras.o $(obj)/Letra.o -o $(bin)/cantidad_letras

$(obj)/testdiccionario.o: $(inc)/Diccionario.h $(inc)/ConjuntoLetras.h $(inc)/Letra.h $(src)/testdiccionario.cpp 
	g++ $(CPPFLAGS) $(src)/testdiccionario.cpp -o $(obj)/testdiccionario.o

$(obj)/letras.o: $(inc)/Diccionario.h $(inc)/BolsaLetras.h $(inc)/ConjuntoLetras.h $(inc)/Letra.h $(src)/letras.cpp
	g++ $(CPPFLAGS) $(src)/letras.cpp -o $(obj)/letras.o

$(obj)/cantidad_letras.o: $(inc)/Letra.h $(inc)/ConjuntoLetras.h $(inc)/Diccionario.h $(src)/cantidad_letras.cpp
	g++ $(CPPFLAGS) $(src)/cantidad_letras.cpp -o $(obj)/cantidad_letras.o

$(obj)/Diccionario.o: $(inc)/Diccionario.h $(inc)/ConjuntoLetras.h $(inc)/Letra.h $(src)/Diccionario.cpp 
	g++ $(CPPFLAGS) $(src)/Diccionario.cpp -o $(obj)/Diccionario.o

$(obj)/ConjuntoLetras.o: $(inc)/ConjuntoLetras.h $(src)/ConjuntoLetras.cpp $(inc)/Letra.h
	g++ $(CPPFLAGS) $(src)/ConjuntoLetras.cpp -o $(obj)/ConjuntoLetras.o

$(obj)/Letra.o: $(inc)/Letra.h $(src)/Letra.cpp 
	g++ $(CPPFLAGS) $(src)/Letra.cpp -o $(obj)/Letra.o

$(obj)/BolsaLetras.o: $(inc)/BolsaLetras.h $(src)/BolsaLetras.cpp $(inc)/ConjuntoLetras.h
	g++ $(CPPFLAGS) $(src)/BolsaLetras.cpp -o $(obj)/BolsaLetras.o



documentacion:
	doxygen doc/doxys/Doxyfile
