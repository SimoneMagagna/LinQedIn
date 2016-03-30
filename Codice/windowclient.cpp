#include "windowclient.h"

windowClient::windowClient(LinQedInClient* c, QWidget *parent) :
    client(c), QWidget(parent), ui(new Ui::windowClient)
{
    ui->setupUi(this);
    connect(ui->pushButtonWindowClientInserisci, SIGNAL(clicked()), this, SLOT(inserisciContatto()));
    connect(ui->pushButtonWindowClientRimuovi, SIGNAL(clicked()), this, SLOT(rimuoviContatto()));
}

windowClient::~windowClient()
{
    delete ui;
}

void windowClient::on_pushButtonWindowClientMostra_clicked()
{
    windowClientProfilo* aw=new windowClientProfilo(client);
    aw->show();
}

void windowClient::on_pushButtonWindowClientAggiorna_clicked()
{
    windowClientAggiorna* aw=new windowClientAggiorna(client);
    aw->show();
}

void windowClient::on_pushButtonWindowClientCerca_clicked()
{
    string user(ui->lineEditClientWindowCerca->text().toStdString());
    Utente* ut = client->ricercaUsernameContatto(user);
    if(ut)
    {
        if(ut->getUsername()!=client->getUtente()->getUsername())
        {
            Username u(ui->lineEditClientWindowCerca->text().toStdString());
            windowClientCerca* aw=new windowClientCerca(client, u);
            aw->show();
        }
        else
        {
            QErrorMessage * em=new QErrorMessage();
            em->showMessage("Per visualizzare il proprio profilo cliccare su Mostra");
        }
    }
    else
    {
        QErrorMessage * em=new QErrorMessage();
        em->showMessage("Username non presente");
    }
}

void windowClient::inserisciContatto()
{
    Utente* ut = client->ricercaUsernameContatto(ui->lineEditClientWindowInserisci->text().toStdString());
    if(ut)
    {
        client->insertRete(ui->lineEditClientWindowInserisci->text().toStdString());
        QMessageBox* mess = new QMessageBox;
        mess->setText("Inserimento avvenuto con successo!");
        mess->exec();
    }
    else
    {
        QErrorMessage * em=new QErrorMessage();
        em->showMessage("Username non presente");
    }
}

void windowClient::on_pushButtonWindowClientSalva_clicked()
{
    client->save();
}

void windowClient::rimuoviContatto()
{
    Utente* ut = client->ricercaUsernameContatto(ui->lineEditClientWindowInserisci->text().toStdString());
    if(ut)
    {
       client->removeRete(ui->lineEditClientWindowRimuovi->text().toStdString());
       QMessageBox* mess = new QMessageBox;
       mess->setText("Rimozione avvenuta con successo!");
       mess->exec();
    }
    else
    {
        QErrorMessage * em=new QErrorMessage();
        em->showMessage("Username non presente");
    }
}

void windowClient::on_pushButtonLogout_clicked()
{
    this->close();
}
