#ifndef STAGECREATE_H
#define STAGECREATE_H

#include <QWidget>

class stageCreate : public QWidget
{
    Q_OBJECT
public:
    explicit stageCreate(QWidget *parent = nullptr);

private:
    QStringList imagePaths;
    QStringList names;
    QByteArray m1;
    QByteArray m2;
    QByteArray m3;
    QByteArray m4;
    QByteArray m5;

public slots:
    void setEra(int era);
    void play(int i);
signals:
    void playMusic(QByteArray path);
    void sendInfor(QStringList image, QStringList names);
};

#endif // STAGECREATE_H
