#ifndef GAMEPAUSE_H
#define GAMEPAUSE_H

#include <QDialog>
#include <QKeyEvent>

namespace Ui {
class GamePause;
}

class GamePause : public QDialog
{
    Q_OBJECT

public:
    explicit GamePause(QWidget *parent = nullptr);
    ~GamePause();

private:
    Ui::GamePause *ui;
    void keyPressEvent(QKeyEvent *);
signals:
    void menu();
    void cont();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // GAMEPAUSE_H
