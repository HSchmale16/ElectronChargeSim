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
 * if no job-file is specified and the simulate flag is active, then
 * one is written out on stdout, and then the program terminates.
 */

#include <iostream>
#include <cstdio>
#include <iniparser.h>
#include "config.h"

dictionary *dict; // ini dictionary

// fwd decl funcs
int parseArgs(int argc, char **argv);


// prog entry point
int main(int argc, char **argv){
    int arg = parseArgs(argc, argv);
    if(!arg){
        return 0;
    }
}

int parseArgs(int argc, char **argv){
    if(argc == 1){
        std::cout << EXAMPLE_INI;
        return 0;
    }
}
