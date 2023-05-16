#ifndef SHOT_H
#define SHOT_H
#include <QPoint>

class Shot
{
public:
    Shot();
    void setPlace(QPoint place){place_ = place;};
    void setEndPlace(QPoint place){endPlace_ = place;};
    void setOwner(bool monstr){fromMonstr_=monstr;};
    QPoint getPlace() const{return place_;};
    QPoint getEndPlace() const{return endPlace_;};
    bool getOwner() const{return fromMonstr_;};
private:
    QPoint place_;
    QPoint endPlace_;
    bool fromMonstr_;
};

#endif // SHOT_H
