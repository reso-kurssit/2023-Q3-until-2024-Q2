#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    operand = -1;
    connect(ui->num1, SIGNAL(clicked(bool)), this, SLOT(handleClickedNumbers()));
    connect(ui->num2, SIGNAL(clicked(bool)), this, SLOT(handleClickedNumbers()));
    connect(ui->num3, SIGNAL(clicked(bool)), this, SLOT(handleClickedNumbers()));
    connect(ui->num4, SIGNAL(clicked(bool)), this, SLOT(handleClickedNumbers()));
    connect(ui->num5, SIGNAL(clicked(bool)), this, SLOT(handleClickedNumbers()));
    connect(ui->num6, SIGNAL(clicked(bool)), this, SLOT(handleClickedNumbers()));
    connect(ui->num7, SIGNAL(clicked(bool)), this, SLOT(handleClickedNumbers()));
    connect(ui->num8, SIGNAL(clicked(bool)), this, SLOT(handleClickedNumbers()));
    connect(ui->num9, SIGNAL(clicked(bool)), this, SLOT(handleClickedNumbers()));
    connect(ui->num0, SIGNAL(clicked(bool)), this, SLOT(handleClickedNumbers()));

    connect(ui->opeAdd, SIGNAL(clicked(bool)), this, SLOT(handleOperands()));
    connect(ui->opeSub, SIGNAL(clicked(bool)), this, SLOT(handleOperands()));
    connect(ui->opeMul, SIGNAL(clicked(bool)), this, SLOT(handleOperands()));
    connect(ui->opeDiv, SIGNAL(clicked(bool)), this, SLOT(handleOperands()));

    connect(ui->Clear, SIGNAL(clicked(bool)), this, SLOT(handleClear()));
    connect(ui->Enter, SIGNAL(clicked(bool)), this, SLOT(handleEnter()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleClickedNumbers()
{
    if (operand == -1)
    {
        ui->value1->setText(ui->value1->displayText() + sender()->objectName().back());
    }
    else
    {
        ui->value2->setText(ui->value2->displayText() + sender()->objectName().back());
    }
    //qDebug() << sender()->objectName().back();

}

void MainWindow::handleOperands()
{
    if (sender()->objectName() == "opeAdd")
    {
        operand = 0;
    }
    else if (sender()->objectName() == "opeSub")
    {
        operand = 1;
    }
    else if (sender()->objectName() == "opeMul")
    {
        operand = 2;
    }
    else if (sender()->objectName() == "opeDiv")
    {
        operand = 3;
    }

}

void MainWindow::handleEnter()
{

    double left = ui->value1->displayText().toDouble();
    double right = ui->value2->displayText().toDouble();

    switch (operand)
    {
        case 0:
            ui->result->setText(QString::number(left + right));
            break;
        case 1:
            ui->result->setText(QString::number(left - right));
            break;
        case 2:
            ui->result->setText(QString::number(left * right));
            break;
        case 3:
            ui->result->setText(QString::number(left / right));
            break;
    }

}

void MainWindow::handleClear()
{
    operand = -1;
    ui->value1->setText(nullptr);
    ui->value2->setText(nullptr);
    ui->result->setText(nullptr);
}

