#ifndef WEATHERDATA_H
#define WEATHERDATA_H
#include<QObject>
#include<QWidget>

class Today{//当天的天气信息
public:
   Today();
   ~Today(){};

public:
   //重载运算符=，可以实现不同类型之间的赋值
   Today& operator=(const QJsonObject& obj);
    QString date;//日期
   QString wendu;//温度
   QString city;//城市
   QString shidu;//湿度
   QString pm25;//pm2.5
    QString quality;//质量
   QString ganmao;//感冒指数
   QString fx;//风向
   QString fl;//风力
   QString type;//天气
   QString sunrise;//日出时间
   QString sunset;//日落时间
   QString notice;//注意信息
};

class Forecast{//非当日的天气信息
public:
    Forecast();
    ~Forecast(){};
public:
    Forecast& operator=(const QJsonObject& obj);
     QString date; //日期
    QString week; //星期
    QString high; //高温
    QString low; //低温
    QString aqi;//质量
    QString type; //天气
};


#endif // WEATHERDATA_H
