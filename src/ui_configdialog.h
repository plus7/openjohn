/********************************************************************************
** Form generated from reading ui file 'configdialog.ui'
**
** Created: Fri Apr 3 12:59:27 2009
**      by: Qt User Interface Compiler version 4.5.0
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CONFIGDIALOG_H
#define UI_CONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConfigDialog
{
public:
    QDialogButtonBox *buttonBox;
    QListWidget *listWidget;
    QStackedWidget *confPanels;
    QWidget *page;
    QGroupBox *groupBox;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QWidget *page_2;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QGroupBox *groupBox_3;
    QCheckBox *checkBox_5;
    QCheckBox *checkBox_6;
    QGroupBox *groupBox_4;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_9;
    QCheckBox *checkBox_10;
    QGroupBox *groupBox_5;
    QCheckBox *checkBox_11;
    QWidget *page_5;
    QWidget *page_3;
    QCheckBox *checkBox_12;
    QCheckBox *checkBox_13;
    QCheckBox *checkBox_14;
    QCheckBox *checkBox_15;
    QCheckBox *checkBox_16;
    QCheckBox *checkBox_17;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;
    QPlainTextEdit *plainTextEdit_3;
    QCheckBox *checkBox_18;
    QCheckBox *checkBox_19;
    QCheckBox *checkBox_20;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QCheckBox *checkBox_21;
    QWidget *page_6;
    QTabWidget *tabWidget;
    QWidget *tab;
    QListWidget *listWidget_2;
    QWidget *tab_2;
    QListWidget *listWidget_3;
    QWidget *tab_3;
    QListWidget *listWidget_4;
    QWidget *tab_4;
    QListWidget *listWidget_5;
    QWidget *tab_5;
    QListWidget *listWidget_6;
    QWidget *tab_6;
    QListWidget *listWidget_7;
    QWidget *tab_7;
    QListWidget *listWidget_8;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QWidget *page_7;
    QTableWidget *tableWidget;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_4;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit_3;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QWidget *page_4;
    QWidget *page_8;
    QTableWidget *tableWidget_2;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QPushButton *pushButton_13;
    QPushButton *pushButton_14;
    QWidget *page_9;
    QLabel *label_10;
    QWidget *page_10;
    QCheckBox *checkBox_22;
    QWidget *page_11;
    QCheckBox *checkBox_23;
    QCheckBox *checkBox_24;
    QCheckBox *checkBox_25;

    void setupUi(QDialog *ConfigDialog)
    {
        if (ConfigDialog->objectName().isEmpty())
            ConfigDialog->setObjectName(QString::fromUtf8("ConfigDialog"));
        ConfigDialog->resize(518, 423);
        ConfigDialog->setModal(true);
        buttonBox = new QDialogButtonBox(ConfigDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(10, 391, 501, 21));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        listWidget = new QListWidget(ConfigDialog);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        new QListWidgetItem(listWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setGeometry(QRect(10, 10, 111, 401));
        confPanels = new QStackedWidget(ConfigDialog);
        confPanels->setObjectName(QString::fromUtf8("confPanels"));
        confPanels->setGeometry(QRect(130, 10, 381, 371));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        groupBox = new QGroupBox(page);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 50, 381, 141));
        checkBox = new QCheckBox(page);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(0, 10, 76, 18));
        checkBox_2 = new QCheckBox(page);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setGeometry(QRect(0, 30, 121, 18));
        lineEdit = new QLineEdit(page);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(90, 200, 291, 20));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 200, 91, 16));
        confPanels->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        groupBox_2 = new QGroupBox(page_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 0, 371, 71));
        checkBox_3 = new QCheckBox(groupBox_2);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setGeometry(QRect(10, 20, 121, 18));
        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setGeometry(QRect(10, 40, 161, 18));
        groupBox_3 = new QGroupBox(page_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 80, 371, 71));
        checkBox_5 = new QCheckBox(groupBox_3);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setGeometry(QRect(10, 20, 151, 18));
        checkBox_6 = new QCheckBox(groupBox_3);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setGeometry(QRect(10, 40, 211, 18));
        groupBox_4 = new QGroupBox(page_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(0, 160, 371, 111));
        checkBox_7 = new QCheckBox(groupBox_4);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setGeometry(QRect(10, 20, 76, 18));
        checkBox_8 = new QCheckBox(groupBox_4);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setGeometry(QRect(10, 40, 76, 18));
        checkBox_9 = new QCheckBox(groupBox_4);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        checkBox_9->setGeometry(QRect(10, 60, 76, 18));
        checkBox_10 = new QCheckBox(groupBox_4);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));
        checkBox_10->setGeometry(QRect(10, 80, 76, 18));
        groupBox_5 = new QGroupBox(page_2);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(0, 280, 371, 51));
        checkBox_11 = new QCheckBox(groupBox_5);
        checkBox_11->setObjectName(QString::fromUtf8("checkBox_11"));
        checkBox_11->setGeometry(QRect(10, 20, 76, 18));
        confPanels->addWidget(page_2);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        confPanels->addWidget(page_5);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        checkBox_12 = new QCheckBox(page_3);
        checkBox_12->setObjectName(QString::fromUtf8("checkBox_12"));
        checkBox_12->setGeometry(QRect(0, 0, 151, 18));
        checkBox_13 = new QCheckBox(page_3);
        checkBox_13->setObjectName(QString::fromUtf8("checkBox_13"));
        checkBox_13->setGeometry(QRect(0, 20, 151, 20));
        checkBox_14 = new QCheckBox(page_3);
        checkBox_14->setObjectName(QString::fromUtf8("checkBox_14"));
        checkBox_14->setGeometry(QRect(0, 40, 161, 18));
        checkBox_15 = new QCheckBox(page_3);
        checkBox_15->setObjectName(QString::fromUtf8("checkBox_15"));
        checkBox_15->setGeometry(QRect(0, 60, 141, 18));
        checkBox_16 = new QCheckBox(page_3);
        checkBox_16->setObjectName(QString::fromUtf8("checkBox_16"));
        checkBox_16->setGeometry(QRect(0, 80, 181, 18));
        checkBox_17 = new QCheckBox(page_3);
        checkBox_17->setObjectName(QString::fromUtf8("checkBox_17"));
        checkBox_17->setGeometry(QRect(0, 100, 76, 18));
        plainTextEdit = new QPlainTextEdit(page_3);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(0, 180, 151, 81));
        plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        plainTextEdit_2 = new QPlainTextEdit(page_3);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(160, 180, 111, 81));
        plainTextEdit_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        plainTextEdit_3 = new QPlainTextEdit(page_3);
        plainTextEdit_3->setObjectName(QString::fromUtf8("plainTextEdit_3"));
        plainTextEdit_3->setGeometry(QRect(280, 180, 104, 81));
        plainTextEdit_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        checkBox_18 = new QCheckBox(page_3);
        checkBox_18->setObjectName(QString::fromUtf8("checkBox_18"));
        checkBox_18->setGeometry(QRect(0, 120, 91, 18));
        checkBox_19 = new QCheckBox(page_3);
        checkBox_19->setObjectName(QString::fromUtf8("checkBox_19"));
        checkBox_19->setGeometry(QRect(0, 140, 76, 18));
        checkBox_20 = new QCheckBox(page_3);
        checkBox_20->setObjectName(QString::fromUtf8("checkBox_20"));
        checkBox_20->setGeometry(QRect(30, 160, 121, 18));
        label_2 = new QLabel(page_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 160, 31, 16));
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(160, 160, 31, 16));
        label_4 = new QLabel(page_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(280, 160, 61, 16));
        checkBox_21 = new QCheckBox(page_3);
        checkBox_21->setObjectName(QString::fromUtf8("checkBox_21"));
        checkBox_21->setGeometry(QRect(200, 160, 76, 18));
        confPanels->addWidget(page_3);
        page_6 = new QWidget();
        page_6->setObjectName(QString::fromUtf8("page_6"));
        tabWidget = new QTabWidget(page_6);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 381, 321));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        listWidget_2 = new QListWidget(tab);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));
        listWidget_2->setGeometry(QRect(10, 10, 361, 281));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        listWidget_3 = new QListWidget(tab_2);
        listWidget_3->setObjectName(QString::fromUtf8("listWidget_3"));
        listWidget_3->setGeometry(QRect(60, 70, 256, 192));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        listWidget_4 = new QListWidget(tab_3);
        listWidget_4->setObjectName(QString::fromUtf8("listWidget_4"));
        listWidget_4->setGeometry(QRect(200, 90, 256, 192));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        listWidget_5 = new QListWidget(tab_4);
        listWidget_5->setObjectName(QString::fromUtf8("listWidget_5"));
        listWidget_5->setGeometry(QRect(10, 10, 256, 192));
        tabWidget->addTab(tab_4, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        listWidget_6 = new QListWidget(tab_5);
        listWidget_6->setObjectName(QString::fromUtf8("listWidget_6"));
        listWidget_6->setGeometry(QRect(40, 30, 256, 192));
        tabWidget->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        listWidget_7 = new QListWidget(tab_6);
        listWidget_7->setObjectName(QString::fromUtf8("listWidget_7"));
        listWidget_7->setGeometry(QRect(70, 20, 256, 192));
        tabWidget->addTab(tab_6, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        listWidget_8 = new QListWidget(tab_7);
        listWidget_8->setObjectName(QString::fromUtf8("listWidget_8"));
        listWidget_8->setGeometry(QRect(50, 60, 256, 192));
        tabWidget->addTab(tab_7, QString());
        lineEdit_2 = new QLineEdit(page_6);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(0, 340, 211, 20));
        pushButton = new QPushButton(page_6);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(220, 340, 75, 23));
        pushButton_2 = new QPushButton(page_6);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(300, 340, 75, 23));
        confPanels->addWidget(page_6);
        page_7 = new QWidget();
        page_7->setObjectName(QString::fromUtf8("page_7"));
        tableWidget = new QTableWidget(page_7);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(0, 140, 381, 191));
        pushButton_3 = new QPushButton(page_7);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(40, 10, 21, 23));
        pushButton_5 = new QPushButton(page_7);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(40, 40, 21, 23));
        pushButton_6 = new QPushButton(page_7);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(70, 40, 20, 23));
        pushButton_7 = new QPushButton(page_7);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        pushButton_7->setGeometry(QRect(40, 70, 21, 23));
        pushButton_4 = new QPushButton(page_7);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(10, 40, 21, 23));
        comboBox = new QComboBox(page_7);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(100, 30, 271, 22));
        comboBox_2 = new QComboBox(page_7);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(100, 80, 81, 22));
        comboBox_3 = new QComboBox(page_7);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(190, 80, 181, 22));
        label_5 = new QLabel(page_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(100, 60, 91, 16));
        label_6 = new QLabel(page_7);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(100, 10, 61, 16));
        label_7 = new QLabel(page_7);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(100, 110, 41, 16));
        lineEdit_3 = new QLineEdit(page_7);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(150, 110, 113, 20));
        pushButton_8 = new QPushButton(page_7);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setGeometry(QRect(220, 340, 75, 23));
        pushButton_9 = new QPushButton(page_7);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));
        pushButton_9->setGeometry(QRect(300, 340, 75, 23));
        confPanels->addWidget(page_7);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        confPanels->addWidget(page_4);
        page_8 = new QWidget();
        page_8->setObjectName(QString::fromUtf8("page_8"));
        tableWidget_2 = new QTableWidget(page_8);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(0, 0, 381, 253));
        label_8 = new QLabel(page_8);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(0, 260, 50, 13));
        label_9 = new QLabel(page_8);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(0, 300, 109, 16));
        lineEdit_4 = new QLineEdit(page_8);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(0, 276, 289, 20));
        lineEdit_5 = new QLineEdit(page_8);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(0, 316, 289, 20));
        pushButton_10 = new QPushButton(page_8);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setGeometry(QRect(296, 276, 75, 23));
        pushButton_11 = new QPushButton(page_8);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));
        pushButton_11->setGeometry(QRect(296, 316, 25, 25));
        pushButton_12 = new QPushButton(page_8);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        pushButton_12->setGeometry(QRect(328, 316, 25, 25));
        pushButton_13 = new QPushButton(page_8);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));
        pushButton_13->setGeometry(QRect(0, 344, 75, 23));
        pushButton_14 = new QPushButton(page_8);
        pushButton_14->setObjectName(QString::fromUtf8("pushButton_14"));
        pushButton_14->setGeometry(QRect(84, 344, 75, 23));
        confPanels->addWidget(page_8);
        page_9 = new QWidget();
        page_9->setObjectName(QString::fromUtf8("page_9"));
        label_10 = new QLabel(page_9);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(4, 4, 50, 13));
        confPanels->addWidget(page_9);
        page_10 = new QWidget();
        page_10->setObjectName(QString::fromUtf8("page_10"));
        checkBox_22 = new QCheckBox(page_10);
        checkBox_22->setObjectName(QString::fromUtf8("checkBox_22"));
        checkBox_22->setGeometry(QRect(4, 4, 305, 18));
        confPanels->addWidget(page_10);
        page_11 = new QWidget();
        page_11->setObjectName(QString::fromUtf8("page_11"));
        checkBox_23 = new QCheckBox(page_11);
        checkBox_23->setObjectName(QString::fromUtf8("checkBox_23"));
        checkBox_23->setGeometry(QRect(4, 4, 137, 18));
        checkBox_24 = new QCheckBox(page_11);
        checkBox_24->setObjectName(QString::fromUtf8("checkBox_24"));
        checkBox_24->setGeometry(QRect(4, 24, 153, 18));
        checkBox_25 = new QCheckBox(page_11);
        checkBox_25->setObjectName(QString::fromUtf8("checkBox_25"));
        checkBox_25->setGeometry(QRect(4, 44, 165, 18));
        confPanels->addWidget(page_11);

        retranslateUi(ConfigDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), ConfigDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ConfigDialog, SLOT(reject()));

        confPanels->setCurrentIndex(10);
        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *ConfigDialog)
    {
        ConfigDialog->setWindowTitle(QApplication::translate("ConfigDialog", "\350\250\255\345\256\232", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("ConfigDialog", "\351\200\232\344\277\241", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("ConfigDialog", "\345\213\225\344\275\234", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("ConfigDialog", "\343\202\277\343\203\226\346\223\215\344\275\234", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("ConfigDialog", "\346\233\270\343\201\215\350\276\274\343\201\277", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem4 = listWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("ConfigDialog", "\343\201\202\343\201\274\343\203\274\343\202\223", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem5 = listWidget->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("ConfigDialog", "\343\203\236\343\202\246\343\202\271\343\202\270\343\202\247\343\202\271\343\203\201\343\203\243", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem6 = listWidget->item(6);
        ___qlistwidgetitem6->setText(QApplication::translate("ConfigDialog", "\343\202\255\343\203\274\343\203\234\343\203\274\343\203\211", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem7 = listWidget->item(7);
        ___qlistwidgetitem7->setText(QApplication::translate("ConfigDialog", "\345\244\226\351\203\250\343\202\242\343\203\227\343\203\252\343\202\261\343\203\274\343\202\267\343\203\247\343\203\263", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem8 = listWidget->item(8);
        ___qlistwidgetitem8->setText(QApplication::translate("ConfigDialog", "\346\244\234\347\264\242", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem9 = listWidget->item(9);
        ___qlistwidgetitem9->setText(QApplication::translate("ConfigDialog", "\350\207\252\345\213\225\346\233\264\346\226\260", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem10 = listWidget->item(10);
        ___qlistwidgetitem10->setText(QApplication::translate("ConfigDialog", "\347\224\273\345\203\217", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem11 = listWidget->item(11);
        ___qlistwidgetitem11->setText(QApplication::translate("ConfigDialog", "\343\202\271\343\203\254\343\203\203\343\203\211", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem12 = listWidget->item(12);
        ___qlistwidgetitem12->setText(QApplication::translate("ConfigDialog", "\343\203\235\343\203\203\343\203\227\343\202\242\343\203\203\343\203\227", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem13 = listWidget->item(13);
        ___qlistwidgetitem13->setText(QApplication::translate("ConfigDialog", "\350\211\262\343\203\273\343\203\225\343\202\251\343\203\263\343\203\210", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem14 = listWidget->item(14);
        ___qlistwidgetitem14->setText(QApplication::translate("ConfigDialog", "\343\203\255\343\202\260\343\202\244\343\203\263", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem15 = listWidget->item(15);
        ___qlistwidgetitem15->setText(QApplication::translate("ConfigDialog", "\343\202\265\343\202\246\343\203\263\343\203\211", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem16 = listWidget->item(16);
        ___qlistwidgetitem16->setText(QApplication::translate("ConfigDialog", "\343\203\206\343\203\274\343\203\236", 0, QApplication::UnicodeUTF8));
        listWidget->setSortingEnabled(__sortingEnabled);

        groupBox->setTitle(QApplication::translate("ConfigDialog", "\343\203\227\343\203\255\343\202\255\343\202\267", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("ConfigDialog", "\343\202\252\343\203\263\343\203\251\343\202\244\343\203\263", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("ConfigDialog", "\343\203\227\343\203\255\343\202\255\343\202\267\343\202\222\344\275\277\347\224\250\343\201\231\343\202\213", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ConfigDialog", "\346\235\277\344\270\200\350\246\247\345\217\226\345\276\227URL", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("ConfigDialog", "\346\235\277\344\270\200\350\246\247", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("ConfigDialog", "\346\226\260\343\201\227\343\201\204\343\202\277\343\203\226\343\201\247\346\235\277\343\202\222\351\226\213\343\201\217", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("ConfigDialog", "\343\202\253\343\203\206\343\202\264\343\203\252\343\202\222\343\201\262\343\201\250\343\201\244\343\201\227\343\201\213\351\226\213\343\201\213\343\201\252\343\201\204", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("ConfigDialog", "\343\202\271\343\203\254\343\203\203\343\203\211\344\270\200\350\246\247", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("ConfigDialog", "\346\226\260\343\201\227\343\201\204\343\202\277\343\203\226\343\201\247\343\202\271\343\203\254\343\203\203\343\203\211\343\202\222\351\226\213\343\201\217", 0, QApplication::UnicodeUTF8));
        checkBox_6->setText(QApplication::translate("ConfigDialog", "\346\234\200\345\276\214\343\201\253\350\246\213\343\201\237\343\202\271\343\203\254\343\203\203\343\203\211\343\201\256\344\275\215\347\275\256\343\201\253\343\202\270\343\203\243\343\203\263\343\203\227\343\201\231\343\202\213", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("ConfigDialog", "\343\202\271\343\203\254\343\203\203\343\203\211", 0, QApplication::UnicodeUTF8));
        checkBox_7->setText(QApplication::translate("ConfigDialog", "CheckBox", 0, QApplication::UnicodeUTF8));
        checkBox_8->setText(QApplication::translate("ConfigDialog", "CheckBox", 0, QApplication::UnicodeUTF8));
        checkBox_9->setText(QApplication::translate("ConfigDialog", "CheckBox", 0, QApplication::UnicodeUTF8));
        checkBox_10->setText(QApplication::translate("ConfigDialog", "CheckBox", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("ConfigDialog", "GroupBox", 0, QApplication::UnicodeUTF8));
        checkBox_11->setText(QApplication::translate("ConfigDialog", "CheckBox", 0, QApplication::UnicodeUTF8));
        checkBox_12->setText(QApplication::translate("ConfigDialog", "\345\261\245\346\255\264\343\202\222kakikomi.txt\343\201\253\344\277\235\345\255\230", 0, QApplication::UnicodeUTF8));
        checkBox_13->setText(QApplication::translate("ConfigDialog", "\346\233\270\343\201\215\350\276\274\343\201\277\346\210\220\345\212\237\346\231\202\343\201\253\351\226\211\343\201\230\343\202\213", 0, QApplication::UnicodeUTF8));
        checkBox_14->setText(QApplication::translate("ConfigDialog", "\343\202\271\343\203\254\343\203\203\343\203\211\343\202\277\343\202\244\343\203\210\343\203\253\343\203\221\343\203\215\343\203\253\343\202\222\350\241\250\347\244\272", 0, QApplication::UnicodeUTF8));
        checkBox_15->setText(QApplication::translate("ConfigDialog", "\343\203\207\343\203\225\343\202\251\343\203\253\343\203\210\343\201\247sage\343\203\201\343\202\247\343\203\203\343\202\257", 0, QApplication::UnicodeUTF8));
        checkBox_16->setText(QApplication::translate("ConfigDialog", "\350\246\217\347\264\204\345\244\211\346\233\264\343\201\214\343\201\252\343\201\221\343\202\214\343\201\260\350\207\252\345\213\225\343\201\247\345\220\214\346\204\217", 0, QApplication::UnicodeUTF8));
        checkBox_17->setText(QApplication::translate("ConfigDialog", "\350\252\244\347\210\206\350\255\246\345\221\212", 0, QApplication::UnicodeUTF8));
        checkBox_18->setText(QApplication::translate("ConfigDialog", "\343\202\263\343\203\206\347\257\200\347\251\264\350\255\246\345\221\212", 0, QApplication::UnicodeUTF8));
        checkBox_19->setText(QApplication::translate("ConfigDialog", "\343\203\252\343\203\263\343\202\257\343\201\253\344\270\213\347\267\232", 0, QApplication::UnicodeUTF8));
        checkBox_20->setText(QApplication::translate("ConfigDialog", "\344\270\200\350\241\214\347\233\256\343\202\222\343\203\207\343\203\225\343\202\251\343\203\253\343\203\210\343\201\253", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ConfigDialog", "\345\220\215\345\211\215:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ConfigDialog", "\343\203\241\343\203\274\343\203\253:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("ConfigDialog", "Be\343\203\255\343\202\260\343\202\244\343\203\263:", 0, QApplication::UnicodeUTF8));
        checkBox_21->setText(QApplication::translate("ConfigDialog", "1\350\241\214\347\233\256\343\203\207\343\203\225\343\202\251", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("ConfigDialog", "Name", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("ConfigDialog", "Addr", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("ConfigDialog", "Word", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("ConfigDialog", "ID", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("ConfigDialog", "Be", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("ConfigDialog", "NGEx", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("ConfigDialog", "Thread", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("ConfigDialog", "\350\277\275\345\212\240", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("ConfigDialog", "\345\211\212\351\231\244", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("ConfigDialog", "\342\206\221", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("ConfigDialog", "C", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("ConfigDialog", "\342\206\222", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("ConfigDialog", "\342\206\223", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("ConfigDialog", "\342\206\220", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ConfigDialog", "\345\256\237\350\241\214\343\201\231\343\202\213\343\203\241\343\203\213\343\203\245\343\203\274:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ConfigDialog", "\343\202\270\343\202\247\343\202\271\343\203\201\343\203\243\343\203\274:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("ConfigDialog", "\343\203\236\343\203\274\343\202\270\343\203\263:", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("ConfigDialog", "\350\277\275\345\212\240", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("ConfigDialog", "\345\211\212\351\231\244", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ConfigDialog", "\345\220\215\345\211\215:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ConfigDialog", "\345\256\237\350\241\214\343\201\231\343\202\213\343\202\263\343\203\236\343\203\263\343\203\211\343\203\251\343\202\244\343\203\263:", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("ConfigDialog", "\345\211\212\351\231\244", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("ConfigDialog", "\342\206\221", 0, QApplication::UnicodeUTF8));
        pushButton_12->setText(QApplication::translate("ConfigDialog", "\342\206\223", 0, QApplication::UnicodeUTF8));
        pushButton_13->setText(QApplication::translate("ConfigDialog", "\350\277\275\345\212\240", 0, QApplication::UnicodeUTF8));
        pushButton_14->setText(QApplication::translate("ConfigDialog", "\346\214\277\345\205\245", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("ConfigDialog", "Migemo", 0, QApplication::UnicodeUTF8));
        checkBox_22->setText(QApplication::translate("ConfigDialog", "\350\265\267\345\213\225\346\231\202\343\201\253\346\234\200\346\226\260\347\211\210\343\201\256\346\234\211\347\204\241\343\202\222\347\242\272\350\252\215\343\201\231\343\202\213(Windows\347\211\210\343\201\256\343\201\277)", 0, QApplication::UnicodeUTF8));
        checkBox_23->setText(QApplication::translate("ConfigDialog", "\347\224\273\345\203\217\343\203\223\343\203\245\343\203\274\343\202\242\343\202\222\344\275\277\343\202\217\343\201\252\343\201\204", 0, QApplication::UnicodeUTF8));
        checkBox_24->setText(QApplication::translate("ConfigDialog", "\343\203\236\343\202\246\343\202\271\343\202\252\343\203\274\343\203\220\343\203\274\343\201\247\347\224\273\345\203\217\343\202\222\351\226\213\343\201\217", 0, QApplication::UnicodeUTF8));
        checkBox_25->setText(QApplication::translate("ConfigDialog", "\347\224\273\345\203\217\343\201\256\343\202\265\343\203\240\343\203\215\343\202\244\343\203\253\343\202\222\350\241\250\347\244\272\343\201\231\343\202\213", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(ConfigDialog);
    } // retranslateUi

};

namespace Ui {
    class ConfigDialog: public Ui_ConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGDIALOG_H
