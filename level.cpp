#include "level.h"

Level::Level(int lvl){
    if (lvl == 1){
        periodOfShots_ = 1000;
        periodOfMove_ = 7000;
        Monstr mon1(QPoint(25, 100));
        Monstr mon2(QPoint(75, 100));
        Monstr mon3(QPoint(125, 100));
        Monstr mon4(QPoint(175, 100));
        Monstr mon5(QPoint(225, 100));
        Monstr mon6(QPoint(275, 100));
        Monstr mon7(QPoint(325, 100));
        Monstr mon8(QPoint(375, 100));
        Monstr mon9(QPoint(425, 100));
        Monstr mon10(QPoint(475, 100));
        Monstr mon11(QPoint(525, 100));
        Monstr mon12(QPoint(575, 100));
        Monstr mon13(QPoint(625, 100));
        Monstr mon14(QPoint(675, 100));
        monstrs_ = QVector<Monstr>{mon1,mon2,mon3,mon4,mon5,mon6,mon7, mon8,mon9,mon10,mon11,mon12,mon13,mon14};
    }else if (lvl == 2){
        periodOfShots_ = 700;
        periodOfMove_ = 5000;
        Monstr mon1(QPoint(25, 100));
        Monstr mon2(QPoint(75, 100),2);
        Monstr mon3(QPoint(125, 100));
        Monstr mon4(QPoint(175, 100),2);
        Monstr mon5(QPoint(225, 100));
        Monstr mon6(QPoint(275, 100),2);
        Monstr mon7(QPoint(325, 100));
        Monstr mon8(QPoint(375, 100));
        Monstr mon9(QPoint(425, 100),2);
        Monstr mon10(QPoint(475, 100));
        Monstr mon11(QPoint(525, 100),2);
        Monstr mon12(QPoint(575, 100));
        Monstr mon13(QPoint(625, 100),2);
        Monstr mon14(QPoint(675, 100));
        monstrs_ = QVector<Monstr>{mon1,mon2,mon3,mon4,mon5,mon6,mon7, mon8,mon9,mon10,mon11,mon12,mon13,mon14};
    }
    else if (lvl == 3){
        periodOfShots_ = 650;
        periodOfMove_ = 5000;
        Monstr mon1(QPoint(25, 100));
        Monstr mon2(QPoint(75, 100));
        Monstr mon3(QPoint(125, 100));
        Monstr mon4(QPoint(175, 100));
        Monstr mon5(QPoint(225, 100));
        Monstr mon6(QPoint(275, 100),2);
        Monstr mon7(QPoint(325, 100));
        Monstr mon8(QPoint(375, 100));
        Monstr mon9(QPoint(425, 100),2);
        Monstr mon10(QPoint(475, 100));
        Monstr mon11(QPoint(525, 100));
        Monstr mon12(QPoint(575, 100));
        Monstr mon13(QPoint(625, 100));
        Monstr mon14(QPoint(675, 100));
        Monstr mon15(QPoint(25, 150));
        Monstr mon16(QPoint(75, 150));
        Monstr mon17(QPoint(125, 150));
        Monstr mon18(QPoint(175, 150),2);
        Monstr mon19(QPoint(225, 150),2);
        Monstr mon20(QPoint(275, 150),2);
        Monstr mon21(QPoint(325, 150));
        Monstr mon22(QPoint(375, 150));
        Monstr mon23(QPoint(425, 150),2);
        Monstr mon24(QPoint(475, 150),2);
        Monstr mon25(QPoint(525, 150),2);
        Monstr mon26(QPoint(575, 150));
        Monstr mon27(QPoint(625, 150));
        Monstr mon28(QPoint(675, 150));
        monstrs_ = QVector<Monstr>{mon1,mon2,mon3,mon4,mon5,mon6,mon7, mon8,mon9,mon10,mon11,mon12,mon13,
                mon14,mon15,mon16,mon17,mon18,mon19,mon20,mon21, mon22,mon23,mon24,mon25,mon26,mon27,mon28};
    }else if (lvl == 4){
        periodOfShots_ = 650;
        periodOfMove_ = 5500;
        Monstr mon1(QPoint(25, 100),2);
        Monstr mon2(QPoint(75, 100));
        Monstr mon3(QPoint(125, 100));
        Monstr mon4(QPoint(175, 100));
        Monstr mon5(QPoint(225, 100));
        Monstr mon6(QPoint(275, 100));
        Monstr mon7(QPoint(325, 100));
        Monstr mon8(QPoint(375, 100));
        Monstr mon9(QPoint(425, 100));
        Monstr mon10(QPoint(475, 100));
        Monstr mon11(QPoint(525, 100));
        Monstr mon12(QPoint(575, 100));
        Monstr mon13(QPoint(625, 100));
        Monstr mon14(QPoint(675, 100),2);
        Monstr mon15(QPoint(25, 150));
        Monstr mon16(QPoint(75, 150));
        Monstr mon17(QPoint(125, 150));
        Monstr mon18(QPoint(175, 150),2);
        Monstr mon19(QPoint(225, 150));
        Monstr mon20(QPoint(275, 150),2);
        Monstr mon21(QPoint(325, 150),2);
        Monstr mon22(QPoint(375, 150),2);
        Monstr mon23(QPoint(425, 150),2);
        Monstr mon24(QPoint(475, 150));
        Monstr mon25(QPoint(525, 150),2);
        Monstr mon26(QPoint(575, 150));
        Monstr mon27(QPoint(625, 150));
        Monstr mon28(QPoint(675, 150));
        monstrs_ = QVector<Monstr>{mon1,mon2,mon3,mon4,mon5,mon6,mon7, mon8,mon9,mon10,mon11,mon12,mon13,
                mon14,mon15,mon16,mon17,mon18,mon19,mon20,mon21, mon22,mon23,mon24,mon25,mon26,mon27,mon28};
    }else if (lvl == 5){
        periodOfShots_ = 500;
        periodOfMove_ = 6500;
        Monstr mon1(QPoint(25, 100),2);
        Monstr mon2(QPoint(75, 100),2);
        Monstr mon3(QPoint(125, 100));
        Monstr mon4(QPoint(175, 100));
        Monstr mon5(QPoint(225, 100));
        Monstr mon6(QPoint(275, 100));
        Monstr mon7(QPoint(325, 100),3);
        Monstr mon8(QPoint(375, 100),3);
        Monstr mon9(QPoint(425, 100));
        Monstr mon10(QPoint(475, 100));
        Monstr mon11(QPoint(525, 100));
        Monstr mon12(QPoint(575, 100));
        Monstr mon13(QPoint(625, 100),2);
        Monstr mon14(QPoint(675, 100),2);
        Monstr mon15(QPoint(25, 150));
        Monstr mon16(QPoint(75, 150));
        Monstr mon17(QPoint(125, 150));
        Monstr mon18(QPoint(175, 150));
        Monstr mon19(QPoint(225, 150));
        Monstr mon20(QPoint(275, 150));
        Monstr mon21(QPoint(325, 150));
        Monstr mon22(QPoint(375, 150));
        Monstr mon23(QPoint(425, 150));
        Monstr mon24(QPoint(475, 150));
        Monstr mon25(QPoint(525, 150));
        Monstr mon26(QPoint(575, 150));
        Monstr mon27(QPoint(625, 150));
        Monstr mon28(QPoint(675, 150));
        Monstr mon29(QPoint(625, 200));
        Monstr mon30(QPoint(675, 200));
        Monstr mon31(QPoint(25, 200));
        Monstr mon32(QPoint(75, 200));
        Monstr mon33(QPoint(125, 200));
        Monstr mon34(QPoint(175, 200));
        Monstr mon35(QPoint(225, 200));
        Monstr mon36(QPoint(275, 200));
        Monstr mon37(QPoint(325, 200));
        Monstr mon38(QPoint(375, 200));
        Monstr mon39(QPoint(425, 200));
        Monstr mon40(QPoint(475, 200));
        Monstr mon41(QPoint(525, 200));
        Monstr mon42(QPoint(575, 200));
        monstrs_ = QVector<Monstr>{mon1,mon2,mon3,mon4,mon5,mon6,mon7, mon8,mon9,mon10,mon11,mon12,mon13,
                mon14,mon15,mon16,mon17,mon18,mon19,mon20,mon21, mon22,mon23,mon24,mon25,mon26,mon27,mon28,
                mon29,mon30,mon31,mon32,mon33,mon34,mon35,mon36,mon37, mon38,mon39,mon40,mon41,mon42};
    }
}
/*
Level::Level(QString lvl){
    QFile fileJson(lvl);

    fileJson.open(QIODevice::ReadOnly | QIODevice::Text);

    QString val;
    val = fileJson.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject json = doc.object();
    QVector<QString> mons;
    QString mon;
    periodOfShots_ = json["Shot"].toInt();
    periodOfMove_ = json["Move"].toInt();
    bool b1 = true;
    QString ms = "Mon1";
    int itr = 1;
    QString res = "";
    while (b1){
        mon = json[ms].toString();
        if (mon!=""){
            ms.resize(ms.size() - 1);
            itr++;
            ms.push_back(QString::number(itr));
            res.push_back(mon);
            res.push_back(",");
        } else {
            b1= false;
        }
    }
    QVector<int> monNums;
    int num = 0;
    for (int i = 0; i < res.size(); i++){
        if(res[i]!=','){
            QString tmp = QString(res[i]);
            num *=10;
            num += tmp.toInt();
        } else {
            monNums.push_back(num);
            num = 0;
        }
    }
    Monstr mon1(QPoint(monNums[0], monNums[1]), monNums[2]);
    monstrs_ = QVector<Monstr>{mon1};
    for (int i = 3; i <monNums.size(); i+=3){
        monstrs_.push_back(Monstr(QPoint(monNums[i], monNums[i+1]), monNums[i+2]));
    }
    fileJson.close();

}*/
