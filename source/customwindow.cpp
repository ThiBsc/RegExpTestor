#include "header/customwindow.h"
#include "header/windowtitlebar.h"
#include <QVBoxLayout>
#include <QGridLayout>
#include <QPainter>
#include <QDesktopWidget>

CustomWindow::CustomWindow(QWidget *parent) :
    QWidget(parent)
{
    setWindowFlags(Qt::FramelessWindowHint);
    resize(512, 310);

    statusBar = new QStatusBar(this);

    gLayout = new QGridLayout();
    gLayout->setMargin(2);
    gLayout->setSpacing(4);
    vLayout = new QVBoxLayout();
    vLayout->setMargin(0);
    vLayout->setSpacing(0);
    setLayout(vLayout);

    titleBar = new WindowTitleBar(this);
    vLayout->addWidget(titleBar);
    vLayout->addLayout(gLayout);
    vLayout->addWidget(statusBar);
    vLayout->setAlignment(titleBar, Qt::AlignTop);

    connect(this, SIGNAL(windowTitleChanged()), titleBar, SLOT(updateWindowTitle()));
}

CustomWindow::~CustomWindow()
{
    delete gLayout;
    delete vLayout;
    delete titleBar;
    delete statusBar;
}

void CustomWindow::showEvent(QShowEvent *evt){
    Q_UNUSED(evt);
    centerOnScreen();
}
void CustomWindow::paintEvent(QPaintEvent *evt){
    Q_UNUSED(evt);
    QPainter painter(this);
    QBrush background(QColor(43, 43, 43));
    painter.setBrush(background);
    painter.setPen(Qt::NoPen);
    painter.drawRect(0, 0, width(), height());
}

void CustomWindow::centerOnScreen(){
    QDesktopWidget screen;
    QRect screenGeom = screen.screenGeometry(this);
    int screenCenterX = screenGeom.center().x();
    int screenCenterY = screenGeom.center().y();
    move(screenCenterX - width () / 2, screenCenterY - height() / 2);
}
void CustomWindow::setWindowTitle(const QString &title){
    QWidget::setWindowTitle(title);
    emit windowTitleChanged();
}

void CustomWindow::addWidget(QWidget *w, int row, int col)
{
    gLayout->addWidget(w, row+1, col+1);
}

void CustomWindow::addWidget(QWidget *w, int row, int col, int rowSpan, int colSpan)
{
    gLayout->addWidget(w, row+1, col+1, rowSpan, colSpan);
}
