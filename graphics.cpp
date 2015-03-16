/** \brief Graphics header for drawing the scene and generating the
 * HTML for the reports
 * \author Henry J Schmale
 * \date   March 12, 2015
 * \file   graphics.cpp
 */

#include "graphics.h"
#include <Board.h>
#include <glog/logging.h>
#include "config.h"

using namespace LibBoard;

static Board board;

// Draws grid and set up board params
void initDrawing(){
    LOG(INFO) << "initing SVG Draw";
    board.setLineWidth(2);
    board.setLineStyle(Shape::SolidStyle);
    board.setLineJoin(Shape::MiterJoin);
    board.setLineCap(Shape::RoundCap);
    board.clear(0, 0, 0);
    board.setPenColor(Color::Green);
    board.setLineWidth(0.2);
    for(double x = XMIN; x <= XMAX; x += DXY_RES){
        if(x != 0){
            board.drawLine(x * SCALE_FACTOR, YMAX * SCALE_FACTOR,
                           x * SCALE_FACTOR, YMIN * SCALE_FACTOR);
        }
    }
    for(double y = YMIN; y <= YMAX; y += DXY_RES){
        if(y != 0){
            board.drawLine(XMIN * SCALE_FACTOR, y * SCALE_FACTOR,
                           XMAX * SCALE_FACTOR, y * SCALE_FACTOR);
        }
    }
    board.setLineWidth(0.5);
    board.drawLine(XMIN * SCALE_FACTOR, 0, XMAX * SCALE_FACTOR , 0);
    board.drawLine(0, YMIN * SCALE_FACTOR, 0, YMAX * SCALE_FACTOR);
}

// Draw the location of charge sources and colors them in
void drawChargeSrcs(){
    if(charges == NULL){
        LOG(WARNING) << "No charges defined";
        return;
    }
    for(int i = 0; i < NUMSRCS; i++){
        if(charges[i].m_charge > 0){
            board 
              << Ellipse(
                   (charges[i].m_xPos * SCALE_FACTOR) - PARTI_RADIUS,
                   (charges[i].m_yPos * SCALE_FACTOR) - PARTI_RADIUS,
                   2 * PARTI_RADIUS, 
                   2 * PARTI_RADIUS, 
                   Color::None,
                   Color::Red, 
                   1.0);
        }else if(charges[i].m_charge < 0){ 
            board 
              << Ellipse(
                   (charges[i].m_xPos * SCALE_FACTOR) - PARTI_RADIUS,
                   (charges[i].m_yPos * SCALE_FACTOR) - PARTI_RADIUS,
                   2 * PARTI_RADIUS,
                   2 * PARTI_RADIUS,
                   Color::None,
                   Color::Blue,
                   1.0);
        }
    }
}

// Draws the Slope Field
void drawVectors(){
    LOG(INFO) << "Drawing Vectors";
    board.setPenColor(Color::White);
    board.setLineWidth(.25);
    int i = 0;
    for(double x = XMIN; x <= XMAX; x += DXY_RES){
        for(double y = YMIN; y <= YMAX; y += DXY_RES){
            if(i < VECCOUNT){
                double angle = atan2(vectors[i].m_yC, vectors[i].m_xC);
                board.drawArrow(
                    .1 * cos(angle) * SCALE_FACTOR + x * SCALE_FACTOR,
                    .1 * sin(angle) * SCALE_FACTOR + y * SCALE_FACTOR,
                    x * SCALE_FACTOR,
                    y * SCALE_FACTOR);
                i++;
            }
        }
    }
}

void doneDraw(const char *fname){
    board.saveSVG(fname);
}
