#include "MainWindow.h"
#include <QMediaPlayer>
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , otherWindow(new Form(this))
    , quizWindow(new Quiz(this))
    , player(new QMediaPlayer(this))
{
    ui->setupUi(this);
    aud = new QAudioOutput;
    player->setAudioOutput(aud);/* we can use this player to play the background music for start menu */
    aud->setVolume(.3);
    connect(otherWindow, &Form::mainWindowComeBack, this, &MainWindow::mainBack);
    connect(quizWindow, &Quiz::mainWindowComeBack, this, &MainWindow::mainBack);

    int id = QFontDatabase::addApplicationFont(":/PixeloidSans-mLxMm.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont font(family);
    font.setStyleHint(QFont::Monospace);
    QApplication::setFont(font);

    // Set icons for all buttons
    SetButtonImage(ui->button1920, ":/1920sIcon.png");
    SetButtonImage(ui->button1930, ":/1930sIcon.png");
    SetButtonImage(ui->button1940, ":/1940sIcon.png");
    SetButtonImage(ui->button1950, ":/1950sIcon.png");
    SetButtonImage(ui->button1960, ":/1960sIcon.png");
    SetButtonImage(ui->button1970, ":/1970sIcon.png");
    SetButtonImage(ui->button1980, ":/1980sIcon.png");
    SetButtonImage(ui->button1990, ":/1990sIcon.png");
    SetButtonImage(ui->button2000, ":/2000sIcon.png");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete otherWindow;
}

void MainWindow::SetButtonImage(QPushButton* button, QString filePath) {
    QPixmap map(filePath);
    QIcon icon(map);
    button->setIcon(icon);
}

void MainWindow::mainBack()
{
    this->show();
}

void MainWindow::on_button1920_clicked()
{
    this->close();
    otherWindow->show();
    emit eraChange(2);
}

void MainWindow::on_button1930_clicked()
{
    this->close();
    otherWindow->show();
    emit eraChange(3);
}

void MainWindow::on_button1940_clicked()
{
    this->close();
    otherWindow->show();
    emit eraChange(4);
}

void MainWindow::on_button1950_clicked()
{
    this->close();
    otherWindow->show();
    emit eraChange(5);
}

void MainWindow::on_button1960_clicked()
{
    this->close();
    otherWindow->show();
    emit eraChange(6);
}

void MainWindow::on_button1970_clicked()
{
    this->close();
    otherWindow->show();
    emit eraChange(7);
}

void MainWindow::on_button1980_clicked()
{
    this->close();
    otherWindow->show();
    emit eraChange(8);
}

void MainWindow::on_button1990_clicked()
{
    this->close();
    otherWindow->show();
    emit eraChange(9);
}

void MainWindow::on_button2000_clicked()
{
    this->close();
    otherWindow->show();
    emit eraChange(0);
}

void MainWindow:: on_quizButton_clicked()
{
    this->close();
    quizWindow->show();
    emit playQuizMusic();
    emit setUpQuizButtons();
}
