# Makefile for Electric Field Simulator
# Henry J Schmale
# March 11, 2015

# Shell Setup - tell make to use `bash` instead of `sh`
SHELL=/bin/bash -O extglob -c

# Compiler Settings
CPP=g++
CPP_FLGS= \
	-Wall

LD_FLGS= \
	-liniparser \
	-lboard \
	-lglog

# Code Settings
ALLSRC := $(shell ls *.+(cpp|h) )
SRC    := $(shell find . -regextype sed -regex ".*/.*.cpp")
OBJ    := $(SRC:.cpp=.o)
EXE    := EleFieldSim.out

all: $(EXE)

$(EXE): $(SRC) $(OBJ)
	$(CPP) $(LD_FLGS) -o $@ $(OBJ) 

depend: .depend

.depend: $(ALLSRC)
	rm -f ./.depend
	$(CPP) $(CPP_FLGS) -MM $^ -MF ./.depend;

include .depend

.cpp.o:
	$(CPP) -c $(CPP_FLGS) -o $@ $<

clean:
	rm -f $(EXE)
	rm -rf *.o

.PHONY: clean
