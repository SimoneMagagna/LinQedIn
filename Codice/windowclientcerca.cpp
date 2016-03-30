#include "windowclientcerca.h"

windowClientCerca::windowClientCerca(LinQedInClient* c, Username u, QWidget *parent) :
    client(c), us(u), QWidget(parent), ui(new Ui::windowClientCerca)
{
   ui->setupUi(this);
   list<string> l;
   client->ricerca(us, l);
   int i=0;
   list<string>::iterator it;
   ui->tableWidgetWindowClientCerca->insertColumn(0);
   for(it=l.begin(); it!=l.end(); ++it)
   {
       QTableWidgetItem *info=new QTableWidgetItem (QString::fromStdString(*it));
       ui->tableWidgetWindowClientCerca->setItem(0,i,info);
       i++;
   }
}

windowClientCerca::~windowClientCerca()
{
    delete ui;
}

void windowClientCerca::on_pushButtonIndietro_clicked()
{
    this->close();
}
