#ifndef GAMEEND_H
#define GAMEEND_H

#include <QDialog>
#include <QKeyEvent>

namespace Ui {
class GameEnd;
}

class GameEnd : public QDialog
{
    Q_OBJECT

public:
    explicit GameEnd(QWidget *parent = nullptr);
    ~GameEnd();
    void changeText(QString);

private slots:

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::GameEnd *ui;
    void keyPressEvent(QKeyEvent *);
signals:
    void menu();
    void next();
};

#endif // GAMEEND_H
