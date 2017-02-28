#include "header/windowtitlebar.h"
#include "header/windowbuttonminimize.h"
#include "header/windowbuttonmaximize.h"
#include "header/windowbuttonclose.h"
#include <QPixmap>
#include <QPainter>
#include <QLabel>
#include <QMouseEvent>

WindowTitleBar::WindowTitleBar(QWidget *parent) : QWidget(parent)
{
    widthBtn = 30;
    setFixedHeight(widthBtn);
    cache = NULL;
    title = new QLabel("WindowTitleBar", this);
    title->setStyleSheet("color: white; font-family: Courier; font-weight: bold; font-size: 14px");

    btnMinimize = new WindowButtonMinimize(this);
    btnMaximize = new WindowButtonMaximize(this);
    btnClose = new WindowButtonClose(this);

    connect(btnMinimize, SIGNAL(clicked()), this, SLOT(minimized()));
    connect(btnMaximize, SIGNAL(clicked()), this, SLOT(maximized()));
    connect(btnClose, SIGNAL(clicked()), this, SLOT(quit()));
}
WindowTitleBar::~WindowTitleBar(){
    delete cache;
    delete title;
    delete btnMinimize;
    delete btnMaximize;
    delete btnClose;
}

void WindowTitleBar::resizeEvent(QResizeEvent *evt){
    Q_UNUSED(evt);
    delete cache; // Remove old cache
    cache = new QPixmap(size());  // Create a cache with same size as the widget
    cache->fill(Qt::transparent);  // Create a the transparent background

    QPainter painter(cache); // Start painting the cache

    QColor lightBlue(49, 140, 231);
    /*QColor gradientStart(0, 0, 0, 0);
    QColor gradientEnd(0, 0, 0, 220);

    QLinearGradient linearGrad(QPointF(0, 0), QPointF(0, height()));
    linearGrad.setColorAt(0, gradientStart);
    linearGrad.setColorAt(1, gradientEnd);*/

    /********** Title bar's frame **********/
    QRectF frame(0, 0, width(), height());
    painter.setPen(QPen(lightBlue));
    painter.setBrush(QBrush(lightBlue));
    painter.drawRect(frame);
    /***************************************/
    title->move(15, 8);
    btnMinimize->resize(widthBtn, height());
    btnMaximize->resize(widthBtn, height());
    btnClose->resize(widthBtn, height());

    btnMinimize->move(width()-(btnMinimize->width()+5)*3, 0);
    btnMaximize->move(width()-(btnMinimize->width()+5)*2, 0);
    btnClose->move(width()-btnMinimize->width()-5, 0);
    painter.end();
}
void WindowTitleBar::paintEvent(QPaintEvent *evt){
    Q_UNUSED(evt);
    if(cache != NULL){
        QPainter painter(this);
        painter.drawPixmap(0, 0, *cache);
    }
}
void WindowTitleBar::updateWindowTitle(){
    title->setText(window()->windowTitle());
}
void WindowTitleBar::minimized(){
    window()->showMinimized();
}
void WindowTitleBar::maximized(){
    if(window()->windowState() == Qt::WindowMaximized){
        window()->showNormal();
    }
    else{
        window()->showMaximized();
    }
}
void WindowTitleBar::quit()
{
    exit(0);
}
void WindowTitleBar::mousePressEvent(QMouseEvent *evt){
    diff = evt->pos();
    setCursor(QCursor(Qt::SizeAllCursor));
}
void WindowTitleBar::mouseReleaseEvent(QMouseEvent *evt){
    Q_UNUSED(evt);
    setCursor(QCursor(Qt::ArrowCursor));
}
void WindowTitleBar::mouseMoveEvent(QMouseEvent *evt){
    QPoint p = evt->globalPos();
    window()->move(p - diff);
}
