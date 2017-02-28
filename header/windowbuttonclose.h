#ifndef WINDOWBUTTONCLOSE_H
#define WINDOWBUTTONCLOSE_H

#include "windowbutton.h"

class WindowButtonClose : public WindowButton
{
public:
    WindowButtonClose(QWidget *parent = 0);
    ~WindowButtonClose();

protected:
    void initButton();
};

#endif // WINDOWBUTTONCLOSE_H
