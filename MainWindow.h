#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Form.h"
#include <QMainWindow>
#include <QtMultiMedia/QtMultiMedia>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //Form* formInstance;

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Form otherWindow;
    QMediaPlayer *player;
    QAudioOutput * aud;
// public slots:
//     void stopMusicPlayer();
};
#endif // MAINWINDOW_H
