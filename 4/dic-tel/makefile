
src = ./src
inc =./include
bin = ./bin
datos = ./datos
obj = ./obj
CPPFLAGS = -Wall -g  -I$(inc) -c


all: $(bin)/usodiccionario $(bin)/usoguia

$(bin)/usoguia : $(obj)/usoguia.o $(obj)/guiatlf.o
	g++  $(obj)/usoguia.o  $(obj)/guiatlf.o -o $(bin)/usoguia
$(obj)/usoguia.o: $(inc)/guiatlf.h $(src)/usoguia.cpp
	g++ $(CPPFLAGS) $(src)/usoguia.cpp -o $(obj)/usoguia.o
$(obj)/guiatlf.o: $(inc)/guiatlf.h $(src)/guiatlf.cpp 
	g++ $(CPPFLAGS) $(src)/guiatlf.cpp -o $(obj)/guiatlf.o

$(bin)/usodiccionario: $(obj)/usodiccionario.o $(obj)/diccionario.o $(obj)/data.o
	g++  $(obj)/usodiccionario.o  $(obj)/diccionario.o $(obj)/data.o -o  $(bin)/usodiccionario

$(obj)/usodiccionario.o: $(inc)/diccionario.h $(src)/usodiccionario.cpp
	g++ $(CPPFLAGS) $(src)/usodiccionario.cpp -o $(obj)/usodiccionario.o

$(obj)/diccionario.o: $(inc)/diccionario.h $(src)/diccionario.cpp $(inc)/data.h
	g++ $(CPPFLAGS) $(src)/diccionario.cpp -o $(obj)/diccionario.o

$(obj)/data.o: $(inc)/data.h $(src)/data.cpp
	g++ $(CPPFLAGS) $(src)/data.cpp -o $(obj)/data.o

documentacion:
	doxygen doc/doxys/Doxyfile

