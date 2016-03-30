#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include "linqedadmin.h"
#include <QWidget>
#include <QTableWidget>
#include "ui_adminwindow.h"
#include "admininsertwindow.h"
#include "utentebasic.h"
#include "utentebusiness.h"
#include "utenteexecutive.h"
#include "cambiatipologiautentewindow.h"
#include <string>
#include <QErrorMessage>
#include <QMessageBox>
#include <QTableWidgetItem>

namespace Ui {
class adminWindow;
}

class adminWindow : public QWidget
{
    Q_OBJECT

public:
    explicit adminWindow(LinQedAdmin*, QWidget *parent = 0);
    ~adminWindow();

private slots:
    void remove();
    void mostra();
    void modificaTipologiaUtente();
    void on_pushButtonAdminWindowInserisci_clicked();
    void on_pushButtonSalva_clicked();
    void on_pushButtonLogout_clicked();


private:
    Ui::adminWindow *ui;
    LinQedAdmin* admin;
};

#endif // ADMINWINDOW_H
