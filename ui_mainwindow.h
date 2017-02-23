/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_8;
    QGridLayout *gridLayout_7;
    QPlainTextEdit *websocket_debug;
    QGroupBox *groupBox_9;
    QGridLayout *gridLayout_8;
    QPlainTextEdit *tcp_debug;
    QGroupBox *groupBox_7;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *dobot_debug;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_11;
    QLabel *label_9;
    QLabel *deviceSNLabel;
    QLabel *label_10;
    QLabel *DeviceNameLabel;
    QLabel *label_11;
    QLabel *DeviceInfoLabel;
    QPushButton *connectBtn;
    QGroupBox *JOGgroupBox;
    QGridLayout *gridLayout_10;
    QPushButton *rHeadAddBtn;
    QPushButton *baseAngleSubBtn;
    QPushButton *longArmAddBtn;
    QPushButton *shortArmAddBtn;
    QPushButton *baseAngleAddBtn;
    QPushButton *shortArmSubBtn;
    QPushButton *rHeadSubBtn;
    QPushButton *longArmSubBtn;
    QComboBox *teachMode;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_5;
    QLabel *CoreIndexAmountlabel;
    QLabel *label_14;
    QLabel *label_21;
    QLabel *label_15;
    QLabel *CoreMaxQueuedIndexLabel;
    QLabel *DobotQueuedIndexLabel;
    QLabel *label_16;
    QLabel *DobotQueuedCmdLeftSpaceLabel;
    QLabel *label_22;
    QLabel *CoreNextIdLabel;
    QPushButton *executeDobotComandsBtn;
    QPushButton *resetDobotIndexBtn;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *joint2Label;
    QLabel *joint3Label;
    QLabel *label_5;
    QLabel *label_8;
    QLabel *zLabel;
    QLabel *label_2;
    QLabel *joint4Label;
    QLabel *yLabel;
    QLabel *label_7;
    QLabel *label_3;
    QLabel *joint1Label;
    QLabel *label;
    QLabel *rLabel;
    QLabel *label_6;
    QLabel *xLabel;
    QGroupBox *groupBox_11;
    QGridLayout *gridLayout_12;
    QPushButton *startPosBtn;
    QPushButton *homeBtn;
    QPushButton *gripperBtn;
    QPushButton *upBtn;
    QPushButton *downBtn;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label_12;
    QLabel *label_19;
    QLabel *label_17;
    QLabel *label_20;
    QLabel *label_18;
    QLineEdit *xPTPEdit;
    QLabel *label_13;
    QLineEdit *yPTPEdit;
    QLineEdit *zPTPEdit;
    QLineEdit *servo1GripperEdit;
    QPushButton *sendBtn;
    QLineEdit *rPTPEdit;
    QLineEdit *servo2GripperEdit;
    QGroupBox *groupBox_6;
    QGridLayout *gridLayout_6;
    QCheckBox *serviceCheckBox;
    QLineEdit *emulatePlayerMsgLineEdit;
    QPushButton *sendSimulatedMsgBtn;
    QGroupBox *groupBox_10;
    QGridLayout *gridLayout_2;
    QLabel *label_25;
    QLabel *label_23;
    QLabel *AIEnLtrFromLbl;
    QPushButton *AIEnemyStartBtn;
    QRadioButton *botOffRadioBtn;
    QRadioButton *botOnRadioBtn;
    QLabel *AIEnDgtFromLbl;
    QPushButton *AIBtn;
    QPushButton *AIEnemySendBtn;
    QLabel *label_24;
    QLabel *AIEnLtrToLbl;
    QLabel *label_27;
    QLabel *AIEnDgtToLbl;
    QGroupBox *groupBox_12;
    QGridLayout *gridLayout_13;
    QLineEdit *commandLine;
    QComboBox *port;
    QPushButton *enterButton;
    QPushButton *visual;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1023, 784);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox_8 = new QGroupBox(centralWidget);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        gridLayout_7 = new QGridLayout(groupBox_8);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        websocket_debug = new QPlainTextEdit(groupBox_8);
        websocket_debug->setObjectName(QStringLiteral("websocket_debug"));

        gridLayout_7->addWidget(websocket_debug, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_8, 0, 4, 1, 1);

        groupBox_9 = new QGroupBox(centralWidget);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        gridLayout_8 = new QGridLayout(groupBox_9);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        tcp_debug = new QPlainTextEdit(groupBox_9);
        tcp_debug->setObjectName(QStringLiteral("tcp_debug"));

        gridLayout_8->addWidget(tcp_debug, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_9, 0, 5, 1, 1);

        groupBox_7 = new QGroupBox(centralWidget);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        verticalLayout = new QVBoxLayout(groupBox_7);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        dobot_debug = new QPlainTextEdit(groupBox_7);
        dobot_debug->setObjectName(QStringLiteral("dobot_debug"));
        dobot_debug->setReadOnly(true);
        dobot_debug->setOverwriteMode(false);

        verticalLayout->addWidget(dobot_debug);


        gridLayout_4->addWidget(groupBox_7, 0, 3, 1, 1);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        gridLayout_9 = new QGridLayout(groupBox_5);
        gridLayout_9->setSpacing(6);
        gridLayout_9->setContentsMargins(11, 11, 11, 11);
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        groupBox = new QGroupBox(groupBox_5);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_11 = new QGridLayout(groupBox);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_11->addWidget(label_9, 0, 0, 1, 1);

        deviceSNLabel = new QLabel(groupBox);
        deviceSNLabel->setObjectName(QStringLiteral("deviceSNLabel"));
        deviceSNLabel->setFrameShape(QFrame::Panel);

        gridLayout_11->addWidget(deviceSNLabel, 0, 1, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_11->addWidget(label_10, 1, 0, 1, 1);

        DeviceNameLabel = new QLabel(groupBox);
        DeviceNameLabel->setObjectName(QStringLiteral("DeviceNameLabel"));
        DeviceNameLabel->setFrameShape(QFrame::Panel);
        DeviceNameLabel->setTextFormat(Qt::AutoText);

        gridLayout_11->addWidget(DeviceNameLabel, 1, 1, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_11->addWidget(label_11, 2, 0, 1, 1);

        DeviceInfoLabel = new QLabel(groupBox);
        DeviceInfoLabel->setObjectName(QStringLiteral("DeviceInfoLabel"));
        DeviceInfoLabel->setFrameShape(QFrame::Panel);
        DeviceInfoLabel->setFrameShadow(QFrame::Plain);

        gridLayout_11->addWidget(DeviceInfoLabel, 2, 1, 1, 1);

        connectBtn = new QPushButton(groupBox);
        connectBtn->setObjectName(QStringLiteral("connectBtn"));

        gridLayout_11->addWidget(connectBtn, 3, 0, 1, 1);


        gridLayout_9->addWidget(groupBox, 8, 2, 1, 1);

        JOGgroupBox = new QGroupBox(groupBox_5);
        JOGgroupBox->setObjectName(QStringLiteral("JOGgroupBox"));
        gridLayout_10 = new QGridLayout(JOGgroupBox);
        gridLayout_10->setSpacing(6);
        gridLayout_10->setContentsMargins(11, 11, 11, 11);
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        rHeadAddBtn = new QPushButton(JOGgroupBox);
        rHeadAddBtn->setObjectName(QStringLiteral("rHeadAddBtn"));
        rHeadAddBtn->setEnabled(false);

        gridLayout_10->addWidget(rHeadAddBtn, 6, 0, 1, 1);

        baseAngleSubBtn = new QPushButton(JOGgroupBox);
        baseAngleSubBtn->setObjectName(QStringLiteral("baseAngleSubBtn"));
        baseAngleSubBtn->setEnabled(false);

        gridLayout_10->addWidget(baseAngleSubBtn, 3, 1, 1, 1);

        longArmAddBtn = new QPushButton(JOGgroupBox);
        longArmAddBtn->setObjectName(QStringLiteral("longArmAddBtn"));
        longArmAddBtn->setEnabled(false);

        gridLayout_10->addWidget(longArmAddBtn, 4, 0, 1, 1);

        shortArmAddBtn = new QPushButton(JOGgroupBox);
        shortArmAddBtn->setObjectName(QStringLiteral("shortArmAddBtn"));
        shortArmAddBtn->setEnabled(false);

        gridLayout_10->addWidget(shortArmAddBtn, 5, 0, 1, 1);

        baseAngleAddBtn = new QPushButton(JOGgroupBox);
        baseAngleAddBtn->setObjectName(QStringLiteral("baseAngleAddBtn"));
        baseAngleAddBtn->setEnabled(false);

        gridLayout_10->addWidget(baseAngleAddBtn, 3, 0, 1, 1);

        shortArmSubBtn = new QPushButton(JOGgroupBox);
        shortArmSubBtn->setObjectName(QStringLiteral("shortArmSubBtn"));
        shortArmSubBtn->setEnabled(false);

        gridLayout_10->addWidget(shortArmSubBtn, 5, 1, 1, 1);

        rHeadSubBtn = new QPushButton(JOGgroupBox);
        rHeadSubBtn->setObjectName(QStringLiteral("rHeadSubBtn"));
        rHeadSubBtn->setEnabled(false);

        gridLayout_10->addWidget(rHeadSubBtn, 6, 1, 1, 1);

        longArmSubBtn = new QPushButton(JOGgroupBox);
        longArmSubBtn->setObjectName(QStringLiteral("longArmSubBtn"));
        longArmSubBtn->setEnabled(false);

        gridLayout_10->addWidget(longArmSubBtn, 4, 1, 1, 1);

        teachMode = new QComboBox(JOGgroupBox);
        teachMode->setObjectName(QStringLiteral("teachMode"));
        teachMode->setEnabled(false);

        gridLayout_10->addWidget(teachMode, 0, 0, 1, 2);


        gridLayout_9->addWidget(JOGgroupBox, 1, 2, 5, 1);

        groupBox_4 = new QGroupBox(groupBox_5);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_5 = new QGridLayout(groupBox_4);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        CoreIndexAmountlabel = new QLabel(groupBox_4);
        CoreIndexAmountlabel->setObjectName(QStringLiteral("CoreIndexAmountlabel"));

        gridLayout_5->addWidget(CoreIndexAmountlabel, 3, 1, 1, 1);

        label_14 = new QLabel(groupBox_4);
        label_14->setObjectName(QStringLiteral("label_14"));

        gridLayout_5->addWidget(label_14, 0, 0, 1, 1);

        label_21 = new QLabel(groupBox_4);
        label_21->setObjectName(QStringLiteral("label_21"));

        gridLayout_5->addWidget(label_21, 2, 0, 1, 1);

        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_5->addWidget(label_15, 1, 0, 1, 1);

        CoreMaxQueuedIndexLabel = new QLabel(groupBox_4);
        CoreMaxQueuedIndexLabel->setObjectName(QStringLiteral("CoreMaxQueuedIndexLabel"));

        gridLayout_5->addWidget(CoreMaxQueuedIndexLabel, 1, 1, 1, 1);

        DobotQueuedIndexLabel = new QLabel(groupBox_4);
        DobotQueuedIndexLabel->setObjectName(QStringLiteral("DobotQueuedIndexLabel"));

        gridLayout_5->addWidget(DobotQueuedIndexLabel, 0, 1, 1, 1);

        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName(QStringLiteral("label_16"));

        gridLayout_5->addWidget(label_16, 3, 0, 1, 1);

        DobotQueuedCmdLeftSpaceLabel = new QLabel(groupBox_4);
        DobotQueuedCmdLeftSpaceLabel->setObjectName(QStringLiteral("DobotQueuedCmdLeftSpaceLabel"));

        gridLayout_5->addWidget(DobotQueuedCmdLeftSpaceLabel, 2, 1, 1, 1);

        label_22 = new QLabel(groupBox_4);
        label_22->setObjectName(QStringLiteral("label_22"));

        gridLayout_5->addWidget(label_22, 4, 0, 1, 1);

        CoreNextIdLabel = new QLabel(groupBox_4);
        CoreNextIdLabel->setObjectName(QStringLiteral("CoreNextIdLabel"));

        gridLayout_5->addWidget(CoreNextIdLabel, 4, 1, 1, 1);

        executeDobotComandsBtn = new QPushButton(groupBox_4);
        executeDobotComandsBtn->setObjectName(QStringLiteral("executeDobotComandsBtn"));
        executeDobotComandsBtn->setEnabled(false);

        gridLayout_5->addWidget(executeDobotComandsBtn, 5, 1, 1, 1);

        resetDobotIndexBtn = new QPushButton(groupBox_4);
        resetDobotIndexBtn->setObjectName(QStringLiteral("resetDobotIndexBtn"));
        resetDobotIndexBtn->setEnabled(false);

        gridLayout_5->addWidget(resetDobotIndexBtn, 5, 0, 1, 1);


        gridLayout_9->addWidget(groupBox_4, 9, 2, 1, 1);

        groupBox_2 = new QGroupBox(groupBox_5);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 1, 0, 1, 1);

        joint2Label = new QLabel(groupBox_2);
        joint2Label->setObjectName(QStringLiteral("joint2Label"));

        gridLayout->addWidget(joint2Label, 0, 4, 1, 1);

        joint3Label = new QLabel(groupBox_2);
        joint3Label->setObjectName(QStringLiteral("joint3Label"));

        gridLayout->addWidget(joint3Label, 1, 1, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 1, 3, 1, 1);

        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout->addWidget(label_8, 3, 3, 1, 1);

        zLabel = new QLabel(groupBox_2);
        zLabel->setObjectName(QStringLiteral("zLabel"));

        gridLayout->addWidget(zLabel, 3, 1, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        joint4Label = new QLabel(groupBox_2);
        joint4Label->setObjectName(QStringLiteral("joint4Label"));

        gridLayout->addWidget(joint4Label, 1, 4, 1, 1);

        yLabel = new QLabel(groupBox_2);
        yLabel->setObjectName(QStringLiteral("yLabel"));

        gridLayout->addWidget(yLabel, 2, 4, 1, 1);

        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 0, 3, 1, 1);

        joint1Label = new QLabel(groupBox_2);
        joint1Label->setObjectName(QStringLiteral("joint1Label"));
        joint1Label->setEnabled(true);

        gridLayout->addWidget(joint1Label, 0, 1, 1, 1);

        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        rLabel = new QLabel(groupBox_2);
        rLabel->setObjectName(QStringLiteral("rLabel"));

        gridLayout->addWidget(rLabel, 3, 4, 1, 1);

        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout->addWidget(label_6, 2, 3, 1, 1);

        xLabel = new QLabel(groupBox_2);
        xLabel->setObjectName(QStringLiteral("xLabel"));
        xLabel->setEnabled(true);

        gridLayout->addWidget(xLabel, 2, 1, 1, 1);


        gridLayout_9->addWidget(groupBox_2, 9, 0, 1, 1);

        groupBox_11 = new QGroupBox(groupBox_5);
        groupBox_11->setObjectName(QStringLiteral("groupBox_11"));
        gridLayout_12 = new QGridLayout(groupBox_11);
        gridLayout_12->setSpacing(6);
        gridLayout_12->setContentsMargins(11, 11, 11, 11);
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        startPosBtn = new QPushButton(groupBox_11);
        startPosBtn->setObjectName(QStringLiteral("startPosBtn"));
        startPosBtn->setEnabled(false);

        gridLayout_12->addWidget(startPosBtn, 1, 1, 1, 1);

        homeBtn = new QPushButton(groupBox_11);
        homeBtn->setObjectName(QStringLiteral("homeBtn"));
        homeBtn->setEnabled(false);

        gridLayout_12->addWidget(homeBtn, 0, 1, 1, 1);

        gripperBtn = new QPushButton(groupBox_11);
        gripperBtn->setObjectName(QStringLiteral("gripperBtn"));
        gripperBtn->setEnabled(false);

        gridLayout_12->addWidget(gripperBtn, 1, 0, 1, 1);

        upBtn = new QPushButton(groupBox_11);
        upBtn->setObjectName(QStringLiteral("upBtn"));
        upBtn->setEnabled(false);

        gridLayout_12->addWidget(upBtn, 2, 0, 1, 1);

        downBtn = new QPushButton(groupBox_11);
        downBtn->setObjectName(QStringLiteral("downBtn"));
        downBtn->setEnabled(false);

        gridLayout_12->addWidget(downBtn, 2, 1, 1, 1);

        gripperBtn->raise();
        startPosBtn->raise();
        homeBtn->raise();
        upBtn->raise();
        downBtn->raise();

        gridLayout_9->addWidget(groupBox_11, 7, 2, 1, 1);

        groupBox_3 = new QGroupBox(groupBox_5);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_3->addWidget(label_12, 2, 0, 1, 1);

        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QStringLiteral("label_19"));

        gridLayout_3->addWidget(label_19, 1, 0, 1, 1);

        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QStringLiteral("label_17"));

        gridLayout_3->addWidget(label_17, 0, 0, 1, 1);

        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QStringLiteral("label_20"));

        gridLayout_3->addWidget(label_20, 1, 2, 1, 1);

        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QStringLiteral("label_18"));

        gridLayout_3->addWidget(label_18, 0, 2, 1, 1);

        xPTPEdit = new QLineEdit(groupBox_3);
        xPTPEdit->setObjectName(QStringLiteral("xPTPEdit"));
        xPTPEdit->setEnabled(false);

        gridLayout_3->addWidget(xPTPEdit, 0, 1, 1, 1);

        label_13 = new QLabel(groupBox_3);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_3->addWidget(label_13, 2, 2, 1, 1);

        yPTPEdit = new QLineEdit(groupBox_3);
        yPTPEdit->setObjectName(QStringLiteral("yPTPEdit"));
        yPTPEdit->setEnabled(false);

        gridLayout_3->addWidget(yPTPEdit, 0, 3, 1, 1);

        zPTPEdit = new QLineEdit(groupBox_3);
        zPTPEdit->setObjectName(QStringLiteral("zPTPEdit"));
        zPTPEdit->setEnabled(false);

        gridLayout_3->addWidget(zPTPEdit, 1, 1, 1, 1);

        servo1GripperEdit = new QLineEdit(groupBox_3);
        servo1GripperEdit->setObjectName(QStringLiteral("servo1GripperEdit"));
        servo1GripperEdit->setEnabled(false);

        gridLayout_3->addWidget(servo1GripperEdit, 2, 1, 1, 1);

        sendBtn = new QPushButton(groupBox_3);
        sendBtn->setObjectName(QStringLiteral("sendBtn"));
        sendBtn->setEnabled(false);

        gridLayout_3->addWidget(sendBtn, 3, 1, 1, 3);

        rPTPEdit = new QLineEdit(groupBox_3);
        rPTPEdit->setObjectName(QStringLiteral("rPTPEdit"));
        rPTPEdit->setEnabled(false);

        gridLayout_3->addWidget(rPTPEdit, 1, 3, 1, 1);

        servo2GripperEdit = new QLineEdit(groupBox_3);
        servo2GripperEdit->setObjectName(QStringLiteral("servo2GripperEdit"));
        servo2GripperEdit->setEnabled(false);

        gridLayout_3->addWidget(servo2GripperEdit, 2, 3, 1, 1);


        gridLayout_9->addWidget(groupBox_3, 1, 0, 5, 1);

        groupBox_6 = new QGroupBox(groupBox_5);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        gridLayout_6 = new QGridLayout(groupBox_6);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        serviceCheckBox = new QCheckBox(groupBox_6);
        serviceCheckBox->setObjectName(QStringLiteral("serviceCheckBox"));
        serviceCheckBox->setEnabled(false);

        gridLayout_6->addWidget(serviceCheckBox, 1, 0, 1, 1);

        emulatePlayerMsgLineEdit = new QLineEdit(groupBox_6);
        emulatePlayerMsgLineEdit->setObjectName(QStringLiteral("emulatePlayerMsgLineEdit"));
        emulatePlayerMsgLineEdit->setEnabled(false);

        gridLayout_6->addWidget(emulatePlayerMsgLineEdit, 0, 0, 1, 2);

        sendSimulatedMsgBtn = new QPushButton(groupBox_6);
        sendSimulatedMsgBtn->setObjectName(QStringLiteral("sendSimulatedMsgBtn"));
        sendSimulatedMsgBtn->setEnabled(false);
        sendSimulatedMsgBtn->setAutoDefault(true);

        gridLayout_6->addWidget(sendSimulatedMsgBtn, 1, 1, 1, 1);


        gridLayout_9->addWidget(groupBox_6, 8, 0, 1, 1);

        groupBox_10 = new QGroupBox(groupBox_5);
        groupBox_10->setObjectName(QStringLiteral("groupBox_10"));
        gridLayout_2 = new QGridLayout(groupBox_10);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_25 = new QLabel(groupBox_10);
        label_25->setObjectName(QStringLiteral("label_25"));

        gridLayout_2->addWidget(label_25, 1, 2, 1, 1);

        label_23 = new QLabel(groupBox_10);
        label_23->setObjectName(QStringLiteral("label_23"));

        gridLayout_2->addWidget(label_23, 1, 0, 1, 1);

        AIEnLtrFromLbl = new QLabel(groupBox_10);
        AIEnLtrFromLbl->setObjectName(QStringLiteral("AIEnLtrFromLbl"));

        gridLayout_2->addWidget(AIEnLtrFromLbl, 1, 1, 1, 1);

        AIEnemyStartBtn = new QPushButton(groupBox_10);
        AIEnemyStartBtn->setObjectName(QStringLiteral("AIEnemyStartBtn"));
        AIEnemyStartBtn->setEnabled(false);

        gridLayout_2->addWidget(AIEnemyStartBtn, 3, 0, 1, 2);

        botOffRadioBtn = new QRadioButton(groupBox_10);
        botOffRadioBtn->setObjectName(QStringLiteral("botOffRadioBtn"));
        botOffRadioBtn->setEnabled(false);
        botOffRadioBtn->setChecked(true);

        gridLayout_2->addWidget(botOffRadioBtn, 0, 0, 1, 1);

        botOnRadioBtn = new QRadioButton(groupBox_10);
        botOnRadioBtn->setObjectName(QStringLiteral("botOnRadioBtn"));
        botOnRadioBtn->setEnabled(false);

        gridLayout_2->addWidget(botOnRadioBtn, 0, 1, 1, 1);

        AIEnDgtFromLbl = new QLabel(groupBox_10);
        AIEnDgtFromLbl->setObjectName(QStringLiteral("AIEnDgtFromLbl"));

        gridLayout_2->addWidget(AIEnDgtFromLbl, 1, 3, 1, 1);

        AIBtn = new QPushButton(groupBox_10);
        AIBtn->setObjectName(QStringLiteral("AIBtn"));
        AIBtn->setEnabled(false);

        gridLayout_2->addWidget(AIBtn, 0, 2, 1, 2);

        AIEnemySendBtn = new QPushButton(groupBox_10);
        AIEnemySendBtn->setObjectName(QStringLiteral("AIEnemySendBtn"));
        AIEnemySendBtn->setEnabled(false);

        gridLayout_2->addWidget(AIEnemySendBtn, 3, 2, 1, 2);

        label_24 = new QLabel(groupBox_10);
        label_24->setObjectName(QStringLiteral("label_24"));

        gridLayout_2->addWidget(label_24, 2, 0, 1, 1);

        AIEnLtrToLbl = new QLabel(groupBox_10);
        AIEnLtrToLbl->setObjectName(QStringLiteral("AIEnLtrToLbl"));

        gridLayout_2->addWidget(AIEnLtrToLbl, 2, 1, 1, 1);

        label_27 = new QLabel(groupBox_10);
        label_27->setObjectName(QStringLiteral("label_27"));

        gridLayout_2->addWidget(label_27, 2, 2, 1, 1);

        AIEnDgtToLbl = new QLabel(groupBox_10);
        AIEnDgtToLbl->setObjectName(QStringLiteral("AIEnDgtToLbl"));

        gridLayout_2->addWidget(AIEnDgtToLbl, 2, 3, 1, 1);


        gridLayout_9->addWidget(groupBox_10, 7, 0, 1, 1);

        groupBox_12 = new QGroupBox(groupBox_5);
        groupBox_12->setObjectName(QStringLiteral("groupBox_12"));
        gridLayout_13 = new QGridLayout(groupBox_12);
        gridLayout_13->setSpacing(6);
        gridLayout_13->setContentsMargins(11, 11, 11, 11);
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        commandLine = new QLineEdit(groupBox_12);
        commandLine->setObjectName(QStringLiteral("commandLine"));

        gridLayout_13->addWidget(commandLine, 0, 0, 1, 1);

        port = new QComboBox(groupBox_12);
        port->setObjectName(QStringLiteral("port"));

        gridLayout_13->addWidget(port, 1, 0, 1, 1);

        enterButton = new QPushButton(groupBox_12);
        enterButton->setObjectName(QStringLiteral("enterButton"));

        gridLayout_13->addWidget(enterButton, 0, 1, 1, 1);

        visual = new QPushButton(groupBox_12);
        visual->setObjectName(QStringLiteral("visual"));

        gridLayout_13->addWidget(visual, 1, 1, 1, 1);


        gridLayout_9->addWidget(groupBox_12, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_5, 0, 0, 1, 2);

        MainWindow->setCentralWidget(centralWidget);
        groupBox_5->raise();
        groupBox_7->raise();
        groupBox_8->raise();
        groupBox_9->raise();
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1023, 18));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(xPTPEdit, zPTPEdit);
        QWidget::setTabOrder(zPTPEdit, sendBtn);
        QWidget::setTabOrder(sendBtn, connectBtn);
        QWidget::setTabOrder(connectBtn, websocket_debug);

        retranslateUi(MainWindow);

        sendSimulatedMsgBtn->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox_8->setTitle(QApplication::translate("MainWindow", "WebSockets", 0));
        groupBox_9->setTitle(QApplication::translate("MainWindow", "TCP socket", 0));
        groupBox_7->setTitle(QApplication::translate("MainWindow", "Arm log", 0));
        groupBox_5->setTitle(QApplication::translate("MainWindow", "Dobot Arm", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Device", 0));
        label_9->setText(QApplication::translate("MainWindow", "SN", 0));
        deviceSNLabel->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "Name", 0));
        DeviceNameLabel->setText(QString());
        label_11->setText(QApplication::translate("MainWindow", "Info", 0));
        DeviceInfoLabel->setText(QString());
        connectBtn->setText(QApplication::translate("MainWindow", "Connect", 0));
        JOGgroupBox->setTitle(QApplication::translate("MainWindow", "JOG", 0));
        rHeadAddBtn->setText(QApplication::translate("MainWindow", "J4+", 0));
        baseAngleSubBtn->setText(QApplication::translate("MainWindow", "J1-", 0));
        longArmAddBtn->setText(QApplication::translate("MainWindow", "J2+", 0));
        shortArmAddBtn->setText(QApplication::translate("MainWindow", "J3+", 0));
        baseAngleAddBtn->setText(QApplication::translate("MainWindow", "J1+", 0));
        shortArmSubBtn->setText(QApplication::translate("MainWindow", "J3-", 0));
        rHeadSubBtn->setText(QApplication::translate("MainWindow", "J4-", 0));
        longArmSubBtn->setText(QApplication::translate("MainWindow", "J2-", 0));
        teachMode->clear();
        teachMode->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Joint", 0)
         << QApplication::translate("MainWindow", "Axis", 0)
        );
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Queue", 0));
        CoreIndexAmountlabel->setText(QApplication::translate("MainWindow", "-1", 0));
        label_14->setText(QApplication::translate("MainWindow", "DIndex", 0));
        label_21->setText(QApplication::translate("MainWindow", "DLeftSpc", 0));
        label_15->setText(QApplication::translate("MainWindow", "CMaxIdx", 0));
        CoreMaxQueuedIndexLabel->setText(QApplication::translate("MainWindow", "-1", 0));
        DobotQueuedIndexLabel->setText(QApplication::translate("MainWindow", "-1", 0));
        label_16->setText(QApplication::translate("MainWindow", "CIds", 0));
        DobotQueuedCmdLeftSpaceLabel->setText(QApplication::translate("MainWindow", "-1", 0));
        label_22->setText(QApplication::translate("MainWindow", "CNextId", 0));
        CoreNextIdLabel->setText(QApplication::translate("MainWindow", "-1", 0));
        executeDobotComandsBtn->setText(QApplication::translate("MainWindow", "ExecDtCmds", 0));
        resetDobotIndexBtn->setText(QApplication::translate("MainWindow", "ResDtId", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Pose", 0));
        label_4->setText(QApplication::translate("MainWindow", "J3", 0));
        joint2Label->setText(QApplication::translate("MainWindow", "0", 0));
        joint3Label->setText(QApplication::translate("MainWindow", "0", 0));
        label_5->setText(QApplication::translate("MainWindow", "J4", 0));
        label_8->setText(QApplication::translate("MainWindow", "R", 0));
        zLabel->setText(QApplication::translate("MainWindow", "0", 0));
        label_2->setText(QApplication::translate("MainWindow", "X", 0));
        joint4Label->setText(QApplication::translate("MainWindow", "0", 0));
        yLabel->setText(QApplication::translate("MainWindow", "0", 0));
        label_7->setText(QApplication::translate("MainWindow", "Z", 0));
        label_3->setText(QApplication::translate("MainWindow", "J2", 0));
        joint1Label->setText(QApplication::translate("MainWindow", "0", 0));
        label->setText(QApplication::translate("MainWindow", "J1", 0));
        rLabel->setText(QApplication::translate("MainWindow", "0", 0));
        label_6->setText(QApplication::translate("MainWindow", "Y", 0));
        xLabel->setText(QApplication::translate("MainWindow", "0", 0));
        groupBox_11->setTitle(QApplication::translate("MainWindow", "Dobot Movements", 0));
        startPosBtn->setText(QApplication::translate("MainWindow", "StartGmPos", 0));
        homeBtn->setText(QApplication::translate("MainWindow", "HOME", 0));
        gripperBtn->setText(QApplication::translate("MainWindow", "Open gripper", 0));
        upBtn->setText(QApplication::translate("MainWindow", "Up", 0));
        downBtn->setText(QApplication::translate("MainWindow", "Down", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Service PTP", 0));
        label_12->setText(QApplication::translate("MainWindow", "s1", 0));
        label_19->setText(QApplication::translate("MainWindow", "Z", 0));
        label_17->setText(QApplication::translate("MainWindow", "X", 0));
        label_20->setText(QApplication::translate("MainWindow", "R", 0));
        label_18->setText(QApplication::translate("MainWindow", "Y", 0));
        label_13->setText(QApplication::translate("MainWindow", "s2", 0));
        sendBtn->setText(QApplication::translate("MainWindow", "Send", 0));
        groupBox_6->setTitle(QApplication::translate("MainWindow", "Simulate player msg ", 0));
        serviceCheckBox->setText(QApplication::translate("MainWindow", "servMsg", 0));
        sendSimulatedMsgBtn->setText(QApplication::translate("MainWindow", "Send", 0));
        groupBox_10->setTitle(QApplication::translate("MainWindow", "AI", 0));
        label_25->setText(QApplication::translate("MainWindow", "EnDgtF", 0));
        label_23->setText(QApplication::translate("MainWindow", "EnLtrF", 0));
        AIEnLtrFromLbl->setText(QApplication::translate("MainWindow", "-", 0));
        AIEnemyStartBtn->setText(QApplication::translate("MainWindow", "PlayerStart", 0));
        botOffRadioBtn->setText(QApplication::translate("MainWindow", "Off", 0));
        botOnRadioBtn->setText(QApplication::translate("MainWindow", "On", 0));
        AIEnDgtFromLbl->setText(QApplication::translate("MainWindow", "-", 0));
        AIBtn->setText(QApplication::translate("MainWindow", "Send", 0));
        AIEnemySendBtn->setText(QApplication::translate("MainWindow", "PlayerSend", 0));
        label_24->setText(QApplication::translate("MainWindow", "EnLtrT", 0));
        AIEnLtrToLbl->setText(QApplication::translate("MainWindow", "-", 0));
        label_27->setText(QApplication::translate("MainWindow", "EnDgtT", 0));
        AIEnDgtToLbl->setText(QApplication::translate("MainWindow", "-", 0));
        groupBox_12->setTitle(QApplication::translate("MainWindow", "Arduino Usb", 0));
        enterButton->setText(QApplication::translate("MainWindow", "Enter", 0));
        visual->setText(QApplication::translate("MainWindow", "Visualize", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
