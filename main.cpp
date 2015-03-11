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
#include <iniparser.h>
#include "config.h"

dictionary *dict; // ini dictionary

// fwd decl funcs


// prog entry point
int main(int argc, char **argv){
    int arg = parseArgs(argc, argv);
    if(!arg){
        return 0;
    }
}
