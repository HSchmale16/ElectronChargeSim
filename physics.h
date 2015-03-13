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

    vec2d()
        :m_xC(0), m_yC(0) {}

    vec2d(double x, double y)
        :m_xC(x), m_yC(y) {}
    
    // Assignment opperator
    void operator()(double x, double y){
        m_xC = x;
        m_yC = y;
    }
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

struct pithBall{
    double m_initX;          //!< Initial X Pos
    double m_initY;          //!< Initial Y Pos
    double m_charge;         //!< Charge of this pithball
    double m_xPos;           //!< Current X Pos
    double m_yPos;           //!< Current Y Pos
    double m_dX;             //!< current acceleration on x-axis
    double m_dY;             //!< current acceleration on y-axis 
    double m_mass;           //!< Mass of this ball (Kg)

    pithBall()
        :m_initX(0), m_initY(0), m_charge(0), m_xPos(0),
         m_yPos(0), m_dX(0), m_dY(0), m_mass(0) {}
};

inline double calcDistance(chargeSrc *s1, chargeSrc *s2){
    return sqrt(pow((s1->m_xPos - s2->m_xPos), 2) 
             + pow((s1->m_yPos - s2->m_yPos), 2));
}

inline double calcDistance(chargeSrc *s1, pithBall *s2){
    return sqrt(pow((s1->m_xPos - s2->m_xPos), 2) 
              + pow((s1->m_yPos - s2->m_yPos), 2));
}

inline double calcDistance(chargeSrc *s1, double x, double y){
    return sqrt(pow((s1->m_xPos - x), 2) 
              + pow((s1->m_yPos - y), 2));
}

void calcElectroForceVecs();
#endif // PHYSICS_H_INC
