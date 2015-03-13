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
              << Ellipse(charges[i].m_xPos - (.5 * PARTI_RADIUS),
                         -charges[i].m_yPos - (.5 * PARTI_RADIUS),
                         PARTI_RADIUS, PARTI_RADIUS, Color::None,
                         Color::Red, 1.0);
        }
    }
}

void doneDraw(const char *fname){
    board.saveSVG(fname);
}
