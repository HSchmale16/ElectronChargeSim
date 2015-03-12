/** Header for handling physics
 * \author Henry J Schmale
 * \date March 11, 2015
 * \file physics.h
 */

#ifndef PHYSICS_H_INC
#define PHYSICS_H_INC

#include <cmath>

struct vec2d{
    double m_xC;             //!< x componet (newtons)
    double m_yC;             //!< y componet (newtons)
};

struct chargeSrc{
    double m_xPos;           //!< x posisition (meters)
    double m_yPos;           //!< y posisition (meters)
    double m_charge;         //!< electric charge

    //default ctor
    chargeSrc()
        :m_xPos(0), m_yPos(0), m_charge(0){}

    chargeSrc(double x, double y, double c)
        :m_xPos(0), m_yPos(0), m_charge(0){}
};

struct chargedBall{
    const double m_initX;    //!< Initial X Pos
    const double m_initY;    //!< Initial Y Pos
    double m_xpos;           //!< Current X Pos
    double m_ypos;           //!< Current Y Pos
    double m_dX;             //!< current acceleration on x-axis
    double m_dY;             //!< current acceleration on y-axis 
};

inline double calcDistance(chargeSrc *s1, chargeSrc *s2){
    return sqrt(pow((s1->m_xPos - s2->m_xPos), 2) 
              + pow((s1->m_yPos - s2->m_yPos), 2));
}

#endif // PHYSICS_H_INC
