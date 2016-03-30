#include "windowclientmostra.h"
#include "ui_windowclientmostra.h"

windowClientMostra::windowClientMostra(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::windowClientMostra)
{
    ui->setupUi(this);
}

windowClientMostra::~windowClientMostra()
{
    delete ui;
}
