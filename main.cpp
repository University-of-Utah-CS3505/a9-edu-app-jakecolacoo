/*
 *Main Class
 *Created by Alex Qi, Matthew Goh, Sam Onwukeme, Yujie He, Jake Crane,  ZengZheng Jiang
 *Assignment 9: Education Application
 *
 * Jake Github: @jakecolacoo
 * Alex Github: @Qibola
 * Matt Github: @Mattgoh
 * Sam Github: @reignoverall
 * Mario Github: @Mariohyj
 * Constantine Github: @CycleBird
 *
*/

#include "MainWindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
