
src = ./src
inc =./include
bin = ./bin
datos = ./datos
obj = ./obj
CPPFLAGS = -Wall -g  -I$(inc) -c


all: $(bin)/usodiccionario

$(bin)/usodiccionario: $(obj)/usodiccionario.o $(obj)/diccionario.o
	g++ $(CPPFLAGS) $(obj)/usodiccionario.o  $(obj)/diccionario.o -o  $(bin)/usodiccionario

$(obj)/usodiccionario.o: $(inc)/diccionario.h $(src)/usodiccionario.cpp
	g++ $(CPPFLAGS) $(src)/usodiccionario.cpp -o $(obj)/usodiccionario.o

$(obj)/diccionario.o: $(inc)/diccionario.h $(src)/diccionario.cpp
	g++ $(CPPFLAGS) $(src)/diccionario.cpp -o $(obj)/diccionario.o


documentacion:
	doxygen doc/doxys/Doxyfile

