#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultiMedia/QtMultiMedia>
#include "Form.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //Form* formInstance;

private slots:

    void on_button1920_clicked();

    void on_button1930_clicked();

    void on_button1940_clicked();

    void on_button1950_clicked();

    void on_button1960_clicked();

    void on_button1970_clicked();

    void on_button1980_clicked();

    void on_button1990_clicked();

    void on_button2000_clicked();

private:
    Ui::MainWindow *ui;
    Form* otherWindow;
    QMediaPlayer *player;
    QAudioOutput *aud;
public slots:
    void mainBack();

signals:
//    void clicked1920();
    void eraChange(int era);
};
#endif // MAINWINDOW_H
