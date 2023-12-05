/*
 * Model class to store the information of chosen era
 * So that the Form class only need to set up stuff that
 * send from this class, and when need change the sprites
 * path and all other informations, we can simply change in this
 * class, so it can prevent affecting other code
*/

#include "stagecreate.h"

stageCreate::stageCreate(QWidget *parent)
    : QWidget{parent}
{

}

// Set era by the era identity number
// Such that : 0 is 2000's
//             2 is 1920's
//             3 is 1930's and so on
void stageCreate::setEra(int era){
    switch (era) {
    case 0:
        // Set sprites paths and corresponding names(same as the rest cases)
        imagePaths = {":/Mariah_Carey.png", ":/I_forgot.png", ":/Cheryl_James.png", ":/2000sIcon.jpg", ":/1990sIcon.jpg"};
        names = {"0-1", "0-2", "0-3", "0-4", "0-5"};

        //set musics for corresponding buttons(same as the rest cases)
        m1 = "qrc:/Biggie_MoMoneyMoProblems.mp3";
        m2 = "qrc:/BobDylan_LikeARollingStone.mp3";
        m3 = "qrc:/DaftPunk_OneMoreTime.mp3";
        m4 = "qrc:/BingCrosby_ISurrenderDear.mp3";
        m5 = "qrc:/DukeEllington_Caravan.mp3";

        //send all musication sprite and names(same as the rest cases)
        emit sendInfor(imagePaths, names);

        //send background music(same as the rest cases)
        break;
    case 2:
        imagePaths = {":/1920 Will The Lion Smith Sprite.png", ":/1920 Jelly Roll Morton Sprite.png", ":/1920 Louis Armstring Sprite.png", ":/1920 Sidney Bechet Sprite.png", ":/1920 King Oliver Sprite.png"};
        names = {"Willie Smith", "Jelly Roll Morton", "Louis Armstrong", "Sydney Bechet", "King Oliver"};
        m1 = "qrc:/WillieSmith_EchoesOfSpring.mp3";
        m2 = "qrc:/JellyRollMorton_HonkyTonkBlues.mp3";
        m3 = "qrc:/LouisArmstrong_BasinStreetBlues.mp3";
        m4 = "qrc:/SidneyBechet_WildCatBlues.mp3";
        m5 = "qrc:/KingOliver_DoctorJazz.mp3";


        artist1Info = ":/WillySmithInfo.txt";
        artist2Info = ":/JellyRollInfo.txt";
        artist3Info = ":/LouisArmstrongInfo.txt";
        artist4Info = ":/SydneyBechetInfo.txt";
        artist5Info = ":/KingOliverInfo.txt";

        emit sendInfor(imagePaths, names);
        emit sendFileForInfoBar(":/1920sInfo.txt");
        break;
    case 3:
        imagePaths = {":/Mariah_Carey.png", ":/I_forgot.png", ":/Cheryl_James.png", ":/2000sIcon.jpg", ":/1990sIcon.jpg"};
        names = {"3-1", "3-2", "3-3", "3-4", "3-5"};
        m1 = "qrc:/DukeEllington_Caravan.mp3";
        m2 = "qrc:/BobDylan_LikeARollingStone.mp3";
        m3 = "qrc:/DaftPunk_OneMoreTime.mp3";
        m4 = "qrc:/BingCrosby_ISurrenderDear.mp3";
        m5 = "qrc:/Biggie_MoMoneyMoProblems.mp3";
        emit sendInfor(imagePaths, names);
        break;
    case 4:
        imagePaths = {":/Cheryl_James.png", ":/I_forgot.png", ":/Cheryl_James.png", ":/2000sIcon.jpg", ":/1990sIcon.jpg"};
        names = {"4-1", "4-2", "4-3", "4-4", "4-5"};
        m1 = "qrc:/Biggie_MoMoneyMoProblems.mp3";
        m2 = "qrc:/BobDylan_LikeARollingStone.mp3";
        m3 = "qrc:/DaftPunk_OneMoreTime.mp3";
        m4 = "qrc:/BingCrosby_ISurrenderDear.mp3";
        m5 = "qrc:/DukeEllington_Caravan.mp3";
        emit sendInfor(imagePaths, names);
        break;
    case 5:
        imagePaths = {":/2000sIcon.jpg", ":/I_forgot.png", ":/Cheryl_James.png", ":/2000sIcon.jpg", ":/1990sIcon.jpg"};
        names = {"0-1", "0-2", "0-3", "0-4", "0-5"};
        m1 = "qrc:/Biggie_MoMoneyMoProblems.mp3";
        m2 = "qrc:/BobDylan_LikeARollingStone.mp3";
        m3 = "qrc:/DaftPunk_OneMoreTime.mp3";
        m4 = "qrc:/BingCrosby_ISurrenderDear.mp3";
        m5 = "qrc:/DukeEllington_Caravan.mp3";
        emit sendInfor(imagePaths, names);
        break;
    case 6:
        imagePaths = {":/Mariah_Carey.png", ":/I_forgot.png", ":/Cheryl_James.png", ":/2000sIcon.jpg", ":/1990sIcon.jpg"};
        names = {"0-1", "0-2", "0-3", "0-4", "0-5"};
        m1 = "qrc:/Biggie_MoMoneyMoProblems.mp3";
        m2 = "qrc:/BobDylan_LikeARollingStone.mp3";
        m3 = "qrc:/DaftPunk_OneMoreTime.mp3";
        m4 = "qrc:/BingCrosby_ISurrenderDear.mp3";
        m5 = "qrc:/DukeEllington_Caravan.mp3";
        emit sendInfor(imagePaths, names);
        break;
    case 7:
        imagePaths = {":/Mariah_Carey.png", ":/I_forgot.png", ":/Cheryl_James.png", ":/2000sIcon.jpg", ":/1990sIcon.jpg"};
        names = {"0-1", "0-2", "0-3", "0-4", "0-5"};
        m1 = "qrc:/Biggie_MoMoneyMoProblems.mp3";
        m2 = "qrc:/BobDylan_LikeARollingStone.mp3";
        m3 = "qrc:/DaftPunk_OneMoreTime.mp3";
        m4 = "qrc:/BingCrosby_ISurrenderDear.mp3";
        m5 = "qrc:/DukeEllington_Caravan.mp3";
        emit sendInfor(imagePaths, names);
        break;
    case 8:
        imagePaths = {":/Mariah_Carey.png", ":/I_forgot.png", ":/Cheryl_James.png", ":/2000sIcon.jpg", ":/1990sIcon.jpg"};
        names = {"0-1", "0-2", "0-3", "0-4", "0-5"};
        m1 = "qrc:/Biggie_MoMoneyMoProblems.mp3";
        m2 = "qrc:/BobDylan_LikeARollingStone.mp3";
        m3 = "qrc:/DaftPunk_OneMoreTime.mp3";
        m4 = "qrc:/BingCrosby_ISurrenderDear.mp3";
        m5 = "qrc:/DukeEllington_Caravan.mp3";
        emit sendInfor(imagePaths, names);
        break;
    case 9:
        imagePaths = {":/Mariah_Carey.png", ":/I_forgot.png", ":/Cheryl_James.png", ":/2000sIcon.jpg", ":/1990sIcon.jpg"};
        names = {"0-1", "0-2", "0-3", "0-4", "0-5"};
        m1 = "qrc:/Biggie_MoMoneyMoProblems.mp3";
        m2 = "qrc:/BobDylan_LikeARollingStone.mp3";
        m3 = "qrc:/DaftPunk_OneMoreTime.mp3";
        m4 = "qrc:/BingCrosby_ISurrenderDear.mp3";
        m5 = "qrc:/DukeEllington_Caravan.mp3";
        emit sendInfor(imagePaths, names);
        break;
    default:
        break;
    }
}

void stageCreate::play(int i){
    switch (i) {
    case 1:
        emit playMusic(m1);
        emit sendFileForInfoBar(artist1Info);
        break;
    case 2:
        emit playMusic(m2);
        emit sendFileForInfoBar(artist2Info);
        break;
    case 3:
        emit playMusic(m3);
        emit sendFileForInfoBar(artist3Info);
        break;
    case 4:
        emit playMusic(m4);
        emit sendFileForInfoBar(artist4Info);
        break;
    case 5:
        emit playMusic(m5);
        emit sendFileForInfoBar(artist5Info);
        break;
    default:
        break;
    }
}
