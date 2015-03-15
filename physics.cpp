/** Header for handling physics
 * \author Henry J Schmale
 * \date March 11, 2015
 * \file physics.cpp
 */

#include "physics.h"
#include "config.h"
#include <glog/logging.h>

using namespace std;

void calcElectroForceVecs(){
    int i = 0;
    double Et = 0;
    for(double x = XMIN; x <= XMAX; x += DXY_RES){
        for(double y = YMIN; y <= YMAX; y += DXY_RES){
            if(i >= VECCOUNT){
                continue;
            }
            Et = 0;
            for(int n = 0; n < NUMSRCS; n++){
                Et = (abs(9E9 * 5E-6 * charges[n].m_charge) /
                      pow(calcDistance(&charges[n], x, y), 2));
                double angle = atan2((y - charges[n].m_yPos),
                                     (x - charges[n].m_xPos));
                if(charges[n].m_charge > 0){
                    vectors[i].m_xC -= cos(angle) * Et;
                    vectors[i].m_yC -= sin(angle) * Et; 
                }else{
                    vectors[i].m_xC += cos(angle) * Et;
                    vectors[i].m_yC += sin(angle) * Et;
                }
            }
            i++;
        }
    }
}
