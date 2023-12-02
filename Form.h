#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QtMultiMedia/QtMultiMedia>

namespace Ui {



class Form;
}

class MainWindow;

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(MainWindow* mainWindow, QWidget *parent = nullptr);
    ~Form();

private slots:
    void on_pushButton_clicked();
    void on_music1_clicked();

    void on_music2_clicked();

    void on_music3_clicked();

    void on_music4_clicked();

    void on_music5_clicked();

public slots:
    void Stuffs1920();

private:
    Ui::Form *ui;
    MainWindow* m_mainWindow;
    QMediaPlayer *musicPlayer;
    QAudioOutput *musicAud;
signals:
    void mainWindowComeBack();
};

#endif // FORM_H
