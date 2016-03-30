#ifndef ADMININSERTWINDOW_H
#define ADMININSERTWINDOW_H

#include "ui_admininsertwindow.h"
#include "profilo.h"
#include "username.h"
#include "linqedadmin.h"
#include "utentebasic.h"
#include "utentebusiness.h"
#include "utenteexecutive.h"
#include <string>
#include <list>
#include <QErrorMessage>
#include <QMessageBox>

namespace Ui {
class adminInsertWindow;
}

class adminInsertWindow : public QWidget
{
    Q_OBJECT

public:
    explicit adminInsertWindow(LinQedAdmin*, QWidget *parent = 0);
    ~adminInsertWindow();
    string getTipoUtente() const;

public slots:
    void insert();

private:
    Ui::adminInsertWindow *ui;
    LinQedAdmin* admin;
};

#endif // ADMININSERTWINDOW_H
