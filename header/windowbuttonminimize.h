#ifndef WINDOWBUTTONMINIMIZE_H
#define WINDOWBUTTONMINIMIZE_H

#include "windowbutton.h"

class WindowButtonMinimize : public WindowButton
{
public:
    WindowButtonMinimize(QWidget *parent = 0);
    ~WindowButtonMinimize();

protected:
    void initButton();
};

#endif // WINDOWBUTTONMINIMIZE_H
