#include "header/windowbuttonminimize.h"

WindowButtonMinimize::WindowButtonMinimize(QWidget *parent)
    : WindowButton(parent)
{

}
WindowButtonMinimize::~WindowButtonMinimize(){

}

void WindowButtonMinimize::initButton(){
    QRectF border(-1, -1, width()+1, height()+1);
    /*************************************/
    /********** Button's symbol **********/
    QPolygon symbol;
    symbol << QPoint(          4, height() - 8)
         << QPoint(width() - 4, height() - 8)
         << QPoint(width() - 4, height() - 4)
         << QPoint(          4, height() - 4);
    /*************************************/
    QColor background(255, 255, 255, 100);
    QPainter painter;
    /********** Normal **********/
    painter.begin(normal);
    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(background));
    painter.drawRect(border);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::black));
    painter.drawPolygon(symbol);
    painter.end();
    /****************************/
    /********** Hovered **********/
    painter.begin(hovered);
    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(background));
    painter.drawRect(border);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::white));
    painter.drawPolygon(symbol);
    painter.end();
    /*****************************/
    /********** Clicked **********/
    painter.begin(clicked);
    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(background));
    painter.drawRect(border);
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::white));
    painter.drawPolygon(symbol);
    painter.end();
    /*****************************/
}
