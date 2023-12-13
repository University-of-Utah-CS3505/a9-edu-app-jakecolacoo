#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtMultiMedia/QtMultiMedia>
#include "Form.h"
#include "Quiz.h"
#include "QPushButton"
#include "QLabel"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Construct a new MainWindow object
     *
     * @param parent Pointer to the parent QWidget object (default is nullptr)
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destroy the MainWindow object
     */
    ~MainWindow();

private slots:
    /**
     * @brief Slot for handling 1920 button click event
     */
    void on_button1920_clicked();

    /**
     * @brief Slot for handling 1930 button click event
     */
    void on_button1930_clicked();

    /**
     * @brief Slot for handling 1940 button click event
     */
    void on_button1940_clicked();

    /**
     * @brief Slot for handling 1950 button click event
     */
    void on_button1950_clicked();

    /**
     * @brief Slot for handling 1960 button click event
     */
    void on_button1960_clicked();

    /**
     * @brief Slot for handling 1970 button click event
     */
    void on_button1970_clicked();

    /**
     * @brief Slot for handling 1980 button click event
     */
    void on_button1980_clicked();

    /**
     * @brief Slot for handling 1990 button click event
     */
    void on_button1990_clicked();

    /**
     * @brief Slot for handling 2000 button click event
     */
    void on_button2000_clicked();

    /**
     * @brief Slot for handling quiz button click event
     */
    void on_quizButton_clicked();

    /**
     * @brief Slot for handling start button click event
     */
    void on_start_clicked();

private:
    Ui::MainWindow *ui; ///< Pointer to the UI MainWindow object
    Form* stageWindow; ///< Pointer to the Form object
    Quiz* quizWindow; ///< Pointer to the Quiz object
    QMediaPlayer *player; ///< Pointer to the QMediaPlayer object
    QAudioOutput *aud; ///< Pointer to the QAudioOutput object

    /**
     * @brief Set the Button Image
     *
     * @param button Pointer to the QPushButton object
     * @param filePath Path to the image file
     */
    void setButtonImage(QPushButton* button, QString filePath);

    QLabel *backgroundImageLabel; ///< Pointer to the QLabel object for background image

public slots:
    /**
     * @brief Slot for handling main back event
     */
    void mainBack();

    /**
     * @brief Slot for handling resize event
     *
     * @param event Pointer to the QResizeEvent object
     */
    void resizeEvent(QResizeEvent *event) override;

    /**
     * @brief Set up the background image
     *
     * @param size Size of the background image
     */
    void setupBackgroundImage(const QSize &size);

signals:
    /**
     * @brief Signal to notify era change
     *
     * @param era Era number
     */
    void eraChange(int era);

    /**
     * @brief Signal to play quiz music
     */
    void playQuizMusic();

    /**
     * @brief Signal to set up quiz buttons
     */
    void setUpQuizButtons();
};

#endif // MAINWINDOW_H

