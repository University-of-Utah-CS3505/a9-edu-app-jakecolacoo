#include "Form.h"
#include "ui_Form.h"
#include "mainwindow.h"
#include <QMediaPlayer>

Form::Form(MainWindow* mainWindow,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
    , m_mainWindow(mainWindow)
    , musicPlayer(new QMediaPlayer(this))
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


    connect(m_mainWindow, &MainWindow::clicked1920, this, &Form::Stuffs1920);

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

void Form::Stuffs1920(){
    int w = ui->sprite1->width();
    int h = ui->sprite1->height();
    QPixmap pix(":/Cheryl_James.png");
    ui->sprite1->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap pix2(":/2000sIcon.jpg");
    ui->sprite2->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap pix3(":/I_forgot.png");
    ui->sprite3->setPixmap(pix3.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap pix4(":/Mariah_Carey.png");
    ui->sprite4->setPixmap(pix4.scaled(w,h,Qt::KeepAspectRatio));

    QPixmap pix5(":/Sandra_Denton.png");
    ui->sprite5->setPixmap(pix5.scaled(w,h,Qt::KeepAspectRatio));



}

void Form::on_music1_clicked()
{
    musicPlayer->setSource(QUrl::fromEncoded("qrc:/Biggie_MoMoneyMoProblems.mp3"));
    musicPlayer->play();
}


void Form::on_music2_clicked()
{
    musicPlayer->setSource(QUrl::fromEncoded("qrc:/BobDylan_LikeARollingStone.mp3"));
    musicPlayer->play();

}


void Form::on_music3_clicked()
{
    musicPlayer->setSource(QUrl::fromEncoded("qrc:/DaftPunk_OneMoreTime.mp3"));
    musicPlayer->play();
}


void Form::on_music4_clicked()
{
    musicPlayer->setSource(QUrl::fromEncoded("qrc:/BingCrosby_ISurrenderDear.mp3"));
    musicPlayer->play();

}


void Form::on_music5_clicked()
{
    musicPlayer->setSource(QUrl::fromEncoded("qrc:/DukeEllington_Caravan.mp3"));
    musicPlayer->play();

}

