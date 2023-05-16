#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
    gWindow = new GamePlay();
    connect(gWindow, &GamePlay::firstWindow, this, &Menu::show);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    gWindow->start();
    gWindow->show();  // Показываем второе окно
    this->close();    // Закрываем основное окно
}
