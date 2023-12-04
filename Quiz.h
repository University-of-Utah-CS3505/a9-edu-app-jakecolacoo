#ifndef QUIZ_H
#define QUIZ_H

#include <QWidget>
#include <QtMultiMedia/QtMultiMedia>

namespace Ui {



class Quiz;
}

class MainWindow;

class Quiz : public QWidget
{
    Q_OBJECT

public:
    explicit Quiz(MainWindow* mainWindow, QWidget *parent = nullptr);
    ~Quiz();

private slots:
    void on_pushButton_clicked();


public slots:
//    void Stuffs1920();
    void setEra(QStringList image, QStringList names);

    void playMusic(QByteArray path);

    void setInfoBar(QString filePath);

private:
    Ui::Quiz *ui;
    MainWindow* m_mainWindow;
    QMediaPlayer *musicPlayer;
    QAudioOutput *musicAud;

signals:
    void mainWindowComeBack();
};

#endif // QUIZ_H
