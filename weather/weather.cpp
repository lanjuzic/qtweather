#include "weather.h"
#include "ui_weather.h"


const QPoint weather::sun[2] = {
    QPoint(0, 129),
    QPoint(119, 129)
};

const QRect weather::sunRizeSet[2]={
  QRect(0,0,50,20),
  QRect(60,0,50,20)
};

const QRect weather::rect[2]={
    QRect(0,65,119,129),
    QRect(60,65,50,50)
};

weather::weather(QWidget *parent)//构造函数声明
    : QMainWindow(parent)
    , ui(new Ui::weather)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);//在构造函数中设置窗口无边框

    m_pMenu = new QMenu(this);//实例菜单对象指针
    m_pExitAct = new QAction;//实例化菜单下组件
    m_pExitAct->setText(u8"退出");//设置菜单组件
    m_pExitAct->setIcon(QIcon(":/weatherico/close.ico"));//加载背景
    m_pMenu->addAction(m_pExitAct);//将组件加入菜单
    connect(m_pExitAct,SIGNAL(triggered(bool)),this,SLOT(slot_exitApp()));//点击后退出操作进行绑定

    //将个组件添加进入列表
    forecast_week_list<<ui->week0<<ui->week1<<ui->week2<<ui->week3<<ui->week4<<ui->week5;
    forecast_date_list<<ui->date0<<ui->date1<<ui->date2<<ui->date3<<ui->date4<<ui->date5;
    forecast_aqi_list<<ui->quli0<<ui->quli1<<ui->quli2<<ui->quli3<<ui->quli4<<ui->quli5;
    forecast_type_list<<ui->we0<<ui->we1<<ui->we2<<ui->we3<<ui->we4<<ui->we5;
    forecast_typeico_list<<ui->tq0<<ui->tq1<<ui->tq2<<ui->tq3<<ui->tq4<<ui->tq5;
    forecast_high_list<<ui->h0<<ui->h1<<ui->h2<<ui->h3<<ui->h4<<ui->h5;
    forecast_low_list<<ui->l0<<ui->l1<<ui->l2<<ui->l3<<ui->l4<<ui->l5;

    //网络请求相关
    url = "http://t.weather.itboy.net/api/weather/city/";
    city = u8"广汉";
    cityTmp = city;
    manager = new QNetworkAccessManager(this);

    getWeatherInfo(manager);

    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(replayFinished(QNetworkReply*)));
    // 文本框样式 - 半透明背景、圆角边框
    ui->cityLineEdit->setStyleSheet("QLineEdit {"
        "background-color: rgba(240, 240, 240, 200);"
        "border: 2px solid #8B9CB0;"
        "border-radius: 12px;"
        "padding: 8px;"
        "selection-background-color: rgba(100, 149, 237, 150);"
    "}");

    // 日期显示栏样式 - 较大的文本、半透明背景、圆角边框
    ui->dateLb->setStyleSheet("QLabel {"
        "background-color: rgba(240, 240, 240, 150);"
        "border: 2px solid #8B9CB0;"
        "border-radius: 12px;"
        "padding: 12px;"
        "font-size: 18px;" // 调整文本大小
        "color: #333333;" // 字体颜色
        "qproperty-alignment: AlignCenter;" // 文本居中
    "}");

    // 搜索框按钮样式 - 悬停和点击效果
    ui->pushButton->setStyleSheet(
         "QPushButton {"
         "background-image: url(:/weatherico/search.png);" // 添加背景图片
         "background-size: contain;" // 等比例缩放图片，使图片完全可见
        "background-color: rgba(100, 149, 237, 150);"
        "border: 2px solid #1E90FF;"
        "border-radius: 12px;"
        "padding: 8px 16px;"
        "font-size: 16px;"
        "color: white;"
    "}"
    "QPushButton:hover {"
        "background-color: rgba(30, 144, 255, 180);"
        "border: 2px solid #0000CD;"
    "}"
    "QPushButton:pressed {"
        "background-color: rgba(135, 206, 250, 200);"
    "}");

    // 刷新按钮样式 - 带有旋转效果的图标
    ui->refresh->setStyleSheet("QPushButton {"
         "background-image: url(:/weatherico/refresh.ico);"
          "background-size: contain;" // 等比例缩放图片，使图片完全可见
        "background-color: rgba(144, 238, 144, 150);"
        "border: 2px solid #3CB371;"
        "border-radius: 12px;"
        "padding: 8px 16px;"
        "font-size: 16px;"
        "color: white;"
    "}"
    "QPushButton:hover {"
        "background-color: rgba(46, 139, 87, 180);"
        "border: 2px solid #2E8B57;"
    "}"
    "QPushButton:pressed {"
        "background-color: rgba(152, 251, 152, 200);"
    "}");
    for(int i=0;i<6;i++){
        // 公共样式属性
            QString commonStyle =
                "QLabel {"
                "   font-family: 'Microsoft YaHei';"  // 统一字体
                "   font-size: 14px;"
                "   border-radius: 8px;"             // 圆角半径
                "   padding: 8px 12px;"              // 内边距
                "   border: 1px solid rgba(0, 0, 0, 0.1);" // 半透明边框
                "   background-color: rgba(255, 255, 255, 0.7);" // 半透明白色背景
                "}";

            // 星期样式（深蓝色系）
            forecast_week_list[i]->setStyleSheet(
                commonStyle +
                "QLabel {"
                "   color: #2C3E50;"                  // 深蓝灰文字
                "   border-bottom: 2px solid #3498DB;" // 底部装饰线
                "}"
            );

            // 日期样式（紫色系）
            forecast_date_list[i]->setStyleSheet(
                commonStyle +
                "QLabel {"
                "   color: #8E44AD;"                  // 紫色文字
                "   background-color: rgba(142, 68, 173, 0.1);" // 浅紫色背景
                "}"
            );

            // 天气类型样式（渐变蓝）
            forecast_type_list[i]->setStyleSheet(
                commonStyle +
                "QLabel {"
                "   color: #2980B9;"                  // 天空蓝
                "   background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                "               stop:0 rgba(41, 128, 185, 0.1),"
                "               stop:1 rgba(52, 152, 219, 0.2));" // 渐变色背景
                "   border: 1px solid rgba(41, 128, 185, 0.3);"
                "}"
            );

            // 最高温度样式（暖色渐变）
            forecast_high_list[i]->setStyleSheet(
                commonStyle +
                "QLabel {"
                "   color: #E74C3C;"                  // 强调红
                "   background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                "               stop:0 rgba(231, 76, 60, 0.1),"
                "               stop:1 rgba(241, 148, 138, 0.2));"
                "   font-weight: bold;"
                "}"
            );

            // 最低温度样式（冷色渐变）
            forecast_low_list[i]->setStyleSheet(
                commonStyle +
                "QLabel {"
                "   color: #3498DB;"                  // 蓝色
                "   background: qlineargradient(x1:0, y1:0, x2:1, y2:0,"
                "               stop:0 rgba(52, 152, 219, 0.1),"
                "               stop:1 rgba(133, 193, 233, 0.2));"
                "   font-weight: bold;"
                "}"
            );

    }

    ui->sunRiseSetLb->installEventFilter(this);//启用事件过滤器
    ui->curveLb->installEventFilter(this);
    ui->cityLineEdit->installEventFilter(this);


    sunTimer = new QTimer(ui->sunRiseSetLb);//创建了一个计时对象
     connect(sunTimer, SIGNAL(timeout()), ui->sunRiseSetLb, SLOT(update()));
     sunTimer->start(5000);

}

weather::~weather()
{
    delete ui;
}

//定义窗口重绘函数
void weather::paintEvent(QPaintEvent* event){

    QPainter qPainter(this);
    qPainter.drawPixmap(0,0,width(),height(),QPixmap(":/ui/weaUI.png"));
    //此处为重新绘制背景图代码

    event->accept();
}
void weather::contextMenuEvent(QContextMenuEvent* menuevent){//获取鼠标事件与光标位置
    m_pMenu->exec(QCursor::pos());//获取当前光标坐标，并显示菜单
    menuevent->accept();//表示点击事件已经被处理避免进一步传播
}

void weather::slot_exitApp(){//退出窗口槽函数
    qApp->exit(0);
}

void weather::mouseMoveEvent(QMouseEvent *event){//根据鼠标当前的位置距离将窗口移动到指定的位置距离
    this->move(event->globalPos()-mPos);//只有在mPos被正确设置时才会调用该函数
}
void weather::mousePressEvent(QMouseEvent *event){//记录鼠标被按下时窗口和鼠标的相对位置距离

    mPos = event->globalPos()-this->pos();//计算光标与背景的相对距离
}

void weather::getWeatherInfo(QNetworkAccessManager *manager){//根据城市json表获取城市编码并进行网络请求
    QString citycode = tool[city];
   // QMessageBox::warning(this,u8"看一下citycode的内容",citycode,QMessageBox::Ok);
    if(citycode == "000000"){
        QMessageBox::warning(this,u8"错误",u8"天气：指定城市不存在！",QMessageBox::Ok);
        return ;
    }
    QUrl jsonUrl(url+citycode);
    manager->get(QNetworkRequest(jsonUrl));
}

void weather::replayFinished(QNetworkReply *reply){//在发送请求后接收数据
    QVariant status_code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);//获取返回标识
    if(reply->error() != QNetworkReply::NoError || status_code != 200){//请求失败或者请求超时
        QMessageBox::warning(this,u8"错误",u8"天气：请求数据错误，请检查网络连接！",QMessageBox::Ok);
        return;
    }
    QByteArray bytes = reply->readAll();//将接收到的数据转换成二进制数组
    //qDebug()<<bytes;
    parseJson(bytes);//解析接收到的二进制数据

}

void weather::parseJson(const QByteArray &bytes){//根据获取到的json数据文件进行解析
    QJsonParseError err;
    QJsonDocument jsondoc = QJsonDocument::fromJson(bytes,&err);//根据二进制数据转换成json文本
    if(err.error != QJsonParseError::NoError){
        qDebug()<<"switch is wrong and exited!";
        return;
    }
    QJsonObject jsonobj = jsondoc.object();//将json文本转换成json对象
    QString message = jsonobj.value("message").toString();//这里提取出指定信息是为了查看数据有没有问题
    if(message.contains("success") == false){
        QMessageBox::information(this,tr("the information of Json_desc"),
                             u8"天气：城市错误", QMessageBox::Ok);
        city = cityTmp;
        return;
    }

    //???需要修改
    today = jsonobj;//将json对象给data类对象赋值

    QJsonObject dataObj = jsonobj.value("data").toObject();

    //？？？？需要修改
    forecast[0] = dataObj.value("yesterday").toObject();//解析data中的forecast
    QJsonArray forecastArr =  dataObj.value("forecast").toArray();
    int j =0;
    for(int i = 1; i< 6;i++){
        forecast[i] = forecastArr.at(j).toObject();
        j++;
    }


    setLabelContent();//更新左栏信息
    paintSunRiseSet();

}

void weather::setLabelContent(){
    //
    // 日期显示（顶部日期）
        ui->dateLb->setStyleSheet(
            "QLabel {"
            "    color: #7F8C8D;"          // 灰蓝色
            "    font: 14px 'Microsoft YaHei';"
            "    padding: 5px 10px;"
            "    background: rgba(255,255,255,0.7);"
            "    border-radius: 8px;"
            "}"
        );

        // 温度显示（大号突出）
        ui->temLb->setStyleSheet(
            "QLabel {"
            "    color: #E74C3C;"          // 强调红
            "    font: bold 56px 'Segoe UI';"
            "    text-shadow: 1px 1px 2px rgba(0,0,0,0.1);"
            "    margin: 15px 0;"
            "}"
        );

        // 城市位置citywz
        ui->wz->setStyleSheet(
            "QLabel {"
            "    color: #2C3E50;"          // 深蓝灰
            "    font: bold 24px 'Microsoft YaHei';"
            "    padding: 5px 0;"
            "    border-bottom: 2px solid #3498DB;"  // 底部装饰线
            "}"
        );

        // 天气类型
        ui->typewea->setStyleSheet(
            "QLabel {"
            "    color: #2980B9;"          // 天空蓝
            "    font: 20px 'Microsoft YaHei';"
            "    padding: 8px 15px;"
            "    background: rgba(52,152,219,0.1);"  // 浅蓝色背景
            "    border-radius: 20px;"      // 胶囊形状
            "}"
        );

        // 温馨提示
        ui->jianyi->setStyleSheet(
            "QLabel {"
            "    color: #27AE60;"          // 绿色
            "    font: 14px 'Microsoft YaHei';"
            "    background: rgba(46,204,113,0.15);"
            "    padding: 12px 20px;"
            "    border-radius: 10px;"
            "    border-left: 4px solid #27AE60;"  // 左侧装饰条
            "}"
        );

        // 湿度数值
        ui->xidunr->setStyleSheet(
            "QLabel {"
            "    color: #16A085;"          // 青色
            "    font: bold 16px 'Microsoft YaHei';"
            "    background: rgba(22,160,133,0.1);"
            "    padding: 10px;"
            "    border-radius: 8px;"
            "    min-width: 100px;"        // 固定最小宽度
            "}"
        );

        // PM2.5数值
        ui->pmnr->setStyleSheet(
            "QLabel {"
            "    color: #8E44AD;"          // 紫色
            "    font: bold 16px 'Microsoft YaHei';"
            "    background: rgba(142,68,173,0.1);"
            "    padding: 10px;"
            "    border-radius: 8px;"
            "    min-width: 100px;"
            "}"
        );

        // 风向
        ui->fxnr->setStyleSheet(
            "QLabel {"
            "    color: #D35400;"          // 橙色
            "    font: bold 16px 'Microsoft YaHei';"
            "    background: rgba(211,84,0,0.1);"
            "    padding: 10px;"
            "    border-radius: 8px;"
            "    min-width: 100px;"
            "}"
        );

        // 风力
        ui->flnr->setStyleSheet(
            "QLabel {"
            "    color: #C0392B;"          // 暗红
            "    font: bold 16px 'Microsoft YaHei';"
            "    background: rgba(192,57,43,0.1);"
            "    padding: 10px;"
            "    border-radius: 8px;"
            "    min-width: 100px;"
            "}"
        );

        // 健康建议
        // 健康建议
        ui->suggest->setStyleSheet(
            "QLabel {"
            "    color: #E67E22;"
            "    font: 14px 'Microsoft YaHei';"
            "    background: rgba(230,126,34,0.15);"
            "    padding: 12px 20px;"
            "    border-radius: 10px;"
            "    border-left: 4px solid #E67E22;"
            "    line-height: 1.5;"
            "    word-wrap: break-word;"      // 新增：允许文本自动换行
            "    max-width: 100px;"          // 新增：限制最大宽度（根据实际布局调整）
            "}"
        );
//        ui->suggest->setStyleSheet(
//            "QLabel {"
//            "    color: #E67E22;"          // 橙色
//            "    font: 14px 'Microsoft YaHei';"
//            "    background: rgba(230,126,34,0.15);"
//            "    padding: 12px 20px;"
//            "    border-radius: 10px;"
//            "    border-left: 4px solid #E67E22;"  // 左侧装饰条
//            "    line-height: 1.5;"       // 行高设置
//            "}"
//        );
    //
    ui->dateLb->setText(today.date);
    ui->temLb->setText(today.wendu);
    ui->wz->setText(today.city);//
    qDebug()<<"look the city "+today.city;
    ui->typewea->setText(today.type);
    ui->jianyi->setText(today.notice);
    ui->xidunr->setText(today.shidu);
     ui->pmnr->setText(today.pm25);
     ui->fxnr->setText(today.fx);
     ui->flnr->setText(today.fl);
     ui->suggest->setText(today.ganmao);

     for(int i=0;i<6;i++){//以天数为角标设置各个元素
         forecast_week_list[i]->setText(forecast[i].week.right(3));//返回字符串最右边的n个字节构成的字符串
         //forecast[i].week.right(3)
         //qDebug()<<"week is "+forecast[i].week;//接收信息没有问题可以继续写代码
         forecast_date_list[i]->setText(forecast[i].date.left(3));
         forecast_type_list[i]->setText(forecast[i].type);
         forecast_high_list[i]->setText(forecast[i].high.split(" ").at(1));//将字符串 forecast[i].high 按空格分割，并取第二个部分（索引为 1），然后将其设置为 forecast_high_list[i] 的文本
         forecast_low_list[i]->setText(forecast[i].low.split(" ").at(1));
         forecast_typeico_list[i]->setStyleSheet( tr("image:url(:/day/day/%1.png);").arg(forecast[i].type));//tr() 主要用于标记用户界面中显示的文本，以便它们可以被翻译。//可以加载中文的资源文件名
         //使用 setStyleSheet 方法为 forecast_typeico_list[i] 设置背景图片。
         //图片路径是动态生成的，forecast[i].type 的值被插入到路径中，例如 ":/day/day/sunny.png"。

         if(forecast[i].aqi.toInt() >= 0 && forecast[i].aqi.toInt()<= 50){//forecast[i].aqi.toInt() 将字符串转换为整数进行比较
             forecast_aqi_list[i]->setText(u8"优质");
             forecast_aqi_list[i]->setStyleSheet("color: rgb(170,0,0);");
         }else if(forecast[i].aqi.toInt() >50 && forecast[i].aqi.toInt()<= 100){
             forecast_aqi_list[i]->setText(u8"良好");
             forecast_aqi_list[i]->setStyleSheet("color: rgb(170,0,0);");
         }else if(forecast[i].aqi.toInt() > 100 && forecast[i].aqi.toInt()<= 150){
             forecast_aqi_list[i]->setText(u8"轻度污染");
             forecast_aqi_list[i]->setStyleSheet("color: rgb(170,0,0);");
         }else if(forecast[i].aqi.toInt() > 150 && forecast[i].aqi.toInt()<= 200){
             forecast_aqi_list[i]->setText(u8"重度污染");
             forecast_aqi_list[i]->setStyleSheet("color: rgb(170,0,0);");
         }else{
             forecast_aqi_list[i]->setText(u8"严重污染");
             forecast_aqi_list[i]->setStyleSheet("color: rgb(170,0,0);");
         }

         ui->week0->setText( u8"昨天" );
          ui->week1->setText( u8"今天" );
     }


}

void weather::paintSunRiseSet(){//绘制日落日出
    QPainter painter(ui->sunRiseSetLb);//创建一个绘制器对象
    painter.setRenderHint(QPainter::Antialiasing,true);//开启抗锯齿

    painter.save();//保存当前绘制器状态
    QPen pen = painter.pen();//创建笔对象
    pen.setWidthF(0.5);//设置笔宽为0.5
    pen.setColor(Qt::yellow);//设置黄色笔迹
    painter.setPen(pen);//保存笔的配置信息到绘制器
    painter.drawLine(sun[0],sun[1]);//绘制一条黄色的线
    painter.restore();
    painter.save();
    painter.setFont(QFont("Microsoft Yahei",8,QFont::Normal));
    painter.setPen(Qt::white);

    //区域太小了不够绘制
    if(today.sunrise != "" && today.sunset!=""){
        //在指定区域内绘制文字
        painter.drawText(sunRizeSet[0],Qt::AlignHCenter,today.sunrise);
        painter.drawText(sunRizeSet[1],Qt::AlignHCenter,today.sunset);
    }
    painter.drawText(rect[1],Qt::AlignHCenter,u8"日出日落");
    painter.restore();

    painter.save();
    pen.setWidthF(0.5);//设置线条宽度
    pen.setStyle(Qt::DotLine);//设置为虚线
    pen.setColor(Qt::green);
    painter.setPen(pen);
    painter.drawArc(rect[0],0*16,180*16);//绘制圆弧Qt的角度的基数是16分之一度，所以在任何话圆弧的地方，我们都要乘以
    //16 才得到我们正常的度数
    painter.restore();

    if(today.sunrise !="" && today.sunset != ""){
        painter.setPen(Qt::NoPen);
        painter.setBrush(QColor(255,85,0,100));

        int startAngle,spanAngle;

        QString sunsetTime = today.date+" "+today.sunset;
        if(QDateTime::currentDateTime() > QDateTime::fromString(sunsetTime,"yyyy-MM-dd hh:mm")){
            startAngle = 0 * 16;
            spanAngle = 180* 16;
            qDebug()<<"tttttttttttttttttttttttttttttttt";

        }else{
            qDebug()<<"fffffffffffffffffffffffffffffff";
            static QStringList sunSet = today.sunset.split(":");
            static QStringList sunRiseTime = today.sunrise.split(":");

            static QString sunsetHour = sunSet.at(0);
            static QString sunsetMinit = sunSet.at(1);
            static QString sunriseHour = sunRiseTime.at(0);
            static QString sunriseMinit = sunRiseTime.at(1);

            static int sunrise = sunriseHour.toInt()*60+sunriseMinit.toInt();
            static int sunset = sunsetHour.toInt()*60+sunsetMinit.toInt();
            int now = QTime::currentTime().hour()*60+QTime::currentTime().minute();
            startAngle = ((double)(sunset-now)/(sunset-sunrise))*180*16;//计算起始角度
            spanAngle = ((double)(now-sunrise)/(sunset-sunrise))*180*16;//计算需要绘制的角度值

        }
        if(startAngle>= 0&& spanAngle>=0){
            painter.drawPie(rect[0],startAngle,spanAngle);//圆弧里面是空白的，需要绘制成黄色以显示
            //painter.drawPie(rect[0],0,90*16);
            //第一个参数是绘制区域
            //第二个参数是起始角度，
            //第三个参数是绘制的角度，而不是结束角度
        }


    }

}

void weather::paintCurve(){//绘制温度曲线图
    QPainter painter(ui->curveLb);//对改table进行绘制
    painter.setRenderHint(QPainter::Antialiasing,true);//抗锯齿
    int tempToal = 0;//最高温总和
    int high[6] ={};
    int low[6] = {};
    QString h;
    QString l;
    for(int i =0; i< 6;i++){
        h = forecast[i].high.split(" ").at(1);
        h = h.left(h.length()-1);//获取当日最高温度
        high[i] = (int)(h.toDouble());//存储在当日最高温度中
        tempToal += high[i];//记录最高温度的总和

        l = forecast[i].low.split(" ").at(1);
        l = l.left(h.length()-1);//获取当日最低温度
        low[i] = (int)(l.toDouble());//存储在当日最低温度中


    }

    int tempAverage = (int)(tempToal/6);//w549 h97  78 32
    int pointx[6] = {78,156,234,312,390,468};
    int pointHY[6] = {};//存储高温的y轴坐标
    int pointLY[6] = {};//存储低温的y轴坐标
    for(int i =0; i< 6; i++){
        pointHY[i] = TEMPERATURE_STARTING_COORDINATE-((high[i]-tempAverage)*SPAN_INDEX);
        pointLY[i] = TEMPERATURE_STARTING_COORDINATE+((tempAverage-low[i])*SPAN_INDEX);
    }
    QPen pen = painter.pen();
    pen.setWidth(1);//设置笔的宽度为1
    //绘制高温曲线
    painter.save();
    pen.setColor(QColor(255,170,0));
    pen.setStyle(Qt::DotLine);//设置虚线
    painter.setPen(pen);
    painter.setBrush(QColor(255,170,0));

    //先绘制昨天和今天的温度点和虚线
    painter.drawEllipse(QPoint(pointx[0],pointHY[0]),ORIGIN_SIZE,ORIGIN_SIZE);//绘制原点
    painter.drawEllipse(QPoint(pointx[1],pointHY[1]),ORIGIN_SIZE,ORIGIN_SIZE);//绘制今天原点
    painter.drawLine(pointx[0],pointHY[0],pointx[1],pointHY[1]);

    //今天和昨天的点和线绘制完毕后将笔重新设置为实线
    pen.setStyle(Qt::SolidLine);
    pen.setWidth(1);
    painter.setPen(pen);

    for(int i =1; i< 5;i++){
        painter.drawEllipse(QPoint(pointx[i+1],pointHY[i+1]),ORIGIN_SIZE,ORIGIN_SIZE);//绘制下一天原点
        painter.drawLine(pointx[i],pointHY[i],pointx[i+1],pointHY[i+1]);//绘制今天和下一天的连线

    }
    painter.restore();//将绘制对象恢复成save时的状态
    //绘制低温曲线
    pen.setColor(QColor(0,255,255));
    pen.setStyle(Qt::DotLine);//设置虚线
    painter.setPen(pen);
    painter.setBrush(QColor(0,255,255));

    //先绘制昨天和今天的温度点和虚线
    painter.drawEllipse(QPoint(pointx[0],pointLY[0]),ORIGIN_SIZE,ORIGIN_SIZE);//绘制原点
    painter.drawEllipse(QPoint(pointx[1],pointLY[1]),ORIGIN_SIZE,ORIGIN_SIZE);//绘制今天原点
    painter.drawLine(pointx[0],pointLY[0],pointx[1],pointLY[1]);

    pen.setStyle(Qt::SolidLine);
    painter.setPen(pen);
    for(int i =1; i< 5;i++){
        painter.drawEllipse(QPoint(pointx[i+1],pointLY[i+1]),ORIGIN_SIZE,ORIGIN_SIZE);//绘制下一天原点
        painter.drawLine(pointx[i],pointLY[i],pointx[i+1],pointLY[i+1]);//绘制今天和下一天的连线
    }

}

void weather::on_refresh_clicked()//点击按钮后触发的槽函数
{
    getWeatherInfo(manager);
    ui->curveLb->update();//调用控件的update方法，这个方法会触发paint事件
    ui->sunRiseSetLb->update();
}

void weather::on_pushButton_clicked()//点击搜索后触发的槽函数
{
    cityTmp = city;//缓存一个city文本对象
    city = ui->cityLineEdit->text();//从文本框中获取文本信息
    getWeatherInfo(manager);
    ui->curveLb->update();
    ui->sunRiseSetLb->update();
}

bool weather::eventFilter(QObject *watched, QEvent *event){//事件过滤器 继承父类方法，并处理子类事件，再交由父类处理
    if(watched == ui->sunRiseSetLb && event->type() == QEvent::Paint){
        paintSunRiseSet();
        return true;
    }else if(watched == ui->curveLb && event->type() == QEvent::Paint){
        paintCurve();
        return true;
    }
    return QWidget::eventFilter(watched,event);
}
