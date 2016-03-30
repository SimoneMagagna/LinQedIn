#include "cambiatipologiautentewindow.h"

using std::string;

cambiaTipologiaUtenteWindow::cambiaTipologiaUtenteWindow(LinQedAdmin* l, string user,  QWidget *parent) :
    admin(l), login(user), QWidget(parent), ui(new Ui::cambiaTipologiaUtenteWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonModificaTipologiaUtente, SIGNAL(clicked()), this, SLOT(modifica_tipo_utente()));
}

cambiaTipologiaUtenteWindow::~cambiaTipologiaUtenteWindow()
{
    delete ui;
}

void cambiaTipologiaUtenteWindow::getTipologiaUtente(const string & tu)
{
    tipoUtenteIniziale=tu;
    if(tu=="Utente Basic")
       ui->radioButtonUtenteBasic->setChecked(true);
    if(tu=="Utente Business")
       ui->radioButtonUtenteBusiness->setChecked(true);
    if(tu=="Utente Executive")
       ui->radioButtonUtenteExecutive->setChecked(true);
}

void cambiaTipologiaUtenteWindow::modifica_tipo_utente()
{
    string tu;
    if(ui->radioButtonUtenteBasic->isChecked())
    {
        tu=ui->radioButtonUtenteBasic->text().toStdString();
    }
    if(ui->radioButtonUtenteBusiness->isChecked())
    {
        tu=ui->radioButtonUtenteBusiness->text().toStdString();
    }
    if(ui->radioButtonUtenteExecutive->isChecked())
    {
        tu=ui->radioButtonUtenteExecutive->text().toStdString();
    }
    if(tu!=tipoUtenteIniziale)
    {
        Username us(login);
        admin->cambiaTipoUtente(us, tu);

        QMessageBox msgBox;
        msgBox.setText("Modifica avvenuta con successo");
        msgBox.exec();
        this->close();
    }
    else
    {
        QErrorMessage * em=new QErrorMessage();
        em->showMessage("L'utente appartiene già a questa tipologia");
    }

}
