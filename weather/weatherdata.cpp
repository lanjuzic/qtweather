#include<weatherdata.h>

#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonValue>
#include<QJsonParseError>
#include<QDateTime>

#include<QDebug>
Today::Today(){
    date = "0000-00-00";
    city = "null";
    fl = u8"无数据";
    fx = u8"无数据";
    ganmao = u8"无数据";
    notice = u8"无数据";
    pm25 = u8"无数据";
    quality = u8"无数据";
    shidu = u8"无数据";
    sunrise = "00:00";
    sunset = "00:00";
    wendu = "null";
    type = u8"无数据";
}

Today &Today::operator=(const QJsonObject &jsObj){
    QString dateStr = jsObj.value("date").toString();//这里将时间数据转换成字符串后续转换成专门的时间变量
    //qDebug()<<"date issssssssssss"+dateStr;//此处有数据输出，说明解析没有问题
    date = QDate::fromString(dateStr,"yyyyMMdd").toString("yyyy-MM-dd");
    //qDebug()<<"date is"+date;
    city = jsObj.value("cityInfo").toObject().value("city").toString();
    qDebug()<<"city is "+city;
    QJsonObject dataObj=jsObj.value("data").toObject();
    shidu = dataObj.value("shidu").toString();
    qDebug()<<"shidu is "+shidu;
    pm25 = QString::number(dataObj.value("pm25").toDouble());
    qDebug()<<"pm25 is "+pm25;
    quality = dataObj.value("quality").toString();
    qDebug()<<"quality is "+quality;
    wendu = dataObj.value("wendu").toString()+u8"度";
    qDebug()<<"wendu is "+wendu;
    ganmao = dataObj.value("ganmao").toString();
    qDebug()<<"ganmao is "+ganmao;

    QJsonArray forecastArr = dataObj.value("forecast").toArray();//这里转换成列表其中0为当天信息
    QJsonObject  todayObj = forecastArr.at(0).toObject();
    fx = todayObj.value("fx").toString();
    fl = todayObj.value("fl").toString();
    type = todayObj.value("type").toString();
    sunrise = todayObj.value("sunrise").toString();
    sunset = todayObj.value("sunset").toString();
    notice = todayObj.value("notice").toString();
    return *this;

}

Forecast::Forecast(){
    aqi = "0";
    date = u8"00日星期0";
    week =u8"星期0";
    high = u8"高温 0.0℃";
    low = u8"低温 0.0℃";
    type = "undefind";

}

Forecast &Forecast::operator=(const QJsonObject &obj){
    date = obj.value("date").toString();
    week = obj.value("week").toString();
    high = obj.value("high").toString();
    low = obj.value("low").toString();
    aqi = QString::number(obj.value("aqi").toDouble());
    type = obj.value("type").toString();
    return *this;

}
