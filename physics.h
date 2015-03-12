/** Header for handling physics
 * \author Henry J Schmale
 * \date March 11, 2015
 * \file physics.h
 */

#ifndef PHYSICS_H_INC
#define PHYSICS_H_INC

struct vec2d{
    double m_xC;       //!< x componet (newtons)
    double m_yC;       //!< y componet (newtons)
};

struct chargeSrc{
    double m_xPos;     //!< x posisition (meters)
    double m_yPos;     //!< y posisition (meters)
    double m_charge;   //!< electric charge

    //default ctor
    chargeSrc()
        :m_xPos(0), m_yPos(0), m_charge(0){}

    chargeSrc(double x, double y, double c)
        :m_xPos(0), m_yPos(0), m_charge(0){}
}

#endif // PHYSICS_H_INC
