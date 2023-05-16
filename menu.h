#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "gameplay.h"
#include <QIcon>

namespace Ui { class Menu; }


class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Menu *ui;
    // второе и третье окна
    GamePlay *gWindow;
};
#endif // MENU_H
