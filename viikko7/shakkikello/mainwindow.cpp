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

    connect(ui->start, SIGNAL(clicked(bool)), this, SLOT(startGame()));
    connect(ui->stop, SIGNAL(clicked(bool)), this, SLOT(stopGame()));

    connect(ui->time120, &QPushButton::clicked, this, [=](){ this->handleTimer(120); });
    connect(ui->time300, &QPushButton::clicked, this, [=](){ this->handleTimer(300); });

    connect(ui->endTurnP1, SIGNAL(clicked(bool)), this, SLOT(handleTurns()));
    connect(ui->progressP1, SIGNAL(clicked(bool)), this, SLOT(handlePlayers()));
    connect(ui->endTurnP2, SIGNAL(clicked(bool)), this, SLOT(handleTurns()));
    connect(ui->progressP2, SIGNAL(clicked(bool)), this, SLOT(handlePlayers()));

    //connect(ui->textLabel, SIGNAL(clicked(bool)), this, SLOT(handleTitles()));

    connect(pTimerP1, SIGNAL(timeout()), this, SLOT(update()));
    connect(pTimerP2, SIGNAL(timeout()), this, SLOT(update()));
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
    pTimerP1->setInterval(1000);
    pTimerP2->setInterval(1000);

    pTimerP1->start();

    ui->endTurnP1->setDisabled(false);
    ui->endTurnP2->setDisabled(false);
}

void MainWindow::stopGame()
{
    pTimerP1->stop();
    pTimerP2->stop();

    ui->endTurnP1->setDisabled(true);
    ui->endTurnP2->setDisabled(true);
}

void MainWindow::handleTimer(short gameTime)
{
    pTimerP1->stop();
    pTimerP2->stop();

    timeLeftP1 = gameTime;
    timeLeftP2 = gameTime;
    ui->progressP1->setMaximum(gameTime);
    ui->progressP2->setMaximum(gameTime);
    updateProgressBars();

    ui->endTurnP1->setDisabled(true);
    ui->endTurnP2->setDisabled(true);
}

void MainWindow::handlePlayers()
{

}

void MainWindow::handleTurns()
{

    if (ui->endTurnP1 == sender())
    {
        pTimerP1->stop(); ui->endTurnP1->setDisabled(true); ui->endTurnP2->setDisabled(false); pTimerP2->start();
    }
    else if (ui->endTurnP2 == sender())
    {
        pTimerP2->stop(); ui->endTurnP2->setDisabled(true); ui->endTurnP1->setDisabled(false); pTimerP1->start();
    }

}

void MainWindow::titles()
{
    // hox mahdollisesti lisää joku end game, reset tms, jos haluat pitää pausen ja continuen
    // 1. Select playtime and press "START GAME"
    // 2. Ready to play
    // 3. Game ongoing
    // 4. Player " " WON!
    // 5. Reset game
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
        qDebug() << "Time left (P1) = " << timeLeftP1 ;
    }
    else if (pTimerP2->isActive())
    {
        timeLeftP2--;
        qDebug() << "Time left (P2) = " << timeLeftP2 ;
    }

    updateProgressBars();
}

