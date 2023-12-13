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

    // Set up all the game buttons, scores, and music paths
    setUpQuiz();

    int id = QFontDatabase::addApplicationFont(":/PixeloidSans-mLxMm.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont font(family);
    font.setStyleHint(QFont::Monospace);
    ui->question->setFont(font);

    musicAud = new QAudioOutput;
    musicPlayer->setAudioOutput(musicAud);
    musicAud->setVolume(1);

    connect(m_mainWindow, &MainWindow::playQuizMusic, this, &Quiz::playMusic);
    connect(m_mainWindow, &MainWindow::setUpQuizButtons, this, &Quiz::setUpButtons);
}

Quiz::~Quiz()
{
    delete ui;
}

void Quiz::setUpQuiz()
{
    questionNumber = 0;
    amountCorrect = 0;
    amountIncorrect = 0;

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
                  {"qrc:/Oasis_DontLookBackInAnger.mp3", 1990}, {"qrc:/JayZ_EmpireStateOfMind.mp3", 2000},
                  {"qrc:/Prince_Kiss.mp3", 1980}, {"qrc:/Ramones_BlitzkriegBop.mp3", 1970},
                  {"qrc:/SidneyBechet_WildCatBlues.mp3", 1920}, {"qrc:/StevieWonder_SirDuke.mp3", 1970},
                  {"qrc:/TheBeatles_HereComesTheSun.mp3", 1960}, {"qrc:/TheEverlyBrothers_AllIHavetoDoIsDream.mp3", 1950},
                  {"qrc:/TheSupremes_StopintheNameofLove.mp3", 1960}, {"qrc:/ThroughTheWire.mp3", 2000},
                  {"qrc:/VeraLynn_We_llMeetAgain.mp3", 1940}, {"qrc:/WhiteStripes_SevenNationArmy.mp3", 2000},
                  {"qrc:/WillieSmith_EchoesOfSpring.mp3", 1920}, {"qrc:/MariahCarey_Fantasy.mp3", 1990}};

    // Move all paths to vector
    for(auto elem : musicPaths)
    {
        vecOfPaths.push_back(elem.first);
    }

    // Randomly shuffle the order
    auto rd = std::random_device {};
    auto rng = std::default_random_engine { rd() };
    std::shuffle(std::begin(vecOfPaths), std::end(vecOfPaths), rng);

    questionNumber = 0;
    correctEra = 1920;

    // Disable game over buttons
    ui->finalScore->setVisible(false);
    ui->retryButton->setVisible(false);

    // Enable all game buttons
    ui->eraButton1->setVisible(true);
    ui->eraButton2->setVisible(true);
    ui->eraButton3->setVisible(true);
    ui->eraButton4->setVisible(true);
    ui->question->setVisible(true);
    ui->correctScore->setVisible(true);
    ui->incorrectScore->setVisible(true);
    ui->eraButton1->setEnabled(true);
    ui->eraButton2->setEnabled(true);
    ui->eraButton3->setEnabled(true);
    ui->eraButton4->setEnabled(true);

    // Set up ui correct buttons
    QString incorrectSet = "Incorrect: ";
    incorrectSet+=std::to_string(amountIncorrect);
    ui->incorrectScore->setText(incorrectSet);

    QString  correctSet = "Correct: ";
    correctSet+=std::to_string(amountCorrect);
    ui->correctScore->setText(correctSet);
}

//When the go back button clicked
void Quiz::on_pushButton_clicked()
{
    this->close();
    emit mainWindowComeBack();
    musicPlayer->stop();
}

void Quiz::playMusic()
{
    musicPlayer->setSource(QUrl::fromEncoded(vecOfPaths[questionNumber]));
    musicPlayer->play();
    qDebug()<<vecOfPaths[questionNumber];
}

void Quiz::setUpButtons()
{
    if (questionNumber >= 10)
    {
        gameOver();
        return;
    }
    ui->eraButton1->setEnabled(true);
    ui->eraButton2->setEnabled(true);
    ui->eraButton3->setEnabled(true);
    ui->eraButton4->setEnabled(true);
    ui->pushButton->setEnabled(true);

    correctButton = QRandomGenerator::global()->bounded(1,5);
    correctEra = musicPaths[vecOfPaths[questionNumber]];
    QString correctText = QString::number(musicPaths[vecOfPaths[questionNumber]]);

    switch(correctButton)
    {
    case 1:
        ui->eraButton1->setText(correctText);
        setOtherButtons(2, 3, 4);
        break;

    case 2:
        ui->eraButton2->setText(correctText);
        setOtherButtons(1, 3, 4);
        break;

    case 3:
        ui->eraButton3->setText(correctText);
        setOtherButtons(1, 2, 4);
        break;

    case 4:
        ui->eraButton4->setText(correctText);
        setOtherButtons(1, 2, 3);
        break;
    }
}

void Quiz::setOtherButtons (int button1, int button2, int button3)
{
    int randomEra = QRandomGenerator::global()->bounded(0,9);
    int usedValue = (correctEra - 1920)/10;

    // If the random era is the value we already set, create it again
    while (randomEra == usedValue)
    {
        randomEra = QRandomGenerator::global()->bounded(0,9);
    }

    // Must save this value so it isn't repeated for the next buttons
    int usedValue2 = randomEra;
    randomEra = (randomEra * 10) + 1920;
    QString randomEraText = QString::number(randomEra);
    switch(button1)
    {
    case 1:
        ui->eraButton1->setText(randomEraText);
        break;

    case 2:
        ui->eraButton2->setText(randomEraText);
        break;

    case 3:
        ui->eraButton3->setText(randomEraText);
        break;

    case 4:
        ui->eraButton4->setText(randomEraText);
        break;
    }

    randomEra = QRandomGenerator::global()->bounded(0,9);
    usedValue = (correctEra - 1920)/10;
    while (randomEra == usedValue || randomEra == usedValue2)
    {
        randomEra = QRandomGenerator::global()->bounded(0,9);
    }

    int usedValue3 = randomEra;
    randomEra = (randomEra * 10) + 1920;
    randomEraText = QString::number(randomEra);
    switch(button2)
    {
    case 1:
        ui->eraButton1->setText(randomEraText);
        break;

    case 2:
        ui->eraButton2->setText(randomEraText);
        break;

    case 3:
        ui->eraButton3->setText(randomEraText);
        break;

    case 4:
        ui->eraButton4->setText(randomEraText);
        break;
    }

    randomEra = QRandomGenerator::global()->bounded(0,9);
    usedValue = (correctEra - 1920)/10;
    while (randomEra == usedValue || randomEra == usedValue2 || randomEra == usedValue3)
    {
        randomEra = QRandomGenerator::global()->bounded(0,9);
    }

    randomEra = (randomEra * 10) + 1920;
    randomEraText = QString::number(randomEra);
    switch(button3)
    {
    case 1:
        ui->eraButton1->setText(randomEraText);
        break;

    case 2:
        ui->eraButton2->setText(randomEraText);
        break;

    case 3:
        ui->eraButton3->setText(randomEraText);
        break;

    case 4:
        ui->eraButton4->setText(randomEraText);
        break;
    }
}

void Quiz::on_eraButton1_clicked()
{
    if (correctButton == 1)
    {
        QString text = "Correct!";
        ui->rightOrWrong->setText("<font color='light green'>" + text);
        QString scoreText = "Correct: ";
        amountCorrect++;
        scoreText+=std::to_string(amountCorrect);
        ui->correctScore->setText(scoreText);
    }
    else
    {
        QString text = "Incorrect!";
        ui->rightOrWrong->setText("<font color='red'>" + text);
        amountIncorrect++;
        QString scoreText = "Incorrect: ";
        scoreText+=std::to_string(amountIncorrect);
        ui->incorrectScore->setText(scoreText);
    }
    ui->eraButton1->setEnabled(false);
    ui->eraButton2->setEnabled(false);
    ui->eraButton3->setEnabled(false);
    ui->eraButton4->setEnabled(false);
    ui->pushButton->setEnabled(false);
    questionNumber++;

    QTimer::singleShot(2000, [=]()
    {
       ui->rightOrWrong->setText("");
       playMusic();
       setUpButtons();
    });
}

void Quiz::on_eraButton2_clicked()
{
    if (correctButton == 2)
    {
        QString text = "Correct!";
        ui->rightOrWrong->setText("<font color='light green'>" + text);
        amountCorrect++;
        QString scoreText = "Correct: ";
        scoreText+=std::to_string(amountCorrect);
        ui->correctScore->setText(scoreText);
    }
    else
    {
        QString text = "Incorrect!";
        ui->rightOrWrong->setText("<font color='red'>" + text);
        amountIncorrect++;
        QString scoreText = "Incorrect: ";
        scoreText+=std::to_string(amountIncorrect);
        ui->incorrectScore->setText(scoreText);
    }
    ui->eraButton1->setEnabled(false);
    ui->eraButton2->setEnabled(false);
    ui->eraButton3->setEnabled(false);
    ui->eraButton4->setEnabled(false);
    ui->pushButton->setEnabled(false);
    questionNumber++;

    // Set delay until right or wrong text disappears and music plays
    QTimer::singleShot(2000, [=]()
    {
       ui->rightOrWrong->setText("");
       playMusic();
       setUpButtons();
    });
}

void Quiz::on_eraButton3_clicked()
{
    if (correctButton == 3)
    {
        QString text = "Correct!";
        ui->rightOrWrong->setText("<font color='light green'>" + text);
        amountCorrect++;
        QString scoreText = "Correct: ";
        scoreText+=std::to_string(amountCorrect);
        ui->correctScore->setText(scoreText);
    }
    else
    {
        QString text = "Incorrect!";
        ui->rightOrWrong->setText("<font color='red'>" + text);
        amountIncorrect++;
        QString scoreText = "Incorrect: ";
        scoreText+=std::to_string(amountIncorrect);
        ui->incorrectScore->setText(scoreText);
    }
    ui->eraButton1->setEnabled(false);
    ui->eraButton2->setEnabled(false);
    ui->eraButton3->setEnabled(false);
    ui->eraButton4->setEnabled(false);
    ui->pushButton->setEnabled(false);
    questionNumber++;

    QTimer::singleShot(2000, [=]()
    {
       ui->rightOrWrong->setText("");
       playMusic();
       setUpButtons();
    });
}

void Quiz::on_eraButton4_clicked()
{
    if (correctButton == 4)
    {
        QString text = "Correct!";
        ui->rightOrWrong->setText("<font color='light green'>" + text);
        amountCorrect++;
        QString scoreText = "Correct: ";
        scoreText+=std::to_string(amountCorrect);
        ui->correctScore->setText(scoreText);
    }
    else
    {
        QString text = "Incorrect!";
        ui->rightOrWrong->setText("<font color='red'>" + text);
        amountIncorrect++;
        QString scoreText = "Incorrect: ";
        scoreText+=std::to_string(amountIncorrect);
        ui->incorrectScore->setText(scoreText);
    }
    ui->eraButton1->setEnabled(false);
    ui->eraButton2->setEnabled(false);
    ui->eraButton3->setEnabled(false);
    ui->eraButton4->setEnabled(false);
    ui->pushButton->setEnabled(false);
    questionNumber++;

    QTimer::singleShot(2000, [=]()
    {
        ui->rightOrWrong->setText("");
        playMusic();
        setUpButtons();
    });
}

void Quiz::gameOver()
{
    ui->eraButton1->setVisible(false);
    ui->eraButton2->setVisible(false);
    ui->eraButton3->setVisible(false);
    ui->eraButton4->setVisible(false);
    ui->question->setVisible(false);
    ui->correctScore->setVisible(false);
    ui->incorrectScore->setVisible(false);

    ui->retryButton->setVisible(true);
    QString userScore = "You Scored: ";
    userScore+=std::to_string(amountCorrect);
    userScore+="/10";
    ui->finalScore->setText(userScore);
    ui->finalScore->setVisible(true);
    ui->pushButton->setEnabled(true);

    musicPlayer->stop();
}

void Quiz::on_retryButton_clicked()
{
    setUpQuiz();
    musicPlayer->play();
}
