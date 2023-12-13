#ifndef STAGECREATE_H
#define STAGECREATE_H

#include <QWidget>

/**
 * @class stageCreate
 * @brief The stageCreate class inherits from QWidget and represents a custom widget for creating stages.
 */
class StageCreate : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief stageCreate Constructor.
     * @param parent The parent widget, null pointer by default.
     */
    explicit StageCreate(QWidget *parent = nullptr);

private:
    QStringList imagePaths; ///< Paths to the sprite images.

    QStringList names; ///< Names of the musications.

    ///v Paths to the music files.
    QByteArray m1;
    QByteArray m2;
    QByteArray m3;
    QByteArray m4;
    QByteArray m5;

    ///v Paths for the artists information files.
    QString artist1Info;
    QString artist2Info;
    QString artist3Info;
    QString artist4Info;
    QString artist5Info;

    QString decadeInfo; ///< Path to file for information about the decade.

public slots:
    /**
     * @brief Sets the era.
     * @param era The era to set.
     */
    void setEra(int era);

    /**
     * @brief Plays the music at the given index.
     * @param i The index of the music to play.
     */
    void play(int i);

signals:
    /**
     * @brief Signal to play the music at the given path.
     * @param path The path of the music to play.
     */
    void playMusic(QByteArray path);

    /**
     * @brief Signal to stop the music.
     */
    void stopMusic();

    /**
     * @brief Sends the file path for the info bar.
     * @param filePath The file path to send.
     */
    void sendFileForInfoBar(QString filePath);

    /**
     * @brief Sends currentDecade, the artists images in that decade, and those artists songs to update ui.
     * @param image The image to send.
     * @param names The names to send.
     * @param decadeNum The decade number to send.
     */
    void sendInfor(QStringList image, QStringList names, int decadeNum);
};

#endif // STAGECREATE_H
