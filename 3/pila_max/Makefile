SRC = src
INC = include
OBJ = obj
BIN = bin
CXX = g++
CPPFLAGS = -Wall -g  -I$(INC) -c


all: clean $(BIN)/usopilas_max
# ************ Generación de documentación ******************
documentacion:
	doxygen doc/doxys/Doxyfile

	
# ************ Compilación de módulos ************
$(BIN)/usopilas_max: $(OBJ)/usopilas_max.o $(OBJ)/Pila_max.o $(OBJ)/cola.o
	$(CXX) -o $(BIN)/usopilas_max $(OBJ)/usopilas_max.o $(OBJ)/Pila_max.o $(OBJ)/cola.o 

$(OBJ)/usopilas_max.o : $(INC)/Pila_max.h $(INC)/cola.h 
	$(CXX) $(CPPFLAGS) -o $(OBJ)/usopilas_max.o $(SRC)/usopilas_max.cpp

$(OBJ)/Pila_max.o : $(INC)/Pila_max.h $(INC)/cola.h 
	$(CXX) $(CPPFLAGS) -o $(OBJ)/Pila_max.o $(SRC)/Pila_max.cpp

$(OBJ)/cola.o : $(INC)/cola.h 
	$(CXX) $(CPPFLAGS) -o $(OBJ)/cola.o $(SRC)/cola.cpp 


# ************ Limpieza ************
clean :
	-rm $(OBJ)/* $(SRC)/*~ $(INC)/*~ ./*~

mrproper : clean
	-rm $(BIN)/* doc/html/*
