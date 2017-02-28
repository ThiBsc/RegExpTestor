#ifndef WINDOWBUTTONMAXIMIZE_H
#define WINDOWBUTTONMAXIMIZE_H

#include "windowbutton.h"

class WindowButtonMaximize : public WindowButton
{
public:
    WindowButtonMaximize(QWidget *parent = 0);
    ~WindowButtonMaximize();

protected:
    void initButton();
};

#endif // WINDOWBUTTONMAXIMIZE_H
