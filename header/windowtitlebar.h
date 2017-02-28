#ifndef WINDOWTITLEBAR_H
#define WINDOWTITLEBAR_H

#include <QWidget>

class QPixmap;
class QLabel;
class WindowButton;

class WindowTitleBar : public QWidget
{
    Q_OBJECT
public:
    WindowTitleBar(QWidget *parent = 0);
    ~WindowTitleBar();

signals:

public slots:
    void updateWindowTitle();
    void minimized();
    void maximized();
    void quit();

protected:
    void resizeEvent(QResizeEvent *evt);
    void paintEvent(QPaintEvent *evt);
    void mousePressEvent(QMouseEvent *evt);
    void mouseReleaseEvent(QMouseEvent *evt);
    void mouseMoveEvent(QMouseEvent *evt);

private:
    int             widthBtn;
    QPoint          diff; // stock les données relative au déplacement
    QPixmap         *cache;
    QLabel          *title;
    WindowButton    *btnMinimize;
    WindowButton    *btnMaximize;
    WindowButton    *btnClose;
};

#endif // WINDOWTITLEBAR_H
