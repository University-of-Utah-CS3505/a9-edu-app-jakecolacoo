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
    aud->setVolume(100);
    connect(&otherWindow, &Form::mainWindowComeBack, this, &MainWindow::mainBack);


    int id = QFontDatabase::addApplicationFont(":/PixeloidSans-mLxMm.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont font(family);
    font.setStyleHint(QFont::Monospace);
    QApplication::setFont(font);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mainBack(){
    this->show();
    player->stop();
}

void MainWindow::on_button1920_clicked()
{
    this->hide();
    otherWindow.show();
    player->setSource(QUrl::fromEncoded("qrc:/2Pac_CaliforniaLove.mp3"));
    player->play();
}


void MainWindow::on_button1930_clicked()
{
    this->hide();
    otherWindow.show();
    player->setSource(QUrl::fromEncoded("qrc:/Louis Armstrong - What A Wonderful World.mp3"));
    player->play();
}


void MainWindow::on_button1940_clicked()
{
    this->hide();
    otherWindow.show();
    player->setSource(QUrl::fromEncoded("qrc:/JohnnyCash_IWalkTheLine.mp3"));
    player->play();
}


void MainWindow::on_button1950_clicked()
{
    this->hide();
    otherWindow.show();
    player->setSource(QUrl::fromEncoded("qrc:/N.K.COLE_L.O.V.E.mp3"));
    player->play();
}


void MainWindow::on_button1960_clicked()
{
    this->hide();
    otherWindow.show();
    player->setSource(QUrl::fromEncoded("qrc:/SidneyBechet_WildCatBlues.mp3"));
    player->play();
}


void MainWindow::on_button1970_clicked()
{
    this->hide();
    otherWindow.show();
    player->setSource(QUrl::fromEncoded("qrc:/TheBeatles_HereComesTheSun.mp3"));
    player->play();
}


void MainWindow::on_button1980_clicked()
{
    this->hide();
    otherWindow.show();
    player->setSource(QUrl::fromEncoded("qrc:/MichaelJacson_BeatIt.mp3"));
    player->play();
}


void MainWindow::on_button1990_clicked()
{
    this->hide();
    otherWindow.show();
    player->setSource(QUrl::fromEncoded("qrc:/Oasis_DontLookBackInAnger.mp3"));
    player->play();
}


void MainWindow::on_button2000_clicked()
{
    this->hide();
    otherWindow.show();
    player->setSource(QUrl::fromEncoded("qrc:/DaftPunk_OneMoreTime.mp3"));
    player->play();
}

