#ifndef CAMBIATIPOLOGIAUTENTEWINDOW_H
#define CAMBIATIPOLOGIAUTENTEWINDOW_H

#include <string>
#include "linqedadmin.h"
#include <QWidget>
#include "ui_cambiatipologiautentewindow.h"
#include "linqedadmin.h"
#include <string>
#include <QMessageBox>
#include <QErrorMessage>

using std::string;

namespace Ui {
class cambiaTipologiaUtenteWindow;
}

class cambiaTipologiaUtenteWindow : public QWidget
{
    Q_OBJECT

public:
    explicit cambiaTipologiaUtenteWindow(LinQedAdmin*, string, QWidget *parent = 0);
    ~cambiaTipologiaUtenteWindow();
     void getTipologiaUtente(const string &);

public slots:
     void modifica_tipo_utente();

private:
    Ui::cambiaTipologiaUtenteWindow *ui;
    LinQedAdmin* admin;
    string login;
    string tipoUtenteIniziale;
};

#endif // CAMBIATIPOLOGIAUTENTEWINDOW_H
