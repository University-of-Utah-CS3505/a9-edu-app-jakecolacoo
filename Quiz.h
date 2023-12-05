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
    void on_eraButton1_clicked();
    void on_eraButton2_clicked();
    void on_eraButton3_clicked();
    void on_eraButton4_clicked();

    void on_trueButton_clicked();
    void on_falseButton_clicked();


public slots:

private:
    Ui::Quiz *ui;
    MainWindow* m_mainWindow;
    QMediaPlayer *musicPlayer;
    QAudioOutput *musicAud;

    void showNextQuestion();
    void playMusic();
    void setUpButtons();
    void setOtherButtons(int button1, int button2, int button3);
    std::map<QByteArray, int> musicPaths;
    std::vector<QByteArray> vecOfPaths;

    bool setAnswer;
    int questionNumber;
    int correctEra;
    int correctButton;

signals:
    void mainWindowComeBack();
};

#endif // QUIZ_H
