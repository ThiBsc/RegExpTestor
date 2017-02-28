#ifndef CUSTOMWINDOW_H
#define CUSTOMWINDOW_H

#include <QWidget>
#include <QStatusBar>
#include "windowtitlebar.h"

class QVBoxLayout;
class QGridLayout;
class WindowTitleBar;


class CustomWindow : public QWidget
{
    Q_OBJECT

public:
    CustomWindow(QWidget *parent = 0);
    ~CustomWindow();

    void setWindowTitle(const QString &title);
    void addWidget(QWidget *w, int row, int col);
    void addWidget(QWidget *w, int row, int col, int rowSpan, int colSpan);

signals:
    void windowTitleChanged();

protected:
    void showEvent(QShowEvent *evt);
    void paintEvent(QPaintEvent *evt);
    QStatusBar      *statusBar;

private:
    void centerOnScreen();

    QVBoxLayout     *vLayout;
    QGridLayout     *gLayout;
    WindowTitleBar  *titleBar;
};

#endif // CUSTOMWINDOW_H
