#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , pTimerP1 (new QTimer (this))
    , pTimerP2 (new QTimer (this))

{
    ui->setupUi(this);
    ui->progressP1->setMinimum(0);
    ui->progressP2->setMinimum(0);
    ui->progressP1->setMaximum(100);
    ui->progressP2->setMaximum(100);
    ui->progressP1->setValue(100);
    ui->progressP2->setValue(100);

    ui->titles->setText("Choose playtime before starting the game");
    ui->titles->setAlignment(Qt::AlignCenter);

    connect(ui->start, SIGNAL(clicked(bool)), this, SLOT(startGame()));
    connect(ui->pause, SIGNAL(clicked(bool)), this, SLOT(pauseGame()));
    connect(ui->stop, SIGNAL(clicked(bool)), this, SLOT(stopGame()));

    connect(ui->time120, &QPushButton::clicked, this, [=](){ this->handleTimer(120); });
    connect(ui->time300, &QPushButton::clicked, this, [=](){ this->handleTimer(300); });

    connect(ui->endTurnP1, SIGNAL(clicked(bool)), this, SLOT(handleTurns()));
    connect(ui->endTurnP2, SIGNAL(clicked(bool)), this, SLOT(handleTurns()));

    connect(pTimerP1, SIGNAL(timeout()), this, SLOT(update()));
    connect(pTimerP2, SIGNAL(timeout()), this, SLOT(update()));

    ui->endTurnP1->setDisabled(true);
    ui->endTurnP2->setDisabled(true);
    ui->start->setDisabled(true);
    ui->pause->setDisabled(true);
    ui->stop->setDisabled(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateProgressBars()
{
    ui->progressP1->setValue(timeLeftP1);
    ui->progressP2->setValue(timeLeftP2);
}

void MainWindow::startGame()
{
    ui->titles->setText("Game ongoing, switch player via END TURN");

    pTimerP1->setInterval(1000);
    pTimerP2->setInterval(1000);

    ui->pause->setDisabled(true);
    ui->start->setDisabled(true);
    ui->stop->setDisabled(false);
    ui->time120->setDisabled(true);
    ui->time300->setDisabled(true);

    if (currentPlayer == 1 || currentPlayer == 0)
    {
        pTimerP1->start();
        ui->endTurnP1->setDisabled(false);
    }
    else if (currentPlayer == 2)
    {
        pTimerP2->start();
        ui->endTurnP2->setDisabled(false);
    }
    else
    {
        pTimerP1->start();
        ui->endTurnP1->setDisabled(false);
    }
}

void MainWindow::stopGame()
{
    ui->titles->setText("Reset game");

    pTimerP1->stop();
    pTimerP2->stop();

    ui->progressP1->setValue(0);
    ui->progressP2->setValue(0);
    currentPlayer = 0;

    ui->endTurnP1->setDisabled(true);
    ui->endTurnP2->setDisabled(true);
    ui->start->setDisabled(true);
    ui->pause->setDisabled(true);
    ui->time120->setDisabled(false);
    ui->time300->setDisabled(false);
}

void MainWindow::pauseGame()
{
    pTimerP1->stop();
    pTimerP2->stop();

    ui->endTurnP1->setDisabled(true);
    ui->endTurnP2->setDisabled(true);
}

void MainWindow::handleTimer(short gameTime)
{
    ui->titles->setText("Ready to play, press CONTINUE to start");

    pTimerP1->stop();
    pTimerP2->stop();

    timeLeftP1 = gameTime;
    timeLeftP2 = gameTime;
    ui->progressP1->setMaximum(gameTime);
    ui->progressP2->setMaximum(gameTime);
    updateProgressBars();

    ui->endTurnP1->setDisabled(true);
    ui->endTurnP2->setDisabled(true);
    ui->start->setDisabled(false);
    ui->pause->setDisabled(true);
    ui->stop->setDisabled(true);
    ui->time120->setDisabled(true);
    ui->time300->setDisabled(true);
}

void MainWindow::handleTurns()
{
    ui->titles->setText("Switch player via END TURN");

    if (ui->endTurnP1 == sender())
    {
        pTimerP1->stop(); ui->endTurnP1->setDisabled(true); ui->endTurnP2->setDisabled(false); pTimerP2->start();
    }
    else if (ui->endTurnP2 == sender())
    {
        pTimerP2->stop(); ui->endTurnP2->setDisabled(true); ui->endTurnP1->setDisabled(false); pTimerP1->start();
    }
}

void MainWindow::start()
{
    qDebug() << "Start timer?" ;
}

void MainWindow::update()
{
    if (pTimerP1->isActive())
    {
        timeLeftP1--;
        currentPlayer = 1;
        qDebug() << "Time left (P1) = " << timeLeftP1 ;
    }
    else if (pTimerP2->isActive())
    {
        timeLeftP2--;
        currentPlayer = 2;
        qDebug() << "Time left (P2) = " << timeLeftP2 ;
    }

    updateProgressBars();

    if (timeLeftP1 == 0 && timeLeftP2 >= 1)
    {
        pTimerP1->stop();
        ui->endTurnP1->setDisabled(true);
        return  ui->titles->setText("Player 2. WON!");
    }
    else if (timeLeftP2 == 0 && timeLeftP1 >= 1)
    {
        pTimerP2->stop();
        ui->endTurnP2->setDisabled(true);
        return  ui->titles->setText("Player 1. WON!");
    }
}
