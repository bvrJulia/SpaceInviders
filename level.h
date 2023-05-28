#ifndef LEVEL_H
#define LEVEL_H
#include "monstr.h"
#include <QMainWindow>
#include <QVector>
#include <QMap>
#include <QFile>
#include <QVariantMap>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariant>
class Level
{
public:
    Level(int lvl);
    Level(QString lvl);
    Level(QVector<Monstr> mon, int shot, int move){monstrs_ = mon; periodOfShots_ = shot; periodOfMove_ = move;};
    void setMonstrs(QVector<Monstr> mon){monstrs_ = mon;};
    void setPeriodOfShot(int shot){periodOfShots_ = shot;};
    void setPeriodOfMove(int move){periodOfMove_ = move;};
    QVector<Monstr> getMonstrs() const{return monstrs_;};
    int getShotPeriod() const{return periodOfShots_;};
    int getMovePeriod() const{return periodOfMove_;};
    bool getHard(){return hard_;};
private:
    QVector<Monstr> monstrs_;
    int periodOfShots_;
    int periodOfMove_;
    bool hard_ = false;
};

#endif // LEVEL_H
