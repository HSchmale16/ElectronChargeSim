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
#include "config.h"
extern "C"{ // Not included in this header
    #include <iniparser.h>
};

using namespace LibBoard;

dictionary *dict; // ini dictionary

// prog entry point
int main(int argc, char **argv){
    //int argret = parseArgs(argc, argv);
    dict = iniparser_load("i.job");
    std::cout << iniparser_getint(dict, XMIN, 0);
    iniparser_freedict(dict);
}
