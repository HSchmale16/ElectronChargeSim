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

int parseArgs(int argc, char **argv){
    if(argc <= 1){
        std::cout << "ARG FAIL! SEE PROJECT DOC AT main.cpp of this"
                  << " project" << std::endl;
        return ARG_FAILED; // No Good
    }
    if(argv[1][0] == 's'){
        return 1; // it's good
    }
    if(argv[1][0] == 'e'){

    }
}
