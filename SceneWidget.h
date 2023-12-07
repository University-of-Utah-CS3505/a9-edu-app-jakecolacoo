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

private:
    b2World world;
    b2Body* body;
    QTimer timer;
    QImage image;
    std::vector<b2Body*> bodies;
};

#endif // SCENEWIDGET_H
