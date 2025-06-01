/********************************************************************************
** Form generated from reading UI file 'Form.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDial>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QDial *dial;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLCDNumber *lcdNumber;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLCDNumber *lcdNumber_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLCDNumber *lcdNumber_3;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_5;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushButton;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(725, 601);
        verticalLayout = new QVBoxLayout(Form);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(Form);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(Form);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout->addWidget(spinBox);

        dial = new QDial(Form);
        dial->setObjectName(QString::fromUtf8("dial"));

        horizontalLayout->addWidget(dial);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 168, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(Form);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setStyleSheet(QString::fromUtf8("color: rgb(10, 156, 89);"));

        horizontalLayout_2->addWidget(label_2);

        lcdNumber = new QLCDNumber(Form);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setStyleSheet(QString::fromUtf8("background-color: rgb(46, 194, 126);"));
        lcdNumber->setDigitCount(7);
        lcdNumber->setMode(QLCDNumber::Bin);

        horizontalLayout_2->addWidget(lcdNumber);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(Form);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setStyleSheet(QString::fromUtf8("color: rgb(28, 113, 216);"));

        horizontalLayout_3->addWidget(label_3);

        lcdNumber_2 = new QLCDNumber(Form);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));
        lcdNumber_2->setStyleSheet(QString::fromUtf8("background-color: rgb(28, 113, 216);"));
        lcdNumber_2->setDigitCount(7);
        lcdNumber_2->setMode(QLCDNumber::Oct);

        horizontalLayout_3->addWidget(lcdNumber_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(Form);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setStyleSheet(QString::fromUtf8("color: rgb(192, 28, 40);"));

        horizontalLayout_4->addWidget(label_4);

        lcdNumber_3 = new QLCDNumber(Form);
        lcdNumber_3->setObjectName(QString::fromUtf8("lcdNumber_3"));
        lcdNumber_3->setStyleSheet(QString::fromUtf8("background-color: rgb(192, 28, 40);"));
        lcdNumber_3->setDigitCount(7);
        lcdNumber_3->setMode(QLCDNumber::Hex);

        horizontalLayout_4->addWidget(lcdNumber_3);


        verticalLayout->addLayout(horizontalLayout_4);

        verticalSpacer_2 = new QSpacerItem(20, 167, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        pushButton = new QPushButton(Form);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_5->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout_5);


        retranslateUi(Form);
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), dial, SLOT(setValue(int)));
        QObject::connect(dial, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), lcdNumber_2, SLOT(display(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), lcdNumber_3, SLOT(display(int)));
        QObject::connect(pushButton, SIGNAL(clicked()), Form, SLOT(close()));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), lcdNumber, SLOT(display(int)));

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        label->setText(QCoreApplication::translate("Form", "Write a natrual number", nullptr));
        label_2->setText(QCoreApplication::translate("Form", "Binary", nullptr));
        label_3->setText(QCoreApplication::translate("Form", "Octal", nullptr));
        label_4->setText(QCoreApplication::translate("Form", "Hexadecimal", nullptr));
        pushButton->setText(QCoreApplication::translate("Form", "&Quit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
