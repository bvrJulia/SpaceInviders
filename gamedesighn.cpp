#include "gamedesighn.h"
#include "ui_gamedesighn.h"

GameDesighn::GameDesighn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameDesighn)
{
    ui->setupUi(this);
    setFixedSize(700, 900);
    m_music = new QMediaPlayer();
    m_musiclist = new QMediaPlaylist(m_music);
    m_music->setPlaylist(m_musiclist);
    m_musiclist->addMedia(QUrl("qrc:/sounds/yehat.mp3"));
    m_musiclist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
}

GameDesighn::~GameDesighn()
{
    delete ui;
}

void GameDesighn::on_pushButton_clicked()
{
    this->close();
    m_music->stop();
    emit firstWindow();
}

void GameDesighn::start(){
    m_music->play();
}
