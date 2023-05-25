#include "gameplay.h"
#include "ui_gameplay.h"

GamePlay::GamePlay(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GamePlay)
{
    ui->setupUi(this);
    setFixedSize(700, 900);

    timer = new QTimer(this);

    lvl = 1;
    if (user_lvl ==-1){
        this->setWindowTitle("1 level");
    } else if(user_lvl==0){
        this->setWindowTitle("User level");
    }else{
        this->setWindowTitle(QString::number(user_lvl)+" level");
    }
    connect(timer, SIGNAL(timeout()), this, SLOT(on_timeout()));

    images = new QVector<QImage>{QImage(":/images/mon1.png"),QImage(":/images/mon2.png"),QImage(":/images/mon3.png"),
            QImage(":/images/mon4.png"), QImage(":/images/mon5.png"),QImage(":/images/shot.png"),
            QImage(":/images/player.png"),QImage(":/images/live.png")};
    m_player = new QMediaPlayer();
    m_playlist = new QMediaPlaylist(m_player);
    m_player->setPlaylist(m_playlist);
    m_playlist->addMedia(QUrl("qrc:/sounds/shot.mp3"));
    m_music = new QMediaPlayer();
    m_musiclist = new QMediaPlaylist(m_music);
    m_music->setPlaylist(m_musiclist);
    m_musiclist->addMedia(QUrl("qrc:/sounds/hyperspace.mp3"));
    m_musiclist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    //gEnd = new gameEnd();

}

void GamePlay::start(){
    timer->start(50);
    if (user_lvl ==-1){
        control = new Controller(":/levels/"+QString::number(lvl)+".json");
    } else if (user_lvl ==0){
        control = new Controller("../SpaceInvidors/levels/0.json");
    }else{
        control = new Controller(":/levels/"+QString::number(user_lvl)+".json");
    }
    m_music->play();
}

GamePlay::~GamePlay()
{
    delete ui;
}

void GamePlay::setUserLvl(int levl){
    user_lvl=levl;
}

void GamePlay::on_pushButton_clicked()
{
    m_music->stop();
    timer->stop();
    this->close();  // Закрываем окно
    delete control;
    emit firstWindow(); // И вызываем сигнал на открытие главного окна*/
}

void GamePlay::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setPen(QPen(QBrush(QColor(200,0,150)), 3));
    painter.setBrush(QBrush(QColor(200,0,150)));
    for (int i =0; i<control->getMonstrs().size();i++){
        QPoint point = control->getMonstrs()[i].getPlace();
        if (point.x()>control->getMonstrs()[i].getEndPlace().x()){
            point.setX(point.x()-10);
            if (point.x()<control->getMonstrs()[i].getEndPlace().x()){
                point.setX(control->getMonstrs()[i].getEndPlace().x());
            }
        } else if (point.x()<control->getMonstrs()[i].getEndPlace().x()){
            point.setX(point.x()+10);
            if (point.x()>control->getMonstrs()[i].getEndPlace().x()){
                point.setX(control->getMonstrs()[i].getEndPlace().x());
            }
        }else if (point.y()<control->getMonstrs()[i].getEndPlace().y()){
            point.setY(point.y()+10);
            if (point.y()>control->getMonstrs()[i].getEndPlace().y()){
                point.setY(control->getMonstrs()[i].getEndPlace().y());
            }
        }else if (point.y()>control->getMonstrs()[i].getEndPlace().y()){
            point.setX(point.x()-10);
            if (point.y()<control->getMonstrs()[i].getEndPlace().y()){
                point.setY(control->getMonstrs()[i].getEndPlace().y());
            }
        }
        control->setMonstrPlace(i, point);
        if (control->getMonstrs()[i].getLives()==1){
            painter.drawImage(QRect(point.x()-20,point.y()-20,40,40),images->at(0));
        } else if (control->getMonstrs()[i].getLives()==2){
            painter.drawImage(QRect(point.x()-20,point.y()-20,40,40),images->at(1));
        }else if (control->getMonstrs()[i].getLives()==3){
            painter.drawImage(QRect(point.x()-20,point.y()-20,40,40),images->at(2));
        } else if (control->getMonstrs()[i].getLives()==4){
            painter.drawImage(QRect(point.x()-20,point.y()-20,40,40),images->at(3));
        }else if (control->getMonstrs()[i].getLives()==5){
            painter.drawImage(QRect(point.x()-20,point.y()-20,40,40),images->at(4));
        }

    }
    painter.setPen(QPen(QBrush(QColor(200,0,0)), 3));
    painter.setBrush(QBrush(QColor(200,0,0)));
    for (int i =0; i<control->getShots().size();i++){
        QPoint point = control->getShots()[i].getPlace();
        if (point.y()<control->getShots()[i].getEndPlace().y()){
            point.setY(point.y()+15);
            if (point.y()>control->getShots()[i].getEndPlace().y()){
                point.setY(control->getShots()[i].getEndPlace().y());
            }
        }else if (point.y()>control->getShots()[i].getEndPlace().y()){
            point.setY(point.y()-15);
            if (point.y()<control->getShots()[i].getEndPlace().y()){
                point.setY(control->getShots()[i].getEndPlace().y());
            }
        }
        control->setShotPlace(i, point);
        painter.drawImage(QRect(point.x()-3,point.y()-7,6,14),images->at(5));
    }
    painter.setPen(QPen(QBrush(QColor(0,200,0)), 3));
    painter.setBrush(QBrush(QColor(0,200,0)));

    QPoint point = control->getPlayer().getPlace();
    if (point.x()>control->getPlayer().getEndPlace().x()){
        point.setX(point.x()-10);
        if (point.x()<control->getPlayer().getEndPlace().x()){
            point.setX(control->getPlayer().getEndPlace().x());
        }
    } else if (point.x()<control->getPlayer().getEndPlace().x()){
        point.setX(point.x()+10);
        if (point.x()>control->getPlayer().getEndPlace().x()){
            point.setX(control->getPlayer().getEndPlace().x());
        }
    }
    control->setPlayerPlace(point);
    painter.drawImage(QRect(point.x()-20,point.y()-20,40,40),images->at(6));
    if (control->getPlayer().getLives()>0){
        painter.drawImage(QRect(660, 10, 40, 30),images->at(7));
    }
    if (control->getPlayer().getLives()>1){
        painter.drawImage(QRect(620, 10, 40, 30),images->at(7));
    }
    if (control->getPlayer().getLives()>2){
        painter.drawImage(QRect(580, 10, 40, 30),images->at(7));
    }

}

void GamePlay::lvl_changed(){
    lvl++;
    this->setWindowTitle(QString::number(lvl)+" level");
    timer->stop();
    delete control;
    start();
}

void GamePlay::on_timeout(){
    control->timeout();
    if (control->endOfLevel()==-1){
        timer->stop();
        QMessageBox* message = new QMessageBox();
        message->setText("You are loser");
        message->setWindowTitle("End of level!");
        QPushButton* bt = new QPushButton("Continue");
        message->addButton(bt, QMessageBox::ActionRole);
        connect(bt, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
        message->setVisible(true);

    } else if (control->endOfLevel()==1){
        timer->stop();
        QMessageBox* message = new QMessageBox();
        message->setText("You are winner");
        message->setWindowTitle("End of level!");
        QPushButton* bt = new QPushButton("Menu");
        message->addButton(bt, QMessageBox::ActionRole);
        connect(bt, SIGNAL(clicked()), this, SLOT(on_pushButton_clicked()));
        if (lvl<5 && user_lvl==-1){
            QPushButton* bt1 = new QPushButton("Continue");
            message->addButton(bt1, QMessageBox::ActionRole);
            connect(bt1, SIGNAL(clicked()), this, SLOT(lvl_changed()));
        } else{
            message->setWindowTitle("End of game!");
        }
        message->setVisible(true);
        //gEnd->show();
    } else{
        repaint();
    }
}

void GamePlay::keyPressEvent(QKeyEvent *e){
    QPoint place = control->getPlayer().getPlace();
    if (e->key()==Qt::Key_D && place.x()<680){
        place.setX(place.x()+25);
        if (place.x()>680){
            place.setX(680);
        }
        control->setPlayerEndPlace(place);
    }
    if (e->key()==Qt::Key_S && place.x()>20){
        place.setX(place.x()-25);
        if (place.x()<20){
            place.setX(20);
        }
        control->setPlayerEndPlace(place);
    }
    if (e->key()==Qt::Key_E){
        if (control->getTime()%100 == 0){ // time limit for shots???
            Shot shot;
            shot.setOwner(false);
            shot.setPlace(place);
            shot.setEndPlace(QPoint(place.y(),0));
            control->addShot(shot);
            m_player->play();
        }
    }
}

void GamePlay::on_pushButton_2_clicked()
{
    if (pause == false){
        timer->stop();
        pause = true;
    } else{
        timer->start();
        pause = false;
    }
}

