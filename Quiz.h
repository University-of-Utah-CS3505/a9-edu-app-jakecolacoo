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
    /**
     * @brief Constructor for the quiz window that sets up the background, fonts, and audio settings.
     *
     * @param mainWindow Pointer to the MainWindow object
     * @param parent Pointer to the parent QWidget object (default is nullptr)
     */
    explicit Quiz(MainWindow* mainWindow, QWidget *parent = nullptr);

    /**
     * @brief Destroy the Quiz object
     */
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

private:
    Ui::Quiz *ui; ///< Pointer to the UI Quiz object
    MainWindow* m_mainWindow; ///< Pointer to the MainWindow object
    QMediaPlayer *musicPlayer; ///< Pointer to the QMediaPlayer object
    QAudioOutput *musicAud; ///< Pointer to the QAudioOutput object

    /**
     * @brief Set up the quiz
     */
    void setUpQuiz();

    /**
     * @brief Play the music
     */
    void playMusic();

    /**
     * @brief Set up the buttons
     */
    void setUpButtons();

    /**
     * @brief Set other buttons
     *
     * @param button1
     * @param button2
     * @param button3
     */
    void setOtherButtons(int button1, int button2, int button3);

    /**
     * @brief End the game
     */
    void gameOver();

    std::map<QByteArray, int> musicPaths; ///< Map of music paths
    std::map<QByteArray, QString> artistEra; ///< Map of eras corresponding to each artist
    std::vector<QByteArray> vecOfPaths; ///< Vector of paths

    int questionNumber; ///< Current question number
    int amountCorrect = 0;
    int amountIncorrect = 0;
    int correctEra;
    int correctButton;
signals:
    /**
     * @brief Signal to notify that main window should come back
     */
    void mainWindowComeBack();
};

#endif // QUIZ_H
