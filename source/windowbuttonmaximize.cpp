#include "header/windowbuttonmaximize.h"

WindowButtonMaximize::WindowButtonMaximize(QWidget *parent)
    : WindowButton(parent)
{

}
WindowButtonMaximize::~WindowButtonMaximize(){

}

void WindowButtonMaximize::initButton(){
    QRectF border(-1, -1, width()+1, height()+1);
    /*************************************/
    /********** Button's symbol **********/
    QPolygon symbol1, symbol2;
      symbol1 << QPoint(          4, 4)
              << QPoint(width() - 4, 4)
              << QPoint(width() - 4, 8)
              << QPoint(          4, 8);
      symbol2 << QPoint(          4,            8)
              << QPoint(width() - 4,            8)
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
    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(Qt::black));
    painter.drawPolygon(symbol1);
    painter.setPen(QPen(Qt::black));
    painter.setBrush(Qt::NoBrush);
    painter.drawPolygon(symbol2);
    painter.end();
    /****************************/
    /********** Hovered **********/
    painter.begin(hovered);
    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(background));
    painter.drawRect(border);
    painter.setPen  (QPen  (Qt::white));
    painter.setBrush(QBrush(Qt::white));
    painter.drawPolygon(symbol1);
    painter.setPen  (QPen(Qt::white));
    painter.setBrush(Qt::NoBrush    );
    painter.drawPolygon(symbol2);
    painter.end();
    /*****************************/
    /********** Clicked **********/
    painter.begin(clicked);
    painter.setPen(QPen(Qt::black));
    painter.setBrush(QBrush(background));
    painter.drawRect(border);
    painter.setPen(QPen(Qt::white));
    painter.setBrush(QBrush(Qt::white));
    painter.drawPolygon(symbol1);
    painter.setPen(QPen(Qt::white));
    painter.setBrush(Qt::NoBrush);
    painter.drawPolygon(symbol2);
    painter.end();
    /*****************************/
}
