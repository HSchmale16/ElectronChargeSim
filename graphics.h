/** \brief Graphics header for drawing the scene and generating the
 * HTML for the reports
 * \author Henry J Schmale
 * \date   March 12, 2015
 * \file   graphics.h
 */

#ifndef GRAPHICS_H_INC
#define GRAPHICS_H_INC

const double SCALE_FACTOR = 100.0;
const double PARTI_RADIUS = 5.0;

void initDrawing();

void drawChargeSrcs();

void drawVectors();

void doneDraw(const char *fname);

#endif // GRAPHICS_H_INC
