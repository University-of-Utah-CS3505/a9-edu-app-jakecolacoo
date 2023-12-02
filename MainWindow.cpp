#include "MainWindow.h"
#include <QMediaPlayer>
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , otherWindow(new Form(this))
    , player(new QMediaPlayer(this))
{
    ui->setupUi(this);
    aud = new QAudioOutput;
    player->setAudioOutput(aud);
    aud->setVolume(100);
    connect(otherWindow, &Form::mainWindowComeBack, this, &MainWindow::mainBack);

    int id = QFontDatabase::addApplicationFont(":/PixeloidSans-mLxMm.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont font(family);
    font.setStyleHint(QFont::Monospace);
    QApplication::setFont(font);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete otherWindow;
}

void MainWindow::mainBack()
{
    this->show();
    player->stop();
}

void MainWindow::on_button1920_clicked()
{
    this->close();
    otherWindow->show();
    player->setSource(QUrl::fromEncoded("qrc:/2Pac_CaliforniaLove.mp3"));
    //player->play();

    //clicked 1920s stuff
    emit clicked1920();
}

void MainWindow::on_button1930_clicked()
{
    this->close();
    otherWindow->show();
    player->setSource(QUrl::fromEncoded("qrc:/Louis Armstrong - What A Wonderful World.mp3"));
    player->play();
    //emit clicked1930();
}

void MainWindow::on_button1940_clicked()
{
    this->close();
    otherWindow->show();
    player->setSource(QUrl::fromEncoded("qrc:/JohnnyCash_IWalkTheLine.mp3"));
    player->play();
    //emit clicked1940();
}

void MainWindow::on_button1950_clicked()
{
    this->close();
    otherWindow->show();
    player->setSource(QUrl::fromEncoded("qrc:/N.K.COLE_L.O.V.E.mp3"));
    player->play();
    //emit clicked1950();
}

void MainWindow::on_button1960_clicked()
{
    this->close();
    otherWindow->show();
    player->setSource(QUrl::fromEncoded("qrc:/SidneyBechet_WildCatBlues.mp3"));
    player->play();
    //emit clicked1960();
}

void MainWindow::on_button1970_clicked()
{
    this->close();
    otherWindow->show();
    player->setSource(QUrl::fromEncoded("qrc:/TheBeatles_HereComesTheSun.mp3"));
    player->play();
    //emit clicked1970();
}

void MainWindow::on_button1980_clicked()
{
    this->close();
    otherWindow->show();
    player->setSource(QUrl::fromEncoded("qrc:/MichaelJacson_BeatIt.mp3"));
    player->play();
    //emit clicked1980();
}

void MainWindow::on_button1990_clicked()
{
    this->close();
    otherWindow->show();
    player->setSource(QUrl::fromEncoded("qrc:/Oasis_DontLookBackInAnger.mp3"));
    player->play();
    //emit clicked1990();
}

void MainWindow::on_button2000_clicked()
{
    this->close();
    otherWindow->show();
    player->setSource(QUrl::fromEncoded("qrc:/DaftPunk_OneMoreTime.mp3"));
    player->play();
    //emit clicked2000();
}
