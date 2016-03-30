#include "admininsertwindow.h"

using std::string;
using std::list;


adminInsertWindow::adminInsertWindow(LinQedAdmin* l, QWidget *parent) : admin(l), QWidget(parent), ui(new Ui::adminInsertWindow)
{
   ui->setupUi(this);
   connect(ui->pushButtonAdminInsertWindow, SIGNAL(clicked()), this, SLOT(insert()));
}

adminInsertWindow::~adminInsertWindow()
{
    delete ui;
}

string adminInsertWindow::getTipoUtente() const
{
     if(ui->radioButtonUtenteBasic->isChecked())
       return ui->radioButtonUtenteBasic->text().toStdString();
     if(ui->radioButtonUtenteBusiness->isChecked())
       return ui->radioButtonUtenteBusiness->text().toStdString();
     if(ui->radioButtonUtenteExecutive->isChecked())
       return ui->radioButtonUtenteExecutive->text().toStdString();

     return ui->radioButtonUtenteBasic->text().toStdString();
}

void adminInsertWindow::insert()
{
    Utente* u=admin->find(ui->lineEditAdminInsertUsername->text().toStdString());
    string nome = ui->lineEditAdminInsertNome->text().toStdString();
    string cognome = ui->lineEditAdminInsertCognome->text().toStdString();
    string username = ui->lineEditAdminInsertUsername->text().toStdString();
        if(!u)
        {
         if(nome!="" && cognome!="" && username!="")
         {
            string tu=getTipoUtente();
            string email = ui->lineEditAdminInsertEmail->text().toStdString();
            string lingue = ui->lineEditAdminInsertLingue->text().toStdString();
            string esperienze = ui->lineEditAdminInsertEsperienze->text().toStdString();
            string competenze = ui->lineEditAdminInsertCompetenze->text().toStdString();
            string titoli = ui->lineEditAdminInsertTitoliStudio->text().toStdString();
            Username us(username);
            Profilo pf(nome, cognome, email);
            pf.caricaLingue(lingue);
            pf.caricaEsperienze(esperienze);
            pf.caricaCompetenze(competenze);
            pf.caricaTitoliStudio(titoli);
            if(tu=="Utente Basic")
                u=new UtenteBasic(pf, us);
            if(tu=="Utente Business")
                u=new UtenteBusiness(pf, us);
            if(tu=="Utente Executive")
                u=new UtenteExecutive(pf, us);
            admin->insert(u);

            QMessageBox* mess = new QMessageBox;
            mess->setText("Inserimento avvenuto con successo!");
            mess->exec();
            this->close();
         }
         else
         {
             QErrorMessage * em=new QErrorMessage();
             em->showMessage("I campi Nome Cognome e Username sono obbligatori!");
         }
        }
        else
        {
            QErrorMessage * em=new QErrorMessage();
            em->showMessage("Username già presente!");
        }
}
