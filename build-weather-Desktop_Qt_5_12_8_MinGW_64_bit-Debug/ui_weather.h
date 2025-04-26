/********************************************************************************
** Form generated from reading UI file 'weather.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEATHER_H
#define UI_WEATHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_weather
{
public:
    QWidget *centralwidget;
    QLineEdit *cityLineEdit;
    QLabel *dateLb;
    QFrame *hLine_1;
    QFrame *hLine_10;
    QFrame *hLine_11;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *pmnr;
    QLabel *flnr;
    QLabel *pm;
    QLabel *shidu;
    QLabel *xidunr;
    QLabel *fengl;
    QLabel *fxnr;
    QLabel *fengx;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_4;
    QLabel *typewea;
    QLabel *citywz;
    QLabel *jianyi;
    QLabel *temLb;
    QLabel *wz;
    QWidget *gridLayoutWidget_3;
    QGridLayout *gridLayout_6;
    QLabel *sunRiseSetLb;
    QLabel *suggest;
    QLabel *coolill;
    QWidget *gridLayoutWidget_4;
    QGridLayout *gridLayout_7;
    QLabel *quli4;
    QLabel *tq4;
    QLabel *we3;
    QLabel *date4;
    QLabel *quli1;
    QLabel *quli5;
    QLabel *week3;
    QLabel *date3;
    QLabel *we2;
    QLabel *date2;
    QLabel *h2;
    QLabel *tq0;
    QLabel *h1;
    QLabel *week2;
    QLabel *tq5;
    QLabel *tq1;
    QLabel *date0;
    QLabel *h0;
    QLabel *h4;
    QLabel *tq2;
    QLabel *h5;
    QLabel *date1;
    QLabel *quli3;
    QLabel *week0;
    QLabel *we4;
    QLabel *week4;
    QLabel *h3;
    QLabel *we5;
    QLabel *week5;
    QLabel *quli0;
    QLabel *we0;
    QLabel *week1;
    QLabel *quli2;
    QLabel *tq3;
    QLabel *we1;
    QLabel *date5;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_8;
    QLabel *l3;
    QLabel *l4;
    QLabel *l1;
    QLabel *curveLb;
    QLabel *l0;
    QLabel *l5;
    QLabel *l2;
    QPushButton *refresh;
    QPushButton *pushButton;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *weather)
    {
        if (weather->objectName().isEmpty())
            weather->setObjectName(QString::fromUtf8("weather"));
        weather->resize(1001, 696);
        weather->setAutoFillBackground(false);
        centralwidget = new QWidget(weather);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        cityLineEdit = new QLineEdit(centralwidget);
        cityLineEdit->setObjectName(QString::fromUtf8("cityLineEdit"));
        cityLineEdit->setGeometry(QRect(740, 40, 121, 41));
        cityLineEdit->setCursor(QCursor(Qt::PointingHandCursor));
        cityLineEdit->setStyleSheet(QString::fromUtf8(""));
        dateLb = new QLabel(centralwidget);
        dateLb->setObjectName(QString::fromUtf8("dateLb"));
        dateLb->setGeometry(QRect(380, 30, 161, 41));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        dateLb->setFont(font);
        dateLb->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\276\256\350\275\257\351\233\205\351\273\221\";\n"
"background-color: rgba(255, 255, 255, 0);\n"
"color: rgb(255, 255, 255);\n"
"border: 1px solid rgba(0, 0, 0, 0.2);\n"
"padding: 5px;"));
        dateLb->setMidLineWidth(1);
        hLine_1 = new QFrame(centralwidget);
        hLine_1->setObjectName(QString::fromUtf8("hLine_1"));
        hLine_1->setGeometry(QRect(-10, 110, 1011, 20));
        hLine_1->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    border: none;\n"
"    border-top: 1px solid rgb(0, 255, 0);\n"
"}"));
        hLine_1->setFrameShape(QFrame::HLine);
        hLine_1->setFrameShadow(QFrame::Sunken);
        hLine_10 = new QFrame(centralwidget);
        hLine_10->setObjectName(QString::fromUtf8("hLine_10"));
        hLine_10->setGeometry(QRect(-10, 310, 451, 20));
        hLine_10->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    border: none;\n"
"    border-top: 1px solid rgb(0, 255, 0);\n"
"}"));
        hLine_10->setFrameShape(QFrame::HLine);
        hLine_10->setFrameShadow(QFrame::Sunken);
        hLine_11 = new QFrame(centralwidget);
        hLine_11->setObjectName(QString::fromUtf8("hLine_11"));
        hLine_11->setGeometry(QRect(0, 510, 441, 16));
        hLine_11->setStyleSheet(QString::fromUtf8("QFrame {\n"
"    border: none;\n"
"    border-top: 1px solid rgb(0, 255, 0);\n"
"}"));
        hLine_11->setFrameShape(QFrame::HLine);
        hLine_11->setFrameShadow(QFrame::Sunken);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(3, 10, 381, 91));
        label->setStyleSheet(QString::fromUtf8("font: 20pt \"\345\215\216\346\226\207\347\220\245\347\217\200\";\n"
" background-color: rgba(255, 255, 255, 0);\n"
" color: rgb(85, 255, 0);\n"
""));
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 320, 421, 181));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pmnr = new QLabel(gridLayoutWidget);
        pmnr->setObjectName(QString::fromUtf8("pmnr"));

        gridLayout->addWidget(pmnr, 1, 1, 1, 1);

        flnr = new QLabel(gridLayoutWidget);
        flnr->setObjectName(QString::fromUtf8("flnr"));

        gridLayout->addWidget(flnr, 3, 1, 1, 1);

        pm = new QLabel(gridLayoutWidget);
        pm->setObjectName(QString::fromUtf8("pm"));

        gridLayout->addWidget(pm, 1, 0, 1, 1);

        shidu = new QLabel(gridLayoutWidget);
        shidu->setObjectName(QString::fromUtf8("shidu"));
        shidu->setEnabled(true);

        gridLayout->addWidget(shidu, 0, 0, 1, 1);

        xidunr = new QLabel(gridLayoutWidget);
        xidunr->setObjectName(QString::fromUtf8("xidunr"));

        gridLayout->addWidget(xidunr, 0, 1, 1, 1);

        fengl = new QLabel(gridLayoutWidget);
        fengl->setObjectName(QString::fromUtf8("fengl"));

        gridLayout->addWidget(fengl, 3, 0, 1, 1);

        fxnr = new QLabel(gridLayoutWidget);
        fxnr->setObjectName(QString::fromUtf8("fxnr"));

        gridLayout->addWidget(fxnr, 2, 1, 1, 1);

        fengx = new QLabel(gridLayoutWidget);
        fengx->setObjectName(QString::fromUtf8("fengx"));

        gridLayout->addWidget(fengx, 2, 0, 1, 1);

        gridLayoutWidget_2 = new QWidget(centralwidget);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(9, 120, 421, 181));
        gridLayout_4 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        typewea = new QLabel(gridLayoutWidget_2);
        typewea->setObjectName(QString::fromUtf8("typewea"));
        typewea->setStyleSheet(QString::fromUtf8("border-image: url(:/day/day/sunny.png);\n"
"background-color: rgba(60, 60, 60, 0);"));

        gridLayout_4->addWidget(typewea, 0, 2, 2, 1);

        citywz = new QLabel(gridLayoutWidget_2);
        citywz->setObjectName(QString::fromUtf8("citywz"));
        citywz->setStyleSheet(QString::fromUtf8("image:url(:/weatherico/leaf.ico)"));

        gridLayout_4->addWidget(citywz, 0, 0, 1, 1);

        jianyi = new QLabel(gridLayoutWidget_2);
        jianyi->setObjectName(QString::fromUtf8("jianyi"));

        gridLayout_4->addWidget(jianyi, 1, 0, 1, 1);

        temLb = new QLabel(gridLayoutWidget_2);
        temLb->setObjectName(QString::fromUtf8("temLb"));

        gridLayout_4->addWidget(temLb, 1, 1, 1, 1);

        wz = new QLabel(gridLayoutWidget_2);
        wz->setObjectName(QString::fromUtf8("wz"));

        gridLayout_4->addWidget(wz, 0, 1, 1, 1);

        gridLayoutWidget_3 = new QWidget(centralwidget);
        gridLayoutWidget_3->setObjectName(QString::fromUtf8("gridLayoutWidget_3"));
        gridLayoutWidget_3->setGeometry(QRect(9, 519, 421, 131));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_3);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        sunRiseSetLb = new QLabel(gridLayoutWidget_3);
        sunRiseSetLb->setObjectName(QString::fromUtf8("sunRiseSetLb"));

        gridLayout_6->addWidget(sunRiseSetLb, 0, 2, 1, 1);

        suggest = new QLabel(gridLayoutWidget_3);
        suggest->setObjectName(QString::fromUtf8("suggest"));

        gridLayout_6->addWidget(suggest, 0, 1, 1, 1);

        coolill = new QLabel(gridLayoutWidget_3);
        coolill->setObjectName(QString::fromUtf8("coolill"));

        gridLayout_6->addWidget(coolill, 0, 0, 1, 1);

        gridLayoutWidget_4 = new QWidget(centralwidget);
        gridLayoutWidget_4->setObjectName(QString::fromUtf8("gridLayoutWidget_4"));
        gridLayoutWidget_4->setGeometry(QRect(439, 120, 551, 321));
        gridLayout_7 = new QGridLayout(gridLayoutWidget_4);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_7->setContentsMargins(0, 0, 0, 0);
        quli4 = new QLabel(gridLayoutWidget_4);
        quli4->setObjectName(QString::fromUtf8("quli4"));

        gridLayout_7->addWidget(quli4, 2, 4, 1, 1);

        tq4 = new QLabel(gridLayoutWidget_4);
        tq4->setObjectName(QString::fromUtf8("tq4"));
        tq4->setStyleSheet(QString::fromUtf8("image:url(:/day/day/blowing_dust.png)"));

        gridLayout_7->addWidget(tq4, 4, 4, 1, 1);

        we3 = new QLabel(gridLayoutWidget_4);
        we3->setObjectName(QString::fromUtf8("we3"));

        gridLayout_7->addWidget(we3, 3, 3, 1, 1);

        date4 = new QLabel(gridLayoutWidget_4);
        date4->setObjectName(QString::fromUtf8("date4"));

        gridLayout_7->addWidget(date4, 1, 4, 1, 1);

        quli1 = new QLabel(gridLayoutWidget_4);
        quli1->setObjectName(QString::fromUtf8("quli1"));

        gridLayout_7->addWidget(quli1, 2, 1, 1, 1);

        quli5 = new QLabel(gridLayoutWidget_4);
        quli5->setObjectName(QString::fromUtf8("quli5"));

        gridLayout_7->addWidget(quli5, 2, 5, 1, 1);

        week3 = new QLabel(gridLayoutWidget_4);
        week3->setObjectName(QString::fromUtf8("week3"));

        gridLayout_7->addWidget(week3, 0, 3, 1, 1);

        date3 = new QLabel(gridLayoutWidget_4);
        date3->setObjectName(QString::fromUtf8("date3"));

        gridLayout_7->addWidget(date3, 1, 3, 1, 1);

        we2 = new QLabel(gridLayoutWidget_4);
        we2->setObjectName(QString::fromUtf8("we2"));

        gridLayout_7->addWidget(we2, 3, 2, 1, 1);

        date2 = new QLabel(gridLayoutWidget_4);
        date2->setObjectName(QString::fromUtf8("date2"));

        gridLayout_7->addWidget(date2, 1, 2, 1, 1);

        h2 = new QLabel(gridLayoutWidget_4);
        h2->setObjectName(QString::fromUtf8("h2"));

        gridLayout_7->addWidget(h2, 5, 2, 1, 1);

        tq0 = new QLabel(gridLayoutWidget_4);
        tq0->setObjectName(QString::fromUtf8("tq0"));
        tq0->setStyleSheet(QString::fromUtf8("image:url(:/day/day/cloudy.png)"));

        gridLayout_7->addWidget(tq0, 4, 0, 1, 1);

        h1 = new QLabel(gridLayoutWidget_4);
        h1->setObjectName(QString::fromUtf8("h1"));

        gridLayout_7->addWidget(h1, 5, 1, 1, 1);

        week2 = new QLabel(gridLayoutWidget_4);
        week2->setObjectName(QString::fromUtf8("week2"));

        gridLayout_7->addWidget(week2, 0, 2, 1, 1);

        tq5 = new QLabel(gridLayoutWidget_4);
        tq5->setObjectName(QString::fromUtf8("tq5"));
        tq5->setStyleSheet(QString::fromUtf8("image:url(:/night/night/snow_shower.png)"));

        gridLayout_7->addWidget(tq5, 4, 5, 1, 1);

        tq1 = new QLabel(gridLayoutWidget_4);
        tq1->setObjectName(QString::fromUtf8("tq1"));
        tq1->setStyleSheet(QString::fromUtf8("image: url(:/day/day/extreme_rain.png);"));

        gridLayout_7->addWidget(tq1, 4, 1, 1, 1);

        date0 = new QLabel(gridLayoutWidget_4);
        date0->setObjectName(QString::fromUtf8("date0"));

        gridLayout_7->addWidget(date0, 1, 0, 1, 1);

        h0 = new QLabel(gridLayoutWidget_4);
        h0->setObjectName(QString::fromUtf8("h0"));

        gridLayout_7->addWidget(h0, 5, 0, 1, 1);

        h4 = new QLabel(gridLayoutWidget_4);
        h4->setObjectName(QString::fromUtf8("h4"));

        gridLayout_7->addWidget(h4, 5, 4, 1, 1);

        tq2 = new QLabel(gridLayoutWidget_4);
        tq2->setObjectName(QString::fromUtf8("tq2"));
        tq2->setStyleSheet(QString::fromUtf8("image:url(:/day/day/sunny.png)"));

        gridLayout_7->addWidget(tq2, 4, 2, 1, 1);

        h5 = new QLabel(gridLayoutWidget_4);
        h5->setObjectName(QString::fromUtf8("h5"));

        gridLayout_7->addWidget(h5, 5, 5, 1, 1);

        date1 = new QLabel(gridLayoutWidget_4);
        date1->setObjectName(QString::fromUtf8("date1"));

        gridLayout_7->addWidget(date1, 1, 1, 1, 1);

        quli3 = new QLabel(gridLayoutWidget_4);
        quli3->setObjectName(QString::fromUtf8("quli3"));

        gridLayout_7->addWidget(quli3, 2, 3, 1, 1);

        week0 = new QLabel(gridLayoutWidget_4);
        week0->setObjectName(QString::fromUtf8("week0"));

        gridLayout_7->addWidget(week0, 0, 0, 1, 1);

        we4 = new QLabel(gridLayoutWidget_4);
        we4->setObjectName(QString::fromUtf8("we4"));

        gridLayout_7->addWidget(we4, 3, 4, 1, 1);

        week4 = new QLabel(gridLayoutWidget_4);
        week4->setObjectName(QString::fromUtf8("week4"));

        gridLayout_7->addWidget(week4, 0, 4, 1, 1);

        h3 = new QLabel(gridLayoutWidget_4);
        h3->setObjectName(QString::fromUtf8("h3"));

        gridLayout_7->addWidget(h3, 5, 3, 1, 1);

        we5 = new QLabel(gridLayoutWidget_4);
        we5->setObjectName(QString::fromUtf8("we5"));

        gridLayout_7->addWidget(we5, 3, 5, 1, 1);

        week5 = new QLabel(gridLayoutWidget_4);
        week5->setObjectName(QString::fromUtf8("week5"));

        gridLayout_7->addWidget(week5, 0, 5, 1, 1);

        quli0 = new QLabel(gridLayoutWidget_4);
        quli0->setObjectName(QString::fromUtf8("quli0"));

        gridLayout_7->addWidget(quli0, 2, 0, 1, 1);

        we0 = new QLabel(gridLayoutWidget_4);
        we0->setObjectName(QString::fromUtf8("we0"));

        gridLayout_7->addWidget(we0, 3, 0, 1, 1);

        week1 = new QLabel(gridLayoutWidget_4);
        week1->setObjectName(QString::fromUtf8("week1"));

        gridLayout_7->addWidget(week1, 0, 1, 1, 1);

        quli2 = new QLabel(gridLayoutWidget_4);
        quli2->setObjectName(QString::fromUtf8("quli2"));

        gridLayout_7->addWidget(quli2, 2, 2, 1, 1);

        tq3 = new QLabel(gridLayoutWidget_4);
        tq3->setObjectName(QString::fromUtf8("tq3"));
        tq3->setStyleSheet(QString::fromUtf8("image:url(:/day/day/dust_storm.png)"));

        gridLayout_7->addWidget(tq3, 4, 3, 1, 1);

        we1 = new QLabel(gridLayoutWidget_4);
        we1->setObjectName(QString::fromUtf8("we1"));

        gridLayout_7->addWidget(we1, 3, 1, 1, 1);

        date5 = new QLabel(gridLayoutWidget_4);
        date5->setObjectName(QString::fromUtf8("date5"));

        gridLayout_7->addWidget(date5, 1, 5, 1, 1);

        gridLayoutWidget_5 = new QWidget(centralwidget);
        gridLayoutWidget_5->setObjectName(QString::fromUtf8("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(439, 450, 551, 201));
        gridLayout_8 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setContentsMargins(0, 0, 0, 0);
        l3 = new QLabel(gridLayoutWidget_5);
        l3->setObjectName(QString::fromUtf8("l3"));

        gridLayout_8->addWidget(l3, 1, 3, 1, 1);

        l4 = new QLabel(gridLayoutWidget_5);
        l4->setObjectName(QString::fromUtf8("l4"));

        gridLayout_8->addWidget(l4, 1, 4, 1, 1);

        l1 = new QLabel(gridLayoutWidget_5);
        l1->setObjectName(QString::fromUtf8("l1"));

        gridLayout_8->addWidget(l1, 1, 1, 1, 1);

        curveLb = new QLabel(gridLayoutWidget_5);
        curveLb->setObjectName(QString::fromUtf8("curveLb"));

        gridLayout_8->addWidget(curveLb, 0, 0, 1, 6);

        l0 = new QLabel(gridLayoutWidget_5);
        l0->setObjectName(QString::fromUtf8("l0"));

        gridLayout_8->addWidget(l0, 1, 0, 1, 1);

        l5 = new QLabel(gridLayoutWidget_5);
        l5->setObjectName(QString::fromUtf8("l5"));

        gridLayout_8->addWidget(l5, 1, 5, 1, 1);

        l2 = new QLabel(gridLayoutWidget_5);
        l2->setObjectName(QString::fromUtf8("l2"));

        gridLayout_8->addWidget(l2, 1, 2, 1, 1);

        refresh = new QPushButton(centralwidget);
        refresh->setObjectName(QString::fromUtf8("refresh"));
        refresh->setGeometry(QRect(890, 30, 51, 51));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Adobe \345\256\213\344\275\223 Std L"));
        font1.setPointSize(6);
        refresh->setFont(font1);
        refresh->setCursor(QCursor(Qt::PointingHandCursor));
        refresh->setStyleSheet(QString::fromUtf8("image:url(:/weatherico/refresh.ico)"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(810, 40, 51, 41));
        pushButton->setStyleSheet(QString::fromUtf8("border-image: url(:/weatherico/search.png);\n"
"background-color: rgba(60, 60, 60, 0);"));
        weather->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(weather);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        weather->setStatusBar(statusbar);
        menubar = new QMenuBar(weather);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1001, 21));
        weather->setMenuBar(menubar);

        retranslateUi(weather);

        QMetaObject::connectSlotsByName(weather);
    } // setupUi

    void retranslateUi(QMainWindow *weather)
    {
        weather->setWindowTitle(QApplication::translate("weather", "weather", nullptr));
        dateLb->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#00ff00;\">2025-4-11</span></p></body></html>", nullptr));
        label->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\">\345\244\251\346\260\224\351\242\204\346\212\245</p></body></html>", nullptr));
        pmnr->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" color:#55aa7f;\">26</span></p></body></html>", nullptr));
        flnr->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" color:#55aa7f;\">4\347\272\247</span></p></body></html>", nullptr));
        pm->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#55aa7f;\">PM2.5</span></p></body></html>", nullptr));
        shidu->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#55aa7f;\">\346\271\277\345\272\246</span></p></body></html>", nullptr));
        xidunr->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" color:#55aa7f;\">63%</span></p></body></html>", nullptr));
        fengl->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#55aa7f;\">\351\243\216\345\212\233</span></p></body></html>", nullptr));
        fxnr->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" color:#55aa7f;\">\345\214\227\351\243\216</span></p></body></html>", nullptr));
        fengx->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#55aa7f;\">\351\243\216\345\220\221</span></p></body></html>", nullptr));
        typewea->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#55aa7f;\"></span></p></body></html>", nullptr));
        citywz->setText(QApplication::translate("weather", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\"-qt-paragraph-type:empty; margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        jianyi->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#55aa7f;\">\351\201\223\350\267\257\346\271\277\346\273\221\357\274\214\346\255\245\350\241\214\345\274\200\350\275\246\350\260\250\346\205\216</span></p></body></html>", nullptr));
        temLb->setText(QString());
        wz->setText(QString());
        sunRiseSetLb->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><br/></p></body></html>", nullptr));
        suggest->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" color:#55aa7f;\">\346\236\201\345\260\221\346\225\260\346\225\217\346\204\237\344\272\272\347\276\244\345\272\224\345\207\217\345\260\221\346\210\267\345\244\226\346\264\273\345\212\250</span></p></body></html>", nullptr));
        coolill->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#55aa7f;\">\346\204\237\345\206\222\346\214\207\346\225\260</span></p></body></html>", nullptr));
        quli4->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#00aaff;\">\350\275\273\345\272\246\346\261\241\346\237\223</span></p></body></html>", nullptr));
        tq4->setText(QString());
        we3->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ff5500;\">\345\244\232\344\272\221</span></p></body></html>", nullptr));
        date4->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ffaaff;\">14</span></p></body></html>", nullptr));
        quli1->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#00aaff;\">\344\274\230</span></p></body></html>", nullptr));
        quli5->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#00aaff;\">\351\207\215\345\272\246\346\261\241\346\237\223</span></p></body></html>", nullptr));
        week3->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ffaa7f;\">\346\230\237\346\234\237\345\244\251</span></p></body></html>", nullptr));
        date3->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ffaaff;\">13</span></p></body></html>", nullptr));
        we2->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ff5500;\">\346\231\264</span></p></body></html>", nullptr));
        date2->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ffaaff;\">12</span></p></body></html>", nullptr));
        h2->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ff0000;\">1</span></p></body></html>", nullptr));
        tq0->setText(QString());
        h1->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ff0000;\">4</span></p></body></html>", nullptr));
        week2->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ffaa7f;\">\346\230\237\346\234\237\345\205\255</span></p></body></html>", nullptr));
        tq5->setText(QString());
        tq1->setText(QString());
        date0->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ffaaff;\">10</span></p></body></html>", nullptr));
        h0->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ff0000;\">1</span></p></body></html>", nullptr));
        h4->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ff0000;\">13</span></p></body></html>", nullptr));
        tq2->setText(QString());
        h5->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ff0000;\">20</span></p></body></html>", nullptr));
        date1->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ffaaff;\">11</span></p></body></html>", nullptr));
        quli3->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#00aaff;\">\350\211\257</span></p></body></html>", nullptr));
        week0->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ffaa7f;\">\346\230\250\345\244\251</span></p></body></html>", nullptr));
        we4->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ff5500;\">\351\230\264</span></p></body></html>", nullptr));
        week4->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ffaa7f;\">\346\230\237\346\234\237\344\270\200</span></p></body></html>", nullptr));
        h3->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ff0000;\">2</span></p></body></html>", nullptr));
        we5->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ff5500;\">\346\231\264</span></p></body></html>", nullptr));
        week5->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ffaa7f;\">\346\230\237\346\234\237\344\272\214</span></p></body></html>", nullptr));
        quli0->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#00aaff;\">\350\275\273\345\272\246\346\261\241\346\237\223</span></p></body></html>", nullptr));
        we0->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ff5500;\">\345\260\217\351\233\250</span></p></body></html>", nullptr));
        week1->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ffaa7f;\">\344\273\212\345\244\251</span></p></body></html>", nullptr));
        quli2->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#00aaff;\">\344\274\230</span></p></body></html>", nullptr));
        tq3->setText(QString());
        we1->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ff5500;\">\351\233\250\345\244\271\351\233\252</span></p></body></html>", nullptr));
        date5->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#ffaaff;\">15</span></p></body></html>", nullptr));
        l3->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#5555ff;\">7</span></p></body></html>", nullptr));
        l4->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#5555ff;\">9</span></p></body></html>", nullptr));
        l1->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#5555ff;\">2</span></p></body></html>", nullptr));
        curveLb->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\">TextLabel</p></body></html>", nullptr));
        l0->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#5555ff;\">0</span></p></body></html>", nullptr));
        l5->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#5555ff;\">10</span></p></body></html>", nullptr));
        l2->setText(QApplication::translate("weather", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600; color:#5555ff;\">3</span></p></body></html>", nullptr));
        refresh->setText(QString());
        pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class weather: public Ui_weather {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEATHER_H
