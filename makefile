# Makefile for Electric Field Simulator
# Henry J Schmale
# March 11, 2015

# Compiler Settings
CPP=g++
CPP_FLGS=
LD_FLGS=-liniparser

# Code Settings
SRC=$(shell find . -regextype sed -regex ".*/.*.cpp")
OBJ=$(SRC:.cpp=.o)
EXE=EleFieldSim.out

all: $(EXE)

$(EXE): $(SRC) $(OBJ)
	$(CPP) $(LD_FLAGS) -o $@ $(OBJ) 

.cpp.o:
	$(CPP) -c $(CPP_FLAGS) -o $@ $<

clean:
	rm -f $(EXE)
	rm -rf *.o
