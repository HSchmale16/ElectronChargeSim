/**\brief  Config File Implementation for Electric Field Sim
 * \author Henry J Schmale
 * \date   March 11, 2015
 * \file   config.cpp
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
#include <cstdio>
#include <cstring>
extern "C"{ // Not included in this header
    #include <iniparser.h>
};
#include <glog/logging.h>

// INI Key Id Constant Strings
#define D_XMIN       "GLOBAL:Xmin"
#define D_XMAX       "GLOBAL:Xmax"
#define D_YMIN       "GLOBAL:Ymin"
#define D_YMAX       "GLOBAL:Ymax"
#define D_NUMSRCS    "GLOBAL:NumSrcs"
#define D_NUMBALLS   "GLOBAL:NumBall"
#define D_DXYRES     "GLOBAL:dXYRes"
#define D_DTRES      "GLOBAL:dTRes"
#define D_SIMULATE   "GLOBAL:simulate"
#define D_TSIM       "GLOBAL:TSim"

// any of the constants below need to be processed with snprintf for
// index numbers, before using as a key for iniparser
#define D_SRC_XPOS   "SRC_%d:xPos"
#define D_SRC_YPOS   "SRC_%d:yPos"
#define D_SRC_CHARGE "SRC_%d:charge"
#define D_BLL_XPOS   "BLL_%d:xPos"
#define D_BLL_YPOS   "BLL_%d:yPos"
#define D_BLL_MASS   "BLL_%d:mass"
#define D_BLL_CHARGE "BLL_%d:charge"

using namespace std;

double XMIN;
double XMAX;
double YMIN;
double YMAX;
double DXY_RES;
double DT_RES;
double TSIM;
bool   SIMULATE;
int    NUMSRCS;
int    NUMBALLS;
int    VECCOUNT;

vec2d     *vectors;
chargeSrc *charges;
pithBall  *balls;

static dictionary *dict;

// this is a private function to load the constants from the INI
// file given.
static int loadConstants(char *fname){
    char buffer[50] = {0};
    LOG(INFO) << "Now loading constants and allocating "
              << " memory for constants";
    CHECK(fname != NULL);
    dict = iniparser_load(fname); // load config file with iniparser
    CHECK_NOTNULL(dict);

    // Load the constants
    XMIN     = iniparser_getdouble(dict, D_XMIN, 0);
    XMAX     = iniparser_getdouble(dict, D_XMAX, 0);
    YMIN     = iniparser_getdouble(dict, D_YMIN, 0);
    YMAX     = iniparser_getdouble(dict, D_YMAX, 0);
    DXY_RES  = iniparser_getdouble(dict, D_DXYRES, 0);
    DT_RES   = iniparser_getdouble(dict, D_DTRES, 0);
    TSIM     = iniparser_getdouble(dict, D_TSIM, 0);
    SIMULATE = iniparser_getboolean(dict, D_SIMULATE, 0);
    NUMSRCS  = iniparser_getint(dict, D_NUMSRCS, 0);
    NUMBALLS = iniparser_getint(dict, D_NUMBALLS, 0);

    // Verify information fetched
    CHECK((XMAX - XMIN) > 0) << "Invalid XMIN & XMAX in job file";
    CHECK((YMAX - YMIN) > 0) << "Invalid YMIN & YMAX in job file";
    CHECK(DXY_RES > 0);
    LOG(INFO) << "Finished Fetching Global Values from INI file";

    if(NUMSRCS > 0){
        charges = new chargeSrc[NUMSRCS];
        CHECK_NOTNULL(charges);
        for(int i = 0; i < NUMSRCS; i++){
            snprintf(buffer, 50, D_SRC_XPOS, i);
            charges[i].m_xPos = iniparser_getdouble(dict, buffer, 0);
            snprintf(buffer, 50, D_SRC_YPOS, i);
            charges[i].m_yPos = iniparser_getdouble(dict, buffer, 0);
            snprintf(buffer, 50, D_SRC_CHARGE, i);
            charges[i].m_charge = iniparser_getdouble(dict, buffer, 0);
            LOG(INFO) << "ChargeSrc[" << i << "] charge = " 
                      << charges[i].m_charge;
        }
    }else{
        LOG(ERROR) << "Invalid value defined in NUMSRCS in job file";
    }
    if((SIMULATE == true) && (NUMBALLS > 0)){
        LOG(INFO) << "Simulation has " << NUMBALLS  << "pithballs";
        balls = new pithBall[NUMBALLS];
        CHECK_NOTNULL(balls);
        for(int i = 0; i < NUMBALLS; i++){
            snprintf(buffer, 50, D_BLL_XPOS, i);
            balls[i].cx     = iniparser_getdouble(dict, buffer, 0);
            snprintf(buffer, 50, D_BLL_YPOS, i);
            balls[i].cy     = iniparser_getdouble(dict, buffer, 0);
            snprintf(buffer, 50, D_BLL_MASS, i);
            balls[i].mass   = iniparser_getdouble(dict, buffer, 0);
            snprintf(buffer, 50, D_BLL_CHARGE, i);
            balls[i].charge = iniparser_getdouble(dict, buffer, 0); 
            LOG(INFO) << "Ball[" << i << "] charge = " 
                      << balls[i].charge;
        }
    }else{
        LOG(ERROR) << "Invalid value defined in NUMBALLS in job file";
    }
    int arraySz = ((XMAX - XMIN) / DXY_RES) * ((YMAX - YMIN) / DXY_RES);
    VECCOUNT = arraySz;
    vectors = new vec2d[arraySz];
    CHECK_NOTNULL(vectors);
    LOG(INFO) << "memory allocation and initialization is complete";
    return 0;
}


int parseArgs(int argc, char **argv){
    FLAGS_log_dir = "./logs/";
    google::InitGoogleLogging(argv[0]);
    if(argc <= 1){
        LOG(FATAL) << "ARG FAIL! SEE PROJECT DOC AT main.cpp of this"
                   << " project" << std::endl;
        return ARG_FAILED; // No Good
    }
    if(argv[1][0] == 's'){
        if(argc != 3){
            LOG(FATAL) << "ARG FAIL! Did you forget a file name. "
                       << "That is required for the simulate option.\n"
                       << "A config file can be generated with the "
                       << "command:\n"  << argv[0] << " e <file>" 
                       << std::endl;
            return ARG_FAILED;
        }else{
            loadConstants(argv[2]);
        }
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
    }else{
        LOG(FATAL) << "Bad Args Passed and can't be parsed.\n"
                   << "Go read the documentation you stinking monkey";
        return ARG_FAILED;
    }
    
}

void shutdown(){
    LOG(INFO) << "Begining shutdown procedure";
    iniparser_freedict(dict); 
    delete[] balls;
    delete[] vectors;
    delete[] charges;
    LOG(INFO) << "Finished memory clean up";
}
