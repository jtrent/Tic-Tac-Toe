/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Mon Dec 6 13:20:20 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *backgroundImage;
    QPushButton *buttonNext;
    QPushButton *button0b;
    QPushButton *button0o;
    QPushButton *button2b;
    QPushButton *button3b;
    QPushButton *button4b;
    QPushButton *button5b;
    QPushButton *button6b;
    QPushButton *button7b;
    QPushButton *button8b;
    QPushButton *button1b;
    QPushButton *button0x;
    QPushButton *button1o;
    QPushButton *button2o;
    QPushButton *button3o;
    QPushButton *button4o;
    QPushButton *button5o;
    QPushButton *button6o;
    QPushButton *button7o;
    QPushButton *button8o;
    QPushButton *button1x;
    QPushButton *button2x;
    QPushButton *button3x;
    QPushButton *button4x;
    QPushButton *button5x;
    QPushButton *button6x;
    QPushButton *button7x;
    QPushButton *button8x;
    QLabel *playero;
    QLabel *playerx;
    QPushButton *buttonDraw;
    QPushButton *buttonPlayerXWins;
    QPushButton *buttonPlayerOWins;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(600, 600);
        MainWindow->setMinimumSize(QSize(600, 600));
        MainWindow->setMaximumSize(QSize(600, 600));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setMinimumSize(QSize(600, 600));
        centralWidget->setMaximumSize(QSize(600, 600));
        backgroundImage = new QLabel(centralWidget);
        backgroundImage->setObjectName(QString::fromUtf8("backgroundImage"));
        backgroundImage->setGeometry(QRect(0, 0, 600, 600));
        backgroundImage->setMinimumSize(QSize(600, 600));
        backgroundImage->setMaximumSize(QSize(600, 600));
        backgroundImage->setMidLineWidth(0);
        backgroundImage->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/Back")));
        buttonNext = new QPushButton(centralWidget);
        buttonNext->setObjectName(QString::fromUtf8("buttonNext"));
        buttonNext->setGeometry(QRect(440, 458, 138, 26));
        buttonNext->setMinimumSize(QSize(138, 26));
        buttonNext->setMaximumSize(QSize(138, 26));
        buttonNext->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/Next"), QSize(), QIcon::Normal, QIcon::Off);
        buttonNext->setIcon(icon);
        buttonNext->setIconSize(QSize(138, 25));
        button0b = new QPushButton(centralWidget);
        button0b->setObjectName(QString::fromUtf8("button0b"));
        button0b->setGeometry(QRect(36, 102, 111, 111));
        button0b->setMinimumSize(QSize(111, 111));
        button0b->setMaximumSize(QSize(111, 111));
        button0b->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/B"), QSize(), QIcon::Normal, QIcon::Off);
        button0b->setIcon(icon1);
        button0b->setIconSize(QSize(111, 111));
        button0o = new QPushButton(centralWidget);
        button0o->setObjectName(QString::fromUtf8("button0o"));
        button0o->setGeometry(QRect(36, 102, 111, 111));
        button0o->setMinimumSize(QSize(111, 111));
        button0o->setMaximumSize(QSize(111, 111));
        button0o->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/O"), QSize(), QIcon::Normal, QIcon::Off);
        button0o->setIcon(icon2);
        button0o->setIconSize(QSize(111, 111));
        button2b = new QPushButton(centralWidget);
        button2b->setObjectName(QString::fromUtf8("button2b"));
        button2b->setGeometry(QRect(308, 102, 111, 111));
        button2b->setMinimumSize(QSize(111, 111));
        button2b->setMaximumSize(QSize(111, 111));
        button2b->setCursor(QCursor(Qt::PointingHandCursor));
        button2b->setIcon(icon1);
        button2b->setIconSize(QSize(111, 111));
        button3b = new QPushButton(centralWidget);
        button3b->setObjectName(QString::fromUtf8("button3b"));
        button3b->setGeometry(QRect(36, 238, 111, 111));
        button3b->setMinimumSize(QSize(111, 111));
        button3b->setMaximumSize(QSize(111, 111));
        button3b->setCursor(QCursor(Qt::PointingHandCursor));
        button3b->setIcon(icon1);
        button3b->setIconSize(QSize(111, 111));
        button4b = new QPushButton(centralWidget);
        button4b->setObjectName(QString::fromUtf8("button4b"));
        button4b->setGeometry(QRect(172, 238, 111, 111));
        button4b->setMinimumSize(QSize(111, 111));
        button4b->setMaximumSize(QSize(111, 111));
        button4b->setCursor(QCursor(Qt::PointingHandCursor));
        button4b->setIcon(icon1);
        button4b->setIconSize(QSize(111, 111));
        button5b = new QPushButton(centralWidget);
        button5b->setObjectName(QString::fromUtf8("button5b"));
        button5b->setGeometry(QRect(308, 238, 111, 111));
        button5b->setMinimumSize(QSize(111, 111));
        button5b->setMaximumSize(QSize(111, 111));
        button5b->setCursor(QCursor(Qt::PointingHandCursor));
        button5b->setIcon(icon1);
        button5b->setIconSize(QSize(111, 111));
        button6b = new QPushButton(centralWidget);
        button6b->setObjectName(QString::fromUtf8("button6b"));
        button6b->setGeometry(QRect(36, 374, 111, 111));
        button6b->setMinimumSize(QSize(111, 111));
        button6b->setMaximumSize(QSize(111, 111));
        button6b->setCursor(QCursor(Qt::PointingHandCursor));
        button6b->setIcon(icon1);
        button6b->setIconSize(QSize(111, 111));
        button7b = new QPushButton(centralWidget);
        button7b->setObjectName(QString::fromUtf8("button7b"));
        button7b->setGeometry(QRect(172, 374, 111, 111));
        button7b->setMinimumSize(QSize(111, 111));
        button7b->setMaximumSize(QSize(111, 111));
        button7b->setCursor(QCursor(Qt::PointingHandCursor));
        button7b->setIcon(icon1);
        button7b->setIconSize(QSize(111, 111));
        button8b = new QPushButton(centralWidget);
        button8b->setObjectName(QString::fromUtf8("button8b"));
        button8b->setGeometry(QRect(308, 374, 111, 111));
        button8b->setMinimumSize(QSize(111, 111));
        button8b->setMaximumSize(QSize(111, 111));
        button8b->setCursor(QCursor(Qt::PointingHandCursor));
        button8b->setIcon(icon1);
        button8b->setIconSize(QSize(111, 111));
        button1b = new QPushButton(centralWidget);
        button1b->setObjectName(QString::fromUtf8("button1b"));
        button1b->setGeometry(QRect(172, 102, 111, 111));
        button1b->setMinimumSize(QSize(111, 111));
        button1b->setMaximumSize(QSize(111, 111));
        button1b->setCursor(QCursor(Qt::PointingHandCursor));
        button1b->setIcon(icon1);
        button1b->setIconSize(QSize(111, 111));
        button0x = new QPushButton(centralWidget);
        button0x->setObjectName(QString::fromUtf8("button0x"));
        button0x->setGeometry(QRect(36, 102, 111, 111));
        button0x->setMinimumSize(QSize(111, 111));
        button0x->setMaximumSize(QSize(111, 111));
        button0x->setCursor(QCursor(Qt::PointingHandCursor));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/X"), QSize(), QIcon::Normal, QIcon::Off);
        button0x->setIcon(icon3);
        button0x->setIconSize(QSize(111, 111));
        button1o = new QPushButton(centralWidget);
        button1o->setObjectName(QString::fromUtf8("button1o"));
        button1o->setGeometry(QRect(172, 102, 111, 111));
        button1o->setMinimumSize(QSize(111, 111));
        button1o->setMaximumSize(QSize(111, 111));
        button1o->setCursor(QCursor(Qt::PointingHandCursor));
        button1o->setIcon(icon2);
        button1o->setIconSize(QSize(111, 111));
        button2o = new QPushButton(centralWidget);
        button2o->setObjectName(QString::fromUtf8("button2o"));
        button2o->setGeometry(QRect(308, 102, 111, 111));
        button2o->setMinimumSize(QSize(111, 111));
        button2o->setMaximumSize(QSize(111, 111));
        button2o->setCursor(QCursor(Qt::PointingHandCursor));
        button2o->setIcon(icon2);
        button2o->setIconSize(QSize(111, 111));
        button3o = new QPushButton(centralWidget);
        button3o->setObjectName(QString::fromUtf8("button3o"));
        button3o->setGeometry(QRect(36, 238, 111, 111));
        button3o->setMinimumSize(QSize(111, 111));
        button3o->setMaximumSize(QSize(111, 111));
        button3o->setCursor(QCursor(Qt::PointingHandCursor));
        button3o->setIcon(icon2);
        button3o->setIconSize(QSize(111, 111));
        button4o = new QPushButton(centralWidget);
        button4o->setObjectName(QString::fromUtf8("button4o"));
        button4o->setGeometry(QRect(172, 238, 111, 111));
        button4o->setMinimumSize(QSize(111, 111));
        button4o->setMaximumSize(QSize(111, 111));
        button4o->setCursor(QCursor(Qt::PointingHandCursor));
        button4o->setIcon(icon2);
        button4o->setIconSize(QSize(111, 111));
        button5o = new QPushButton(centralWidget);
        button5o->setObjectName(QString::fromUtf8("button5o"));
        button5o->setGeometry(QRect(308, 238, 111, 111));
        button5o->setMinimumSize(QSize(111, 111));
        button5o->setMaximumSize(QSize(111, 111));
        button5o->setCursor(QCursor(Qt::PointingHandCursor));
        button5o->setIcon(icon2);
        button5o->setIconSize(QSize(111, 111));
        button6o = new QPushButton(centralWidget);
        button6o->setObjectName(QString::fromUtf8("button6o"));
        button6o->setGeometry(QRect(36, 374, 111, 111));
        button6o->setMinimumSize(QSize(111, 111));
        button6o->setMaximumSize(QSize(111, 111));
        button6o->setCursor(QCursor(Qt::PointingHandCursor));
        button6o->setIcon(icon2);
        button6o->setIconSize(QSize(111, 111));
        button7o = new QPushButton(centralWidget);
        button7o->setObjectName(QString::fromUtf8("button7o"));
        button7o->setGeometry(QRect(172, 374, 111, 111));
        button7o->setMinimumSize(QSize(111, 111));
        button7o->setMaximumSize(QSize(111, 111));
        button7o->setCursor(QCursor(Qt::PointingHandCursor));
        button7o->setIcon(icon2);
        button7o->setIconSize(QSize(111, 111));
        button8o = new QPushButton(centralWidget);
        button8o->setObjectName(QString::fromUtf8("button8o"));
        button8o->setGeometry(QRect(308, 374, 111, 111));
        button8o->setMinimumSize(QSize(111, 111));
        button8o->setMaximumSize(QSize(111, 111));
        button8o->setCursor(QCursor(Qt::PointingHandCursor));
        button8o->setIcon(icon2);
        button8o->setIconSize(QSize(111, 111));
        button1x = new QPushButton(centralWidget);
        button1x->setObjectName(QString::fromUtf8("button1x"));
        button1x->setGeometry(QRect(172, 102, 111, 111));
        button1x->setMinimumSize(QSize(111, 111));
        button1x->setMaximumSize(QSize(111, 111));
        button1x->setCursor(QCursor(Qt::PointingHandCursor));
        button1x->setIcon(icon3);
        button1x->setIconSize(QSize(111, 111));
        button2x = new QPushButton(centralWidget);
        button2x->setObjectName(QString::fromUtf8("button2x"));
        button2x->setGeometry(QRect(308, 102, 111, 111));
        button2x->setMinimumSize(QSize(111, 111));
        button2x->setMaximumSize(QSize(111, 111));
        button2x->setCursor(QCursor(Qt::PointingHandCursor));
        button2x->setIcon(icon3);
        button2x->setIconSize(QSize(111, 111));
        button3x = new QPushButton(centralWidget);
        button3x->setObjectName(QString::fromUtf8("button3x"));
        button3x->setGeometry(QRect(36, 238, 111, 111));
        button3x->setMinimumSize(QSize(111, 111));
        button3x->setMaximumSize(QSize(111, 111));
        button3x->setCursor(QCursor(Qt::PointingHandCursor));
        button3x->setIcon(icon3);
        button3x->setIconSize(QSize(111, 111));
        button4x = new QPushButton(centralWidget);
        button4x->setObjectName(QString::fromUtf8("button4x"));
        button4x->setGeometry(QRect(172, 238, 111, 111));
        button4x->setMinimumSize(QSize(111, 111));
        button4x->setMaximumSize(QSize(111, 111));
        button4x->setCursor(QCursor(Qt::PointingHandCursor));
        button4x->setIcon(icon3);
        button4x->setIconSize(QSize(111, 111));
        button5x = new QPushButton(centralWidget);
        button5x->setObjectName(QString::fromUtf8("button5x"));
        button5x->setGeometry(QRect(308, 238, 111, 111));
        button5x->setMinimumSize(QSize(111, 111));
        button5x->setMaximumSize(QSize(111, 111));
        button5x->setCursor(QCursor(Qt::PointingHandCursor));
        button5x->setIcon(icon3);
        button5x->setIconSize(QSize(111, 111));
        button6x = new QPushButton(centralWidget);
        button6x->setObjectName(QString::fromUtf8("button6x"));
        button6x->setGeometry(QRect(36, 374, 111, 111));
        button6x->setMinimumSize(QSize(111, 111));
        button6x->setMaximumSize(QSize(111, 111));
        button6x->setCursor(QCursor(Qt::PointingHandCursor));
        button6x->setIcon(icon3);
        button6x->setIconSize(QSize(111, 111));
        button7x = new QPushButton(centralWidget);
        button7x->setObjectName(QString::fromUtf8("button7x"));
        button7x->setGeometry(QRect(172, 374, 111, 111));
        button7x->setMinimumSize(QSize(111, 111));
        button7x->setMaximumSize(QSize(111, 111));
        button7x->setCursor(QCursor(Qt::PointingHandCursor));
        button7x->setIcon(icon3);
        button7x->setIconSize(QSize(111, 111));
        button8x = new QPushButton(centralWidget);
        button8x->setObjectName(QString::fromUtf8("button8x"));
        button8x->setGeometry(QRect(308, 374, 111, 111));
        button8x->setMinimumSize(QSize(111, 111));
        button8x->setMaximumSize(QSize(111, 111));
        button8x->setCursor(QCursor(Qt::PointingHandCursor));
        button8x->setIcon(icon3);
        button8x->setIconSize(QSize(111, 111));
        playero = new QLabel(centralWidget);
        playero->setObjectName(QString::fromUtf8("playero"));
        playero->setGeometry(QRect(440, 102, 131, 33));
        playero->setMinimumSize(QSize(131, 33));
        playero->setMaximumSize(QSize(131, 33));
        playero->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/PlayerO")));
        playerx = new QLabel(centralWidget);
        playerx->setObjectName(QString::fromUtf8("playerx"));
        playerx->setGeometry(QRect(440, 102, 131, 33));
        playerx->setMinimumSize(QSize(131, 33));
        playerx->setMaximumSize(QSize(131, 33));
        playerx->setLineWidth(14);
        playerx->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/PlayerX")));
        buttonDraw = new QPushButton(centralWidget);
        buttonDraw->setObjectName(QString::fromUtf8("buttonDraw"));
        buttonDraw->setGeometry(QRect(0, 0, 600, 570));
        buttonDraw->setMinimumSize(QSize(600, 570));
        buttonDraw->setMaximumSize(QSize(600, 570));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/images/drawgame.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        buttonDraw->setIcon(icon4);
        buttonDraw->setIconSize(QSize(600, 570));
        buttonPlayerXWins = new QPushButton(centralWidget);
        buttonPlayerXWins->setObjectName(QString::fromUtf8("buttonPlayerXWins"));
        buttonPlayerXWins->setGeometry(QRect(0, 0, 600, 570));
        buttonPlayerXWins->setMinimumSize(QSize(600, 570));
        buttonPlayerXWins->setMaximumSize(QSize(600, 570));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/images/playerxwins.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        buttonPlayerXWins->setIcon(icon5);
        buttonPlayerXWins->setIconSize(QSize(600, 570));
        buttonPlayerOWins = new QPushButton(centralWidget);
        buttonPlayerOWins->setObjectName(QString::fromUtf8("buttonPlayerOWins"));
        buttonPlayerOWins->setGeometry(QRect(0, 0, 600, 570));
        buttonPlayerOWins->setMinimumSize(QSize(600, 570));
        buttonPlayerOWins->setMaximumSize(QSize(600, 570));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/images/playerowins.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        buttonPlayerOWins->setIcon(icon6);
        buttonPlayerOWins->setIconSize(QSize(600, 570));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        backgroundImage->setText(QString());
        buttonNext->setText(QString());
        button0b->setText(QString());
        button0o->setText(QString());
        button2b->setText(QString());
        button3b->setText(QString());
        button4b->setText(QString());
        button5b->setText(QString());
        button6b->setText(QString());
        button7b->setText(QString());
        button8b->setText(QString());
        button1b->setText(QString());
        button0x->setText(QString());
        button1o->setText(QString());
        button2o->setText(QString());
        button3o->setText(QString());
        button4o->setText(QString());
        button5o->setText(QString());
        button6o->setText(QString());
        button7o->setText(QString());
        button8o->setText(QString());
        button1x->setText(QString());
        button2x->setText(QString());
        button3x->setText(QString());
        button4x->setText(QString());
        button5x->setText(QString());
        button6x->setText(QString());
        button7x->setText(QString());
        button8x->setText(QString());
        playero->setText(QString());
        playerx->setText(QString());
        buttonDraw->setText(QString());
        buttonPlayerXWins->setText(QString());
        buttonPlayerOWins->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
