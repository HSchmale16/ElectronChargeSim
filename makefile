# Makefile for Electric Field Simulator
# Henry J Schmale
# March 11, 2015

# Shell Setup - tell make to use `bash` instead of `sh`
SHELL=/bin/bash -O extglob -c

# Compiler Settings
CXX=g++
CXX_FLGS= -pg \
	-Wall

LD_FLGS= -pg \
	-liniparser \
	-lboard \
	-lglog

# Code Settings
ALLSRC := $(shell ls *.+(cpp|h) )
SRC    := $(shell find . -regextype sed -regex ".*/.*.cpp")
OBJ    := $(SRC:.cpp=.o)
EXE    := EleFieldSim.out

.PHONY: all
all: depend $(EXE)

$(EXE): $(SRC) $(OBJ)
	$(CXX) $(LD_FLGS) -o $@ $(OBJ) 

.cpp.o:
	$(CXX) -c $(CXX_FLGS) -o $@ $<

.PHONY: clean
clean:
	rm -f $(EXE)
	rm -rf *.o

# Dependcy Resolution
depend: .depend

.depend: $(ALLSRC)
	rm -f ./.depend
	$(CXX) $(CPP_FLGS) -MM $^ > ./.depend

include .depend

