/********************************************************************************
** Form generated from reading UI file 'image2sound.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGE2SOUND_H
#define UI_IMAGE2SOUND_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_image2soundClass
{
public:
    QWidget *centralWidget;
    QPushButton *button_load;
    QPushButton *button_play;
    QProgressBar *progressBar;
    QLabel *label_original;
    QPushButton *button_close;
    QLabel *label_processed;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *image2soundClass)
    {
        if (image2soundClass->objectName().isEmpty())
            image2soundClass->setObjectName(QStringLiteral("image2soundClass"));
        image2soundClass->resize(600, 400);
        centralWidget = new QWidget(image2soundClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        button_load = new QPushButton(centralWidget);
        button_load->setObjectName(QStringLiteral("button_load"));
        button_load->setGeometry(QRect(30, 40, 81, 41));
        button_play = new QPushButton(centralWidget);
        button_play->setObjectName(QStringLiteral("button_play"));
        button_play->setGeometry(QRect(130, 40, 91, 41));
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(360, 40, 211, 23));
        progressBar->setValue(0);
        label_original = new QLabel(centralWidget);
        label_original->setObjectName(QStringLiteral("label_original"));
        label_original->setGeometry(QRect(70, 130, 151, 161));
        label_original->setTextFormat(Qt::RichText);
        label_original->setScaledContents(true);
        button_close = new QPushButton(centralWidget);
        button_close->setObjectName(QStringLiteral("button_close"));
        button_close->setGeometry(QRect(250, 40, 81, 41));
        label_processed = new QLabel(centralWidget);
        label_processed->setObjectName(QStringLiteral("label_processed"));
        label_processed->setGeometry(QRect(340, 130, 161, 161));
        label_processed->setTextFormat(Qt::RichText);
        label_processed->setScaledContents(true);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(80, 310, 131, 31));
        textEdit->setFrameShape(QFrame::NoFrame);
        textEdit_2 = new QTextEdit(centralWidget);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));
        textEdit_2->setGeometry(QRect(360, 310, 131, 31));
        textEdit_2->setFrameShape(QFrame::NoFrame);
        image2soundClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(image2soundClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        image2soundClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(image2soundClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        image2soundClass->setStatusBar(statusBar);

        retranslateUi(image2soundClass);
        QObject::connect(button_load, SIGNAL(clicked()), image2soundClass, SLOT(load()));
        QObject::connect(button_play, SIGNAL(clicked()), image2soundClass, SLOT(play()));
        QObject::connect(button_close, SIGNAL(clicked()), image2soundClass, SLOT(close_window()));

        QMetaObject::connectSlotsByName(image2soundClass);
    } // setupUi

    void retranslateUi(QMainWindow *image2soundClass)
    {
        image2soundClass->setWindowTitle(QApplication::translate("image2soundClass", "image2sound", 0));
        button_load->setText(QApplication::translate("image2soundClass", "Load", 0));
        button_play->setText(QApplication::translate("image2soundClass", "Play", 0));
        label_original->setText(QString());
        button_close->setText(QApplication::translate("image2soundClass", "Close", 0));
        label_processed->setText(QString());
        textEdit->setHtml(QApplication::translate("image2soundClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Original frame</span></p></body></html>", 0));
        textEdit_2->setHtml(QApplication::translate("image2soundClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600;\">Processed frame</span></p></body></html>", 0));
    } // retranslateUi

};

namespace Ui {
    class image2soundClass: public Ui_image2soundClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGE2SOUND_H
