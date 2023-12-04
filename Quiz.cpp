/*
 * View class of the stage
 * Use to set up the sprites and all other UI stuff
*/

#include "Quiz.h"
#include "ui_Quiz.h"
#include "mainwindow.h"
#include <QMediaPlayer>

Quiz::Quiz(MainWindow* mainWindow,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Quiz)
    , m_mainWindow(mainWindow)
    , musicPlayer(new QMediaPlayer(this))
{
    ui->setupUi(this);
    QPalette palette;

    // Load the image from the resource
    QImage backgroundImage(":/peakpx.jpg");

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

    int id = QFontDatabase::addApplicationFont(":/PixeloidSans-mLxMm.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont font(family);
    font.setStyleHint(QFont::Monospace);
    ui->question->setFont(font);

    musicAud = new QAudioOutput;
    musicPlayer->setAudioOutput(musicAud);
    musicAud->setVolume(60);

    // Set button color
//    ui->trueButton->setStyleSheet("background-color: green");
//    ui->falseButton->setStyleSheet("background-color: red");


//    connect(m_mainWindow, &MainWindow::clicked1920, this, &Form::Stuffs1920);
//    connect(m_mainWindow, &MainWindow::eraChange, stage, &stageCreate::setEra);
//    connect(stage, &stageCreate::sendInfor, this, &Form::setEra);
//    connect(stage, &stageCreate::playMusic, this, &Form::playMusic);
//    connect(stage, &stageCreate::sendFileForInfoBar, this, &Form::setInfoBar);
}

Quiz::~Quiz()
{
    delete ui;
}

//When the go back button clicked
void Quiz::on_pushButton_clicked()
{
    this->close();
    emit mainWindowComeBack();
}
