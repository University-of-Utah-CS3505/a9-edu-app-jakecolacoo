/*
 * View class of the stage
 * Use to set up the sprites and all other UI stuff
*/

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

    int id = QFontDatabase::addApplicationFont(":/PixeloidSans-mLxMm.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont font(family);
    font.setStyleHint(QFont::Monospace);
    ui->label->setFont(font);

    musicAud = new QAudioOutput;
    musicPlayer->setAudioOutput(musicAud);
    musicAud->setVolume(1);

//    connect(m_mainWindow, &MainWindow::clicked1920, this, &Form::Stuffs1920);
    connect(m_mainWindow, &MainWindow::eraChange, stage, &stageCreate::setEra);
    connect(stage, &stageCreate::sendInfor, this, &Form::setEra);
    connect(stage, &stageCreate::playMusic, this, &Form::playMusic);
    connect(stage, &stageCreate::stopMusic, this, &Form::stopMusic);
    connect(stage, &stageCreate::sendFileForInfoBar, this, &Form::setInfoBar);
    connect(ui->decadeButton, &QPushButton::clicked, this, [this]() {
        stage->play(6);
    });
}

Form::~Form()
{
    delete ui;
}

//When the go back button clicked
void Form::on_pushButton_clicked()
{
    this->close();
    emit mainWindowComeBack();
    musicPlayer->stop();
    // MainOne.show();
    // MainOne.player->stop();
}

//use to set the current era's musication sprites and names
void Form::setEra(QStringList image, QStringList names, int decadeNum){

    //Size of sprites, can be adjust by need
    int w = ui->sprite1->width();
    int h = ui->sprite1->height();

    for (int i = 0; i < names.size(); ++i) {
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
            //connect each button to corresponding music
            connect(button, &QPushButton::clicked, this, [this, i]() {
                stage->play(i+1);
            });
        }
    }

    switch (decadeNum) {
    case 0:
        SetDecadeButtonImage(":/2000.png");
        break;
    case 2:
        SetDecadeButtonImage(":/1920.png");
        break;
    case 3:
        SetDecadeButtonImage(":/1930.png");
        break;
    case 4:
        SetDecadeButtonImage(":/1940.png");
        break;
    case 5:
        SetDecadeButtonImage(":/1950.png");
        break;
    case 6:
        SetDecadeButtonImage(":/1960.png");
        break;
    case 7:
        SetDecadeButtonImage(":/1970.png");
        break;
    case 8:
        SetDecadeButtonImage(":/1980.png");
        break;
    case 9:
        SetDecadeButtonImage(":/1990.png");
        break;
    }

    // Uncheck any previously checked buttons
    resetButtons();
}

//Make the player to play the music at the path
void Form::playMusic(QByteArray path){
    musicPlayer->setSource(QUrl::fromEncoded(path));
    musicPlayer->play();
}

void Form::resetButtons() {
    ui->music1->setAutoExclusive(false);
    ui->music1->setChecked(false);
    ui->music1->setAutoExclusive(true);

    ui->music2->setAutoExclusive(false);
    ui->music2->setChecked(false);
    ui->music2->setAutoExclusive(true);

    ui->music3->setAutoExclusive(false);
    ui->music3->setChecked(false);
    ui->music3->setAutoExclusive(true);

    ui->music4->setAutoExclusive(false);
    ui->music4->setChecked(false);
    ui->music4->setAutoExclusive(true);

    ui->music5->setAutoExclusive(false);
    ui->music5->setChecked(false);
    ui->music5->setAutoExclusive(true);
}

void Form::SetDecadeButtonImage(QString filePath) {
    QPixmap map(filePath);
    QIcon icon(map);
    ui->decadeButton->setIcon(icon);
    ui->decadeButton->setIconSize(ui->decadeButton->size());
}

void Form::stopMusic(){
    musicPlayer->stop();
    resetButtons();
}

void Form::setInfoBar(QString filePath) {
    QFile file(filePath);

    if (!file.exists()) {
        qDebug() << "File does not exist";
    } else if (!file.permissions().testFlag(QFileDevice::ReadUser)) {
        qDebug() << "Read permissions denied";
    } else if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file: " << file.errorString();
    } else {
        QTextStream in(&file);
        QString text = in.readAll();

        ui->label->setText("<font color='white'>" + text);
    }
}
