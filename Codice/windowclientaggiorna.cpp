#include "windowclientaggiorna.h"

windowClientAggiorna::windowClientAggiorna(LinQedInClient* c, QWidget *parent) :
    client(c), QWidget(parent), ui(new Ui::windowClientAggiorna)
{
    ui->setupUi(this);
    connect(ui->pushButtonWindowClientAggiorna, SIGNAL(clicked()), this, SLOT(aggiornaProfilo()));
}

windowClientAggiorna::~windowClientAggiorna()
{
    delete ui;
}

void windowClientAggiorna::aggiornaProfilo()
{
    if(ui->lineEditEmail->text().toStdString()!="")
    {client->modificaEmail(ui->lineEditEmail->text().toStdString());}


    if(ui->lineEditLingue->text().toStdString()!="")
    {client->aggiungiLingua(ui->lineEditLingue->text().toStdString());}


    if(ui->lineEditCompetenze->text().toStdString()!="")
    {client->aggiungiCompetenza(ui->lineEditCompetenze->text().toStdString());}


    if(ui->lineEditEsperienze->text().toStdString()!="")
    {client->aggiungiEperienza(ui->lineEditEsperienze->text().toStdString());}


    if(ui->lineEditTitoliStudio->text().toStdString()!="")
    {client->aggiungiTitolo(ui->lineEditTitoliStudio->text().toStdString());}

    QMessageBox* mess = new QMessageBox;
    mess->setText("Modifica avvenuta con successo!");
    mess->exec();

    this->close();
}
