/**\brief Physics handling system for Electric Forces Sim
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
    double px, py;           //!< Prev x & y coords     (m)
    double cx, cy;           //!< Current x & y coords  (m)
    double vx, vy;           //!< velocity x & y axis   (m/s)
    double ax, ay;           //!< current acceleration  (m/s^2)   
    double fx, fy;           //!< forces on each axis   (Newtons)
    double mass;             //!< mass of this object   (kg)
    double charge;           //!< Charge of this        (Columbs)

    pithBall()
        :px(0), py(0), cx(0), cy(0), vx(0), vy(0), ax(0), ay(0),
         fx(0), fy(0), mass(0), charge(0) {}
};

inline double calcDistance(chargeSrc *s1, chargeSrc *s2){
    return sqrt(pow((s1->m_xPos - s2->m_xPos), 2) 
              + pow((s1->m_yPos - s2->m_yPos), 2));
}

inline double calcDistance(chargeSrc *s1, pithBall *s2){
    return sqrt(pow((s1->m_xPos - s2->cx), 2) 
              + pow((s1->m_yPos - s2->cy), 2));
}

inline double calcDistance(chargeSrc *s1, double x, double y){
    return sqrt(pow((s1->m_xPos - x), 2) 
              + pow((s1->m_yPos - y), 2));
}

/**\brief calculates the electric field vectors due to the charge srcs
 * \return nothing
 *
 * Calculates the force vectors and places them in global var `vectors`
 */
void calcElectroForceVecs();



#endif // PHYSICS_H_INC
