#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMediaPlayer>
#include <QMediaPlayer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    player(new QMediaPlayer(this))
{
    ui->setupUi(this);
    aud = new QAudioOutput;
    player->setAudioOutput(aud);
    player->setSource(QUrl::fromEncoded("qrc:/music.mp3")); // Assuming the music file is named "music.mp3" and is in the root of the resource file
    aud->setVolume(100);
    connect(&otherWindow, &Form::mainWindowComeBack, this, &MainWindow::mainBack);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    this->hide();
    otherWindow.show();
    player->play();

}

void MainWindow::mainBack(){
    this->show();
    player->stop();
}
