#include "SceneWidget.h"
#include <QPainter>
#include <QDebug>
#include <QMouseEvent>
#include <random>

SceneWidget::SceneWidget(QWidget *parent) : QWidget(parent),
    world(b2Vec2(0.0f, 10.0f)),
    timer(this),
    createTime(this),
    image(":/alien1.png")
{
    // Define the ground body.
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, 35.0f);

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
    createTime.start(1000);
    timer.start(10);
}

void SceneWidget::paintEvent(QPaintEvent *) {
    QPainter painter(this);
    for (auto& body : bodies) {
        b2Vec2 position = body->GetPosition();
        painter.drawImage((int)(position.x*20), (int)(position.y*20), image);
    }
    painter.end();
}

void SceneWidget::updateWorld() {
    world.Step(1.0/60.0, 6, 2);

    std::vector<b2Body*> bodiesToRemove;

    for (auto& body : bodies) {
        b2Vec2 position = body->GetPosition();

        // check if it is out of screen
        if (position.x * 20 > this->width() || position.x * 20 < -70) {
            bodiesToRemove.push_back(body);
        }
    }

    // delete body that is out of screen
    for (auto& body : bodiesToRemove) {
        world.DestroyBody(body);
        bodies.erase(std::remove(bodies.begin(), bodies.end(), body), bodies.end());
    }

    update();
}

void SceneWidget::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<> dis(-5.0, 5.0);

        float mouseX = (event->x() / 20.0f) - 1.0f;
        float mouseY = (event->y() / 20.0f) - 1.0f;

        b2BodyDef bodyDef;
        bodyDef.type = b2_dynamicBody;
        bodyDef.position.Set(mouseX, mouseY);

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

        bodies.push_back(newBody);
        update();
    }
}

void SceneWidget::createBody() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-5.0, 5.0);

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(20.0f, -5.0f);

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

    bodies.push_back(newBody);
    update();
}
