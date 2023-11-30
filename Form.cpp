#include "Form.h"
#include "ui_Form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    QPalette palette;

    // Load the image from the resource
    QImage backgroundImage(":/Stage.png");

    // Set the pixmap for the palette using the image
    palette.setBrush(QPalette::Window, QBrush(backgroundImage));

    // Apply the palette to the widget
    this->setPalette(palette);

    // Make sure the widget background is set to be drawn
    this->setAutoFillBackground(true);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    this->hide();


}

