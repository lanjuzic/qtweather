#ifndef WEATHERTOOL_H
#define WEATHERTOOL_H

//解析json的头文件
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonValue>
#include<QJsonArray>
#include<QJsonParseError>
//解析json的头文件
#include<map>//获取城市与编码的键值对
#include<QFile>//用于读取文件
#include<QCoreApplication>//当前目录的获取



class weathertool{
public:
     weathertool();//在构造函数中对本地json文件进行解析
     ~weathertool(){};
private:
    std::map<QString,QString> m_mapCity2Code;//将解析后的信息作为键值对存储

public:
    //运算符重载支持对象名后跟[]，而后直接输出返回类型值
    QString operator[](const QString& city);//搜索函数，根据指定城市名获取城市编码
};

#endif // WEATHERTOOL_H
