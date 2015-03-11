/** Config File Implementation for Electric Field Sim
 * \author Henry J Schmale
 * \date March 11, 2015
 * \file config.cpp
 *
 * Contains the complete text of an example ini file for this program
 * and it contains a function to write it out to file.
 */

#include "config.h"
#include <iostream>

int parseArgs(int argc, char **argv){
    if(argc <= 1){
        std::cout << "ARG FAIL! SEE PROJECT DOC AT main.cpp of this"
                  << " project" << std::endl;
        return 0; // No Good
    }
    if(argv[1][0] == 's'){
        
    }
}
