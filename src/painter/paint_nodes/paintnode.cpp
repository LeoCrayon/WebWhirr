#include "paintnode.h"

PaintNode::PaintNode()
{
    needsPainting = true;
    dimensions = QSize(0, 0);
    coordinates = QPoint(0, 0);
}

void PaintNode::paint(QPainter *qPainter, PaintArea *display, Layout *layout)
{
    paintChildNodes(qPainter, display, layout);
    return;
}

void PaintNode::paintChildNodes(QPainter *qPainter, PaintArea *display,
                                Layout *layout)
{
    for (std::vector<PaintNode*>::iterator i = childPaintNodes.begin();
         i != childPaintNodes.end(); i++)
    {
        (*i)->calculateDimensions(display);
        (*i)->paint(qPainter, display, layout);
    }
}

void PaintNode::addChildPaintNodes(std::vector<PaintNode*> childNodes)
{
    childPaintNodes = childNodes;
}

void PaintNode::setCoordinates(QPoint coordinatesToSet)
{
    if (!(coordinates == coordinatesToSet))
    {
        coordinates = coordinatesToSet;
        needsPainting = true;
    }
}

QPoint PaintNode::getCoordinates()
{
    return coordinates;
}

void PaintNode::calculateDimensions(PaintArea *display)
{
}

QSize PaintNode::getDimensions()
{
    return dimensions;
}

int PaintNode::getWidth()
{
    return dimensions.width();
}

int PaintNode::getHeight()
{
    return dimensions.height();
}