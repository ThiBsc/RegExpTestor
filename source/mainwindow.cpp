#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "customwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    treeWidget = new QTreeWidget(this);
    treeWidget->setAnimated(true);
    treeWidget->setColumnCount(1);
    treeWidget->setHeaderLabel("Menu");
    treeWidget->setStyleSheet("background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(68, 132, 200, 255), stop:1 rgba(160, 214, 255, 255)); color: black;");
    QTreeWidgetItem *substance = new QTreeWidgetItem;
    substance->setText(0, "Substances");
    treeWidget->addTopLevelItem(substance);
    substance->addChild(new QTreeWidgetItem((QTreeWidget * )0, QStringList("Créer")));

    QTreeWidgetItem *melange = new QTreeWidgetItem;
    melange->setText(0, "Mélanges");
    treeWidget->addTopLevelItem(melange);
    melange->addChild(new QTreeWidgetItem((QTreeWidget * )0, QStringList("Calculer")));
    ui->horizontalLayout->addWidget(treeWidget);

    webView = new QWebView(this);
    webView->setHtml("<body>Hello World!</body>");
    ui->horizontalLayout->addWidget(webView);
}

MainWindow::~MainWindow()
{
    delete ui;
}
