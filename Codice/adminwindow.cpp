#include "adminwindow.h"

using std::string;

adminWindow::adminWindow(LinQedAdmin* l, QWidget *parent) : admin(l), QWidget(parent), ui(new Ui::adminWindow)
{
    ui->setupUi(this);
    ui->tableWidgetAdminWindow->setColumnWidth(3,150);
    connect(ui->pushButtonAdminWindowRimuovi, SIGNAL(clicked()), this, SLOT(remove()));
    connect(ui->pushButtonAdminWindowCerca, SIGNAL(clicked()), this, SLOT(mostra()));
    connect(ui->pushButtonModificaTipologiaUtente, SIGNAL(clicked()), this, SLOT(modificaTipologiaUtente()));
}

void adminWindow::on_pushButtonSalva_clicked()
{
    admin->save();
}

adminWindow::~adminWindow()
{
    delete ui;
}

void adminWindow::on_pushButtonAdminWindowInserisci_clicked()
{
    adminInsertWindow* aW=new adminInsertWindow(admin);
    aW->show();
}

void adminWindow::on_pushButtonLogout_clicked()
{
    this->close();
}

void adminWindow::remove()
{
   Utente* u=admin->find(ui->lineEditAdminWindowRimuovi->text().toStdString());
      if(u)
      {
         admin->remove(ui->lineEditAdminWindowRimuovi->text().toStdString());

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

void adminWindow::mostra()
{
    ui->tableWidgetAdminWindow->setRowCount(0);;
    int i=0;
    vector<Utente*> v(admin->getDataBase());
    vector<Utente*>::iterator it;
    for(it=v.begin(); it!=v.end(); ++it)
    {
     QTableWidgetItem *username=new QTableWidgetItem (QString::fromStdString((*it)->getUsername().getLogin()));
     QTableWidgetItem *nome=new QTableWidgetItem (QString::fromStdString((*it)->getProfilo().getNome()));
     QTableWidgetItem *cognome=new QTableWidgetItem (QString::fromStdString((*it)->getProfilo().getCognome()));
     QTableWidgetItem *email=new QTableWidgetItem (QString::fromStdString((*it)->getProfilo().getEmail()));
     QTableWidgetItem *tipo_di_utente;
     if (dynamic_cast<UtenteBasic*>(*it))
        tipo_di_utente=new QTableWidgetItem ("Utente Basic");
     if (dynamic_cast<UtenteBusiness*>(*it))
        tipo_di_utente=new QTableWidgetItem ("Utente Business");
     if (dynamic_cast<UtenteExecutive*>(*it))
        tipo_di_utente=new QTableWidgetItem ("Utente Executive");
     ui->tableWidgetAdminWindow->insertRow(i);
     ui->tableWidgetAdminWindow->setItem(i,0,username);
     ui->tableWidgetAdminWindow->setItem(i,1,nome);
     ui->tableWidgetAdminWindow->setItem(i,2,cognome);
     ui->tableWidgetAdminWindow->setItem(i,3,email);
     ui->tableWidgetAdminWindow->setItem(i,4,tipo_di_utente);
     i++;
    }
}

void adminWindow::modificaTipologiaUtente()
{
     bool utenteSelezionato=false;
     for(int i=0; i<ui->tableWidgetAdminWindow->rowCount(); ++i)
     {
      if(ui->tableWidgetAdminWindow->item(i,0)->isSelected())
       {
          utenteSelezionato=true;
          cambiaTipologiaUtenteWindow* m=new cambiaTipologiaUtenteWindow(admin, ui->tableWidgetAdminWindow->item(i,0)->text().toStdString());
          m->getTipologiaUtente(ui->tableWidgetAdminWindow->item(i,4)->text().toStdString());
          m->show();
        }
      }
      if(!utenteSelezionato)
      {
         QErrorMessage * em=new QErrorMessage();
         em->showMessage("Utente non selezionato");
      }
}



