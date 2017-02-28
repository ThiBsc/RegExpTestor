#ifndef REGEXWINDOW_H
#define REGEXWINDOW_H

#include "customwindow.h"
#include <QLabel>

class QLineEdit;
class QPlainTextEdit;
class QToolButton;
class QSplitter;

class RegExWindow : public CustomWindow
{
    Q_OBJECT

public:
    RegExWindow(QWidget *parent = 0);
    ~RegExWindow();
    static QString version;

public slots:
    void printMatch(QString regex);
    void refreshMatch();
    void devInfo();

private:
    QLabel          lblReg, lblTest, lblMatch;
    QLineEdit       *leReg;
    QPlainTextEdit  *pteTest, *pteMatch;
    QToolButton     *btnInfo;
    QSplitter       *splitter;
    QWidget         *left, *right;
    QVBoxLayout     *vlLeft, *vlRight;

};

#endif // REGEXWINDOW_H
