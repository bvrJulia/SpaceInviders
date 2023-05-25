#ifndef GAMEDESIGHN_H
#define GAMEDESIGHN_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QFile>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMouseEvent>
#include <QPainter>
#include <QVector>
#include "monstr.h"
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
    int button = 1;
    QVector<Monstr>* mons;
    QVector<QImage>* images;
    int findMon(QPoint po);
signals:
    void firstWindow();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
    void on_pushButton_7_clicked();
protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
};

#endif // GAMEDESIGHN_H
