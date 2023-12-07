#include "SceneWidget.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>

SceneWidget::SceneWidget(QWidget *parent) : QWidget(parent),
    world(b2Vec2(0.0f, 10.0f)),
    timer(this),
    image(":/alien1.png")
{
    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, 37.0f);

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

    // Define the dynamic body. We set its position and call the body factory.
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);

    body = world.CreateBody(&bodyDef);

    // Define another box shape for our dynamic body.
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);

    // Define the dynamic body fixture.
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;

    // Set the box density to be non-zero, so it will be dynamic.
    fixtureDef.density = 1.0f;

    // Override the default friction.
    fixtureDef.friction = 0.3f;
    fixtureDef.restitution = 0.7;
    // Add the shape to the body.
    body->CreateFixture(&fixtureDef);
    bodies.push_back(body);
    printf("Init world\n");

    connect(&timer, &QTimer::timeout, this, &SceneWidget::updateWorld);
    timer.start(10);
}

void SceneWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    for (auto& body : bodies) { // 遍历并绘制所有物体
        b2Vec2 position = body->GetPosition();
        painter.drawImage((int)(position.x*20), (int)(position.y*20), image);
    }
    painter.end();
}

void SceneWidget::updateWorld() {
    world.Step(1.0/60.0, 6, 2);
//    size_t oldSize = bodies.size();
    // 定义水平速度和垂直速度阈值
    float newVelocityX = 5.0f;
    float verticalSpeedThreshold = 0.1f;

    // 用于存储需要移除的物体
    std::vector<b2Body*> bodiesToRemove;

    for (auto& body : bodies) {
        b2Vec2 position = body->GetPosition();
        b2Vec2 velocity = body->GetLinearVelocity();

        // 更新物体状态
        if (std::abs(velocity.y) > verticalSpeedThreshold) {
            body->SetLinearVelocity(b2Vec2(newVelocityX, velocity.y));
        } else {
            body->SetLinearVelocity(b2Vec2(0.0f, velocity.y));
        }

        // 检查物体是否离开屏幕
        if (position.x * 20 > this->width() || position.y * 20 > this->height()) {
            bodiesToRemove.push_back(body);
        }
    }

    // 移除离开屏幕的物体
    for (auto& body : bodiesToRemove) {
        world.DestroyBody(body);
        bodies.erase(std::remove(bodies.begin(), bodies.end(), body), bodies.end());
    }

//    if(oldSize != bodies.size()){
//        qDebug() << bodies.size();
//    }

    update();
}

void SceneWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(0.0f, 4.0f);

        b2Body* newBody = world.CreateBody(&bodyDef);

        b2PolygonShape dynamicBox;
        dynamicBox.SetAsBox(1.0f, 1.0f);

        b2FixtureDef fixtureDef;
        fixtureDef.shape = &dynamicBox;
        fixtureDef.density = 1.0f;
        fixtureDef.friction = 0.3f;
        fixtureDef.restitution = 0.7;

        newBody->CreateFixture(&fixtureDef);

        bodies.push_back(newBody); // 将新创建的物体添加到容器中
        update();
    }
}
