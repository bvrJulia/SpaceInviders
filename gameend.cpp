#include "gameend.h"
#include "ui_gameend.h"

GameEnd::GameEnd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameEnd)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
}

GameEnd::~GameEnd()
{
    delete ui;
}

void GameEnd::changeText(QString str){
    ui->label->setText(str);
}

void GameEnd::on_pushButton_clicked()
{
    this->close();
    emit next();
}


void GameEnd::on_pushButton_2_clicked()
{
    this->close();
    emit menu();
}

void GameEnd::keyPressEvent(QKeyEvent *e){
    if(e->key()==Qt::Key_Y){
        this->close();
        emit next();
    }else if(e->key()==Qt::Key_N){
        this->close();
        emit menu();
    }
}
