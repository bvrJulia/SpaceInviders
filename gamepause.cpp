#include "gamepause.h"
#include "ui_gamepause.h"

GamePause::GamePause(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GamePause)
{
    ui->setupUi(this);
}

GamePause::~GamePause()
{
    delete ui;
}

void GamePause::on_pushButton_clicked()
{
    this->close();
    emit firstWindow();
}

