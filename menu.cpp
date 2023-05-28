#include "menu.h"
#include "ui_menu.h"
#include <QPalette>

Menu::Menu(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    setFixedSize(700, 900);
    gWindow = new GamePlay();
    dWindow = new GameDesighn();
    ui->comboBox->addItem("Choose level",Qt::AlignCenter);
    ui->comboBox->addItem("1 level",Qt::AlignCenter);
    ui->comboBox->addItem("2 level",Qt::AlignCenter);
    ui->comboBox->addItem("3 level",Qt::AlignCenter);
    ui->comboBox->addItem("4 level",Qt::AlignCenter);
    ui->comboBox->addItem("5 level",Qt::AlignCenter);
    ui->comboBox->addItem("User level",Qt::AlignCenter);
    connect(gWindow, &GamePlay::firstWindow, this, &Menu::show);
    connect(dWindow, &GameDesighn::firstWindow, this, &Menu::show);
    connect(ui->pushButton_3, SIGNAL(clicked()), qApp, SLOT(quit()));
    setWindowFlags(Qt::FramelessWindowHint);
    setFocusPolicy(Qt::NoFocus);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    gWindow->start();
    gWindow->show();
    this->close();
}


void Menu::on_comboBox_currentIndexChanged(int index)
{
    if (index == 0){
        gWindow->setUserLvl(-1);
    } else if (index == 6){
        gWindow->setUserLvl(0);
    } else{
        gWindow->setUserLvl(index);
    }
}


void Menu::on_pushButton_2_clicked()
{
    dWindow->show();
    dWindow->start();
    this->close();
}

void Menu::keyPressEvent(QKeyEvent *e){
    if(e->key()==Qt::Key_E){
        qApp->quit();
    }
}
