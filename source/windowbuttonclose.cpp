#include "header/windowbuttonclose.h"

WindowButtonClose::WindowButtonClose(QWidget *parent)
    : WindowButton(parent)
{

}
WindowButtonClose::~WindowButtonClose(){

}

void WindowButtonClose::initButton(){
    QRectF border(-1, -1, width()+1, height()+1);
    /*************************************/
    /********** Button's symbol **********/
    QLine symbol1(QPoint(          4, 4), QPoint(width() - 5, height() - 5));
    QLine symbol2(QPoint(width() - 5, 4), QPoint(          4, height() - 5));
    /*************************************/
    QColor background(255, 255, 255, 100);
    QPainter painter;
    /********** Normal **********/
    painter.begin(normal);
    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(background));
    painter.drawRect(border);
    painter.setPen(QPen(QBrush(Qt::black), 2.0));
    painter.drawLine(symbol1);
    painter.drawLine(symbol2);
    painter.end();
    /****************************/
    /********** Hovered **********/
    painter.begin(hovered);
    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(background));
    painter.drawRect(border);
    painter.setPen(QPen(QBrush(Qt::white), 2.0));
    painter.drawLine(symbol1);
    painter.drawLine(symbol2);
    painter.end();
    /*****************************/
    /********** Clicked **********/
    painter.begin(clicked);
    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(background));
    painter.drawRect(border);
    painter.setPen(QPen(QBrush(Qt::white), 2.0));
    painter.drawLine(symbol1);
    painter.drawLine(symbol2);
    painter.end();
    /*****************************/
}
