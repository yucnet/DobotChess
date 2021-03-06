#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QSignalMapper>
#include <QScrollBar>
#include <QTcpSocket>
#include <QAbstractSocket>
#include "DobotDll.h"
#include "DobotType.h"
#include "xml_reader.h"
#include "websockets.h"
#include "dobot.h"
#include "chess.h"
#include "client.h"
#include "piece_controller.h"

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Websockets* pWebSockets, PieceController* pPieceController,
                        Chessboard* pBoardMain, Chessboard* pBoardRemoved,
                        Chessboard *pBoardChenard, TCPMsgs* pTCPMsg, ArduinoUsb* pUsb,
                        Dobot* pDobot, Chess* pChess, Clients* pClientsList,
                        QWidget* parent = 0);

    virtual ~MainWindow();

private:
    Ui::MainWindow *ui;

    Dobot* _pDobot;
    PieceController* _pPieceController;
    Websockets* _pWebSockets;
    Chessboard* _pBoardMain;
    Chessboard* _pBoardRemoved;
    Chessboard* _pBoardChenard;
    TCPMsgs* _pTCPMsg;
    ArduinoUsb* _pUsb;
    Clients* _pClientsList;
    Chess* _pChess;

    void initControl();

private slots:
    void onChangedMode();
    void onJOGCtrlBtnPressed(int nID);
    void onJOGCtrlBtnReleased();

    //slots for GUI MainWindow
    void writeInConsole(QString QStrMsg, LOG TypeOfMsg);
    void setBoardDataLabel(QString QStrLabel, BOARD_DATA_LABEL LabelType);
    void showBoardInUI(QString QStrBoard);
    void showRealBoardInUI();
    void clearBoardInUI();
    void showLegalMovesInUI(QStringList legalMoves);
    void showHistoryMovesInUI(QStringList historyMoves);

    //dobot slots
    void setDobotPTEValidatorsInUI();
    void setJointLabelText(QString QStrJointLabelText, short sJoint);
    void setAxisLabelText(QString QStrAxisLabelText, char chAxis);
    void setDobotButtonsStates(bool bDobotButtonsStates);
    void setDeviceLabels(QString QStrDeviceSN, QString QStrDeviceName,
                         QString QStrDeviceVersion);
    void showDobotErrorMsgBox();
    void on_emulatePlayerMsgLineEdit_textChanged(const QString& QStrTextChanged);
    void on_sendSimulatedMsgBtn_clicked();
    void setQueueLabels(int nSpaceLeft, int nDobotId, int nCoreMaxId, int nCoreIdLeft,
                        int nCoreNextId);
    void showActualDobotQueuedCmdIDList(QList<DobotMove> list);
    void showOnDobotQueuedCmdsList(QList<DobotMove> list);
    void showArduinoGripperStateList(QList<ServoArduino> list);

    //websocket slots
    void on_calibrateBtn_clicked();
    void on_upBtn_clicked();
    void on_downBtn_clicked();
    void on_resetDobotIndexBtn_clicked();
    void on_AIBtn_clicked();
    void on_AIEnemySendBtn_clicked();
    void showClientsList(QList<Client> list);

    //arduino usb slots
    void updatePortsComboBox(int nUsbPorst);
    void on_portsComboBox_currentIndexChanged(int nID);
    void on_reloadPortsBtn_clicked();
    void on_sendUsbBtn_clicked();
    void on_openGripperBtn_clicked();
    void on_closeGripperBtn_clicked();
    void on_startGmPosBtn_clicked();
    void on_startDtPosBtn_clicked();
    void on_SimulateFromUsbBtn_clicked();
    void on_sendTcpBtn_clicked();
    void on_sendTcpLineEdit_textChanged(const QString& QStrTextChanged);
    void on_SimulateFromUsbLineEdit_textChanged(const QString& QStrTextChanged);
    void on_homeBtn_clicked();
    void on_usbCmdLine_textChanged(const QString& QStrTextChanged);
    void on_middleAboveBtn_clicked();
    void on_sendBtn_clicked();
    void on_xPTPEdit_textChanged(const QString& QStrTextChanged);
    void on_yPTPEdit_textChanged(const QString& QStrTextChanged);
    void on_zPTPEdit_textChanged(const QString& QStrTextChanged);
};

#endif // MAINWINDOW_H
