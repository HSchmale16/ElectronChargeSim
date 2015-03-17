/**\brief  Electric Field Simulator Entry Point
 * \author Henry J Schmale
 * \date   March 11, 2015
 * \file   main.cpp
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
#include <string>
#include <cstdio>
#include "config.h"
#include "physics.h"
#include "graphics.h"

//using namespace LibBoard;

/**\brief This is the program entry point, stupid
 * \param argc The number of args passed in argv
 * \param argv The arguement array
 */
int main(int argc, char **argv){
    int argret = parseArgs(argc, argv);
    if(argret == ARG_FAILED){
        return 0;
    }
    initDrawing();
    calcElectroForceVecs();
    drawVectors();
    drawChargeSrcs();
    doneDraw(std::string(std::string(argv[2]) + ".svg").c_str());
    shutdown();
}
