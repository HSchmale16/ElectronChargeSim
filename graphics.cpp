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

void initDrawing(){
    LOG(INFO) << "initing SVG Draw";
    board.setLineWidth(2);
    board.setLineStyle(Shape::SolidStyle);
    board.setLineJoin(Shape::MiterJoin);
    board.setLineCap(Shape::RoundCap);
    board.clear(0, 0, 0);
}

void drawChargeSrcs(){
    if(charges == NULL){
        LOG(WARNING) << "No charges defined";
        return;
    }
    for(int i = 0; i < NUMSRCS; i++){
        if(charges[i].m_charge > 0){
            board 
              << Ellipse(
                   (charges[i].m_xPos * SCALE_FACTOR) - (.5 * PARTI_RADIUS),
                   (charges[i].m_yPos* SCALE_FACTOR) - (.5 * PARTI_RADIUS),
                   PARTI_RADIUS, PARTI_RADIUS, Color::None,
                   Color::Red, 1.0);
        }else if(charges[i].m_charge < 0){
            board 
              << Ellipse(
                   (charges[i].m_xPos * SCALE_FACTOR) - (.5 * PARTI_RADIUS),
                   (charges[i].m_yPos* SCALE_FACTOR) - (.5 * PARTI_RADIUS),
                   PARTI_RADIUS, PARTI_RADIUS, Color::None,
                   Color::Blue, 1.0);
        }
    }
}

void drawVectors(){
    LOG(INFO) << "Drawing Vectors";
    board.setPenColor(Color::White);
    board.setLineWidth(.25);
    int i = 0;
    for(double x = XMIN; x <= XMAX; x += DXY_RES){
        for(double y = YMIN; y <= YMAX; y += DXY_RES){
            double angle = atan2(vectors[i].m_yC, vectors[i].m_xC);
            board.drawArrow(
                 .2 * cos(angle) * SCALE_FACTOR + x * SCALE_FACTOR,
                 .2 * sin(angle) * SCALE_FACTOR + y * SCALE_FACTOR,
                 x * SCALE_FACTOR,
                 y * SCALE_FACTOR);
            i++;
        }
    }
}

void doneDraw(const char *fname){
    board.saveSVG(fname);
}
