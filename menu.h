#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "gameplay.h"
#include <QIcon>
#include "gamedesighn.h"

namespace Ui { class Menu; }


class Menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_pushButton_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_2_clicked();

private:
    Ui::Menu *ui;
    // второе и третье окна
    GamePlay *gWindow;
    GameDesighn *dWindow;
};
#endif // MENU_H
