#include "windowclientprofilo.h"

windowClientProfilo::windowClientProfilo(LinQedInClient* c, QWidget *parent) :
    client(c), QWidget(parent), ui(new Ui::windowClientProfilo)
{
    ui->setupUi(this);

    Utente* ut = client->getUtente();
    QTableWidgetItem *username=new QTableWidgetItem (QString::fromStdString(client->getUtente()->getUsername().getLogin()));
    QTableWidgetItem *nome=new QTableWidgetItem (QString::fromStdString(client->getUtente()->getProfilo().getNome()));
    QTableWidgetItem *cognome=new QTableWidgetItem (QString::fromStdString(client->getUtente()->getProfilo().getCognome()));
    QTableWidgetItem *email=new QTableWidgetItem (QString::fromStdString(client->getUtente()->getProfilo().getEmail()));
    QTableWidgetItem *tipo_di_utente;
    if (dynamic_cast<UtenteBasic*>(ut))
       tipo_di_utente=new QTableWidgetItem ("Utente Basic");
    if (dynamic_cast<UtenteBusiness*>(ut))
       tipo_di_utente=new QTableWidgetItem ("Utente Business");
    if (dynamic_cast<UtenteExecutive*>(ut))
       tipo_di_utente=new QTableWidgetItem ("Utente Executive");

    string competenze = client->getUtente()->getProfilo().tutteCompetenze();
    QTableWidgetItem *comp=new QTableWidgetItem (QString::fromStdString(competenze));

    string esperienze = client->getUtente()->getProfilo().tutteEsperienze();
    QTableWidgetItem *esp=new QTableWidgetItem (QString::fromStdString(esperienze));

    string titoli = client->getUtente()->getProfilo().tuttiTitoliStudio();
    QTableWidgetItem *tit=new QTableWidgetItem (QString::fromStdString(titoli));

    string lingue = client->getUtente()->getProfilo().tutteLingue();
    QTableWidgetItem *l=new QTableWidgetItem (QString::fromStdString(lingue));

    string contatti = client->getUtente()->getRete()->tuttiContatti();
    QTableWidgetItem *cont=new QTableWidgetItem (QString::fromStdString(contatti));

    ui->tableWidgetWindowClientProfilo->insertColumn(0);
    ui->tableWidgetWindowClientProfilo->setItem(0,0,username);
    ui->tableWidgetWindowClientProfilo->setItem(1,0,nome);
    ui->tableWidgetWindowClientProfilo->setItem(2,0,cognome);
    ui->tableWidgetWindowClientProfilo->setItem(3,0,email);
    ui->tableWidgetWindowClientProfilo->setItem(4,0,tipo_di_utente);
    ui->tableWidgetWindowClientProfilo->setItem(5,0,comp);
    ui->tableWidgetWindowClientProfilo->setItem(6,0,esp);
    ui->tableWidgetWindowClientProfilo->setItem(7,0,tit);
    ui->tableWidgetWindowClientProfilo->setItem(8,0,l);
    ui->tableWidgetWindowClientProfilo->setItem(9,0,cont);
}

void windowClientProfilo::on_pushButtonIndietro_clicked()
{
    this->close();
}

windowClientProfilo::~windowClientProfilo()
{
    delete ui;
}
