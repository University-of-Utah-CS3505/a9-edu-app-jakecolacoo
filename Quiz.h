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
    void on_trueButton_clicked();
    void on_falseButton_clicked();


public slots:

private:
    Ui::Quiz *ui;
    MainWindow* m_mainWindow;
    QMediaPlayer *musicPlayer;
    QAudioOutput *musicAud;

    void showNextQuestion();
    bool setAnswer;
    void playMusic();
    std::vector<QByteArray> vecOfPaths;

signals:
    void mainWindowComeBack();
};

#endif // QUIZ_H
