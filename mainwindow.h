#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include <QMainWindow>
/*#include <QSerialPort>
#include <QSerialPortInfo>*/
/*#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>*/
#include <QMessageBox>
#include <QDebug>
#include <QSignalMapper>
/*#include <QTimer>*/
#include <QScrollBar>
#include <QTcpSocket>
#include <QAbstractSocket>
/*#include "QtWebSockets/QWebSocketServer"
#include "QtWebSockets/QWebSocket"*/
#include "DobotDll.h"
#include "DobotType.h"
//#include "workerThread.h"
//#include "chessboard.h"
//#include "tcpmsgs.h"
#include "websockets.h"
//#include "webtable.h"
#include "dobot.h"
#include "chess.h"

/*QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
QT_FORWARD_DECLARE_CLASS(QWebSocket)*/

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(WebTable *pWebTable, Websockets *pWebSockets, Chessboard *pChessboard,
                        TCPMsgs *pTCPmsg, Dobot *pDobotArm, Chess *pChess, QWidget *parent = 0);

    virtual ~MainWindow(); //tutaj virtual?

/*protected:
    void closeEvent(QCloseEvent *);*/ //TODO: to się może chyba przydać

private:
    Ui::MainWindow *ui;

    Dobot *_pDobotArm;
    WebTable *_pWebTable;
    Websockets *_pWebSockets;
    Chessboard *_pChessboard;
    TCPMsgs *_pTCPmsg;
    Chess *_pChess;

    void refreshBtn();
    void initDobot();
    void initControl();

private slots:
    void onChangedMode();
    void onJOGCtrlBtnPressed(int index);
    void onJOGCtrlBtnReleased();
    void onPTPsendBtnClicked();

    /*---sloty do używania GUI MainWindow---*/
    //dobot slots
    void writeInDobotConsole(QString QStrMsg);
    void setDobotValidators();
    void setJointLabelText(QString QSJointLabelText, short sJoint);
    void setAxisLabelText(QString QSAxisLabelText, char chAxis);
    void setDobotButtonsStates(bool bDobotButtonsStates);
    void setDeviceLabels(QString QSdeviceSN, QString QSdeviceName, QString QSdeviceVersion);
    void showDobotErrorMsgBox();
    void on_emulatePlayerMsgLineEdit_textChanged(const QString &textChanged);
    void on_sendSimulatedMsgBtn_clicked();

    //tcp slots
    void writeInTcpConsole(QString QS_msg);

    //websocket slots
    void writeInWebsocketConsole(QString QStrMsg);
    void on_gripperBtn_clicked();
    void on_homeBtn_clicked();
};

#endif // MAINWINDOW_H
