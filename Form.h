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
    /**
     * @brief Construct a new Form object
     *
     * @param mainWindow Pointer to the MainWindow object
     * @param parent Pointer to the parent QWidget object (default is nullptr)
     */
    explicit Form(MainWindow* mainWindow, QWidget *parent = nullptr);

    /**
     * @brief Destroy the Form object
     */
    ~Form();

private slots:
    /**
     * @brief Slot for handling push button click event
     */
    void on_pushButton_clicked();

public slots:
    /**
     * @brief Set the Era
     *
     * @param image List of image paths
     * @param names List of names
     * @param decadeNum Decade number
     */
    void setEra(QStringList image, QStringList names, int decadeNum);

    /**
     * @brief Play music
     *
     * @param path Path to the music file
     */
    void playMusic(QByteArray path);

    /**
     * @brief Stop the music
     */
    void stopMusic();

    /**
     * @brief Set the Info Bar
     *
     * @param filePath Path to the file
     */
    void setInfoBar(QString filePath);

private:
    Ui::Form *ui; ///< Pointer to the UI Form object
    MainWindow* m_mainWindow; ///< Pointer to the MainWindow object
    QMediaPlayer *musicPlayer; ///< Pointer to the QMediaPlayer object
    QAudioOutput *musicAud; ///< Pointer to the QAudioOutput object
    stageCreate* stage; ///< Pointer to the stageCreate object

    /**
     * @brief Set the Decade Button Image
     *
     * @param filePath Path to the image file
     */
    void SetDecadeButtonImage(QString filePath);

    /**
     * @brief Reset all buttons
     */
    void resetButtons();

signals:
    /**
     * @brief Signal to notify that main window should come back
     */
    void mainWindowComeBack();
};

#endif // FORM_H
