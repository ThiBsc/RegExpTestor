#include "header/regexwindow.h"
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QRegularExpression>
#include <QToolButton>
#include <QStyle>
#include <QSplitter>
#include <QVBoxLayout>
#include <QSizePolicy>
#include <QMessageBox>

QString RegExWindow::version = "1.0";

RegExWindow::RegExWindow(QWidget *parent)
    : CustomWindow(parent)
{
    setWindowTitle("RegExp testor");

    splitter = new QSplitter(Qt::Horizontal, this);
    splitter->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    splitter->setHandleWidth(1);
    left = new QWidget(this);
    right = new QWidget(this);
    splitter->addWidget(left);
    splitter->addWidget(right);
    vlLeft = new QVBoxLayout(left);
    vlLeft->setMargin(2);
    vlRight = new QVBoxLayout(right);
    vlRight->setMargin(2);

    btnInfo = new QToolButton(this);
    btnInfo->setText("About");
    btnInfo->setToolTip(btnInfo->text());
    btnInfo->setIcon(style()->standardIcon(QStyle::SP_MessageBoxQuestion));
    statusBar->addPermanentWidget(btnInfo);
    btnInfo->resize(statusBar->height(), statusBar->height());

    lblReg.setText("RegExp:");
    lblTest.setText("Test string:");
    lblMatch.setText("Matchs:");

    leReg = new QLineEdit(this);
    pteTest = new QPlainTextEdit(this);
    pteMatch = new QPlainTextEdit(this);
    pteMatch->setReadOnly(true);

    lblReg.setStyleSheet("color: lightgray;");
    lblTest.setStyleSheet(lblReg.styleSheet());
    lblMatch.setStyleSheet(lblReg.styleSheet());
    leReg->setStyleSheet("background: gainsboro;");
    pteTest->setStyleSheet(leReg->styleSheet());
    pteMatch->setStyleSheet(leReg->styleSheet());

    vlLeft->addWidget(&lblReg);
    vlLeft->addWidget(leReg);
    vlLeft->addWidget(&lblTest);
    vlLeft->addWidget(pteTest);
    vlRight->addWidget(&lblMatch);
    vlRight->addWidget(pteMatch);
    addWidget(splitter, 0, 0);

    connect(leReg, SIGNAL(textChanged(QString)), this, SLOT(printMatch(QString)));
    connect(pteTest, SIGNAL(textChanged()), this, SLOT(refreshMatch()));
    connect(btnInfo, SIGNAL(clicked(bool)), this, SLOT(devInfo()));
}

RegExWindow::~RegExWindow()
{
    delete leReg;
    delete pteTest;
    delete pteMatch;
    delete btnInfo;
    delete splitter;
    delete left;
    delete right;
    delete vlLeft;
    delete vlRight;
}

void RegExWindow::printMatch(QString regex)
{
    QRegularExpression rexp(regex);
    rexp.setPatternOptions(QRegularExpression::MultilineOption);
    pteMatch->clear();
    QPalette pal = statusBar->palette();
    if (rexp.isValid()){
        if (!regex.isEmpty()){
            auto rexp_it = rexp.globalMatch(pteTest->toPlainText());
            int matchNum = 1;
            while (rexp_it.hasNext()){
                auto match = rexp_it.next();
                pteMatch->appendHtml(QString("<span style='font-weight: bold; color: cornflowerblue;'>Match %1.</span>").arg(matchNum++));
                for (QString s : match.capturedTexts())
                    pteMatch->appendHtml(QString("<span>&nbsp;&nbsp;&nbsp;%1</span>").arg(s));
            }
            pal.setColor(QPalette::WindowText, Qt::green);
            statusBar->setPalette(pal);
            statusBar->showMessage("regex valid.");
        }
    }
    else{
        pal.setColor(QPalette::WindowText, QColor("lightcoral"));
        statusBar->setPalette(pal);
        statusBar->showMessage(rexp.errorString());
    }
}

void RegExWindow::refreshMatch()
{
    printMatch(leReg->text());
}

void RegExWindow::devInfo()
{
    QMessageBox::information(this,
                             windowTitle()+" - About",
                             "<div><b>"+windowTitle()+" v"+RegExWindow::version+"</b><br>by thibDev - 2017, <a href='https://github.com/thibDev'>GitHub</a></div>",
                             QMessageBox::Ok);
}
