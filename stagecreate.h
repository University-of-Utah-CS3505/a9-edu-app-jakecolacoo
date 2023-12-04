#ifndef STAGECREATE_H
#define STAGECREATE_H

#include <QWidget>

class stageCreate : public QWidget
{
    Q_OBJECT
public:
    explicit stageCreate(QWidget *parent = nullptr);

private:
    //sprite paths
    QStringList imagePaths;
    //Names of musication
    QStringList names;
    //5 music path
    QByteArray m1;
    QByteArray m2;
    QByteArray m3;
    QByteArray m4;
    QByteArray m5;

    // 5 informational paths
    QString artist1Info;
    QString artist2Info;
    QString artist3Info;
    QString artist4Info;
    QString artist5Info;

public slots:
    void setEra(int era);
    void play(int i);
signals:
    void playMusic(QByteArray path);

    void sendFileForInfoBar(QString filePath);
    void sendInfor(QStringList image, QStringList names);
};

#endif // STAGECREATE_H
