#include "header/windowbutton.h"

WindowButton::WindowButton(QWidget *parent)
    : QAbstractButton(parent)
{
    state = STATE_NORMAL;

    normal = new QPixmap();
    hovered = new QPixmap();
    clicked = new QPixmap();
    //setFixedWidth(40);
}
WindowButton::~WindowButton(){
    delete normal;
    delete hovered;
    delete clicked;
}

void WindowButton::resizeEvent(QResizeEvent *evt){
    Q_UNUSED(evt);
    initPixmaps();
}
void WindowButton::paintEvent(QPaintEvent *evt){
    Q_UNUSED(evt);
    QPainter painter(this);
    if (isEnabled()){
        switch (state) {
            case STATE_NORMAL:
                if (normal != NULL)
                    painter.drawPixmap(0, 0, *normal);
                break;
            case STATE_HOVERED:
                if (hovered != NULL)
                    painter.drawPixmap(0, 0, *hovered);
                break;
            case STATE_CLICKED:
                if (clicked != NULL)
                    painter.drawPixmap(0, 0, *clicked);
                break;
            default:
                break;
        }
    }
    else{
        if (normal != NULL)
            painter.drawPixmap(0, 0, *normal);
    }
}
void WindowButton::initPixmaps(){
    initPixmap(&normal);
    initPixmap(&hovered);
    initPixmap(&clicked);

    initButton();
}
void WindowButton::initPixmap(QPixmap **pixmap){
    delete *pixmap;
    *pixmap = new QPixmap(size());
    (*pixmap)->fill(Qt::transparent);
}
void WindowButton::initButton(){
    return;
}

void WindowButton::enterEvent(QEvent *evt)
{
    Q_UNUSED(evt);
    state = STATE_HOVERED;
    update();
}
void WindowButton::leaveEvent(QEvent *evt)
{
    Q_UNUSED(evt);
    state = STATE_NORMAL;
    update();
}
void WindowButton::mousePressEvent(QMouseEvent *evt)
{
    QAbstractButton::mousePressEvent(evt);
    state = STATE_CLICKED;
    update();
}
void WindowButton::mouseReleaseEvent(QMouseEvent *evt)
{
    QAbstractButton::mouseReleaseEvent(evt);
    if(underMouse())
        state = STATE_HOVERED;
    else
        state = STATE_NORMAL;
    update();
}
