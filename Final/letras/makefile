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

documentacion:
	doxygen doc/doxys/Doxyfile
