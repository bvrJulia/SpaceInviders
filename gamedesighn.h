#ifndef GAMEDESIGHN_H
#define GAMEDESIGHN_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>

namespace Ui {
class GameDesighn;
}

class GameDesighn : public QWidget
{
    Q_OBJECT

public:
    explicit GameDesighn(QWidget *parent = nullptr);
    ~GameDesighn();
    void start();

private:
    Ui::GameDesighn *ui;   
    QMediaPlayer * m_music;
    QMediaPlaylist * m_musiclist;
signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();
};

#endif // GAMEDESIGHN_H
