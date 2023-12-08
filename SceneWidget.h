#ifndef SCENEWIDGET_H
#define SCENEWIDGET_H

#include <QWidget>
#include <Box2D/Box2D.h>
#include <QTimer>

class SceneWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SceneWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *);
signals:

public slots:
    void updateWorld();
    void mousePressEvent(QMouseEvent *event) override;
    void createBody();

private:
    b2World world;
    QTimer timer;
    QTimer createTime;
//    QImage image;
    std::vector<QString> images{":/black_note_sprite.png", ":/blue_note_sprite.png", ":/green_note_sprite.png", ":/purple_note_sprite.png", ":/red_note_sprite.png", ":/yellow_note_sprite.png"};
    std::map<b2Body*, QString> bodies;
};

#endif // SCENEWIDGET_H
