src = ./src
inc =./include
bin = ./bin
datos = ./datos
obj = ./obj
CPPFLAGS = -Wall -g  -I$(inc) -c


#makefile prov

all: $(bin)/testdiccionario $(bin)/letras

$(bin)/testdiccionario: $(obj)/testdiccionario.o $(obj)/Diccionario.o
	g++  $(obj)/testdiccionario.o  $(obj)/Diccionario.o -o $(bin)/testdiccionario

$(bin)/letras: $(obj)/letras.o $(obj)/Diccionario.o $(obj)/BolsaLetras.o $(obj)/ConjuntoLetras.o $(obj)/Letra.o
	g++  $(obj)/letras.o  $(obj)/Diccionario.o $(obj)/BolsaLetras.o $(obj)/ConjuntoLetras.o $(obj)/Letra.o -o $(bin)/letras

$(obj)/testdiccionario.o: $(inc)/Diccionario.h $(src)/testdiccionario.cpp
	g++ $(CPPFLAGS) $(src)/testdiccionario.cpp -o $(obj)/testdiccionario.o

$(obj)/letras.o: $(inc)/Diccionario.h $(inc)/BolsaLetras.h $(inc)/ConjuntoLetras.h $(inc)/Letra.h $(src)/letras.cpp
	g++ $(CPPFLAGS) $(src)/letras.cpp -o $(obj)/letras.o

$(obj)/Diccionario.o: $(inc)/Diccionario.h $(src)/Diccionario.cpp 
	g++ $(CPPFLAGS) $(src)/Diccionario.cpp -o $(obj)/Diccionario.o

$(obj)/Letra.o: $(inc)/Letra.h $(src)/Letra.cpp 
	g++ $(CPPFLAGS) $(src)/Letra.cpp -o $(obj)/Letra.o

$(obj)/ConjuntoLetras.o: $(inc)/ConjuntoLetras.h $(src)/ConjuntoLetras.cpp  $(inc)/BolsaLetras.h $(inc)/Letra.h
	g++ $(CPPFLAGS) $(src)/ConjuntoLetras.cpp -o $(obj)/ConjuntoLetras.o

$(obj)/BolsaLetras.o: $(inc)/BolsaLetras.h $(src)/BolsaLetras.cpp 
	g++ $(CPPFLAGS) $(src)/BolsaLetras.cpp -o $(obj)/BolsaLetras.o

documentacion:
	doxygen doc/doxys/Doxyfile
