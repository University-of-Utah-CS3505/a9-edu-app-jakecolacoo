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
        emit playMusic("qrc:/2Pac_CaliforniaLove.mp3");
        break;
    case 2:
        imagePaths = {":/I_forgot.png", ":/I_forgot.png", ":/Cheryl_James.png", ":/2000sIcon.jpg", ":/1990sIcon.jpg"};
        names = {"2-1", "2-2", "2-3", "2-4", "2-5"};
        m1 = "qrc:/BobDylan_LikeARollingStone.mp3";
        m2 = "qrc:/Biggie_MoMoneyMoProblems.mp3";
        m3 = "qrc:/DukeEllington_Caravan.mp3";
        m4 = "qrc:/BingCrosby_ISurrenderDear.mp3";
        m5 = "qrc:/DaftPunk_OneMoreTime.mp3";
        emit sendInfor(imagePaths, names);
        emit playMusic("qrc:/2Pac_CaliforniaLove.mp3");
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
        emit playMusic("qrc:/Louis Armstrong - What A Wonderful World.mp3");
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
        emit playMusic("qrc:/JohnnyCash_IWalkTheLine.mp3");
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
        emit playMusic("qrc:/N.K.COLE_L.O.V.E.mp3");
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
        emit playMusic("qrc:/SidneyBechet_WildCatBlues.mp3");
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
        emit playMusic("qrc:/2Pac_CaliforniaLove.mp3");
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
        emit playMusic("qrc:/2Pac_CaliforniaLove.mp3");
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
        emit playMusic("qrc:/2Pac_CaliforniaLove.mp3");
        break;
    default:
        break;
    }
}

void stageCreate::play(int i){
    switch (i) {
    case 1:
        emit playMusic(m1);
        break;
    case 2:
        emit playMusic(m2);
        break;
    case 3:
        emit playMusic(m3);
        break;
    case 4:
        emit playMusic(m4);
        break;
    case 5:
        emit playMusic(m5);
        break;
    default:
        break;
    }
}
