#ifndef SCENEWIDGET_H
#define SCENEWIDGET_H

#include <QWidget>
#include <Box2D/Box2D.h>
#include <QTimer>

/**
 * @class SceneWidget
 * @brief The SceneWidget class inherits from QWidget and represents a custom widget for displaying a scene.
 */
class SceneWidget : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief SceneWidget Constructor.
     * @param parent The parent widget.
     */
    explicit SceneWidget(QWidget *parent = nullptr);

    void paintEvent(QPaintEvent *);

signals:

public slots:
    /**
     * @brief Updates the world.
     */
    void updateWorld();

    /**
     * @brief Handles mouse press events.
     * @param event The mouse event.
     */
    void mousePressEvent(QMouseEvent *event) override;

    /**
     * @brief Creates a body in the world.
     */
    void createBody();

private:
    b2World world; ///< The world of the Box2D physics engine

    QTimer timer; ///< A timer for updating the world.

    QTimer createTime; ///< A timer for creating bodies.

    std::vector<QString> images{":/black_note_sprite.png", ///< A vector of image paths.
                                ":/blue_note_sprite.png",
                                ":/green_note_sprite.png",
                                ":/purple_note_sprite.png",
                                ":/red_note_sprite.png",
                                ":/yellow_note_sprite.png"};

    std::map<b2Body*, QString> bodies; ///< A map of bodies and their corresponding image paths.
};

#endif // SCENEWIDGET_H
