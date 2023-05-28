#include "controller.h"
#include <QSound>
#include <QRandomGenerator>

Controller::Controller(QString lvl)
{
    //lvl_ = new Level(":/levels/"+QString::number(lvl)+".json");
    lvl_ = new Level(lvl);
    monstrs_=lvl_->getMonstrs();
    play_.setPlace(QPoint(350, 850));
    play_.setEndPlace(QPoint(350, 850));
    play_.setLives(3);
    time_ = 0;

}

void Controller::generateShot(){
    int num;

    if (!lvl_->getHard()){
        double a= QRandomGenerator::global()->generateDouble();
        num = a*monstrs_.size();
    }else{
        num = 0;
        for(int i = 1; i<monstrs_.size();i++){
            int minDist = sqrt((monstrs_[num].getPlace().x() - play_.getPlace().x())*(monstrs_[num].getPlace().x() - play_.getPlace().x())+
                               (monstrs_[num].getPlace().y() - play_.getPlace().y())*(monstrs_[num].getPlace().y() - play_.getPlace().y()));
            int currrentDist = sqrt((monstrs_[i].getPlace().x() - play_.getPlace().x())*(monstrs_[i].getPlace().x() - play_.getPlace().x())+
                               (monstrs_[i].getPlace().y() - play_.getPlace().y())*(monstrs_[i].getPlace().y() - play_.getPlace().y()));
            if(currrentDist<minDist){
                num = i;
            }
        }

    }
    Shot newShot;
    newShot.setOwner(true);
    newShot.setPlace(monstrs_[num].getPlace());
    newShot.setEndPlace(QPoint(monstrs_[num].getPlace().x(), 900));
    addShot(newShot);
}
void Controller::addShot(Shot shot){
    shots_.push_back(shot);
}
int Controller::endOfLevel(){
    for (int i = 0; i < monstrs_.size(); i++){
        if (monstrs_[i].getPlace().y()==850){
            return -1;
        }
    }
    if (play_.getLives() < 1){
        return -1;
    } else if (monstrs_.empty()){
        return 1;
    } else{
        return 0;
    }
}
void Controller::shotOnCreature(){
    int i = 0;
    while( i<shots_.size()){
        int dist = sqrt((shots_[i].getPlace().x() - play_.getPlace().x())*(shots_[i].getPlace().x() - play_.getPlace().x())+
                        (shots_[i].getPlace().y() - play_.getPlace().y())*(shots_[i].getPlace().y() - play_.getPlace().y()));
        if (shots_[i].getOwner() && dist<20){
            play_.shoted();
            shots_.erase(shots_.begin()+i);
        }else{
            i++;
        }
    }
    i =0;

    while(i <monstrs_.size()){
        int j = 0;
        while (j<shots_.size()){
            int dist = sqrt((shots_[j].getPlace().x() - monstrs_[i].getPlace().x())*(shots_[j].getPlace().x() - monstrs_[i].getPlace().x())+
                            (shots_[j].getPlace().y() - monstrs_[i].getPlace().y())*(shots_[j].getPlace().y() - monstrs_[i].getPlace().y()));
            if (!shots_[j].getOwner() && dist<20){
                monstrs_[i].shoted();
                shots_.erase(shots_.begin()+j);
                if (monstrs_[i].getLives()==0){
                    monstrs_.erase(monstrs_.begin()+i);
                    j =shots_.size();
                    i--;
                }
            }else{
                j++;
            }           
        }
        i++;
    }
}
void Controller::timeout(){
    time_ += 50;
    shotOnCreature();
    if (time_ % lvl_->getShotPeriod() == 0){
        generateShot();
    }
    if (time_ % lvl_->getMovePeriod() == 0){
        for (int i = 0; i <monstrs_.size(); i++){
            if (monstrs_[i].getPlace().x()==25 && monstrs_[i].getPlace().y()%100!=0){
                QPoint newPlace = QPoint(monstrs_[i].getPlace().x(),monstrs_[i].getPlace().y()+50);
                monstrs_[i].setEndPlace(newPlace);
            }else if (monstrs_[i].getPlace().x()==675 && monstrs_[i].getPlace().y()%100==0){
                QPoint newPlace = QPoint(monstrs_[i].getPlace().x(),monstrs_[i].getPlace().y()+50);
                monstrs_[i].setEndPlace(newPlace);
            }else if(monstrs_[i].getPlace().y()%100==0){
                QPoint newPlace = QPoint(monstrs_[i].getPlace().x()+50,monstrs_[i].getPlace().y());
                monstrs_[i].setEndPlace(newPlace);
            }else{
                QPoint newPlace = QPoint(monstrs_[i].getPlace().x()-50,monstrs_[i].getPlace().y());
                monstrs_[i].setEndPlace(newPlace);
            }
            /*QPoint newPlace = QPoint(monstrs_[i].getPlace().x(),monstrs_[i].getPlace().y()+100);
            monstrs_[i].setEndPlace(newPlace);*/
        }
    }
    int i = 0;
    while( i<shots_.size()){
        if (shots_[i].getOwner() && shots_[i].getPlace().y()>890){
            shots_.erase(shots_.begin()+i);
        }else if(!shots_[i].getOwner() && shots_[i].getPlace().y()<10) {
            shots_.erase(shots_.begin()+i);
        }else{
            i++;
        }
    }
    if (time_ % lvl_->getShotPeriod() == 0 && time_ % lvl_->getMovePeriod() == 0){
        time_ = 0;
    }
}
