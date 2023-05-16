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
    connect(timer, SIGNAL(timeout()), this, SLOT(on_timeout()));



}

void GamePlay::start(){
    timer->start(50);
    control = new Controller(lvl);
}

GamePlay::~GamePlay()
{
    delete ui;
}

void GamePlay::on_pushButton_clicked()
{
    timer->stop();
    this->close();  // Закрываем окно
    delete control;
    emit firstWindow(); // И вызываем сигнал на открытие главного окна
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
        if (control->getMonstrs()[i].getLives()==1){
            painter.setPen(QPen(QBrush(QColor(200,0,180)), 3));
            painter.setBrush(QBrush(QColor(200,0,180)));
        } else if (control->getMonstrs()[i].getLives()==2){
            painter.setPen(QPen(QBrush(QColor(200,0,100)), 3));
            painter.setBrush(QBrush(QColor(200,0,100)));
        }else if (control->getMonstrs()[i].getLives()==3){
            painter.setPen(QPen(QBrush(QColor(200,0,0)), 3));
            painter.setBrush(QBrush(QColor(200,0,0)));
        }
        control->setMonstrPlace(i, point);
        painter.drawEllipse(point.x()-20,point.y()-20,40,40);
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
        painter.drawEllipse(point.x()-5,point.y()-5,10,10);
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
    painter.drawRect(point.x()-20,point.y()-20,40,40);
    if (control->getPlayer().getLives()>0){
        painter.drawEllipse(660, 10, 30, 30);
    }
    if (control->getPlayer().getLives()>1){
        painter.drawEllipse(620, 10, 30, 30);
    }
    if (control->getPlayer().getLives()>2){
        painter.drawEllipse(580, 10, 30, 30);
    }

}

void GamePlay::lvl_changed(){
    lvl++;
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
        if (lvl<5){
            QPushButton* bt1 = new QPushButton("Continue");
            message->addButton(bt1, QMessageBox::ActionRole);
            connect(bt1, SIGNAL(clicked()), this, SLOT(lvl_changed()));
        } else{
            message->setWindowTitle("End of game!");
        }
        message->setVisible(true);
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
        Shot shot;
        shot.setOwner(false);
        shot.setPlace(place);
        shot.setEndPlace(QPoint(place.y(),0));
        control->addShot(shot);
    }
}
