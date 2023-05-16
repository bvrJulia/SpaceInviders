#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include "controller.h"
#include <QTimer>
#include <QMessageBox>

namespace Ui {
class GamePlay;
}

class GamePlay : public QWidget
{
    Q_OBJECT

public:
    explicit GamePlay(QWidget *parent = nullptr);
    ~GamePlay();
    void start();
signals:
    void firstWindow();
private:
    Ui::GamePlay *ui;
    Controller* control;
    QTimer* timer;
    int lvl;
private slots:
    // Слот-обработчик нажатия кнопки
    void on_pushButton_clicked();
    void on_timeout();
    void lvl_changed();
protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
};

#endif // GAMEPLAY_H
