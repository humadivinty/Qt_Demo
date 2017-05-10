#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_myModel(0)
{
    ui->setupUi(this);
    ui->tableView->setModel(&m_myModel);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    static int iCount = 0;
    QString qTemp = (iCount/2 == 0) ?QString("connect"):QString("disconnect");
    m_myModel.AddData(QString("172.18.0.%1").arg(iCount++), qTemp);
}

void MainWindow::on_pushButton_2_clicked()
{
    m_myModel.ModifyData("", "");
}
