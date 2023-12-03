#include "Form.h"
#include "ui_Form.h"
#include "mainwindow.h"
#include <QMediaPlayer>

Form::Form(MainWindow* mainWindow,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
    , m_mainWindow(mainWindow)
    , musicPlayer(new QMediaPlayer(this))
    , stage(new stageCreate(this))
{
    ui->setupUi(this);
    QPalette palette;

    // Load the image from the resource
    QImage backgroundImage(":/Stage.png");

    // Convert the QImage to QPixmap
    QPixmap backgroundPixmap = QPixmap::fromImage(backgroundImage);

    // Scale the QPixmap to the size of the widget
    backgroundPixmap = backgroundPixmap.scaled(this->size(), Qt::IgnoreAspectRatio);

    // Set the pixmap for the palette using the image
    palette.setBrush(QPalette::Window, QBrush(backgroundPixmap));

    // Apply the palette to the widget
    this->setPalette(palette);

    // Make sure the widget background is set to be drawn
    this->setAutoFillBackground(true);


    musicAud = new QAudioOutput;
    musicPlayer->setAudioOutput(musicAud);
    musicAud->setVolume(60);


//    connect(m_mainWindow, &MainWindow::clicked1920, this, &Form::Stuffs1920);
    connect(m_mainWindow, &MainWindow::eraChange, stage, &stageCreate::setEra);
    connect(stage, &stageCreate::sendInfor, this, &Form::setEra);
    connect(stage, &stageCreate::playMusic, this, &Form::playMusic);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    this->close();
    emit mainWindowComeBack();
    musicPlayer->stop();
    // MainOne.show();
    // MainOne.player->stop();
}

void Form::setEra(QStringList image, QStringList names){
    int w = ui->sprite1->width();
    int h = ui->sprite1->height();
    for (int i = 0; i < 5; ++i) {
        // build QLabel and QPushButton name
        QString labelName = QString("sprite%1").arg(i + 1);
        QString buttonName = QString("music%1").arg(i + 1);

        // find QLabel 和 QPushButton
        QLabel *label = this->findChild<QLabel *>(labelName);
        QPushButton *button = this->findChild<QPushButton *>(buttonName);

        if (label && i < image.size()) {
            // set QLabel image
            QPixmap pixmap(image[i]);
            label->setPixmap(pixmap.scaled(w,h,Qt::KeepAspectRatio));
        }

        if (button && i < names.size()) {
            // set QPushButton text
            button->setText(names[i]);
            connect(button, &QPushButton::clicked, this, [this, i]() {
                stage->play(i+1);
            });
        }
    }
}

void Form::playMusic(QByteArray path){
    musicPlayer->setSource(QUrl::fromEncoded(path));
    musicPlayer->play();
}
