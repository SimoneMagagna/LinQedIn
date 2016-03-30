#include "mainwindow.h"

mainWindow::mainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonWindowClient, SIGNAL(clicked()), this, SLOT(accessoCliente()));
}

mainWindow::~mainWindow()
{
    delete ui;
}

void mainWindow::on_pushButtonAdminWindow_clicked()
{
    adminWindow* aw=new adminWindow(new LinQedAdmin);
    aw->show();
}


void mainWindow::accessoCliente()
{
    Username us(ui->lineEditMainWindow->text().toStdString());
    LinQedInClient* c= new LinQedInClient(us);
    if(c->getUtente())
    {
        windowClient* aw=new windowClient(c);
        aw->show();
    }
    else
    {
        QErrorMessage * em=new QErrorMessage();
        em->showMessage("Username non presente");
    }
}
