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
     * @brief Construct a new Quiz object
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
    /**
     * @brief Slot for handling push button click event
     */
    void on_pushButton_clicked();

    /**
     * @brief Slot for handling era button 1 click event
     */
    void on_eraButton1_clicked();

    /**
     * @brief Slot for handling era button 2 click event
     */
    void on_eraButton2_clicked();

    /**
     * @brief Slot for handling era button 3 click event
     */
    void on_eraButton3_clicked();

    /**
     * @brief Slot for handling era button 4 click event
     */
    void on_eraButton4_clicked();

    /**
     * @brief Slot for handling retry button click event
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
