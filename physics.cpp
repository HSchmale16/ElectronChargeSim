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
            for(int n = 0; n < NUMSRCS; n++){
                Et = (charges[n].m_charge) /
                      pow(calcDistance(&charges[n], x, y), 2);
                double angle = atan2((charges[n].m_xPos - x),
                                     (charges[n].m_yPos - y));
                vectors[i].m_xC += cos(angle) * Et;
                vectors[i].m_yC += sin(angle) * Et;
            }
            i++;
        }
    }
}
