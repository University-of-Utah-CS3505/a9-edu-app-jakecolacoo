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
        imagePaths = {":/2000s The White Stripes Sprite.png", ":/2000s Lady Gaga Sprite.png", ":/2000s Kanye Sprite.png", ":/2000s Jay Z Sprite.png", ":/2000s Daft Punk Sprite.png"};
        names = {"White Stripes", "Lady Gaga", "Kanye West", "Jay Z", "Daft Punk"};

        //set musics for corresponding buttons(same as the rest cases)
        m1 = "qrc:/WhiteStripes_SevenNationArmy.mp3";
        m2 = "qrc:/LadyGaga_BadRomance.mp3";
        m3 = "qrc:/ThroughTheWire.mp3";
        m4 = "qrc:/JayZ_EmpireStateOfMind.mp3";
        m5 = "qrc:/DaftPunk_OneMoreTime.mp3";

        artist1Info = ":/White Stripes info.txt";
        artist2Info = ":/Lady Gaga Info.txt";
        artist3Info = ":/Kanye West Info.txt";
        artist4Info = ":/Jay Z Info.txt";
        artist5Info = ":/Daft Punk Info.txt";

        //send all musication sprite and names(same as the rest cases)
        emit sendInfor(imagePaths, names);
        emit sendFileForInfoBar(":/2000s Info.txt");

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
        imagePaths = {":/1930s Benny Goodman Sprite.png", ":/1930s Billie Holiday Sprite.png", ":/1930s Bing Crosby Sprite.png", ":/1930s Duke Ellington Sprite.png", ":/1930s Glen Miller Sprite.png"};
        names = {"Benny Goodman", "Billie Holiday", "Bing Crosby", "Duke Ellington", "Glen Miller"};
        m1 = "qrc:/BennyGoodman_DontBeThatWay.mp3";
        m2 = "qrc:/BillieHoliday_GodBlessTheChild.mp3";
        m3 = "qrc:/BingCrosby_ISurrenderDear.mp3";
        m4 = "qrc:/DukeEllington_Caravan.mp3";
        m5 = "qrc:/GlenMiller_IntheMood.mp3";

        artist1Info = ":/BennyGoodmanInfo.txt";
        artist2Info = ":/Billie Holiday info.txt";
        artist3Info = ":/Bing Crosby Info.txt";
        artist4Info = ":/DukeEllingtonInfo.txt";
        artist5Info = ":/Glen Miller info.txt";

        emit sendInfor(imagePaths, names);
        emit sendFileForInfoBar(":/1930s Info.txt");
        break;

    case 4:
        imagePaths = {":/1940s Edith Piaf Sprite.png", ":/1940s Ella Fitzgerald Sprite.png", ":/1940s Frank Sinatra Sprite.png", ":/1940s Nat King Cole Sprite.png", ":/1940s Vera Lynn Sprite.png"};
        names = {"Edith Piaf", "Ella Fitzgerald", "Frank Sinatra", "Nat King Cole", "Vera Lynn"};
        m1 = "qrc:/EdithPiaf_LaVieEnRose.mp3";
        m2 = "qrc:/EllaFitzgerald_DreamALittleDreamOfMe.mp3";
        m3 = "qrc:/FrankSinatra_FlyMeToTheMoon.mp3";
        m4 = "qrc:/N.K.COLE_L.O.V.E.mp3";
        m5 = "qrc:/VeraLynn_We_llMeetAgain.mp3";

        artist1Info = ":/Edith Paif info.txt";
        artist2Info = ":/Ella Fitzgerald info.txt";
        artist3Info = ":/Frank Sinatra info.txt";
        artist4Info = ":/Nat King Cole Info.txt";
        artist5Info = ":/Vera Lynn info.txt";

        emit sendInfor(imagePaths, names);
        emit sendFileForInfoBar(":/1940s Info.txt");

        break;
    case 5:
        imagePaths = {":/1950s Chuck Berry Sprite.png", ":/1950s Elvis Presley Sprite.png", ":/1950s Everly Brothers Sprite.png", ":/1950s Johnny Cash Sprite.png", ":/1950s Little Richard Sprite.png"};
        names = {"Chuck Berry", "Elvis Presley", "Everly Brothers", "Johhny Cash", "Little Richard"};
        m1 = "qrc:/Chuck_Berry_-_Johnny_B_Goode.mp3";
        m2 = "qrc:/ElvisPresley_HoundDog.mp3";
        m3 = "qrc:/TheEverlyBrothers_AllIHavetoDoIsDream.mp3";
        m4 = "qrc:/JohnnyCash_IWalkTheLine.mp3";
        m5 = "qrc:/LittleRichard_TuttiFruti.mp3";

        artist1Info = ":/Chuck Berry Info.txt";
        artist2Info = ":/Elvis Presley Info.txt";
        artist3Info = ":/The Everly Brothers Info.txt";
        artist4Info = ":/Johnny Cash Info.txt";
        artist5Info = ":/Little Richard Info.txt";

        emit sendInfor(imagePaths, names);
        emit sendFileForInfoBar(":/1950s Info.txt");

        break;
    case 6:
        imagePaths = {":/1960s Bob Dylan Sprite.png", ":/1960s James Brown Sprite.png", ":/1960s Jimi Hendrix Sprite.png", ":/1960s The Beatles Sprite.png", ":/1960s The Supremes Sprite.png"};
        names = {"Bob Dylan", "James Brown", "Jimi Hendrix", "The Beatles", "The Supremes"};
        m1 = "qrc:/BobDylan_LikeARollingStone.mp3";
        m2 = "qrc:/JamesBrown_IGotYou(IFeelGood).mp3";
        m3 = "qrc:/JimiHendrix_PurpleHaze.mp3";
        m4 = "qrc:/TheBeatles_HereComesTheSun.mp3";
        m5 = "qrc:/TheSupremes_StopintheNameofLove.mp3";

        artist1Info = ":/Bob Dylan Info.txt";
        artist2Info = ":/James Brown Info.txt";
        artist3Info = ":/Jimi Hendrix Info.txt";
        artist4Info = ":/The Beatles Info.txt";
        artist5Info = ":/The Supremes Info.txt";

        emit sendInfor(imagePaths, names);
        emit sendFileForInfoBar(":/1960s Info.txt");
        break;
    case 7:
        imagePaths = {":/1970s Bob Marley Sprite.png", ":/1970s Gloria Gaynor Sprite.png", ":/1970s Led Zeppelin Jimmy Page Sprite.png", ":/1970s Ramones Sprite.png", ":/1970s Stevie Wonder Sprite.png"};
        names = {"Bob Marley", "Gloria Gaynor", "Led Zeppelin", "The Ramones", "Stevie Wonder"};
        m1 = "qrc:/BobMarley_CouldYouBeLoved.mp3";
        m2 = "qrc:/GloriaGaynor_IWillSurvive.mp3";
        m3 = "qrc:/LedZeppelin_ImmigrantSong.mp3";
        m4 = "qrc:/Ramones_BlitzkriegBop.mp3";
        m5 = "qrc:/StevieWonder_SirDuke.mp3";

        artist1Info = ":/Bob Marley Info.txt";
        artist2Info = ":/Gloria Gaynor Info.txt";
        artist3Info = ":/Led Zeppelin Info.txt";
        artist4Info = ":/The Ramones Info.txt";
        artist5Info = ":/Stevie Wonder Info.txt";

        emit sendInfor(imagePaths, names);
        emit sendFileForInfoBar(":/1970s Info.txt");
        break;
    case 8:
        imagePaths = {":/1980s Bruce Springsteen Sprite.png", ":/1980s Madonna Sprite.png", ":/1980s Michael Jackson Sprite.png", ":/1980s Prince Sprite.png", ":/1980s Salt-N-Pepa Cheryl James.png"};
        names = {"Bruce Springsteen", "Madonna", "Michael Jackson", "Prince", "Salt-N-Pepa"};
        m1 = "qrc:/BruceSpringsteen_BornToRun.mp3";
        m2 = "qrc:/Madonna_MaterialGirl.mp3";
        m3 = "qrc:/MichaelJacson_BeatIt.mp3";
        m4 = "qrc:/Prince_Kiss.mp3";
        m5 = "qrc:/SaltNPepa_PushIt.mp3";


        artist1Info = ":/Bruce Springteen Info.txt";
        artist2Info = ":/Madonna Info.txt";
        artist3Info = ":/Michael Jackson info.txt";
        artist4Info = ":/Prince Info.txt";
        artist5Info = ":/Salt-N-Pepa info.txt";

        emit sendInfor(imagePaths, names);
        emit sendFileForInfoBar(":/1980s Info.txt");
        break;
    case 9:
        imagePaths = {":/1990s Mariah Carey Sprite.png", ":/1990s Nirvana Kurt Cobain Sprite.png", ":/1990s Tupac Sprite.png", ":/1990s Notorious B.I.G Sprite.png", ":/1990s Oasis Sprite.png"};
        names = {"Mariah Carey", "Nirvana", "2Pac", "Notorious B.I.G.", "Oasis"};
        m1 = "qrc:/MariahCarey_Fantasy.mp3";
        m2 = "qrc:/Nirvana_SmellsLikeTeenSpirit.mp3";
        m3 = "qrc:/2Pac_CaliforniaLove.mp3";
        m4 = "qrc:/Biggie_MoMoneyMoProblems.mp3";
        m5 = "qrc:/Oasis_DontLookBackInAnger.mp3";

        artist1Info = ":/Mariah Carey info.txt";
        artist2Info = ":/Nirvana Info.txt";
        artist3Info = ":/2Pac info.txt";
        artist4Info = ":/Biggie info.txt";
        artist5Info = ":/Oasis Info.txt";

        emit sendInfor(imagePaths, names);
        emit sendFileForInfoBar(":/1990s Info.txt");
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
