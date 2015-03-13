/** Header for handling physics
 * \author Henry J Schmale
 * \date March 11, 2015
 * \file physics.cpp
 */

#include "physics.h"
#include "config.h"

void calcElectroForceVecs(){
    int i = 0;
    double Et = 0;
    for(double x = XMIN; x < XMAX; x += DXY_RES){
        for(double y = YMIN; y < YMAX; y += DXY_RES){
            Et = 0;
            for(int n = 0; n < NUMSRCS; n++){

            }
        }
    }
}
