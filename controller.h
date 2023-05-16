#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "player.h"
#include "monstr.h"
#include "shot.h"
#include "level.h"
#include <QTimer>
class Controller
{
public:
    Controller(int lvl);
    void generateShot();
    void addShot(Shot shot);
    int endOfLevel();
    void shotOnCreature();
    void timeout();

    void setMonstrs(QVector<Monstr> monstrs){monstrs_ = monstrs;};
    void setShots(QVector<Shot> shots){shots_ = shots;};
    void setTime(int time){time_ = time;};
    void setPlayerPlace(QPoint place){play_.setPlace(place);};
    void setPlayerEndPlace(QPoint place){play_.setEndPlace(place);};
    void setMonstrPlace(int i, QPoint place){monstrs_[i].setPlace(place);};
    void setShotPlace(int i, QPoint place){shots_[i].setPlace(place);};
    Player getPlayer()const {return play_;};
    Level* getLevel() const {return lvl_;};
    QVector<Monstr> getMonstrs(){return monstrs_;};
    QVector<Shot> getShots(){return shots_;};
    int getTime(){return time_;};
private:
    QVector<Monstr> monstrs_;
    QVector<Shot> shots_;
    Player play_;
    Level* lvl_;
    int time_;
};

#endif // CONTROLLER_H
