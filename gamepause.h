#ifndef GAMEPAUSE_H
#define GAMEPAUSE_H

#include <QWidget>

namespace Ui {
class GamePause;
}

class GamePause : public QWidget
{
    Q_OBJECT

public:
    explicit GamePause(QWidget *parent = nullptr);
    ~GamePause();

private slots:
    void on_pushButton_clicked();
signals:
    void firstWindow();

private:
    Ui::GamePause *ui;
};

#endif // GAMEPAUSE_H
