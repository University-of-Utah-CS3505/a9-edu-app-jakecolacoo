#include "MainWindow.h"
#include <QMediaPlayer>
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , stageWindow(new Form(this))
    , quizWindow(new Quiz(this))
    , player(new QMediaPlayer(this))
{
    ui->setupUi(this);
    backgroundImageLabel = new QLabel(this);
    setupBackgroundImage(this->size());
    connect(stageWindow, &Form::mainWindowComeBack, this, &MainWindow::mainBack);
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

    QImage backgroundImage(":/TuneTimelineBackground.png");

    // Convert the QImage to QPixmap
    QPixmap backgroundPixmap = QPixmap::fromImage(backgroundImage);

    int w = ui->bg->width();
    int h = ui->bg->height();
    ui->bg->setPixmap(backgroundPixmap.scaled(w,h));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete stageWindow;
}

void MainWindow::SetButtonImage(QPushButton* button, QString filePath) {
    QPixmap map(filePath);
    QIcon icon(map);
    button->setIcon(icon);
    button->setVisible(false);
}

void MainWindow::mainBack()
{
    this->show();
}

void MainWindow::on_button1920_clicked()
{
    this->close();
    stageWindow->show();
    emit eraChange(2);
}

void MainWindow::on_button1930_clicked()
{
    this->close();
    stageWindow->show();
    emit eraChange(3);
}

void MainWindow::on_button1940_clicked()
{
    this->close();
    stageWindow->show();
    emit eraChange(4);
}

void MainWindow::on_button1950_clicked()
{
    this->close();
    stageWindow->show();
    emit eraChange(5);
}

void MainWindow::on_button1960_clicked()
{
    this->close();
    stageWindow->show();
    emit eraChange(6);
}

void MainWindow::on_button1970_clicked()
{
    this->close();
    stageWindow->show();
    emit eraChange(7);
}

void MainWindow::on_button1980_clicked()
{
    this->close();
    stageWindow->show();
    emit eraChange(8);
}

void MainWindow::on_button1990_clicked()
{
    this->close();
    stageWindow->show();
    emit eraChange(9);
}

void MainWindow::on_button2000_clicked()
{
    this->close();
    stageWindow->show();
    emit eraChange(0);
}

void MainWindow:: on_quizButton_clicked()
{
    this->close();
    quizWindow->show();
    emit playQuizMusic();
    emit setUpQuizButtons();
}

void MainWindow::setupBackgroundImage(const QSize &size) {
    QPixmap originalPixmap(":/Line TuneTimeline.png");
    QPixmap scaledPixmap = originalPixmap.scaled(size, Qt::KeepAspectRatioByExpanding);
    backgroundImageLabel->setPixmap(scaledPixmap);
    backgroundImageLabel->setGeometry(this->rect());
    backgroundImageLabel->lower(); // Ensure the label is behind other widgets
    int yOffset = -30; // Adjust the geometry to move the image up, negative value to move up
    backgroundImageLabel->setGeometry(0, yOffset, size.width(), size.height());
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    setupBackgroundImage(event->size());
}

void MainWindow::on_start_clicked()
{
    ui->bg->hide();
    ui->start->hide();
    ui->title->hide();
    ui->explain->hide();

    ui->button1920->setVisible(true);
    ui->button1930->setVisible(true);
    ui->button1940->setVisible(true);
    ui->button1950->setVisible(true);
    ui->button1960->setVisible(true);
    ui->button1970->setVisible(true);
    ui->button1980->setVisible(true);
    ui->button1990->setVisible(true);
    ui->button2000->setVisible(true);

}

