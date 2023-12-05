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
#include<iterator>
#include<vector>
#include <algorithm>
#include <random>
#include<QDebug>

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

    std::map<QByteArray, int> musicPaths;
    musicPaths = {{"qrc:/2Pac_CaliforniaLove.mp3", 1990}, {"qrc:/BennyGoodman_DontBeThatWay.mp3", 1930},
                   {"qrc:/Biggie_MoMoneyMoProblems.mp3", 1990}, {"qrc:/BillieHoliday_GodBlessTheChild.mp3", 1930},
                   {"qrc:/BingCrosby_ISurrenderDear.mp3", 1930}, {"qrc:/BobDylan_LikeARollingStone.mp3", 1960},
                   {"qrc:/BobMarley_CouldYouBeLoved.mp3", 1970}, {"qrc:/BruceSpringsteen_BornToRun.mp3", 1980},
                   {"qrc:/Chuck_Berry_-_Johnny_B_Goode.mp3", 1950}, {"qrc:/DaftPunk_OneMoreTime.mp3", 2000},
                   {"qrc:/DukeEllington_Caravan.mp3", 1930}, {"qrc:/EdithPiaf_LaVieEnRose.mp3", 1940},
                   {"qrc:/EllaFitzgerald_DreamALittleDreamOfMe.mp3", 1940}, {"qrc:/ElvisPresley_HoundDog.mp3", 1950},
                   {"qrc:/FrankSinatra_FlyMeToTheMoon.mp3", 1940}, {"qrc:/GlenMiller_IntheMood.mp3", 1930},
                   {"qrc:/GloriaGaynor_IWillSurvive.mp3", 1970}, {"qrc:/JamesBrown_IGotYou(IFeelGood).mp3", 1960},
                   {"qrc:/JellyRollMorton_HonkyTonkBlues.mp3", 1920}, {"qrc:/JimiHendrix_PurpleHaze.mp3", 1960},
                   {"qrc:/JohnnyCash_IWalkTheLine.mp3", 1950}, {"qrc:/KingOliver_DoctorJazz.mp3", 1920},
                   {"qrc:/LadyGaga_BadRomance.mp3", 2000}, {"qrc:/LedZeppelin_ImmigrantSong.mp3", 1970},
                   {"qrc:/LittleRichard_TuttiFruti.mp3", 1950}, {"qrc:/Louis Armstrong - What A Wonderful World.mp3", 1920},
                   {"qrc:/Madonna_MaterialGirl.mp3", 1980}, {"qrc:/MichaelJacson_BeatIt.mp3", 1980},
                   {"qrc:/N.K.COLE_L.O.V.E.mp3", 1940}, {"qrc:/Nirvana_SmellsLikeTeenSpirit.mp3", 1990},
                   {"qrc:/Oasis_DontLookBackInAnger.mp3", 1990}, {"qrc:/OutKast_HeyYa.mp3", 2000},
                   {"qrc:/Prince_Kiss.mp3", 1980}, {"qrc:/Ramones_BlitzkriegBop.mp3", 1970},
                   {"qrc:/SidneyBechet_WildCatBlues.mp3", 1920}, {"qrc:/StevieWonder_SirDuke.mp3", 1970},
                   {"qrc:/TheBeatles_HereComesTheSun.mp3", 1960}, {"qrc:/TheEverlyBrothers_AllIHavetoDoIsDream.mp3", 1950},
                   {"qrc:/TheSupremes_StopintheNameofLove.mp3", 1960}, {"qrc:/ThroughTheWire.mp3", 2000},
                   {"qrc:/VeraLynn_We_llMeetAgain.mp3", 1940}, {"qrc:/WhiteStripes_SevenNationArmy.mp3", 2000},
                   {"qrc:/WillieSmith_EchoesOfSpring.mp3", 1920}};

//    std::iterator item = musicPaths.begin();
//    std::advance( item, random_0_to_n(musicPaths.size()) );


    // Move all paths to vector
    for(auto elem : musicPaths)
    {
        vecOfPaths.push_back(elem.first);
    }

    // Randomly shuffle the order
//    auto rng = std::default_random_engine {};
//    std::shuffle(std::begin(vecOfPaths), std::end(vecOfPaths), rng);

    auto rd = std::random_device {};
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(vecOfPaths), std::end(vecOfPaths), rng);


    // Display random question
    //showNextQuestion();

    // Set button color
//    ui->trueButton->setStyleSheet("background-color: green");
//    ui->falseButton->setStyleSheet("background-color: red");
    connect(m_mainWindow, &MainWindow::playQuizMusic, this, &Quiz::playMusic);
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
    musicPlayer->stop();
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

void Quiz::playMusic()
{
    musicPlayer->setSource(QUrl::fromEncoded(vecOfPaths[0]));
    musicPlayer->play();
    qDebug()<<vecOfPaths[0];
}
