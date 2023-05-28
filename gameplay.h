#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include <QWidget>
#include <QPainter>
#include <QKeyEvent>
#include "controller.h"
#include <QTimer>
#include <QMessageBox>
#include <QSound>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include "gameend.h"
#include "gamepause.h"

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
    void setUserLvl(int levl);
signals:
    void firstWindow();
private:
    Ui::GamePlay *ui;
    Controller* control;
    QTimer* timer;
    int lvl;
    int user_lvl = -1;
    QVector<QImage>* images;

    QMediaPlayer * m_player;
    QMediaPlaylist * m_playlist;
    QMediaPlayer * m_music;
    QMediaPlaylist * m_musiclist;
    bool pause = false;
    int time =0;
    GameEnd * gEnd;
    GamePause* gPause;
    bool win = true;
private slots:
    void on_pushButton_clicked();
    void on_timeout();
    void lvl_changed();
    void on_pushButton_2_clicked();

protected:
    void paintEvent(QPaintEvent *);
    void keyPressEvent(QKeyEvent *);
};

#endif // GAMEPLAY_H
