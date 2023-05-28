#include "gamedesighn.h"
#include "ui_gamedesighn.h"

GameDesighn::GameDesighn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameDesighn)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setFixedSize(700, 900);
    m_music = new QMediaPlayer();
    m_musiclist = new QMediaPlaylist(m_music);
    m_music->setPlaylist(m_musiclist);
    m_musiclist->addMedia(QUrl("qrc:/sounds/yehat.mp3"));
    m_musiclist->setPlaybackMode(QMediaPlaylist::CurrentItemInLoop);
    Monstr mon(QPoint(0,0),1);
    mons = new QVector<Monstr>({mon});
    images = new QVector<QImage>{QImage(":/images/mon1.png"),QImage(":/images/mon2.png"),QImage(":/images/mon3.png"),
            QImage(":/images/mon4.png"), QImage(":/images/mon5.png")};
    ui->spinBox->setFocusPolicy(Qt::NoFocus);
    ui->spinBox_2->setFocusPolicy(Qt::NoFocus);
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

void GameDesighn::on_pushButton_2_clicked()
{
    if (mons->size()!=1){
        QFile fileJson("../SpaceInvidors/levels/0.json");

        fileJson.open(QIODevice::WriteOnly);
        QVariantMap testMap;

        testMap.insert("Move", ui->spinBox_2->value());
        testMap.insert("Shot", ui->spinBox->value());
        for (int i = 1; i<mons->size(); i++){
            QString str1 = "Mon";
            if (i<10){
                str1 += "0";
            }
            str1 += QString::number(i);
            QString str2 = QString::number(mons->at(i).getPlace().x())+","+QString::number(mons->at(i).getPlace().y()-475)+","+QString::number(mons->at(i).getLives());
            testMap.insert(str1, str2);
        }
        fileJson.write(QJsonDocument(QJsonObject::fromVariantMap(testMap)).toJson());
        fileJson.close();
    }
}


void GameDesighn::on_pushButton_3_clicked()
{
    if (button !=1){
        button = 1;
    }else{
        button = 0;
    }
    repaint();
}


void GameDesighn::on_pushButton_4_clicked()
{
    if (button !=2){
        button = 2;
    }else{
        button = 0;
    }
    repaint();
}


void GameDesighn::on_pushButton_5_clicked()
{
    if (button !=3){
        button = 3;
    }else{
        button = 0;
    }
    repaint();
}


void GameDesighn::on_pushButton_6_clicked()
{
    if (button !=4){
        button = 4;
    }else{
        button = 0;
    }
    repaint();
}


void GameDesighn::on_pushButton_7_clicked()
{
    if (button !=5){
        button = 5;
    }else{
        button = 0;
    }
    repaint();
}

void GameDesighn::paintEvent(QPaintEvent *){
    QPainter painter(this);
    painter.setPen(QPen(QBrush(QColor(250,250,250)), 3));
    painter.setBrush(QBrush(QColor(250,250,250)));
    painter.drawLine(0,550,700,550);
    painter.drawLine(0,550,0,800);
    painter.drawLine(700,550,700,800);
    painter.drawLine(0,800,700,800);

    //painter.drawLine(0,350,700,490);
    QPoint x1(0,0);
    QPoint x2(0,0);
    if (button == 1){
        x1 = QPoint(20,480);
        x2 = QPoint(140,490);
    }else if (button == 2){
        x1 = QPoint(150,480);
        x2 = QPoint(270,490);
    }else if (button == 3){
        x1 = QPoint(280,480);
        x2 = QPoint(400,490);
    }else if (button == 4){
        x1 = QPoint(420,480);
        x2 = QPoint(540,490);
    }else if (button == 5){
        x1 = QPoint(540,480);
        x2 = QPoint(660,490);
    }
    painter.drawRect(QRect(x1,x2));
    for (int i = 1; i<mons->size();i++){
        QPoint point = mons->at(i).getPlace();
        if (mons->at(i).getLives()==1){
            painter.drawImage(QRect(point.x()-20,point.y()-20,40,40),images->at(0));
        } else if (mons->at(i).getLives()==2){
            painter.drawImage(QRect(point.x()-20,point.y()-20,40,40),images->at(1));
        }else if (mons->at(i).getLives()==3){
            painter.drawImage(QRect(point.x()-20,point.y()-20,40,40),images->at(2));
        } else if (mons->at(i).getLives()==4){
            painter.drawImage(QRect(point.x()-20,point.y()-20,40,40),images->at(3));
        }else if (mons->at(i).getLives()==5){
            painter.drawImage(QRect(point.x()-20,point.y()-20,40,40),images->at(4));
        }
    }
}
void GameDesighn::mousePressEvent(QMouseEvent  *){
    QPoint mouse = QCursor::pos();
    if (button!=0){
        if (findMon(mouse)==-1){
            mouse.setX(mouse.x()-627);
            if (mouse.x()>0 && mouse.x()<700 &&mouse.y()>600 && mouse.y()<850){
                mouse.setX((mouse.x()/50)*50+25);
                mouse.setY((mouse.y()/50)*50-25);
                Monstr mon(mouse, button);
                mons->push_back(mon);
            }
        }
    }else{
        if (findMon(mouse)!=-1){
            mons->erase(mons->begin()+findMon(mouse));
        }
    }
    repaint();

}

int GameDesighn::findMon(QPoint po){
    po.setX(po.x()-627);
    po.setX((po.x()/50)*50+25);
    po.setY((po.y()/50)*50-25);
    for (int i = 1; i < mons->size(); i++){
        if(po==mons->at(i).getPlace()){
            return i;
        }
    }
    return -1;
}
