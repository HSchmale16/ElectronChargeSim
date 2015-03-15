# Makefile for Electric Field Simulator
# Henry J Schmale
# March 11, 2015

# Compiler Settings
CPP=g++
CPP_FLGS= \
	-Wall


LD_FLGS= \
	-liniparser \
	-lboard \
	-lglog

# Code Settings
SRC=$(shell find . -regextype sed -regex ".*/.*.cpp")
OBJ=$(SRC:.cpp=.o)
EXE=EleFieldSim.out

all: $(EXE)

$(EXE): $(shell find . -name ".[ch]*") $(SRC) $(OBJ)
	$(CPP) $(LD_FLGS) -o $@ $(OBJ) 

.cpp.o:
	$(CPP) -c $(CPP_FLGS) -o $@ $<

clean:
	rm -f $(EXE)
	rm -rf *.o

.PHONY: clean
