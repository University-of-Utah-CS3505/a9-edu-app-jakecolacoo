/*
 * This quiz.h file outlines all of the quiz related methods. The quiz will randomly play an artist's music
 * and allows the user to choose between four randomly generated eras. There should be ui feedback on whether
 * the answer is right or wrong and it should also show the song and artist. There is a tracker for right or
 * wrong answers, and a game over screen after 10 songs.
*/

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
    /*!
     * \brief Constructor for the quiz window that sets up the background, fonts, and audio settings.
     * \param mainWindow
     * \param parent
     */
    explicit Quiz(MainWindow* mainWindow, QWidget *parent = nullptr);
    ~Quiz();

private slots:
    /*!
     * \brief Code after the back button has been pressed to return back to the tune timeline window.
     */
    void on_pushButton_clicked();
    /*!
     * \brief Code after the first era button is clicked by the user
     */
    void on_eraButton1_clicked();
    /*!
     * \brief Code after the second era button is clicked by the user
     */
    void on_eraButton2_clicked();
    /*!
     * \brief Code after the third era button is clicked by the user
     */
    void on_eraButton3_clicked();
    /*!
     * \brief Code after the fourth era button is clicked by the user
     */
    void on_eraButton4_clicked();
    /*!
     * \brief Code after the retry button is clicked to re-create all maps and generate buttons again
     */
    void on_retryButton_clicked();

public slots:

private:
    Ui::Quiz *ui;
    MainWindow* m_mainWindow;
    QMediaPlayer *musicPlayer;
    QAudioOutput *musicAud;

    /*!
     * \brief Called by the constructor and after retry button is clicked, randomly shuffles the vector containing the music
     * and sets up all the ui elements of the game.
     */
    void setUpQuiz();
    /*!
     * \brief Plays the music from the first element of the randomly shuffled vector.
     */
    void playMusic();
    /*!
     * \brief randomly selects one button to be chosen as the correct era button and sets the text of that button to the correct
     * era. Calls setupotherbuttons to set up the next three incorrect buttons.
     */
    void setUpButtons();
    /*!
     * \brief Sets up the other buttons with randomly generated eras from 1920 - 2000, all three being incorrect if chosen.
     * \param button1
     * \param button2
     * \param button3
     */
    void setOtherButtons(int button1, int button2, int button3);
    /*!
     * \brief Handles when the game is finished. Hides all the ui elements and shows score and a retry button.
     */
    void gameOver();
    std::map<QByteArray, int> musicPaths;
    std::map<QByteArray, QString> artistEra;
    std::vector<QByteArray> vecOfPaths;

    int questionNumber;
    int amountCorrect = 0;
    int amountIncorrect = 0;
    int correctEra;
    int correctButton;

signals:
    /*!
     * \brief Signal to go back to the mainWindow
     */
    void mainWindowComeBack();
};

#endif // QUIZ_H
