src = ./src
inc =./include
bin = ./bin
datos = ./datos
obj = ./obj
CPPFLAGS = -Wall -g  -I$(inc) -c


#makefile prov

all: $(bin)/testdiccionario

$(bin)/testdiccionario: $(obj)/testdiccionario.o $(obj)/Diccionario.o
	g++  $(obj)/testdiccionario.o  $(obj)/Diccionario.o -o $(bin)/testdiccionario

$(obj)/testdiccionario.o: $(inc)/Diccionario.h $(src)/testdiccionario.cpp
	g++ $(CPPFLAGS) $(src)/testdiccionario.cpp -o $(obj)/testdiccionario.o

$(obj)/Diccionario.o: $(inc)/Diccionario.h $(src)/Diccionario.cpp 
	g++ $(CPPFLAGS) $(src)/Diccionario.cpp -o $(obj)/Diccionario.o

$(obj)/Letra.o: $(inc)/Letra.h $(src)/Letra.cpp 
	g++ $(CPPFLAGS) $(src)/Letra.cpp -o $(obj)/Letra.o

$(obj)/ConjuntoLetras.o: $(inc)/ConjuntoLetras.h $(src)/ConjuntoLetras.cpp 
	g++ $(CPPFLAGS) $(src)/ConjuntoLetras.cpp -o $(obj)/ConjuntoLetras.o

$(obj)/BolsaLetras.o: $(inc)/BolsaLetras.h $(src)/BolsaLetras.cpp 
	g++ $(CPPFLAGS) $(src)/BolsaLetras.cpp -o $(obj)/BolsaLetras.o

documentacion:
	doxygen doc/doxys/Doxyfile
