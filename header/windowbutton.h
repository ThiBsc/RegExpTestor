#ifndef WINDOWBUTTON_H
#define WINDOWBUTTON_H

#include <QAbstractButton>
#include <QPixmap>
#include <QPainter>

class WindowButton : public QAbstractButton
{
public:
    WindowButton(QWidget *parent = 0);
    ~WindowButton();

protected:
    enum ButtonState {
        STATE_NORMAL=0, STATE_HOVERED, STATE_CLICKED
    };
    void resizeEvent(QResizeEvent *evt);
    void paintEvent (QPaintEvent  *evt);
    void initPixmaps();
    void initPixmap(QPixmap **pixmap);
    virtual void initButton();

    ButtonState state;
    QPixmap *normal;
    QPixmap *hovered;
    QPixmap *clicked;

private:
    void enterEvent(QEvent *evt);
    void leaveEvent(QEvent *evt);
    void mousePressEvent(QMouseEvent *evt);
    void mouseReleaseEvent(QMouseEvent *evt);
};

#endif // WINDOWBUTTON_H
