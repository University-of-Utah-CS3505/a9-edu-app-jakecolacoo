/*
 * An interactive QWidget integrating the Box2D physics engine for dynamic object simulation within a Qt application.
 * It features ground body definition, real-time physics updates, dynamic body creation and rendering,
 * and user interaction handling. This class showcases the use of physics in GUI applications,
 * offering engaging and interactive elements that respond to physics laws.
*/
#include "SceneWidget.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include <random>

SceneWidget::SceneWidget(QWidget *parent) : QWidget(parent),
    world(b2Vec2(0.0f, 6.0f)),
    timer(this),
    createTime(this)
{
    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, 38.0f);

    // Call the body factory which allocates memory for the ground body
    // from a pool and creates the ground box shape (also from a pool).
    // The body is also added to the world.
    b2Body* groundBody = world.CreateBody(&groundBodyDef);

    // Define the ground box shape.
    b2PolygonShape groundBox;

    // The extents are the half-widths of the box.
    groundBox.SetAsBox(50.0f, 10.0f);

    // Add the ground fixture to the ground body.
    groundBody->CreateFixture(&groundBox, 0.0f);

    connect(&timer, &QTimer::timeout, this, &SceneWidget::updateWorld);
    connect(&createTime, &QTimer::timeout, this, &SceneWidget::createBody);
    createTime.start(250);
    timer.start(10);
}

void SceneWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    for (auto& pair : bodies) {
        b2Body* body = pair.first;
        QString imagePath = pair.second;
        QImage image(imagePath);

        b2Vec2 position = body->GetPosition();
        float angle = body->GetAngle() * 180.0 / M_PI; // 转换为度

        // 设置变换矩阵
        QTransform transform;
        transform.translate(position.x * 20, position.y * 20);
        transform.rotate(angle);
        painter.setTransform(transform);

        // 绘制图片
        painter.drawImage(-image.width() / 2, -image.height() / 2, image); // 调整锚点到图片中心

        // 重置变换矩阵
        painter.resetTransform();
    }
    painter.end();
}

void SceneWidget::updateWorld() {
    world.Step(1.0/60.0, 6, 2);

//    size_t old = bodies.size();

    for (auto it = bodies.begin(); it != bodies.end(); ) {
        b2Body* body = it->first;
        b2Vec2 position = body->GetPosition();

        if (position.x * 20 > this->width() + 30 || position.x * 20 < -50) {
            world.DestroyBody(body);
            it = bodies.erase(it);
        } else {
            ++it;
        }
    }

//    if(bodies.size() != old){
//        qDebug() << bodies.size();
//    }

    update();
}

void SceneWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-5.0, 5.0);
        std::uniform_real_distribution<> angleDis(0, 2 * M_PI);

        float mouseX = (event->x() / 20.0f) - 1.0f;
        float mouseY = (event->y() / 20.0f) - 1.0f;

        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(mouseX, mouseY);
        bodyDef.angle = angleDis(gen);

        b2Body* newBody = world.CreateBody(&bodyDef);

        b2PolygonShape dynamicBox;
        dynamicBox.SetAsBox(1.0f, 1.0f);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.02f;
        fixtureDef.restitution = 0.5;

        newBody->CreateFixture(&fixtureDef);

        float randomVelocityX = dis(gen);
        newBody->SetLinearVelocity(b2Vec2(randomVelocityX, 0.0f));
        QString selectedImage = images[std::uniform_int_distribution<>(0, images.size() - 1)(gen)];

        bodies[newBody] = selectedImage;

        update();
    }
}

void SceneWidget::createBody() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-5.0, 5.0);
    std::uniform_real_distribution<> angleDis(0, 2 * M_PI);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(20.0f, -5.0f);
    bodyDef.angle = angleDis(gen);

    b2Body* newBody = world.CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.02f;
    fixtureDef.restitution = 0.5;

    newBody->CreateFixture(&fixtureDef);

    float randomVelocityX = dis(gen);
    newBody->SetLinearVelocity(b2Vec2(randomVelocityX, 0.0f));
    QString selectedImage = images[std::uniform_int_distribution<>(0, images.size() - 1)(gen)];

    bodies[newBody] = selectedImage;
    update();
}
