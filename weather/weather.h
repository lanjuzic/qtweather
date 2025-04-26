#ifndef WEATHER_H
#define WEATHER_H

#include<QPainter>//绘制函数头文件
#include <QMainWindow>
#include<QMenu>//菜单头文件
#include<QAction>//窗口行为头文件
#include<QMouseEvent>//添加鼠标行为头文件
#include<QPoint>//获取光标坐标头文件
//jason需要的头文件
#include<QJsonDocument>
#include<QJsonValue>
#include<QJsonObject>
#include<QJsonArray>
#include<QJsonParseError>
//jason需要的头文件
#include<QLabel>//为了使用组件列表
#include<QNetworkAccessManager>//实现联网功能
#include<QNetworkReply>
#include<weathertool.h>//天气工具头文件
#include<QMessageBox>//方便输出错误信息
#include<weatherdata.h>

#include<QPainter>
//#include<map>
#include<QTimer>

#define TEMPERATURE_STARTING_COORDINATE 48 // 高温平均值起始坐标
#define SPAN_INDEX 2 // 温度曲线间隔指数
#define ORIGIN_SIZE 3 // 温度曲线原点大小


QT_BEGIN_NAMESPACE
namespace Ui { class weather; }
QT_END_NAMESPACE

class weather : public QMainWindow
{
    Q_OBJECT

public://构造和析构函数
    weather(QWidget *parent = nullptr);//构造函数
    ~weather();//析构函数

public://公共方法
    void paintEvent(QPaintEvent* event) override;//重写绘制函数
    void contextMenuEvent(QContextMenuEvent* menuevent) override;//专门捕获鼠标右击事件的函数，鼠标右击会自动调用这个函数
    void getWeatherInfo(QNetworkAccessManager *manager);//获取天气信息的方法
    void parseJson(const QByteArray &bytes);//解析json文件
    void setLabelContent();//根据获得的参数绘制图像信息
    void paintSunRiseSet();
    void paintCurve();
    bool eventFilter(QObject *watched, QEvent *event) override;


private://私有对象
    QNetworkAccessManager *manager;
    Ui::weather *ui;
    QMenu  *m_pMenu;//菜单指针
    QAction *m_pExitAct;//退出行为指针
    QPoint mPos;//记录光标位置

    //ui组件对象
    QList<QLabel *> forecast_week_list;
    QList<QLabel *> forecast_date_list;
    QList<QLabel *> forecast_aqi_list;
    QList<QLabel *> forecast_type_list;
    QList<QLabel *> forecast_typeico_list;
    QList<QLabel *> forecast_high_list;
    QList<QLabel *> forecast_low_list;

    //网络请求对象
    QString url;//接口链接
    QString city;//访问城市
    QString cityTmp;//临时存放城市

    //数据解析对象
    Today today;

    //存储每天天气信息
    Forecast forecast[7];
   //天气工具对象
    weathertool tool;

    static const QPoint sun[2];

    static const QRect sunRizeSet[2];
    static const QRect rect[2];

    QTimer* sunTimer;
    //std::map<QString,QString> ch_english;

protected slots://添加声明槽函数
     void slot_exitApp(); //槽函数处理退出事件
     void replayFinished(QNetworkReply *reply);//处理请求后接收数据处理

protected:
     void mouseMoveEvent(QMouseEvent *event) override;//鼠标事件的识别处理
     void mousePressEvent(QMouseEvent *event) override;//鼠标事件的识别处理
private slots:
     void on_refresh_clicked();
     void on_pushButton_clicked();
};

#endif // WEATHER_H
