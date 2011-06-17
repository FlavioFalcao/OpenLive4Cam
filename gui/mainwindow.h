#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <CInterface.h>
#include <capturecom.h>


namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
#ifdef _WIN32
    QPushButton*   mChooseKamera;
#endif
    CInterface     mInterface;
    CaptureCom     *mCapture;

    QTimer          mTimer;
    bool            mStreamingRunning;

private slots:
    void on_chooseKam_clicked();
    void on_source_comboBox_currentIndexChanged(int index);
    void on_startButton_clicked();

};

#endif // MAINWINDOW_H
