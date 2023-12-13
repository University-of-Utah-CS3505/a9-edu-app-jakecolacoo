/*
 * This class implements all of the quiz related methods. The quiz will randomly play an artist's music
 * and allows the user to choose between four randomly generated eras. There should be ui feedback on whether
 * the answer is right or wrong and it should also show the song and artist. There is a tracker for right or
 * wrong answers, and a game over screen after 10 songs.
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

    // Each music path with the correct era
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

    // Map of music paths and artists to view on screen
    artistEra = {{"qrc:/2Pac_CaliforniaLove.mp3", "2Pac from the 1990's"}, {"qrc:/BennyGoodman_DontBeThatWay.mp3", "Benny Goodman from the 1930's"},
                  {"qrc:/Biggie_MoMoneyMoProblems.mp3", "Notorious B.I.G from the 1990's"}, {"qrc:/BillieHoliday_GodBlessTheChild.mp3", "Billie Holiday from the 1930's"},
                  {"qrc:/BingCrosby_ISurrenderDear.mp3", "Bing Crosby from the 1930's"}, {"qrc:/BobDylan_LikeARollingStone.mp3", "Bob Dylan from the 1960's"},
                  {"qrc:/BobMarley_CouldYouBeLoved.mp3", "Bob Marley from the 1970's"}, {"qrc:/BruceSpringsteen_BornToRun.mp3", "Bruce Springsteen from the 1980's"},
                  {"qrc:/Chuck_Berry_-_Johnny_B_Goode.mp3", "Chuck Berry from the 1950's"}, {"qrc:/DaftPunk_OneMoreTime.mp3", "Daft Punk from the 2000's"},
                  {"qrc:/DukeEllington_Caravan.mp3", "Duke Ellington from the 1930's"}, {"qrc:/EdithPiaf_LaVieEnRose.mp3", "Edith Piaf from the 1940's"},
                  {"qrc:/EllaFitzgerald_DreamALittleDreamOfMe.mp3","Ella Fitzgerald from the 1940's"}, {"qrc:/ElvisPresley_HoundDog.mp3","Elvis Presley from the 1950's"},
                  {"qrc:/FrankSinatra_FlyMeToTheMoon.mp3", "Frank Sinatra from the 1940's"}, {"qrc:/GlenMiller_IntheMood.mp3", "Glenn Miller from the 1930's"},
                  {"qrc:/GloriaGaynor_IWillSurvive.mp3", "Gloria Gaynor from the 1970's"}, {"qrc:/JamesBrown_IGotYou(IFeelGood).mp3", "James Brown from the 1960's"},
                  {"qrc:/JellyRollMorton_HonkyTonkBlues.mp3","Jelly Roll Morton from the 1920's"}, {"qrc:/JimiHendrix_PurpleHaze.mp3", "Jimi Hendix from the 1960's"},
                  {"qrc:/JohnnyCash_IWalkTheLine.mp3","Johnny Cash from the 1950's"}, {"qrc:/KingOliver_DoctorJazz.mp3", "King Oliver from the 1920's"},
                  {"qrc:/LadyGaga_BadRomance.mp3","Lady Gaga from the 2000's"}, {"qrc:/LedZeppelin_ImmigrantSong.mp3","Led Zeppelin from the 1970's"},
                  {"qrc:/LittleRichard_TuttiFruti.mp3","Little Richard from the 1950's"}, {"qrc:/Louis Armstrong - What A Wonderful World.mp3","Louis Armstrong from the 1920's"},
                  {"qrc:/Madonna_MaterialGirl.mp3", "Madonna from the 1980's"}, {"qrc:/MichaelJacson_BeatIt.mp3","Michael Jackson from the 1980's"},
                  {"qrc:/N.K.COLE_L.O.V.E.mp3","Nat King Cole from the 1940's"}, {"qrc:/Nirvana_SmellsLikeTeenSpirit.mp3","Nirvana from the 1990's"},
                  {"qrc:/Oasis_DontLookBackInAnger.mp3","Oasis from the 1990's"}, {"qrc:/JayZ_EmpireStateOfMind.mp3","Jay Z from the 2000's"},
                  {"qrc:/Prince_Kiss.mp3","Prince from the 1980's"}, {"qrc:/Ramones_BlitzkriegBop.mp3","Ramones from the 1970's"},
                  {"qrc:/SidneyBechet_WildCatBlues.mp3","Sidney Bechet from the 1920's"}, {"qrc:/StevieWonder_SirDuke.mp3","Stevie Wonder from 1970's"},
                  {"qrc:/TheBeatles_HereComesTheSun.mp3","The Beatles from the 1960's"}, {"qrc:/TheEverlyBrothers_AllIHavetoDoIsDream.mp3","The Everly Brothers from the 1950's"},
                  {"qrc:/TheSupremes_StopintheNameofLove.mp3","The Supremes from the 1960's"}, {"qrc:/ThroughTheWire.mp3","Kanye West from the 2000's"},
                  {"qrc:/VeraLynn_We_llMeetAgain.mp3","Vera Lynn from the 1940's"}, {"qrc:/WhiteStripes_SevenNationArmy.mp3", "The White Stripes from the 2000's"},
                  {"qrc:/WillieSmith_EchoesOfSpring.mp3","Willie Smith from the 1920's"}, {"qrc:/MariahCarey_Fantasy.mp3","Mariah Carey from the 2000's"}};

    // Move all paths to vector
    for(auto elem : musicPaths)
    {
        vecOfPaths.push_back(elem.first);
    }

    // Randomly shuffle the order every time the program is reloaded
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

    // Set up correct and incorrect ui buttons
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

    //Randomly choose which button is going to be the correct button
    correctButton = QRandomGenerator::global()->bounded(1,5);

    // Set the correct era from the map
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

        // Show the correct answer after clicking on button
        ui->artistLabel->setText("<font color='white'>" + artistEra[vecOfPaths[questionNumber]]);
    }
    else
    {
        QString text = "Incorrect!";
        ui->rightOrWrong->setText("<font color='red'>" + text);
        amountIncorrect++;
        QString scoreText = "Incorrect: ";
        scoreText+=std::to_string(amountIncorrect);
        ui->incorrectScore->setText(scoreText);

        ui->artistLabel->setText("<font color='white'>" + artistEra[vecOfPaths[questionNumber]]);
    }
    ui->eraButton1->setEnabled(false);
    ui->eraButton2->setEnabled(false);
    ui->eraButton3->setEnabled(false);
    ui->eraButton4->setEnabled(false);
    ui->pushButton->setEnabled(false);
    questionNumber++;

    QTimer::singleShot(3000, [=]()
    {
       ui->rightOrWrong->setText("");
       playMusic();
       setUpButtons();

       ui->artistLabel->setText("");
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

        ui->artistLabel->setText("<font color='white'>" + artistEra[vecOfPaths[questionNumber]]);
    }
    else
    {
        QString text = "Incorrect!";
        ui->rightOrWrong->setText("<font color='red'>" + text);
        amountIncorrect++;
        QString scoreText = "Incorrect: ";
        scoreText+=std::to_string(amountIncorrect);
        ui->incorrectScore->setText(scoreText);

        ui->artistLabel->setText("<font color='white'>" + artistEra[vecOfPaths[questionNumber]]);
    }
    ui->eraButton1->setEnabled(false);
    ui->eraButton2->setEnabled(false);
    ui->eraButton3->setEnabled(false);
    ui->eraButton4->setEnabled(false);
    ui->pushButton->setEnabled(false);
    questionNumber++;

    // Set delay until right or wrong text disappears and music plays
    QTimer::singleShot(3000, [=]()
    {
       ui->rightOrWrong->setText("");
       playMusic();
       setUpButtons();

       ui->artistLabel->setText("");
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

        ui->artistLabel->setText("<font color='white'>" + artistEra[vecOfPaths[questionNumber]]);
    }
    else
    {
        QString text = "Incorrect!";
        ui->rightOrWrong->setText("<font color='red'>" + text);
        amountIncorrect++;
        QString scoreText = "Incorrect: ";
        scoreText+=std::to_string(amountIncorrect);
        ui->incorrectScore->setText(scoreText);

        ui->artistLabel->setText("<font color='white'>" + artistEra[vecOfPaths[questionNumber]]);
    }
    ui->eraButton1->setEnabled(false);
    ui->eraButton2->setEnabled(false);
    ui->eraButton3->setEnabled(false);
    ui->eraButton4->setEnabled(false);
    ui->pushButton->setEnabled(false);
    questionNumber++;

    QTimer::singleShot(3000, [=]()
    {
       ui->rightOrWrong->setText("");
       playMusic();
       setUpButtons();

       ui->artistLabel->setText("");
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

        ui->artistLabel->setText("<font color='white'>" + artistEra[vecOfPaths[questionNumber]]);
    }
    else
    {
        QString text = "Incorrect!";
        ui->rightOrWrong->setText("<font color='red'>" + text);
        amountIncorrect++;
        QString scoreText = "Incorrect: ";
        scoreText+=std::to_string(amountIncorrect);
        ui->incorrectScore->setText(scoreText);

        ui->artistLabel->setText("<font color='white'>" + artistEra[vecOfPaths[questionNumber]]);
    }
    ui->eraButton1->setEnabled(false);
    ui->eraButton2->setEnabled(false);
    ui->eraButton3->setEnabled(false);
    ui->eraButton4->setEnabled(false);
    ui->pushButton->setEnabled(false);
    questionNumber++;

    QTimer::singleShot(3000, [=]()
    {
        ui->rightOrWrong->setText("");
        playMusic();
        setUpButtons();

        ui->artistLabel->setText("");
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
    playMusic();
}
