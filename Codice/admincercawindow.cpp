#include "admincercawindow.h"
#include "ui_admincercawindow.h"

adminCercaWindow::adminCercaWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::adminCercaWindow)
{
    ui->setupUi(this);
}

adminCercaWindow::~adminCercaWindow()
{
    delete ui;
}
