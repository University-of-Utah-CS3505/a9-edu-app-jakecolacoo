#ifndef FORM_H
#define FORM_H

#include "stagecreate.h"
#include <QWidget>
#include <QtMultiMedia/QtMultiMedia>
#include "QPushButton"


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

public slots:
//    void Stuffs1920();
    void setEra(QStringList image, QStringList names, int decadeNum);

    void playMusic(QByteArray path);

    void stopMusic();

    void setInfoBar(QString filePath);

private:
    Ui::Form *ui;
    MainWindow* m_mainWindow;
    QMediaPlayer *musicPlayer;
    QAudioOutput *musicAud;
    stageCreate* stage;
    void SetDecadeButtonImage(QString filePath);

signals:
    void mainWindowComeBack();
};

#endif // FORM_H
