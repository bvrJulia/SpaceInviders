#include "gamepause.h"
#include "ui_gamepause.h"

GamePause::GamePause(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GamePause)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
}

GamePause::~GamePause()
{
    delete ui;
}

void GamePause::on_pushButton_clicked()
{
    emit menu();

}


void GamePause::on_pushButton_2_clicked()
{
    emit cont();
}

void GamePause::keyPressEvent(QKeyEvent *e){
    if(e->key()==Qt::Key_C){
        emit cont();
    }else if(e->key()==Qt::Key_M){
        emit menu();
    }
}
