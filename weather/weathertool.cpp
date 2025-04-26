#include<weathertool.h>

#include<QDebug>

weathertool::weathertool(){
    //获取当前程序运行的路径
    QString filename = QCoreApplication::applicationDirPath();
   // qDebug()<<"filename is"+filename;
    //创建错误信息搜集对象
    QJsonParseError err;
    filename += "/../../weather/citycode-2019-08-23.json";//添加json文件路径
    //filename = "D:/qtproject/weather/weather/citycode-2019-08-23.json";
 //qDebug()<<"filename111 is "+filename;

    QFile file(filename);//创建文件对象
    file.open(QIODevice::ReadOnly|QIODevice::Text);
    QByteArray json = file.readAll();//读取文件并将内容并作为二进制保存


    file.close();
    //读取json数据
    QJsonDocument jsonDoc=QJsonDocument::fromJson(json,&err);//转换为json对象

    QJsonArray citys = jsonDoc.array();//获取对象中的列表信息
//    qDebug()<<"citysize is";
//    qDebug()<<citys.size();
    for(int i =0; i<citys.size();i++){//遍历列表
        QString code = citys.at(i).toObject().value("city_code").toString();//将单个元素中的指定内容提取
        QString city = citys.at(i).toObject().value("city_name").toString();
        if(code.size()>0){//只要单个元素存在信息
            //qDebug()<<"fact!!!";
            m_mapCity2Code.insert(std::pair<QString,QString>(city,code));//将城市与城市代码组成键值对
        }/*else{
            qDebug()<<"no fact!!!";
        }*/
    }

}

QString weathertool::operator[](const QString &city){//根据城市名对键值对进行搜索
    std::map<QString,QString>::iterator it = m_mapCity2Code.find(city);//设置迭代器并查看是否匹配
    if(it == m_mapCity2Code.end()){
        it = m_mapCity2Code.find(city+u8"市");
    }
    if(it == m_mapCity2Code.end()){
        it = m_mapCity2Code.find(city+u8"县");
    }
    if(it == m_mapCity2Code.end()){
        it = m_mapCity2Code.find(city+u8"区");
    }
    if(it == m_mapCity2Code.end()){
            return "000000";
     }
    return it->second;//查找成功返回编码值
}
