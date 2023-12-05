/*
 * View class of the stage
 * Use to set up the sprites and all other UI stuff
*/

#include "Quiz.h"
#include "ui_Quiz.h"
#include "mainwindow.h"
#include <QMediaPlayer>
#include<QRandomGenerator>
#include<map>

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

    std::map<QString, int> musicPaths;
    musicPaths = {{":/2Pac_CaliforniaLove.mp3", 1990}, {":/BennyGoodman_DontBeThatWay.mp3", 1930},
                   {":/Biggie_MoMoneyMoProblems.mp3", 1990}, {":/BillieHoliday_GodBlessTheChild.mp3", 1930},
                   {":/BingCrosby_ISurrenderDear.mp3", 1930}, {":/BobDylan_LikeARollingStone.mp3", 1960},
                   {":/BobMarley_CouldYouBeLoved.mp3", 1970}, {":/BruceSpringsteen_BornToRun.mp3", 1980},
                   {":/Chuck_Berry_-_Johnny_B_Goode.mp3", 1950}, {":/DaftPunk_OneMoreTime.mp3", 2000},
                   {":/DukeEllington_Caravan.mp3", 1930}, {":/EdithPiaf_LaVieEnRose.mp3", 1940},
                   {":/EllaFitzgerald_DreamALittleDreamOfMe.mp3", 1940}, {":/ElvisPresley_HoundDog.mp3", 1950},
                   {":/FrankSinatra_FlyMeToTheMoon.mp3", 1940}, {":/GlenMiller_IntheMood.mp3", 1930},
                   {":/GloriaGaynor_IWillSurvive.mp3", 1970}, {":/JamesBrown_IGotYou(IFeelGood).mp3", 1960},
                   {":/JellyRollMorton_HonkyTonkBlues.mp3", 1920}, {":/JimiHendrix_PurpleHaze.mp3", 1960},
                   {":/JohnnyCash_IWalkTheLine.mp3", 1950}, {":/KingOliver_DoctorJazz.mp3", 1920},
                   {":/LadyGaga_BadRomance.mp3", 2000}, {":/LedZeppelin_ImmigrantSong.mp3", 1970},
                   {":/LittleRichard_TuttiFruti.mp3", 1950}, {":/Louis Armstrong - What A Wonderful World.mp3", 1920},
                   {":/Madonna_MaterialGirl.mp3", 1980}, {":/MichaelJacson_BeatIt.mp3", 1980},
                   {":/N.K.COLE_L.O.V.E.mp3", 1940}, {":/Nirvana_SmellsLikeTeenSpirit.mp3", 1990},
                   {":/Oasis_DontLookBackInAnger.mp3", 1990}, {":/OutKast_HeyYa.mp3", 2000},
                   {":/Prince_Kiss.mp3", 1980}, {":/Ramones_BlitzkriegBop.mp3", 1970},
                   {":/SidneyBechet_WildCatBlues.mp3", 1920}, {":/StevieWonder_SirDuke.mp3", 1970},
                   {":/TheBeatles_HereComesTheSun.mp3", 1960}, {":/TheEverlyBrothers_AllIHavetoDoIsDream.mp3", 1950},
                   {":/TheSupremes_StopintheNameofLove.mp3", 1960}, {":/ThroughTheWire.mp3", 2000},
                   {":/VeraLynn_We_llMeetAgain.mp3", 1940}, {":/WhiteStripes_SevenNationArmy.mp3", 2000},
                   {":/WillieSmith_EchoesOfSpring.mp3", 1920}};

    // Display random question
    showNextQuestion();

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

void Quiz::showNextQuestion()
{
    int question = QRandomGenerator::global()->bounded(0,3);

    switch(question)
    {
    case 0:
        ui->question->setText("It do clap though");
        setAnswer = true;
        break;

    case 1:
        ui->question->setText("Them cheeks are large");
        setAnswer = false;
        break;

    case 2:
        ui->question->setText("I am heterosexual");
        setAnswer = false;
        break;
    }
}

void Quiz::on_trueButton_clicked()
{
    if(setAnswer)
    {
        ui->rightOrWrong->setText("Correct!");
        ui->rightOrWrong->setStyleSheet("background-color: green");
    }
    else
    {
        ui->rightOrWrong->setText("Incorrect!");
        ui->rightOrWrong->setStyleSheet("background-color: red");

    }
    showNextQuestion();
}

void Quiz::on_falseButton_clicked()
{
    if(!setAnswer)
    {
        ui->rightOrWrong->setText("Correct!");
        ui->rightOrWrong->setStyleSheet("background-color: green");
    }
    else
    {
        ui->rightOrWrong->setText("Incorrect!");
        ui->rightOrWrong->setStyleSheet("background-color: red");
    }
    showNextQuestion();
}
