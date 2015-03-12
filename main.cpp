/** \brief Electric Field Simulator
 * \author Henry J Schmale
 * \date March 11, 2015
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

#include <iostream>
#include <cstdio>
#include <Board.h>
extern "C"{ // Not included in this header
    #include <iniparser.h>
};
#include "config.h"
#include "physics.h"

using namespace LibBoard;

dictionary *dict; // ini dictionary

// prog entry point
int main(int argc, char **argv){
    int argret = parseArgs(argc, argv);
    if(argret == ARG_FAILED){
        return 0;
    }
}
