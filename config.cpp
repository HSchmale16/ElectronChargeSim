/** Config File Implementation for Electric Field Sim
 * \author Henry J Schmale
 * \date March 11, 2015
 * \file config.cpp
 *
 * Contains the complete text of an example ini file for this program
 * and it contains a function to write it out to file.
 * 
 * USAGE:
 * argv[0] <s|e> [file]
 *
 * s - simulate, the simulation parameters must be specified in 
 *     file must be specified
 * e - output an example file, if file is specified then it is written
 *     out to stdout
 *
 */

#include "config.h"
#include <iostream>
#include <fstream>
#include <ios>
#include <cassert>
extern "C"{ // Not included in this header
    #include <iniparser.h>
};

// INI Key Id Constant Strings
#define XMIN       "GLOBAL:Xmin"
#define XMAX       "GLOBAL:Xmax"
#define YMIN       "GLOBAL:Ymin"
#define YMAX       "GLOBAL:Ymax"
#define NUMSRCS    "GLOBAL:NumSrcs"
#define NUMBALLS   "GLOBAL:NumBall"
#define DXYRES     "GLOBAL:dXYRes"
#define DTRES      "GLOBAL:dTRes"
#define SIMULATE   "GLOBAL:simulate"
#define TSIM       "GLOBAL:TSim"

// any of the constants below need to be processed with snprintf for
// index numbers, before using as a key for iniparser
#define SRC_XPOS   "SRC_%d:xPos"
#define SRC_YPOS   "SRC_%d:yPos"
#define SRC_CHARGE "SRC_%d:charge"
#define BLL_XPOS   "BLL_%d:xPos"
#define BLL_YPOS   "BLL_%d:yPos"
#define BLL_MASS   "BLL_%d:mass"

using namespace std;

int parseArgs(int argc, char **argv){
    if(argc <= 1){
        std::cout << "ARG FAIL! SEE PROJECT DOC AT main.cpp of this"
                  << " project" << std::endl;
        return ARG_FAILED; // No Good
    }
    if(argv[1][0] == 's'){
        assert(argc > 2);
        return 1; // it's good
    }
    if(argv[1][0] == 'e'){
        if(argv[2] != NULL){
            // output to file
            fstream out(argv[2], ios::out | ios::binary);
            out << EXAMPLE_INI;
            out.close();
        }else{
            // write to stdout
            std::cout << EXAMPLE_INI;
        }
        return ARG_FAILED;
    }
}
